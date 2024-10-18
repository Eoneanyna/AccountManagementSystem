#include "sreachemployee.h"
#include "ui_sreachemployee.h"

SreachEmployee::SreachEmployee(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SreachEmployee)
{
    ui->setupUi(this);
}

SreachEmployee::~SreachEmployee()
{
    delete ui;
    delete eInfos;
}
