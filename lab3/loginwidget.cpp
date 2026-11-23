#include "loginwidget.h"
#include "ui_loginwidget.h"

#include <QLineEdit>
#include <QPushButton>

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    connect(ui->btnLogin, &QPushButton::clicked, this, &LoginWidget::submit);
    connect(ui->editPwd, &QLineEdit::returnPressed, this, &LoginWidget::submit);
    connect(ui->btnRegister, &QPushButton::clicked, this, &LoginWidget::registerRequested);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::submit()
{
    emit loginRequested(ui->editUser->text().trimmed(), ui->editPwd->text());
}
