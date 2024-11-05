#include "config.h"
#include"QMessageBox"
#include"QDebug"
#include <QSqlError>

Config::Config()
{
}

QString Config::initConfig(){
    //读取配置文件
    QString err = loadConfig();
    if (err != nullptr){
       return err;
    }

    err = initDb();
    if (err != nullptr){
       return err;
    }
    return err;
}

QString Config::loadConfig(){
  QString err = nullptr;

  return err;
}

QString Config::initDb(){
    QString err = nullptr;

    this->orm_db = QSqlDatabase::addDatabase("QMYSQL");
    this->orm_db.setHostName(this->dbConfig.databaseIP);  //连接本地主机
    this->orm_db.setPort(3306);
    this->orm_db.setDatabaseName(this->dbConfig.databaseName);
    this->orm_db.setUserName(this->dbConfig.dbUName);
    this->orm_db.setPassword(this->dbConfig.dbUPW);
    bool ok = orm_db.open();
    if (!ok){
        qDebug()<<"error open database because"<< this->orm_db.lastError().text();
        err = "error open database because"+this->orm_db.lastError().text();
        return err;
        }

    return err;
}
