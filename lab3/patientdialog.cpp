#include "patientdialog.h"
#include "ui_patientdialog.h"

#include <QPushButton>

PatientDialog::PatientDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PatientDialog)
{
    ui->setupUi(this);

    connect(ui->btnCancel, &QPushButton::clicked, this, &PatientDialog::reject);
}

PatientDialog::~PatientDialog()
{
    delete ui;
}
