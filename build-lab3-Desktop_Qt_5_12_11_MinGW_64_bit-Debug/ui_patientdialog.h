/********************************************************************************
** Form generated from reading UI file 'patientdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTDIALOG_H
#define UI_PATIENTDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PatientDialog
{
public:
    QVBoxLayout *mainLayout;
    QFormLayout *formLayout;
    QLabel *lblId;
    QLineEdit *editId;
    QLabel *lblName;
    QLineEdit *editName;
    QLabel *lblIdCard;
    QLineEdit *editIdCard;
    QLabel *lblSex;
    QComboBox *cmbSex;
    QLabel *lblDob;
    QDateEdit *dateDOB;
    QLabel *lblHeight;
    QDoubleSpinBox *spHeight;
    QLabel *lblWeight;
    QDoubleSpinBox *spWeight;
    QLabel *lblPhone;
    QLineEdit *editPhone;
    QHBoxLayout *buttonLayout;
    QSpacerItem *hSpacerButtons;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *PatientDialog)
    {
        if (PatientDialog->objectName().isEmpty())
            PatientDialog->setObjectName(QString::fromUtf8("PatientDialog"));
        PatientDialog->resize(480, 440);
        PatientDialog->setModal(true);
        mainLayout = new QVBoxLayout(PatientDialog);
        mainLayout->setSpacing(16);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(28, 24, 28, 20);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignVCenter);
        formLayout->setHorizontalSpacing(14);
        formLayout->setVerticalSpacing(12);
        lblId = new QLabel(PatientDialog);
        lblId->setObjectName(QString::fromUtf8("lblId"));
        lblId->setMinimumSize(QSize(72, 0));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblId);

        editId = new QLineEdit(PatientDialog);
        editId->setObjectName(QString::fromUtf8("editId"));
        editId->setMinimumSize(QSize(0, 30));

        formLayout->setWidget(0, QFormLayout::FieldRole, editId);

        lblName = new QLabel(PatientDialog);
        lblName->setObjectName(QString::fromUtf8("lblName"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblName);

        editName = new QLineEdit(PatientDialog);
        editName->setObjectName(QString::fromUtf8("editName"));
        editName->setMinimumSize(QSize(0, 30));

        formLayout->setWidget(1, QFormLayout::FieldRole, editName);

        lblIdCard = new QLabel(PatientDialog);
        lblIdCard->setObjectName(QString::fromUtf8("lblIdCard"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lblIdCard);

        editIdCard = new QLineEdit(PatientDialog);
        editIdCard->setObjectName(QString::fromUtf8("editIdCard"));
        editIdCard->setMinimumSize(QSize(0, 30));

        formLayout->setWidget(2, QFormLayout::FieldRole, editIdCard);

        lblSex = new QLabel(PatientDialog);
        lblSex->setObjectName(QString::fromUtf8("lblSex"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lblSex);

        cmbSex = new QComboBox(PatientDialog);
        cmbSex->addItem(QString());
        cmbSex->addItem(QString());
        cmbSex->setObjectName(QString::fromUtf8("cmbSex"));
        cmbSex->setMinimumSize(QSize(0, 30));

        formLayout->setWidget(3, QFormLayout::FieldRole, cmbSex);

        lblDob = new QLabel(PatientDialog);
        lblDob->setObjectName(QString::fromUtf8("lblDob"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lblDob);

        dateDOB = new QDateEdit(PatientDialog);
        dateDOB->setObjectName(QString::fromUtf8("dateDOB"));
        dateDOB->setMinimumSize(QSize(0, 30));
        dateDOB->setCalendarPopup(true);
        dateDOB->setDate(QDate(2000, 1, 1));

        formLayout->setWidget(4, QFormLayout::FieldRole, dateDOB);

        lblHeight = new QLabel(PatientDialog);
        lblHeight->setObjectName(QString::fromUtf8("lblHeight"));

        formLayout->setWidget(5, QFormLayout::LabelRole, lblHeight);

        spHeight = new QDoubleSpinBox(PatientDialog);
        spHeight->setObjectName(QString::fromUtf8("spHeight"));
        spHeight->setMinimumSize(QSize(0, 30));
        spHeight->setDecimals(1);
        spHeight->setMaximum(250.000000000000000);

        formLayout->setWidget(5, QFormLayout::FieldRole, spHeight);

        lblWeight = new QLabel(PatientDialog);
        lblWeight->setObjectName(QString::fromUtf8("lblWeight"));

        formLayout->setWidget(6, QFormLayout::LabelRole, lblWeight);

        spWeight = new QDoubleSpinBox(PatientDialog);
        spWeight->setObjectName(QString::fromUtf8("spWeight"));
        spWeight->setMinimumSize(QSize(0, 30));
        spWeight->setDecimals(1);
        spWeight->setMaximum(300.000000000000000);

        formLayout->setWidget(6, QFormLayout::FieldRole, spWeight);

        lblPhone = new QLabel(PatientDialog);
        lblPhone->setObjectName(QString::fromUtf8("lblPhone"));

        formLayout->setWidget(7, QFormLayout::LabelRole, lblPhone);

        editPhone = new QLineEdit(PatientDialog);
        editPhone->setObjectName(QString::fromUtf8("editPhone"));
        editPhone->setMinimumSize(QSize(0, 30));

        formLayout->setWidget(7, QFormLayout::FieldRole, editPhone);


        mainLayout->addLayout(formLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        hSpacerButtons = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(hSpacerButtons);

        btnSave = new QPushButton(PatientDialog);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setMinimumSize(QSize(90, 32));

        buttonLayout->addWidget(btnSave);

        btnCancel = new QPushButton(PatientDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(90, 32));

        buttonLayout->addWidget(btnCancel);


        mainLayout->addLayout(buttonLayout);


        retranslateUi(PatientDialog);

        QMetaObject::connectSlotsByName(PatientDialog);
    } // setupUi

    void retranslateUi(QDialog *PatientDialog)
    {
        PatientDialog->setWindowTitle(QApplication::translate("PatientDialog", "\346\202\243\350\200\205\344\277\241\346\201\257", nullptr));
        lblId->setText(QApplication::translate("PatientDialog", "ID\357\274\232", nullptr));
        editId->setPlaceholderText(QApplication::translate("PatientDialog", "\346\202\243\350\200\205\347\274\226\345\217\267\357\274\210\345\277\205\345\241\253\357\274\214\345\224\257\344\270\200\357\274\211", nullptr));
        lblName->setText(QApplication::translate("PatientDialog", "\345\247\223\345\220\215\357\274\232", nullptr));
        editName->setPlaceholderText(QApplication::translate("PatientDialog", "\345\277\205\345\241\253", nullptr));
        lblIdCard->setText(QApplication::translate("PatientDialog", "\350\272\253\344\273\275\350\257\201\357\274\232", nullptr));
        editIdCard->setPlaceholderText(QApplication::translate("PatientDialog", "\345\277\205\345\241\253", nullptr));
        lblSex->setText(QApplication::translate("PatientDialog", "\346\200\247\345\210\253\357\274\232", nullptr));
        cmbSex->setItemText(0, QApplication::translate("PatientDialog", "\347\224\267", nullptr));
        cmbSex->setItemText(1, QApplication::translate("PatientDialog", "\345\245\263", nullptr));

        lblDob->setText(QApplication::translate("PatientDialog", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", nullptr));
        dateDOB->setDisplayFormat(QApplication::translate("PatientDialog", "yyyy/MM/dd", nullptr));
        lblHeight->setText(QApplication::translate("PatientDialog", "\350\272\253\351\253\230\357\274\232", nullptr));
        spHeight->setSuffix(QApplication::translate("PatientDialog", " cm", nullptr));
        lblWeight->setText(QApplication::translate("PatientDialog", "\344\275\223\351\207\215\357\274\232", nullptr));
        spWeight->setSuffix(QApplication::translate("PatientDialog", " kg", nullptr));
        lblPhone->setText(QApplication::translate("PatientDialog", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        editPhone->setPlaceholderText(QApplication::translate("PatientDialog", "\351\200\211\345\241\253", nullptr));
        btnSave->setText(QApplication::translate("PatientDialog", "\344\277\235\345\255\230", nullptr));
        btnCancel->setText(QApplication::translate("PatientDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientDialog: public Ui_PatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTDIALOG_H
