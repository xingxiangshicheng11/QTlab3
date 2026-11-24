#include "databasemanager.h"

#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QSqlError>
#include <QSqlQuery>
#include <QStringList>
#include <QVariant>

#ifndef LAB3_SOURCE_DIR
#define LAB3_SOURCE_DIR ""
#endif

DatabaseManager &DatabaseManager::instance()
{
    static DatabaseManager inst;
    return inst;
}

DatabaseManager::~DatabaseManager()
{
    if (QSqlDatabase::contains(QSqlDatabase::defaultConnection)) {
        {
            QSqlDatabase db = QSqlDatabase::database(QSqlDatabase::defaultConnection, false);
            if (db.isOpen())
                db.close();
        }
        QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
    }
}

bool DatabaseManager::open()
{
    if (m_ok && database().isOpen())
        return true;

    if (!QSqlDatabase::isDriverAvailable(QStringLiteral("QSQLITE"))) {
        m_error = QStringLiteral("未找到 QSQLITE 数据库驱动（qsqlite.dll）");
        m_ok = false;
        return false;
    }

    m_path = resolveDatabasePath();

    QSqlDatabase db;
    if (QSqlDatabase::contains(QSqlDatabase::defaultConnection))
        db = QSqlDatabase::database(QSqlDatabase::defaultConnection, false);
    else
        db = QSqlDatabase::addDatabase(QStringLiteral("QSQLITE"));

    db.setDatabaseName(m_path);
    if (!db.open()) {
        m_error = db.lastError().text();
        if (m_error.isEmpty())
            m_error = QStringLiteral("无法打开数据库文件");
        m_ok = false;
        return false;
    }

    if (!ensureSchema()) {
        m_ok = false;
        db.close();
        return false;
    }

    m_ok = true;
    m_error.clear();
    return true;
}

bool DatabaseManager::isOpen() const
{
    return m_ok
            && QSqlDatabase::contains(QSqlDatabase::defaultConnection)
            && QSqlDatabase::database(QSqlDatabase::defaultConnection, false).isOpen();
}

QSqlDatabase DatabaseManager::database() const
{
    return QSqlDatabase::database(QSqlDatabase::defaultConnection, false);
}

QString DatabaseManager::databasePath() const
{
    return m_path;
}

QString DatabaseManager::lastError() const
{
    return m_error;
}

QString DatabaseManager::resolveDatabasePath() const
{
    const QString fileName = QStringLiteral("hospital.db");
    const QString appDir = QCoreApplication::applicationDirPath();

    QStringList candidates;
    candidates << QDir(appDir).filePath(fileName)
               << QDir(appDir).filePath(QStringLiteral("../") + fileName)
               << QDir(appDir).filePath(QStringLiteral("../../") + fileName);

    const QString srcDir = QString::fromUtf8(LAB3_SOURCE_DIR);
    if (!srcDir.isEmpty())
        candidates << QDir(srcDir).filePath(fileName);

    for (const QString &candidate : candidates) {
        if (QFileInfo::exists(candidate))
            return QDir::cleanPath(candidate);
    }

    // 都不存在时，退而求其次在可执行目录新建（open() 后由 ensureSchema 建表）
    return QDir::cleanPath(candidates.first());
}

bool DatabaseManager::ensureSchema()
{
    QSqlDatabase db = database();

    const QStringList ddl = {
        QStringLiteral("CREATE TABLE IF NOT EXISTS \"Department\" ("
                       "\"ID\" TEXT NOT NULL,"
                       "\"NAME\" TEXT(50) NOT NULL,"
                       "CONSTRAINT \"pk_Department\" PRIMARY KEY (\"ID\"))"),
        QStringLiteral("CREATE TABLE IF NOT EXISTS \"Doctor\" ("
                       "\"ID\" TEXT NOT NULL,"
                       "\"NAME\" TEXT(50) NOT NULL,"
                       "\"DEPARTMENT_ID\" TEXT,"
                       "\"EMPLOYEENO\" TEXT(32),"
                       "CONSTRAINT \"pk_Doctor\" PRIMARY KEY (\"ID\"),"
                       "CONSTRAINT \"fk_Doctor_Department_1\" FOREIGN KEY (\"DEPARTMENT_ID\") "
                       "REFERENCES \"Department\" (\"ID\"))"),
        QStringLiteral("CREATE TABLE IF NOT EXISTS \"User\" ("
                       "\"ID\" TEXT NOT NULL,"
                       "\"FULLNAME\" TEXT(50),"
                       "\"USERNAME\" TEXT(32) NOT NULL,"
                       "\"PASSWORD\" TEXT(64) NOT NULL,"
                       "CONSTRAINT \"pk_User\" PRIMARY KEY (\"ID\"),"
                       "CONSTRAINT \"uq_User_USERNAME\" UNIQUE (\"USERNAME\"))"),
        QStringLiteral("CREATE TABLE IF NOT EXISTS \"Patient\" ("
                       "\"ID\" TEXT(32) NOT NULL,"
                       "\"ID_CARD\" TEXT(20) NOT NULL,"
                       "\"NAME\" TEXT(50) NOT NULL,"
                       "\"SEX\" INTEGER NOT NULL DEFAULT 1,"
                       "\"DOB\" TEXT(10),"
                       "\"HEIGHT\" REAL,"
                       "\"WEIGHT\" REAL,"
                       "\"MOBILEPHONE\" TEXT(20),"
                       "\"AGE\" INTEGER,"
                       "\"CREATEDTIMESTAMP\" TEXT DEFAULT (datetime('now','localtime')),"
                       "CONSTRAINT \"pk_Patient\" PRIMARY KEY (\"ID\"))"),
        QStringLiteral("CREATE TABLE IF NOT EXISTS \"History\" ("
                       "\"ID\" TEXT NOT NULL,"
                       "\"USER_ID\" TEXT,"
                       "\"EVENT\" TEXT(255),"
                       "\"TIMESTAMP\" TEXT DEFAULT (datetime('now','localtime')),"
                       "CONSTRAINT \"pk_History\" PRIMARY KEY (\"ID\"),"
                       "CONSTRAINT \"fk_History_User_1\" FOREIGN KEY (\"USER_ID\") "
                       "REFERENCES \"User\" (\"ID\"))")
    };

    for (const QString &statement : ddl) {
        QSqlQuery query(db);
        if (!query.exec(statement)) {
            m_error = QStringLiteral("建表失败：%1").arg(query.lastError().text());
            return false;
        }
    }

    // 兜底：若用户表为空，写入默认管理员，保证登录可用
    QSqlQuery count(db);
    if (!count.exec(QStringLiteral("SELECT COUNT(*) FROM \"User\""))) {
        m_error = QStringLiteral("查询用户表失败：%1").arg(count.lastError().text());
        return false;
    }
    if (count.next() && count.value(0).toInt() == 0) {
        QSqlQuery insert(db);
        insert.prepare(QStringLiteral(
            "INSERT INTO \"User\" (\"ID\",\"FULLNAME\",\"USERNAME\",\"PASSWORD\") "
            "VALUES (?,?,?,?)"));
        insert.addBindValue(QStringLiteral("U001"));
        insert.addBindValue(QStringLiteral("系统管理员"));
        insert.addBindValue(QStringLiteral("admin"));
        insert.addBindValue(QStringLiteral("123456"));
        if (!insert.exec()) {
            m_error = QStringLiteral("写入默认用户失败：%1").arg(insert.lastError().text());
            return false;
        }
    }

    return true;
}

bool DatabaseManager::authenticate(const QString &username, const QString &password)
{
    if (!isOpen()) {
        m_error = QStringLiteral("数据库未连接");
        return false;
    }

    QSqlQuery query(database());
    query.prepare(QStringLiteral(
        "SELECT 1 FROM \"User\" WHERE \"USERNAME\" = ? AND \"PASSWORD\" = ?"));
    query.addBindValue(username);
    query.addBindValue(password);

    if (!query.exec()) {
        m_error = query.lastError().text();
        return false;
    }
    return query.next();
}
