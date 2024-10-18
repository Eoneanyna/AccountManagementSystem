#ifndef CONNECTION_H
#define CONNECTION_H

#include<QString>

class connection
{
public:
    connection();
    int ID;
    int e_ID;   //员工id
    int s_ID;   //系统id
    int status; //状态 0正常使用 1已处理
    QString PS; //备注
};

#endif // CONNECTION_H
