#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#endif // EMPLOYEE_H

#include<QString>

class employee{
public:
    int ID;//员工唯一ID
    QString E_name;//员工姓名+英文名
    int Dep_ID;//员工所属部门ID
    //入职日期，可为空
    //离职日期，可为空
    QString PS;//备注，可为空
};
