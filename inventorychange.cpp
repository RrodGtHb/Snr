#include "inventorychange.h"
#include "ui_inventorychange.h"
#include "actionmenu.h"
#include <QMessageBox>


InventoryChange::InventoryChange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InventoryChange)
{
    ui->setupUi(this);

    ActionMenu conn;

    if(!conn.connOpen())
    {
        ui->labelConnectionStatus->setText("Failed to open.");
    }
    else
    {
        ui->labelConnectionStatus->setText("Connected...");
    }
}

InventoryChange::~InventoryChange()
{
    delete ui;
}

void InventoryChange::on_pushButton_3_clicked() //Add which is the same as Save
{
    ActionMenu conn;
    QString productID,productName, productPrice, productWeight;
    productID = ui->line_ProductID->text();
    productName = ui->lineEdit_Name->text();
    productPrice = ui->lineEdit_Price->text();
    productWeight = ui->lineEdit_Weight->text();

    if(!conn.connOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }


    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into supplies6 (productID,productName,productPrice,productWeight) values ('"+productID+"','"+productName+"','"+productPrice+"','"+productWeight+"')");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Add"),tr("Entry Added"));
        conn.connClose(); //conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error"), qry.lastError().text());
    }
}

void InventoryChange::on_pushButton_Update_clicked()
{
    ActionMenu conn;
    QString productID,productName, productPrice, productWeight;
    productID = ui->line_ProductID->text();
    productName = ui->lineEdit_Name->text();
    productPrice = ui->lineEdit_Price->text();
    productWeight = ui->lineEdit_Weight->text();

    if(!conn.connOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update supplies6 set productID='"+productID+"',productName='"+productName+"',productPrice='"+productPrice+"',productWeight='"+productWeight+"' where productID='"+productID+"'");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Edit"),tr("Updated"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error"), qry.lastError().text());
    }
}

void InventoryChange::on_pushDelete_clicked()
{
    ActionMenu conn;
    QString productID,productName,productPrice,productWeight;
    productID = ui->line_ProductID->text();
    productName = ui->lineEdit_Name->text();
    productPrice = ui->lineEdit_Price->text();
    productWeight = ui->lineEdit_Weight->text();

    if(!conn.connOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }

    //The connOpen() method (or function) is used to open a connection to the SQLite database
    conn.connOpen();
    QSqlQuery qry;

    //This is an example of how to delete from the database by using the employee ID as reference
    qry.prepare("delete from supplies6 where productID='"+productID+"'");

    if(qry.exec())
    {
       //Use a QmessageBox to alert the user they are about to delete the entry

        //This message box will inform the user that the data was succesfully written and saved to the database
        QMessageBox::information(this,tr("Delete"),tr("Deleted"));
        //This is closing the connection to the database when the function to write into it was sucessfully executed
        conn.connClose();
    }
    else
    {
        //This message will show that there was an error during execution
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}

void InventoryChange::on_pushButtonDatabase_clicked()
{
    //table view code here
    ActionMenu conn;
    QSqlQueryModel *modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);

    //Change this code here to get the values necessary
    qry->prepare("select * from supplies6");
    qry->exec();
    modal->setQuery(*qry);
    //ui->listView->setModel(modal);
    ui->tableView->setModel(modal);


    conn.connClose();
    qDebug() << (modal->rowCount());
}
void InventoryChange::on_tableView_activated(const QModelIndex &index)
{

    //takes index selected from table view and converts it to a string stored in variable val
    QString val = ui->tableView->model()->data(index).toString();



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
    qry.prepare("select * from supplies6 where productID='"+val+"' or productName='"+val+"' or productPrice='"+val+"' or productWeight='"+val+"'");

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
