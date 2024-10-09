#ifndef LOGIN_H
#define LOGIN_H
#define HEADIMAGEPATH ":/developer/resource/headiImage.jpg"

#include <QWidget>
#include <iostream>
using namespace std;

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

public slots:
 void click_Login();

private:
    Ui::Login *ui;

    QString accName;
    QString accPw;
};

#endif // LOGIN_H