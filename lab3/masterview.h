#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include <QWidget>

class QStackedWidget;
class QToolBar;
class QAction;
class QLabel;
class LoginWidget;
class WelcomeWidget;
class PatientWidget;

class MasterView : public QWidget
{
    Q_OBJECT

public:
    explicit MasterView(QWidget *parent = nullptr);
    ~MasterView();

private slots:
    void onLoginRequested(const QString &username, const QString &password);
    void onRegisterClicked();
    void onPatientClicked();
    void onOptionalModuleClicked();
    void goBack();

private:
    void buildUi();
    void switchToPage(QWidget *page, const QString &title, bool showBack);

    QToolBar *m_toolBar = nullptr;
    QAction *m_backAction = nullptr;
    QLabel *m_pageTitle = nullptr;
    QLabel *m_developerLabel = nullptr;
    QStackedWidget *m_stack = nullptr;
    LoginWidget *m_loginPage = nullptr;
    WelcomeWidget *m_welcomePage = nullptr;
    PatientWidget *m_patientPage = nullptr;
};

#endif // MASTERVIEW_H
