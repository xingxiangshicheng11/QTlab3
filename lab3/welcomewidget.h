#ifndef WELCOMEWIDGET_H
#define WELCOMEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class WelcomeWidget; }
QT_END_NAMESPACE

class WelcomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeWidget(QWidget *parent = nullptr);
    ~WelcomeWidget();

signals:
    void departmentRequested();
    void doctorRequested();
    void patientRequested();

private:
    Ui::WelcomeWidget *ui;
};

#endif // WELCOMEWIDGET_H
