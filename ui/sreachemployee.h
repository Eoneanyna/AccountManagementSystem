#ifndef SREACHEMPLOYEE_H
#define SREACHEMPLOYEE_H

#include <QWidget>

namespace Ui {
class SreachEmployee;
}

class SreachEmployee : public QWidget
{
    Q_OBJECT

public:
    explicit SreachEmployee(QWidget *parent = nullptr);
    ~SreachEmployee();

private:
    Ui::SreachEmployee *ui;
};

#endif // SREACHEMPLOYEE_H
