#ifndef DB_H
#define DB_H

#include<qstring.h>
#include<map>
#include <iostream>
#include<string>
#include<vector>
#include<err/errorform.h>
using namespace std;

#include<QSqlDatabase>
#include<QSqlQuery>

QString Init_Dbdata();
bool IsExistTable(QString tableName);
QString ExecSQL(QString sql);

#endif // DB_H
