#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"sreachemployee.h"
#include"config/config.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //功能
    connect(ui->employee_search,SIGNAL(clicked(bool)),SLOT(click_Employee_Search()));
    this->show();
    this->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetUser(){
    ui->user_msg->setText(QString("用户%1").arg(conf.user.UserName));
}

 void MainWindow::click_LoginAcc_Edit(){

 }

 void MainWindow::click_Employee_Edit(){

 }

 void MainWindow::click_Employee_Search(){
             SreachEmployee *eSF = new SreachEmployee;
             eSF->show();
 }
