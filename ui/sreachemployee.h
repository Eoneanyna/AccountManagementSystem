#ifndef SREACHEMPLOYEE_H
#define SREACHEMPLOYEE_H

#include <QWidget>
#include<database/employee.h>

namespace Ui {
class SreachEmployee;
}

class SreachEmployee : public QWidget
{
    Q_OBJECT

public:
    explicit SreachEmployee(QWidget *parent = nullptr);
    ~SreachEmployee();
    employee *eInfos;

private:
    Ui::SreachEmployee *ui;
};

#endif // SREACHEMPLOYEE_H
