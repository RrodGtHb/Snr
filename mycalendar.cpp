#include "mycalendar.h"
#include "ui_mycalendar.h"

MyCalendar::MyCalendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyCalendar)
{
    ui->setupUi(this);

}

MyCalendar::~MyCalendar()
{
    delete ui;
}
