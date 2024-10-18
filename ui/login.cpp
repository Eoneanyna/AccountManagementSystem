#include "login.h"
#include "ui_login.h"
#include<QLabel>
#include<QDebug>
#include<qstring.h>
#include<err/errorform.h>

#include <iostream>
using namespace std;


Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    QPixmap *pixmap = new QPixmap(HEADIMAGEPATH);
    pixmap->scaled(ui->label_icon->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_icon->setScaledContents(true);
    ui->label_icon->setPixmap(*pixmap);

    //提交按钮
    connect(ui->loginButton,SIGNAL(clicked(bool)),SLOT(click_Login()));


    //show
    this->show();
}

Login::~Login()
{
    delete ui;
}

void Login::click_Login(){
       this->accName = ui->accountName->text();
       this->accPw = ui->accountPw->text();

       if(accPw.size()<8||accName.size()<1){
            //错误提示框图
            errorForm *err = new errorForm;
            err->SetErrDetail(QString("用户名或密码输入错误，密码为8位及以上，用户名不能为空!"));
            err->show();

       }else{
            qDebug("accName: %s,accPw: %s",qPrintable(this->accName), qPrintable(this->accPw)) ;
            //登录
            this->w.show();
            //关闭窗图
            this->close();
        }
}
