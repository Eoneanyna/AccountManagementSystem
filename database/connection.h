#ifndef CONNECTION_H
#define CONNECTION_H

#include<QString>
#include<config/precompiled.h>

class QX_DLL_EXPORT Connection
{
public:
    Connection():ID(0){}
    ~Connection(){ }

    long ID;
    int e_ID;   //员工id
    int s_ID;   //系统id
    int status; //状态 0正常使用 1已处理
    QString PS; //备注
};

QX_REGISTER_HPP_AMS(Connection, qx::trait::no_base_class_defined, 1)

#endif // CONNECTION_H
