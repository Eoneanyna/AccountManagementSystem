QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QT+=sql

SOURCES += \
    database/account.cpp \
    database/connection.cpp \
    database/department.cpp \
    database/systemSting.cpp \
    err/errorform.cpp \
    main.cpp \
    ui/login.cpp \
    ui/mainwindow.cpp \
    ui/sreachemployee.cpp

HEADERS += \
    account.h \
    connection.h \
    database/account.h \
    database/connection.h \
    database/department.h \
    database/employee.h \
    database/systemSting.h \
    err/errorform.h \
    ui/login.h \
    ui/mainwindow.h \
    ui/sreachemployee.h

FORMS += \
    err/errorform.ui \
    ui/login.ui \
    ui/mainwindow.ui \
    ui/sreachemployee.ui

TRANSLATIONS += \
    AccountManagementSystem_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    readme.md \
    resource/headiImage.jpg
