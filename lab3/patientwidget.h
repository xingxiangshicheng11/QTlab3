#ifndef PATIENTWIDGET_H
#define PATIENTWIDGET_H

#include <QWidget>

class QSqlTableModel;

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

private:
    void setupModel();
    void updateEmptyState();

    Ui::PatientWidget *ui;
    QSqlTableModel *m_model = nullptr;
};

#endif // PATIENTWIDGET_H
