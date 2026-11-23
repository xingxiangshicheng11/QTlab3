#ifndef PATIENTWIDGET_H
#define PATIENTWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class PatientWidget; }
QT_END_NAMESPACE

class PatientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PatientWidget(QWidget *parent = nullptr);
    ~PatientWidget();

private:
    Ui::PatientWidget *ui;
};

#endif // PATIENTWIDGET_H
