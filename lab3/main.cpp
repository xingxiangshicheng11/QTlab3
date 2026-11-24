#include "masterview.h"
#include "databasemanager.h"

#include <QApplication>
#include <QFont>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFont font(QStringLiteral("Microsoft YaHei"), 10);
    a.setFont(font);

    DatabaseManager &db = DatabaseManager::instance();
    if (!db.open()) {
        QMessageBox::critical(nullptr, QStringLiteral("数据库连接失败"),
                              QStringLiteral("无法连接数据库：\n%1\n\n路径：%2")
                                  .arg(db.lastError(), db.databasePath()));
        return 1;
    }

    MasterView w;
    w.show();
    return a.exec();
}
