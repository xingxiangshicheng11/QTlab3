#ifndef PATIENTDIALOG_H
#define PATIENTDIALOG_H

#include <QDate>
#include <QDialog>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class PatientDialog; }
QT_END_NAMESPACE

struct PatientRecord
{
    QString id;
    QString idCard;
    QString name;
    QString dob;      // yyyy-MM-dd
    QString mobile;
    int sex = 1;      // 1=男 0=女
    double height = 0.0;
    double weight = 0.0;
    int age = 0;
};

class PatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PatientDialog(QWidget *parent = nullptr);
    ~PatientDialog();

    void setEditMode(bool edit);
    void setRecord(const PatientRecord &record);
    PatientRecord record() const;

protected:
    void accept() override;

private:
    static int calculateAge(const QDate &dob);

    Ui::PatientDialog *ui;
    bool m_editMode = false;
};

#endif // PATIENTDIALOG_H
