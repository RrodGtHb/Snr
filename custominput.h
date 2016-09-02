#ifndef CUSTOMINPUT_H
#define CUSTOMINPUT_H

#include <QDialog>

namespace Ui {
class CustomInput;
}

class CustomInput : public QDialog
{
    Q_OBJECT

public:
    explicit CustomInput(QWidget *parent = 0);
    ~CustomInput();

private slots:
    void on_btn_vegetables_input_clicked();

    void on_btn_fruits_input_clicked();

private:
    Ui::CustomInput *ui;
};

#endif // CUSTOMINPUT_H

