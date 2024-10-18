#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<QString>

class account
{
public:
    account();
    int ID;
    QString uName;
    QString uPassword;
    int Role;           //0普通用户 -1超级用户
};

#endif // ACCOUNT_H
