#include "ui/mainwindow.h"
#include "ui/login.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include<config/config.h>

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

    config conf;
    QString err = conf.initConfig();
    if (err!=nullptr){
        errorForm errBox;
        errBox.SetErrDetail(err);
        errBox.show();
        return a.exec();
    }

    Login l;
    l.conf = &conf;
    l.show();
    return a.exec();
}
