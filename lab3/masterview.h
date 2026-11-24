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
    void onDepartmentClicked();
    void onDoctorClicked();
    void onPatientClicked();
    void goBack();

private:
    enum class Page {
        Login,
        Welcome,
        Patient,
        Department,
        Doctor
    };

    void buildUi();
    void switchToPage(Page page);
    QWidget *pageWidget(Page page) const;
    static QString pageTitle(Page page);
    static bool pageShowsBack(Page page);

    QToolBar *m_toolBar = nullptr;
    QAction *m_backAction = nullptr;
    QLabel *m_pageTitle = nullptr;
    QLabel *m_developerLabel = nullptr;
    QStackedWidget *m_stack = nullptr;
    LoginWidget *m_loginPage = nullptr;
    WelcomeWidget *m_welcomePage = nullptr;
    PatientWidget *m_patientPage = nullptr;
    QWidget *m_departmentPage = nullptr;
    QWidget *m_doctorPage = nullptr;
    Page m_currentPage = Page::Login;
};

#endif // MASTERVIEW_H
