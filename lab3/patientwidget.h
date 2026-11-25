#ifndef PATIENTWIDGET_H
#define PATIENTWIDGET_H

#include <QWidget>

class QSqlTableModel;
struct PatientRecord;

QT_BEGIN_NAMESPACE
namespace Ui { class PatientWidget; }
QT_END_NAMESPACE

class PatientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PatientWidget(QWidget *parent = nullptr);
    ~PatientWidget();

    void refresh();

private slots:
    void onSearch();
    void onDelete();
    void onAdd();
    void onEdit();

private:
    void setupModel();
    void updateEmptyState();

    bool idExists(const QString &id) const;
    bool insertPatient(const PatientRecord &record, QString &error);
    bool updatePatient(const PatientRecord &record, QString &error);
    void selectPatientById(const QString &id);

    Ui::PatientWidget *ui;
    QSqlTableModel *m_model = nullptr;
};

#endif // PATIENTWIDGET_H
