#ifndef USERLIST_H
#define USERLIST_H

#include <QDialog>

namespace Ui {
class UserList;
}

class UserList : public QDialog
{
    Q_OBJECT

public:
    explicit UserList(QWidget *parent = 0);
    ~UserList();
private slots:
   // void on_tableView_activated(const QModelIndex &index); FOR LISTVIEW
    //void on_pushButtonDatabase_clicked(); LOOK FOR LOAD LISTVIEW
    void on_pushButtonLoadList_clicked();
    void on_listView_activated(const QModelIndex &index);



private:
    Ui::UserList *ui;
};

#endif // USERLIST_H
