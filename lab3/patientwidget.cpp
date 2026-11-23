#include "patientwidget.h"
#include "ui_patientwidget.h"

PatientWidget::PatientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PatientWidget)
{
    ui->setupUi(this);
}

PatientWidget::~PatientWidget()
{
    delete ui;
}
