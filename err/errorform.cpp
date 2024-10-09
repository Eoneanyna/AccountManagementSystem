#include "err/errorform.h"
#include "ui_errorform.h"
#include<QString>

errorForm::errorForm(QWidget *parent):
    QWidget(parent),
    ui(new Ui::errorForm)
{
    ui->setupUi(this);
    ui->err_detail->setWordWrap(true);

    connect(ui->OK,SIGNAL(clicked(bool)),SLOT(click_OK()));
}

errorForm::~errorForm()
{
    delete ui;
}

void errorForm::SetErrDetail(QString msg){
    this->error_detail = msg;
    ui->err_detail->setText(this->error_detail);
}

void errorForm::click_OK(){
    this->close();
}
