#include "userlist.h"
#include "ui_userlist.h"
#include "actionmenu.h"
#include <QMessageBox>

UserList::UserList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserList)
{
    ui->setupUi(this);

    ActionMenu conn;

    if(!conn.connOpen())
    {
        ui->label_Connection3->setText("Failed to open.");
    }
    else
    {
        ui->label_Connection3->setText("Connected...");
    }
}

UserList::~UserList()
{
    delete ui;
}
void UserList::on_pushButtonLoadList_clicked()
{



    //List view code here
    ActionMenu conn;
    QSqlQueryModel *modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);

    //Change this code here to get the values necessary
    qry->prepare("select ProductName from supplies6"); //eid or surname will work to load other columns
    qry->exec();
    modal->setQuery(*qry);
    ui->listView->setModel(modal);
    //ui->comboBox->setModel(modal);

    conn.connClose();
    qDebug() << (modal->rowCount());
}
void UserList::on_listView_activated(const QModelIndex &index)
{
    //takes index selected from table view and converts it to a string stored in variable val
    QString val = ui->listView->model()->data(index).toString();



    //conn is the loging object to open and close the conection to the database
    ActionMenu conn;


    if(!conn.connOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }

    //The connOpen() method (or function) is used to open a connection to the SQLite database
    conn.connOpen();
    QSqlQuery qry;

    //listView can only show 1 item. This is why we can only use a value here. This can be changed as necessary.
    qry.prepare("select * from supplies6 where productName='"+val+"'");

    if(qry.exec())
    {
       while(qry.next())
       {
         //From the database each colunm has an index. The index starts at 0. To specify eid we need colunm 0.
         //To specify name then the value is 1, surname would have value 2, and so on... going from left to right.

           ui->line_ProductID->setText(qry.value(0).toString());
           ui->lineEdit_Name->setText(qry.value(1).toString());
           ui->lineEdit_Price->setText(qry.value(2).toString());
           ui->lineEdit_Weight->setText(qry.value(3).toString());
       }
        //This is closing the connection to the database when the function to write into it was sucessfully executed
        conn.connClose();
    }
    else
    {
        //This message will show that there was an error during execution
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }


}
