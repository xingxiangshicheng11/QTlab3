#include "masterview.h"
#include "loginwidget.h"
#include "welcomewidget.h"
#include "patientwidget.h"

#include <QAction>
#include <QLabel>
#include <QMessageBox>
#include <QStackedWidget>
#include <QToolBar>
#include <QVBoxLayout>
#include <QWidget>

namespace {

QWidget *createPlaceholderPage(QWidget *parent, const QString &text)
{
    QWidget *page = new QWidget(parent);
    QVBoxLayout *layout = new QVBoxLayout(page);
    layout->setContentsMargins(24, 24, 24, 24);

    QLabel *label = new QLabel(text, page);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet(QStringLiteral("color:#888; font-size:15px;"));
    layout->addWidget(label);
    return page;
}

} // namespace

MasterView::MasterView(QWidget *parent)
    : QWidget(parent)
{
    buildUi();
}

MasterView::~MasterView() = default;

void MasterView::buildUi()
{
    setWindowTitle(QStringLiteral("医院诊疗系统"));
    setFixedSize(680, 500);

    QVBoxLayout *root = new QVBoxLayout(this);
    root->setContentsMargins(0, 0, 0, 0);
    root->setSpacing(0);

    // 顶部工具栏：采用代码化方式创建与添加控件
    m_toolBar = new QToolBar(this);
    m_toolBar->setMovable(false);
    m_toolBar->setFloatable(false);
    m_toolBar->setContextMenuPolicy(Qt::PreventContextMenu);
    m_toolBar->setToolButtonStyle(Qt::ToolButtonTextOnly);
    m_toolBar->setMinimumHeight(44);
    m_toolBar->setObjectName(QStringLiteral("topToolBar"));

    m_backAction = m_toolBar->addAction(QStringLiteral("←  返回"));

    QWidget *leftSpacer = new QWidget(m_toolBar);
    leftSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    m_toolBar->addWidget(leftSpacer);

    m_pageTitle = new QLabel(m_toolBar);
    m_pageTitle->setAlignment(Qt::AlignCenter);
    m_pageTitle->setObjectName(QStringLiteral("lblPageTitle"));
    m_toolBar->addWidget(m_pageTitle);

    QWidget *rightSpacer = new QWidget(m_toolBar);
    rightSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    m_toolBar->addWidget(rightSpacer);

    QWidget *rightFix = new QWidget(m_toolBar);
    rightFix->setFixedWidth(72);
    m_toolBar->addWidget(rightFix);

    root->addWidget(m_toolBar);

    m_stack = new QStackedWidget(this);
    m_stack->setObjectName(QStringLiteral("stackedWidget"));
    root->addWidget(m_stack, 1);

    m_loginPage = new LoginWidget(this);
    m_welcomePage = new WelcomeWidget(this);
    m_patientPage = new PatientWidget(this);
    m_departmentPage = createPlaceholderPage(this, QStringLiteral("科室管理（选做功能，暂未实现）"));
    m_doctorPage = createPlaceholderPage(this, QStringLiteral("医生管理（选做功能，暂未实现）"));

    // 页面顺序与 Page 枚举保持一致
    m_stack->addWidget(m_loginPage);      // Page::Login
    m_stack->addWidget(m_welcomePage);    // Page::Welcome
    m_stack->addWidget(m_patientPage);    // Page::Patient
    m_stack->addWidget(m_departmentPage); // Page::Department
    m_stack->addWidget(m_doctorPage);     // Page::Doctor

    m_developerLabel = new QLabel(QStringLiteral("学号：________    姓名：________"), this);
    m_developerLabel->setAlignment(Qt::AlignCenter);
    m_developerLabel->setObjectName(QStringLiteral("lblDeveloper"));
    root->addWidget(m_developerLabel);

    setStyleSheet(QStringLiteral(R"(
        MasterView { background: #F0F0F0; }
        QToolBar#topToolBar {
            background: #FAFAFA;
            border: none;
            border-bottom: 1px solid #D9D9D9;
            padding: 4px 6px;
            spacing: 2px;
        }
        QToolBar#topToolBar QToolButton {
            color: #333;
            padding: 6px 10px;
            border: none;
            border-radius: 4px;
        }
        QToolBar#topToolBar QToolButton:hover { background: #E8E8E8; }
        QToolBar#topToolBar QToolButton:pressed { background: #DCDCDC; }
        QLabel#lblPageTitle {
            font-size: 16px;
            font-weight: 600;
            color: #222;
        }
        QLabel#lblDeveloper {
            color: #666;
            padding: 5px;
            background: #F7F7F7;
            border-top: 1px solid #E0E0E0;
        }
        QPushButton {
            background: #E9E9E9;
            border: 1px solid #ADADAD;
            border-radius: 4px;
            padding: 6px 16px;
            color: #222;
        }
        QPushButton:hover { background: #F3F3F3; }
        QPushButton:pressed { background: #DCDCDC; }
        QLineEdit, QComboBox, QDateEdit, QDoubleSpinBox, QSpinBox {
            background: #FFFFFF;
            border: 1px solid #ADADAD;
            border-radius: 3px;
            padding: 4px 6px;
        }
        QLineEdit:focus, QComboBox:focus, QDateEdit:focus,
        QDoubleSpinBox:focus, QSpinBox:focus {
            border: 1px solid #3A8EDB;
        }
        QTableView {
            background: #FFFFFF;
            border: 1px solid #ADADAD;
            gridline-color: #E3E3E3;
            selection-background-color: #CDE6F7;
            selection-color: #1F1F1F;
        }
        QHeaderView::section {
            background: #EDEDED;
            border: none;
            border-right: 1px solid #DEDEDE;
            border-bottom: 1px solid #DEDEDE;
            padding: 5px;
            font-weight: 600;
        }
    )"));

    connect(m_backAction, &QAction::triggered, this, &MasterView::goBack);
    connect(m_loginPage, &LoginWidget::loginRequested, this, &MasterView::onLoginRequested);
    connect(m_loginPage, &LoginWidget::registerRequested, this, &MasterView::onRegisterClicked);
    connect(m_welcomePage, &WelcomeWidget::departmentRequested, this, &MasterView::onDepartmentClicked);
    connect(m_welcomePage, &WelcomeWidget::doctorRequested, this, &MasterView::onDoctorClicked);
    connect(m_welcomePage, &WelcomeWidget::patientRequested, this, &MasterView::onPatientClicked);

    switchToPage(Page::Login);
}

QWidget *MasterView::pageWidget(Page page) const
{
    switch (page) {
    case Page::Login:
        return m_loginPage;
    case Page::Welcome:
        return m_welcomePage;
    case Page::Patient:
        return m_patientPage;
    case Page::Department:
        return m_departmentPage;
    case Page::Doctor:
        return m_doctorPage;
    }
    return m_loginPage;
}

QString MasterView::pageTitle(Page page)
{
    switch (page) {
    case Page::Login:
        return QStringLiteral("登录");
    case Page::Welcome:
        return QStringLiteral("欢迎");
    case Page::Patient:
        return QStringLiteral("患者管理");
    case Page::Department:
        return QStringLiteral("科室管理");
    case Page::Doctor:
        return QStringLiteral("医生管理");
    }
    return QString();
}

bool MasterView::pageShowsBack(Page page)
{
    return page != Page::Login;
}

void MasterView::switchToPage(Page page)
{
    m_currentPage = page;
    m_stack->setCurrentWidget(pageWidget(page));
    m_pageTitle->setText(pageTitle(page));
    m_backAction->setVisible(pageShowsBack(page));
}

void MasterView::onLoginRequested(const QString &username, const QString &password)
{
    if (username.trimmed().isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, QStringLiteral("提示"),
                             QStringLiteral("请输入用户名和密码"));
        return;
    }
    // 登录校验将在数据库模块中实现，此处仅做界面切换
    switchToPage(Page::Welcome);
}

void MasterView::onRegisterClicked()
{
    QMessageBox::information(this, QStringLiteral("提示"),
                             QStringLiteral("注册功能将在后续步骤实现"));
}

void MasterView::onDepartmentClicked()
{
    switchToPage(Page::Department);
}

void MasterView::onDoctorClicked()
{
    switchToPage(Page::Doctor);
}

void MasterView::onPatientClicked()
{
    switchToPage(Page::Patient);
}

void MasterView::goBack()
{
    switch (m_currentPage) {
    case Page::Department:
    case Page::Doctor:
    case Page::Patient:
        switchToPage(Page::Welcome);
        break;
    case Page::Welcome:
        switchToPage(Page::Login);
        break;
    default:
        break;
    }
}
