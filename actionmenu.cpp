#include "actionmenu.h"
#include "ui_actionmenu.h"
#include "custominput.h"
#include "userlist.h"
ActionMenu::ActionMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActionMenu)
{
    ui->setupUi(this);
}

ActionMenu::~ActionMenu()
{
    delete ui;
}

void ActionMenu::on_pushButton_ChangeInventory_clicked()
{
    //Change entry button from Action Menu which takes to Change Entry window
    InventoryChange changeInventoryVar; //this is the reference variable
    if(!connOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }
    connOpen();
    connClose();
    changeInventoryVar.setModal(true);
    changeInventoryVar.exec();
}

void ActionMenu::on_pushButton_CustomInput_clicked()
{
    //Custom input button from Action Menu which takes to Change input window
    CustomInput customInputVar;    //this is the reference variable
    customInputVar.setModal(true);
    customInputVar.exec();
}

void ActionMenu::on_pushButton_ShoppingList_clicked()
{
    //make it go to userlist
    UserList *u = new UserList;
    u->setModal(true);
    u->setStyleSheet("Background-color:orange");
    u->show();

}
