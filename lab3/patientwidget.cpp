#include "patientwidget.h"
#include "ui_patientwidget.h"
#include "databasemanager.h"
#include "sexdelegate.h"

#include <QHeaderView>
#include <QMessageBox>
#include <QModelIndex>
#include <QSqlError>
#include <QSqlTableModel>

PatientWidget::PatientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PatientWidget)
{
    ui->setupUi(this);

    setupModel();

    connect(ui->btnSearch, &QPushButton::clicked, this, &PatientWidget::onSearch);
    connect(ui->editSearch, &QLineEdit::returnPressed, this, &PatientWidget::onSearch);
    connect(ui->btnDelete, &QPushButton::clicked, this, &PatientWidget::onDelete);
}

PatientWidget::~PatientWidget()
{
    delete ui;
}

void PatientWidget::setupModel()
{
    DatabaseManager &db = DatabaseManager::instance();
    m_model = new QSqlTableModel(this, db.database());
    m_model->setTable(QStringLiteral("Patient"));
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    const QStringList headers = {
        QStringLiteral("ID"),     QStringLiteral("身份证"), QStringLiteral("姓名"),
        QStringLiteral("性别"),   QStringLiteral("出生日期"), QStringLiteral("身高(cm)"),
        QStringLiteral("体重(kg)"), QStringLiteral("手机号"), QStringLiteral("年龄"),
        QStringLiteral("创建时间")
    };
    for (int i = 0; i < headers.size(); ++i)
        m_model->setHeaderData(i, Qt::Horizontal, headers.at(i));

    ui->tableView->setModel(m_model);
    ui->tableView->setItemDelegateForColumn(3, new SexDelegate(this));
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setColumnWidth(0, 70);
    ui->tableView->setColumnWidth(1, 150);
    ui->tableView->setColumnWidth(2, 70);
    ui->tableView->setColumnWidth(3, 50);
    ui->tableView->setColumnWidth(4, 100);
    ui->tableView->setColumnWidth(5, 70);
    ui->tableView->setColumnWidth(6, 70);
    ui->tableView->setColumnWidth(7, 110);
    ui->tableView->setColumnWidth(8, 50);

    refresh();
}

void PatientWidget::refresh()
{
    if (!m_model)
        return;

    if (!m_model->select()) {
        QMessageBox::warning(this, QStringLiteral("查询失败"),
                             m_model->lastError().text());
    }
    updateEmptyState();
}

void PatientWidget::updateEmptyState()
{
    const bool empty = (m_model->rowCount() == 0);
    ui->stackResults->setCurrentWidget(empty ? ui->pageEmpty : ui->pageTable);

    if (empty) {
        const QString keyword = ui->editSearch->text().trimmed();
        ui->lblEmpty->setText(keyword.isEmpty()
                                  ? QStringLiteral("暂无患者记录")
                                  : QStringLiteral("未找到匹配记录"));
    }
}

void PatientWidget::onSearch()
{
    const QString keyword = ui->editSearch->text().trimmed();
    if (keyword.isEmpty()) {
        m_model->setFilter(QString());
    } else {
        QString escaped = keyword;
        escaped.replace(QLatin1Char('\''), QLatin1String("''"));
        m_model->setFilter(QStringLiteral("NAME LIKE '%1%' OR ID_CARD LIKE '%1%'")
                               .arg(escaped));
    }
    refresh();
}

void PatientWidget::onDelete()
{
    const QModelIndex current = ui->tableView->currentIndex();
    if (!current.isValid()) {
        QMessageBox::information(this, QStringLiteral("提示"),
                                 QStringLiteral("请先选择要删除的患者记录"));
        return;
    }

    const int row = current.row();
    const QString id = m_model->data(m_model->index(row, 0)).toString();
    const QString name = m_model->data(m_model->index(row, 2)).toString();

    const QMessageBox::StandardButton answer = QMessageBox::question(
        this, QStringLiteral("确认删除"),
        QStringLiteral("确定删除患者“%1”（ID：%2）吗？\n此操作不可撤销。")
            .arg(name, id),
        QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

    if (answer != QMessageBox::Yes)
        return;

    if (!m_model->removeRow(row)) {
        QMessageBox::warning(this, QStringLiteral("删除失败"),
                             m_model->lastError().text());
        return;
    }

    if (!m_model->submitAll()) {
        QMessageBox::critical(this, QStringLiteral("删除失败"),
                              m_model->lastError().text());
        m_model->revertAll();
        return;
    }

    refresh();
}
