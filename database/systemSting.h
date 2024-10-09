#ifndef SYSTEMSTING_H
#define SYSTEMSTING_H

#include<QString>

class systemSting
{
public:
    systemSting();
    int ID;
    QString Name;
    int PID;//父id
    QString PS;//备注，写账号、卡and so on

};

#endif // SYSTEMSTING_H
