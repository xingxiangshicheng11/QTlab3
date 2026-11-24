#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QString>

class DatabaseManager
{
public:
    static DatabaseManager &instance();

    bool open();
    bool isOpen() const;

    QSqlDatabase database() const;
    QString databasePath() const;
    QString lastError() const;

    // 预留：登录校验（下一步“登录控制”调用，本步不接 UI）
    bool authenticate(const QString &username, const QString &password);

private:
    DatabaseManager() = default;
    ~DatabaseManager();
    DatabaseManager(const DatabaseManager &) = delete;
    DatabaseManager &operator=(const DatabaseManager &) = delete;

    QString resolveDatabasePath() const;
    bool ensureSchema();

    bool m_ok = false;
    QString m_path;
    QString m_error;
};

#endif // DATABASEMANAGER_H
