#include "config.h"
#include"QMessageBox"
#include"QDebug"
#include <QSqlError>

config::config()
{
}

QString config::initConfig(){
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

QString config::loadConfig(){
  QString err = nullptr;

  return err;
}

QString config::initDb(){
    QString err = nullptr;
    //初始化数据库
    this->db = QSqlDatabase::addDatabase("QMYSQL");
    this->db.setHostName(this->dbConfig.databaseIP);  //连接本地主机
    this->db.setPort(3306);
    this->db.setDatabaseName(this->dbConfig.databaseName);
    this->db.setUserName(this->dbConfig.dbUName);
    this->db.setPassword(this->dbConfig.dbUPW);
    bool ok = db.open();
    if (!ok){
        qDebug()<<"error open database because"<< this->db.lastError().text();
        err = "error open database because"+this->db.lastError().text();
        return err;
        }
    return err;
}
