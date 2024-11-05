#ifndef CONFIG_H
#define CONFIG_H

#include<QString>
#include<QSqlDatabase>
#include<err/errorform.h>

class DbConf{
public:
    QString databaseIP = "localhost";
    QString databaseName = "employee";
    QString dbUName = "root";
    QString dbUPW = "123456";
};

enum RoleType{
    Super = -1,
    Normal = 0
};

struct Logined{
    QString UserName;
    RoleType Role;
};

class Config
{
public:
    Config();
    DbConf dbConfig;
    QSqlDatabase orm_db;
    Logined user;
    QString initConfig();

private:
    QString loadConfig();
    QString initDb();

};

extern Config conf;

#endif // CONFIG_H
