#ifndef PATIENTDIALOG_H
#define PATIENTDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class PatientDialog; }
QT_END_NAMESPACE

class PatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PatientDialog(QWidget *parent = nullptr);
    ~PatientDialog();

private:
    Ui::PatientDialog *ui;
};

#endif // PATIENTDIALOG_H
