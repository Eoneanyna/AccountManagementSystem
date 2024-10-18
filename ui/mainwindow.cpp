#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"sreachemployee.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //功能
    connect(ui->employee_search,SIGNAL(clicked(bool)),SLOT(click_Employee_Search()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

 void MainWindow::click_LoginAcc_Edit(){

 }

 void MainWindow::click_Employee_Edit(){

 }

 void MainWindow::click_Employee_Search(){
             SreachEmployee *eSF = new SreachEmployee;
             eSF->show();
 }
