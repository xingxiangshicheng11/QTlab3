#include "welcomewidget.h"
#include "ui_welcomewidget.h"

#include <QPushButton>

WelcomeWidget::WelcomeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WelcomeWidget)
{
    ui->setupUi(this);

    connect(ui->btnDept, &QPushButton::clicked, this, &WelcomeWidget::departmentRequested);
    connect(ui->btnDoctor, &QPushButton::clicked, this, &WelcomeWidget::doctorRequested);
    connect(ui->btnPatient, &QPushButton::clicked, this, &WelcomeWidget::patientRequested);
}

WelcomeWidget::~WelcomeWidget()
{
    delete ui;
}
