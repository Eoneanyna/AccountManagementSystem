QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QT+=sql

#QMAKE_USE += mysql

#包含模块的pri文件，一些宏定义使用中需要用到
include($$PWD/../QxOrm/QxOrm.pri)

CONFIG += console
DEFINES += _BUILDING_QXORM

# 预编译头文件
!contains(DEFINES, _QX_NO_PRECOMPILED_HEADER) {
    PRECOMPILED_HEADER = ./config/precompiled.h
}

# QxOrm 库相关配置
#添加源代码的头文件路劲，后面代码包含头文件的时候就可以使用相对路径了
INCLUDEPATH += $$PWD/../QxOrm/include
#添加编译好的动态库，QxOrm源码编译的动态库在QxOrm/lib目录中，最好编译debug、release两个版本
LIBS += -L$$PWD/../QxOrm/lib

# 设置生成的目标名称、添加依赖库
CONFIG(debug, debug|release) {
#    TARGET = Userd
    LIBS += -lQxOrmd
} else {
#    TARGET = User
    LIBS += -lQxOrm
}

SOURCES += \
    config/config.cpp \
    database/account.cpp \
    database/connection.cpp \
    database/db.cpp \
    database/department.cpp \
    database/systemSting.cpp \
    err/errorform.cpp \
    main.cpp \
    ui/login.cpp \
    ui/mainwindow.cpp \
    ui/sreachemployee.cpp

HEADERS += \
    account.h \
    config/config.h \
    config/export.h \
    config/precompiled.h \
    connection.h \
    database/account.h \
    database/connection.h \
    database/db.h \
    database/department.h \
    database/employee.h \
    database/systemSting.h \
    err/errorform.h \
    export.h \
    precompiled.h \
    ui/login.h \
    ui/mainwindow.h \
    ui/sreachemployee.h

FORMS += \
    err/errorform.ui \
    ui/login.ui \
    ui/mainwindow.ui \
    ui/sreachemployee.ui


CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    database/database.txt \
    readme.md \
    resource/headiImage.jpg
