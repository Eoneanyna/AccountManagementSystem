#include "db.h"
#include<database/account.h>
#include<database/connection.h>
#include<QSqlDatabase>
#include<config/config.h>

QString Init_Dbdata(){
Account a;
bool accError = IsExistTable(a.GetTableName());
if (!accError)
{
    //不存在
    QString err = a.CreateDb();
    if (err != nullptr){
    return  "Table "+a.GetTableName()+"create fail"+err;
    }
}

    return nullptr;
}

bool IsExistTable(QString tableName){
    //查看表是否存在
    QSqlQuery query(conf.orm_db);
    QString selectsql = QString("SHOW TABLES LIKE '%1';").arg(tableName);//是否已经存在表car_bayonet_info
    query.exec(selectsql);
    return query.next();
}

QString ExecSQL(QString sql){
    QSqlQuery query(conf.orm_db);
    if(!query.exec(sql)){
        return query.lastError().text();
    }
    return nullptr;
}
