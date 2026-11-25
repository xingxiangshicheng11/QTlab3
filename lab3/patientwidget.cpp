#include "patientwidget.h"
#include "ui_patientwidget.h"
#include "databasemanager.h"
#include "patientdialog.h"
#include "sexdelegate.h"

#include <QDateTime>
#include <QHeaderView>
#include <QMessageBox>
#include <QModelIndex>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>

PatientWidget::PatientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PatientWidget)
{
    ui->setupUi(this);

    setupModel();

    connect(ui->btnSearch, &QPushButton::clicked, this, &PatientWidget::onSearch);
    connect(ui->editSearch, &QLineEdit::returnPressed, this, &PatientWidget::onSearch);
    connect(ui->btnDelete, &QPushButton::clicked, this, &PatientWidget::onDelete);
    connect(ui->btnAdd, &QPushButton::clicked, this, &PatientWidget::onAdd);
    connect(ui->btnEdit, &QPushButton::clicked, this, &PatientWidget::onEdit);
    connect(ui->tableView, &QTableView::doubleClicked, this, &PatientWidget::onEdit);
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

void PatientWidget::onAdd()
{
    PatientDialog dialog(this);
    dialog.setEditMode(false);

    for (;;) {
        if (dialog.exec() != QDialog::Accepted)
            return;

        const PatientRecord record = dialog.record();
        if (idExists(record.id)) {
            QMessageBox::warning(this, QStringLiteral("添加失败"),
                                 QStringLiteral("患者 ID“%1”已存在，请修改后重试")
                                     .arg(record.id));
            continue;
        }

        QString error;
        if (!insertPatient(record, error)) {
            QMessageBox::critical(this, QStringLiteral("添加失败"), error);
            return;
        }

        // 清空过滤，确保新增记录可见并被选中
        ui->editSearch->clear();
        m_model->setFilter(QString());
        refresh();
        selectPatientById(record.id);
        return;
    }
}

void PatientWidget::onEdit()
{
    const QModelIndex current = ui->tableView->currentIndex();
    if (!current.isValid()) {
        QMessageBox::information(this, QStringLiteral("提示"),
                                 QStringLiteral("请先选择要修改的患者记录"));
        return;
    }

    const int row = current.row();
    PatientRecord record;
    record.id = m_model->data(m_model->index(row, 0)).toString();
    record.idCard = m_model->data(m_model->index(row, 1)).toString();
    record.name = m_model->data(m_model->index(row, 2)).toString();
    record.sex = m_model->data(m_model->index(row, 3)).toInt();
    record.dob = m_model->data(m_model->index(row, 4)).toString();
    record.height = m_model->data(m_model->index(row, 5)).toDouble();
    record.weight = m_model->data(m_model->index(row, 6)).toDouble();
    record.mobile = m_model->data(m_model->index(row, 7)).toString();
    record.age = m_model->data(m_model->index(row, 8)).toInt();

    PatientDialog dialog(this);
    dialog.setEditMode(true);
    dialog.setRecord(record);
    if (dialog.exec() != QDialog::Accepted)
        return;

    PatientRecord updated = dialog.record();
    updated.id = record.id; // 主键不可修改

    QString error;
    if (!updatePatient(updated, error)) {
        QMessageBox::critical(this, QStringLiteral("修改失败"), error);
        return;
    }

    refresh();
    selectPatientById(updated.id);
}

bool PatientWidget::idExists(const QString &id) const
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare(QStringLiteral("SELECT 1 FROM \"Patient\" WHERE \"ID\" = ?"));
    query.addBindValue(id);
    if (!query.exec())
        return false;
    return query.next();
}

bool PatientWidget::insertPatient(const PatientRecord &record, QString &error)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare(QStringLiteral(
        "INSERT INTO \"Patient\" "
        "(\"ID\",\"ID_CARD\",\"NAME\",\"SEX\",\"DOB\",\"HEIGHT\",\"WEIGHT\","
        "\"MOBILEPHONE\",\"AGE\",\"CREATEDTIMESTAMP\") "
        "VALUES (?,?,?,?,?,?,?,?,?,?)"));
    query.addBindValue(record.id);
    query.addBindValue(record.idCard);
    query.addBindValue(record.name);
    query.addBindValue(record.sex);
    query.addBindValue(record.dob);
    query.addBindValue(record.height);
    query.addBindValue(record.weight);
    query.addBindValue(record.mobile);
    query.addBindValue(record.age);
    query.addBindValue(QDateTime::currentDateTime().toString(
        QStringLiteral("yyyy-MM-dd HH:mm:ss")));

    if (!query.exec()) {
        error = query.lastError().text();
        return false;
    }
    return true;
}

bool PatientWidget::updatePatient(const PatientRecord &record, QString &error)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare(QStringLiteral(
        "UPDATE \"Patient\" SET "
        "\"ID_CARD\"=?, \"NAME\"=?, \"SEX\"=?, \"DOB\"=?, \"HEIGHT\"=?, "
        "\"WEIGHT\"=?, \"MOBILEPHONE\"=?, \"AGE\"=? WHERE \"ID\"=?"));
    query.addBindValue(record.idCard);
    query.addBindValue(record.name);
    query.addBindValue(record.sex);
    query.addBindValue(record.dob);
    query.addBindValue(record.height);
    query.addBindValue(record.weight);
    query.addBindValue(record.mobile);
    query.addBindValue(record.age);
    query.addBindValue(record.id);

    if (!query.exec()) {
        error = query.lastError().text();
        return false;
    }
    return true;
}

void PatientWidget::selectPatientById(const QString &id)
{
    for (int i = 0; i < m_model->rowCount(); ++i) {
        if (m_model->data(m_model->index(i, 0)).toString() == id) {
            ui->tableView->selectRow(i);
            ui->tableView->scrollTo(m_model->index(i, 0));
            return;
        }
    }
}
