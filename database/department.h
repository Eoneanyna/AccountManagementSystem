#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include<QString>

class department
{
public:
    department();
    int ID;
    QString Name;
    int PID;//父id
};

#endif // DEPARTMENT_H
