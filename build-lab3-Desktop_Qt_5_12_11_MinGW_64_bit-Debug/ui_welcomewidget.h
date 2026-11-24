/********************************************************************************
** Form generated from reading UI file 'welcomewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEWIDGET_H
#define UI_WELCOMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeWidget
{
public:
    QVBoxLayout *mainLayout;
    QLabel *lblHint;
    QHBoxLayout *buttonLayout;
    QSpacerItem *hSpacerLeft;
    QPushButton *btnDept;
    QPushButton *btnDoctor;
    QPushButton *btnPatient;
    QSpacerItem *hSpacerRight;
    QSpacerItem *bottomSpacer;

    void setupUi(QWidget *WelcomeWidget)
    {
        if (WelcomeWidget->objectName().isEmpty())
            WelcomeWidget->setObjectName(QString::fromUtf8("WelcomeWidget"));
        WelcomeWidget->resize(680, 430);
        mainLayout = new QVBoxLayout(WelcomeWidget);
        mainLayout->setSpacing(18);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(40, 40, 40, 40);
        lblHint = new QLabel(WelcomeWidget);
        lblHint->setObjectName(QString::fromUtf8("lblHint"));
        lblHint->setAlignment(Qt::AlignCenter);
        lblHint->setStyleSheet(QString::fromUtf8("font-size:16px; color:#555;"));

        mainLayout->addWidget(lblHint);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(30);
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        hSpacerLeft = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(hSpacerLeft);

        btnDept = new QPushButton(WelcomeWidget);
        btnDept->setObjectName(QString::fromUtf8("btnDept"));
        btnDept->setMinimumSize(QSize(130, 110));
        btnDept->setStyleSheet(QString::fromUtf8("font-size:16px;"));

        buttonLayout->addWidget(btnDept);

        btnDoctor = new QPushButton(WelcomeWidget);
        btnDoctor->setObjectName(QString::fromUtf8("btnDoctor"));
        btnDoctor->setMinimumSize(QSize(130, 110));
        btnDoctor->setStyleSheet(QString::fromUtf8("font-size:16px;"));

        buttonLayout->addWidget(btnDoctor);

        btnPatient = new QPushButton(WelcomeWidget);
        btnPatient->setObjectName(QString::fromUtf8("btnPatient"));
        btnPatient->setMinimumSize(QSize(130, 110));
        btnPatient->setStyleSheet(QString::fromUtf8("font-size:16px;"));

        buttonLayout->addWidget(btnPatient);

        hSpacerRight = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(hSpacerRight);


        mainLayout->addLayout(buttonLayout);

        bottomSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainLayout->addItem(bottomSpacer);


        retranslateUi(WelcomeWidget);

        QMetaObject::connectSlotsByName(WelcomeWidget);
    } // setupUi

    void retranslateUi(QWidget *WelcomeWidget)
    {
        lblHint->setText(QApplication::translate("WelcomeWidget", "\350\257\267\351\200\211\346\213\251\345\212\237\350\203\275\346\250\241\345\235\227", nullptr));
        btnDept->setText(QApplication::translate("WelcomeWidget", "\347\247\221\345\256\244\347\256\241\347\220\206", nullptr));
        btnDoctor->setText(QApplication::translate("WelcomeWidget", "\345\214\273\347\224\237\347\256\241\347\220\206", nullptr));
        btnPatient->setText(QApplication::translate("WelcomeWidget", "\346\202\243\350\200\205\347\256\241\347\220\206", nullptr));
        Q_UNUSED(WelcomeWidget);
    } // retranslateUi

};

namespace Ui {
    class WelcomeWidget: public Ui_WelcomeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEWIDGET_H
