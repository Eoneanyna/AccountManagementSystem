#ifndef ERRORFORM_H
#define ERRORFORM_H

#include <QWidget>

namespace Ui {
class errorForm;
}

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
