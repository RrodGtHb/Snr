#ifndef INVENTORYCHANGE_H
#define INVENTORYCHANGE_H

#include <QDialog>
#include "actionmenu.h"

namespace Ui {
class InventoryChange;
}

class InventoryChange : public QDialog
{
    Q_OBJECT

public:

    explicit InventoryChange(QWidget *parent = 0);
    ~InventoryChange();

private slots:
    void on_pushButton_3_clicked(); //ADD or SAVE

    void on_pushButton_Update_clicked();

    void on_pushDelete_clicked();

    void on_pushButtonDatabase_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::InventoryChange *ui;

};

#endif // INVENTORYCHANGE_H
