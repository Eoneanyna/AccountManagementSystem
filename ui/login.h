#ifndef LOGIN_H
#define LOGIN_H
#define HEADIMAGEPATH ":/developer/resource/headiImage.jpg"

#include <QDialog>
#include <iostream>

#include<database/account.h>
using namespace std;

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

public slots:
 void click_Login();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
