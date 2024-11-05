#include "database/account.h"
#include<QSqlQuery>
#include<database/db.h>
#include<QDebug>
#include<config/config.h>
#include <QSqlError>


QX_REGISTER_CPP_AMS(Account)

namespace qx {
    template <> void register_class(QxClass<Account> & t)
    {
        t.setName(AccountTableName);
        t.id(&Account::ID, "id");
        t.data(&Account::uName, "uName", 1);
        t.data(&Account::uPassword, "uPassword");
        t.data(&Account::Role, "role");
    }
}


//创建表
QString Account::CreateDb(){
    QString err = nullptr;
    QString createDb = QString("CREATE TABLE `account` (\
    `id` INT NOT NULL AUTO_INCREMENT,\
    `uName` VARCHAR(50) NULL DEFAULT NULL,\
    `uPassword` VARCHAR(50) NULL DEFAULT NULL,\
    `role` INT NULL DEFAULT NULL COMMENT '0普通用户 -1超级用户',\
    PRIMARY KEY (`id`),\
    UNIQUE INDEX `uName` (`uName`)\
    )\
    COMMENT='登录账号管理'\
    COLLATE='utf8mb3_general_ci';\
    ");
    err = ExecSQL(createDb);
    if(err != nullptr){
        err = QString("错误,数据库创建表%1错误\n%2").arg(AccountTableName,err);
        qDebug()<<err;
    }
    return err;
}
