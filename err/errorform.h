#ifndef ERRORFORM_H
#define ERRORFORM_H

#include <QWidget>
#include<string>
using namespace std;

namespace Ui {
class errorForm;
}

template<class T>
struct ReMsg{
    QString err = nullptr;
    vector<T> value;
};

class errorForm : public QWidget
{
    Q_OBJECT

public:
    explicit errorForm(QWidget *parent = nullptr);
    ~errorForm();
    void SetErrDetail(QString msg);

public slots:
   void click_OK();

private:
    Ui::errorForm *ui;

    QString error_detail;
};



#endif // ERRORFORM_H
