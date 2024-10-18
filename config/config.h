#ifndef CONFIG_H
#define CONFIG_H

#include<QString>
#include<QSqlDatabase>
#include<err/errorform.h>

class Db{
public:
    QString databaseIP = "localhost";
    QString databaseName = "employee";
    QString dbUName = "root";
    QString dbUPW = "123456";
};

class config
{
public:
    config();
    Db dbConfig;
    QSqlDatabase db;
    QString initConfig();

private:
    QString loadConfig();
    QString initDb();

};

#endif // CONFIG_H
