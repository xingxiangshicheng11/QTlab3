/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QVBoxLayout *mainLayout;
    QSpacerItem *topSpacer;
    QLabel *lblTitle;
    QSpacerItem *midSpacer;
    QHBoxLayout *formRowLayout;
    QSpacerItem *hSpacerLeft;
    QFormLayout *formLayout;
    QLabel *lblUser;
    QLineEdit *editUser;
    QLabel *lblPwd;
    QLineEdit *editPwd;
    QSpacerItem *hSpacerRight;
    QSpacerItem *btnSpacer;
    QHBoxLayout *buttonLayout;
    QSpacerItem *hSpacerBtnLeft;
    QPushButton *btnRegister;
    QPushButton *btnLogin;
    QSpacerItem *hSpacerBtnRight;
    QSpacerItem *bottomSpacer;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        LoginWidget->resize(680, 430);
        mainLayout = new QVBoxLayout(LoginWidget);
        mainLayout->setSpacing(12);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(40, 24, 40, 24);
        topSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainLayout->addItem(topSpacer);

        lblTitle = new QLabel(LoginWidget);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        lblTitle->setAlignment(Qt::AlignCenter);
        lblTitle->setStyleSheet(QString::fromUtf8("font-size:22px; font-weight:bold; color:#1F1F1F;"));

        mainLayout->addWidget(lblTitle);

        midSpacer = new QSpacerItem(20, 34, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainLayout->addItem(midSpacer);

        formRowLayout = new QHBoxLayout();
        formRowLayout->setObjectName(QString::fromUtf8("formRowLayout"));
        hSpacerLeft = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formRowLayout->addItem(hSpacerLeft);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignVCenter);
        formLayout->setHorizontalSpacing(12);
        formLayout->setVerticalSpacing(14);
        lblUser = new QLabel(LoginWidget);
        lblUser->setObjectName(QString::fromUtf8("lblUser"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblUser);

        editUser = new QLineEdit(LoginWidget);
        editUser->setObjectName(QString::fromUtf8("editUser"));
        editUser->setMinimumSize(QSize(260, 0));

        formLayout->setWidget(0, QFormLayout::FieldRole, editUser);

        lblPwd = new QLabel(LoginWidget);
        lblPwd->setObjectName(QString::fromUtf8("lblPwd"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblPwd);

        editPwd = new QLineEdit(LoginWidget);
        editPwd->setObjectName(QString::fromUtf8("editPwd"));
        editPwd->setMinimumSize(QSize(260, 0));
        editPwd->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, editPwd);


        formRowLayout->addLayout(formLayout);

        hSpacerRight = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formRowLayout->addItem(hSpacerRight);


        mainLayout->addLayout(formRowLayout);

        btnSpacer = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainLayout->addItem(btnSpacer);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        hSpacerBtnLeft = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(hSpacerBtnLeft);

        btnRegister = new QPushButton(LoginWidget);
        btnRegister->setObjectName(QString::fromUtf8("btnRegister"));
        btnRegister->setMinimumSize(QSize(100, 34));

        buttonLayout->addWidget(btnRegister);

        btnLogin = new QPushButton(LoginWidget);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setMinimumSize(QSize(100, 34));

        buttonLayout->addWidget(btnLogin);

        hSpacerBtnRight = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(hSpacerBtnRight);


        mainLayout->addLayout(buttonLayout);

        bottomSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainLayout->addItem(bottomSpacer);


        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        lblTitle->setText(QApplication::translate("LoginWidget", "\346\254\242\350\277\216\344\275\277\347\224\250\350\257\212\347\226\227\346\265\213\350\257\225\347\263\273\347\273\237", nullptr));
        lblUser->setText(QApplication::translate("LoginWidget", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        editUser->setPlaceholderText(QApplication::translate("LoginWidget", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        lblPwd->setText(QApplication::translate("LoginWidget", "\345\257\206\343\200\200\347\240\201\357\274\232", nullptr));
        editPwd->setPlaceholderText(QApplication::translate("LoginWidget", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        btnRegister->setText(QApplication::translate("LoginWidget", "\346\263\250\345\206\214", nullptr));
        btnLogin->setText(QApplication::translate("LoginWidget", "\347\231\273\345\275\225", nullptr));
        Q_UNUSED(LoginWidget);
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
