#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWidget; }
QT_END_NAMESPACE

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

    void clearPassword();

signals:
    void loginRequested(const QString &username, const QString &password);
    void registerRequested();

private:
    void submit();

    Ui::LoginWidget *ui;
};

#endif // LOGINWIDGET_H
