#ifndef MYCALENDAR_H
#define MYCALENDAR_H

#include <QDialog>

namespace Ui {
class MyCalendar;
}

class MyCalendar : public QDialog
{
    Q_OBJECT

public:
    explicit MyCalendar(QWidget *parent = 0);
    ~MyCalendar();

private:
    Ui::MyCalendar *ui;
};

#endif // MYCALENDAR_H

