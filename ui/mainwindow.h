#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
 void click_LoginAcc_Edit();
 void click_Employee_Edit();
 void click_Employee_Search();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
