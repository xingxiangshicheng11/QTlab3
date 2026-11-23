#include "masterview.h"

#include <QApplication>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFont font(QStringLiteral("Microsoft YaHei"), 10);
    a.setFont(font);

    MasterView w;
    w.show();
    return a.exec();
}
