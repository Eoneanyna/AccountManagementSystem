#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<QString>
#include<QSqlDatabase>
#include<config/config.h>

#define AccountTableName "account"

class QX_DLL_EXPORT Account{
public:
    Account():ID(0){}

    long ID;
    QString uName;
    QString uPassword;
    RoleType Role;           //0普通用户 -1超级用户
    QString GetTableName(){return AccountTableName;}
    QString CreateDb();
};

QX_REGISTER_HPP_AMS(Account, qx::trait::no_base_class_defined, 1)

#endif // ACCOUNT_H
