#include "login.h"
#include "ui_login.h"
#include<QLabel>
#include<QDebug>
#include<qstring.h>
#include<err/errorform.h>
#include<config/config.h>

#include <iostream>
using namespace std;

QString superUserName = "root";
QString superUserPW = "Dcnfs";


Login::Login(QWidget *parent) :
    QDialog(parent),
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
       QString accName = ui->accountName->text();
       QString accPw = ui->accountPw->text();

       //错误提示框图
       errorForm *err = new errorForm;
       if(accName == superUserName && accPw == superUserPW){
          conf.user.UserName = superUserName;
          conf.user.Role = Super;
          //关闭窗图
          this->close();
          //开启主窗图
          accept();
       }else{
           if(accPw.size()<8||accName.size()<1){
                err->SetErrDetail(QString("用户名或密码输入错误，密码为8位及以上，用户名不能为空!"));
                err->show();
           }else{
                qDebug("accName: %s,accPw: %s",qPrintable(accName), qPrintable(accPw)) ;

              //搜索账号
              Account acc;
              qx_query query;
              query.where("uName").isEqualTo(accName);
              QSqlError daoError =  qx::dao::fetch_by_query(query, acc, &conf.orm_db);
              if (daoError.type() != QSqlError::NoError)
              {
                err->SetErrDetail(daoError.text());
                err->show();
                return;
               }

              if(acc.uName != accName || acc.uPassword != accPw){
                err->SetErrDetail("用户名或密码错误,请重新输入！");
                err->show();
                return;
              }

              conf.user.UserName = accName;
              conf.user.Role = acc.Role;
              //关闭窗图
              this->close();
              //开启主窗图
              accept();
            }
        }
}
