/********************************************************************************
** Form generated from reading UI file 'patientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTWIDGET_H
#define UI_PATIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientWidget
{
public:
    QVBoxLayout *mainLayout;
    QHBoxLayout *searchBarLayout;
    QLineEdit *editSearch;
    QPushButton *btnSearch;
    QPushButton *btnAdd;
    QPushButton *btnDelete;
    QPushButton *btnEdit;
    QStackedWidget *stackResults;
    QWidget *pageTable;
    QVBoxLayout *pageTableLayout;
    QTableView *tableView;
    QWidget *pageEmpty;
    QVBoxLayout *pageEmptyLayout;
    QLabel *lblEmpty;

    void setupUi(QWidget *PatientWidget)
    {
        if (PatientWidget->objectName().isEmpty())
            PatientWidget->setObjectName(QString::fromUtf8("PatientWidget"));
        PatientWidget->resize(680, 430);
        mainLayout = new QVBoxLayout(PatientWidget);
        mainLayout->setSpacing(10);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(16, 14, 16, 14);
        searchBarLayout = new QHBoxLayout();
        searchBarLayout->setSpacing(8);
        searchBarLayout->setObjectName(QString::fromUtf8("searchBarLayout"));
        editSearch = new QLineEdit(PatientWidget);
        editSearch->setObjectName(QString::fromUtf8("editSearch"));
        editSearch->setMinimumSize(QSize(0, 32));

        searchBarLayout->addWidget(editSearch);

        btnSearch = new QPushButton(PatientWidget);
        btnSearch->setObjectName(QString::fromUtf8("btnSearch"));
        btnSearch->setMinimumSize(QSize(72, 32));

        searchBarLayout->addWidget(btnSearch);

        btnAdd = new QPushButton(PatientWidget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setMinimumSize(QSize(72, 32));

        searchBarLayout->addWidget(btnAdd);

        btnDelete = new QPushButton(PatientWidget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setMinimumSize(QSize(72, 32));

        searchBarLayout->addWidget(btnDelete);

        btnEdit = new QPushButton(PatientWidget);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));
        btnEdit->setMinimumSize(QSize(72, 32));

        searchBarLayout->addWidget(btnEdit);


        mainLayout->addLayout(searchBarLayout);

        stackResults = new QStackedWidget(PatientWidget);
        stackResults->setObjectName(QString::fromUtf8("stackResults"));
        pageTable = new QWidget();
        pageTable->setObjectName(QString::fromUtf8("pageTable"));
        pageTableLayout = new QVBoxLayout(pageTable);
        pageTableLayout->setSpacing(0);
        pageTableLayout->setObjectName(QString::fromUtf8("pageTableLayout"));
        pageTableLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(pageTable);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSortingEnabled(false);

        pageTableLayout->addWidget(tableView);

        stackResults->addWidget(pageTable);
        pageEmpty = new QWidget();
        pageEmpty->setObjectName(QString::fromUtf8("pageEmpty"));
        pageEmptyLayout = new QVBoxLayout(pageEmpty);
        pageEmptyLayout->setObjectName(QString::fromUtf8("pageEmptyLayout"));
        lblEmpty = new QLabel(pageEmpty);
        lblEmpty->setObjectName(QString::fromUtf8("lblEmpty"));
        lblEmpty->setAlignment(Qt::AlignCenter);
        lblEmpty->setStyleSheet(QString::fromUtf8("color:#999; font-size:14px;"));

        pageEmptyLayout->addWidget(lblEmpty);

        stackResults->addWidget(pageEmpty);

        mainLayout->addWidget(stackResults);


        retranslateUi(PatientWidget);

        stackResults->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PatientWidget);
    } // setupUi

    void retranslateUi(QWidget *PatientWidget)
    {
        editSearch->setPlaceholderText(QApplication::translate("PatientWidget", "\346\214\211\345\247\223\345\220\215 / \350\272\253\344\273\275\350\257\201\346\237\245\350\257\242\342\200\246", nullptr));
        btnSearch->setText(QApplication::translate("PatientWidget", "\346\237\245\346\211\276", nullptr));
        btnAdd->setText(QApplication::translate("PatientWidget", "\346\267\273\345\212\240", nullptr));
        btnDelete->setText(QApplication::translate("PatientWidget", "\345\210\240\351\231\244", nullptr));
        btnEdit->setText(QApplication::translate("PatientWidget", "\344\277\256\346\224\271", nullptr));
        lblEmpty->setText(QApplication::translate("PatientWidget", "\346\234\252\346\211\276\345\210\260\345\214\271\351\205\215\350\256\260\345\275\225", nullptr));
        Q_UNUSED(PatientWidget);
    } // retranslateUi

};

namespace Ui {
    class PatientWidget: public Ui_PatientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTWIDGET_H
