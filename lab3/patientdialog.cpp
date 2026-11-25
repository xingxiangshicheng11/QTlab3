#include "patientdialog.h"
#include "ui_patientdialog.h"

#include <QComboBox>
#include <QDateEdit>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>

PatientDialog::PatientDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PatientDialog)
{
    ui->setupUi(this);

    connect(ui->btnSave, &QPushButton::clicked, this, &PatientDialog::accept);
    connect(ui->btnCancel, &QPushButton::clicked, this, &PatientDialog::reject);

    setEditMode(false);
}

PatientDialog::~PatientDialog()
{
    delete ui;
}

void PatientDialog::setEditMode(bool edit)
{
    m_editMode = edit;
    setWindowTitle(edit ? QStringLiteral("编辑患者信息")
                        : QStringLiteral("添加患者信息"));
    // 编辑时主键 ID 不允许修改
    ui->editId->setReadOnly(edit);
}

void PatientDialog::setRecord(const PatientRecord &record)
{
    ui->editId->setText(record.id);
    ui->editName->setText(record.name);
    ui->editIdCard->setText(record.idCard);
    ui->cmbSex->setCurrentIndex(record.sex == 1 ? 0 : 1);

    QDate dob = QDate::fromString(record.dob, QStringLiteral("yyyy-MM-dd"));
    if (!dob.isValid())
        dob = QDate(2000, 1, 1);
    ui->dateDOB->setDate(dob);

    ui->spHeight->setValue(record.height);
    ui->spWeight->setValue(record.weight);
    ui->editPhone->setText(record.mobile);
}

PatientRecord PatientDialog::record() const
{
    PatientRecord r;
    r.id = ui->editId->text().trimmed();
    r.name = ui->editName->text().trimmed();
    r.idCard = ui->editIdCard->text().trimmed();
    r.sex = (ui->cmbSex->currentIndex() == 1) ? 0 : 1;

    const QDate dob = ui->dateDOB->date();
    r.dob = dob.toString(QStringLiteral("yyyy-MM-dd"));
    r.height = ui->spHeight->value();
    r.weight = ui->spWeight->value();
    r.mobile = ui->editPhone->text().trimmed();
    r.age = calculateAge(dob);
    return r;
}

void PatientDialog::accept()
{
    if (ui->editId->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, QStringLiteral("提示"),
                             QStringLiteral("请输入患者 ID"));
        ui->editId->setFocus();
        return;
    }
    if (ui->editName->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, QStringLiteral("提示"),
                             QStringLiteral("请输入患者姓名"));
        ui->editName->setFocus();
        return;
    }
    if (ui->editIdCard->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, QStringLiteral("提示"),
                             QStringLiteral("请输入身份证号"));
        ui->editIdCard->setFocus();
        return;
    }

    QDialog::accept();
}

int PatientDialog::calculateAge(const QDate &dob)
{
    if (!dob.isValid())
        return 0;

    const QDate today = QDate::currentDate();
    int age = today.year() - dob.year();
    if (today.month() < dob.month()
        || (today.month() == dob.month() && today.day() < dob.day())) {
        --age;
    }
    return age < 0 ? 0 : age;
}
