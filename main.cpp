#include "ui/mainwindow.h"
#include<ui/login.h>

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include<config/config.h>
#include<database/db.h>
#include<database/connection.h>

Config conf;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "AccountManagementSystem_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    QString err = conf.initConfig();
    if (err!=nullptr){
        errorForm errBox;
        errBox.SetErrDetail(err);
        errBox.show();
        return a.exec();
    }else{
     QString err2 = Init_Dbdata();
     if (err2 != nullptr){
        errorForm errBox;
        errBox.SetErrDetail(err2);
        errBox.show();
        return a.exec();
     }
    }

    MainWindow w;
    Login l;
    l.show();
    if(l.exec() == QDialog::Accepted){
        w.SetUser();
        w.show();
    }else {
        return a.exec();
    }

    return a.exec();
}
