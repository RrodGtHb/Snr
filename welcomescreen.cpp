#include "welcomescreen.h"
#include "ui_welcomescreen.h"
#include "actionmenu.h"
#include "mycalendar.h"
#include <QStyle>


WelcomeScreen::WelcomeScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomeScreen)
{
    ui->setupUi(this);
    //This is an example of how to set a tool tip. Whenever the user hovers over this button it will say "Go to Action Menu"
    //Using tooltips is also possible to add icons, pictures and html formatting.
    ui->WelcomeScreenStartButton_2->setToolTip("Go to Action Menu.");
    //This is an example of how to add an icon to a button. In general icon extension should be .ico but png works.
    //It is recomended to use .ico because if the window is resized the icon will look good, whereas the picture can look blurry.
    QIcon icon (":/ImagesAndIcons/Home.png");
    ui->WelcomeScreenStartButton_2->setIcon(icon);
    //This is an example of how to change the font. It can work on buttons and labels, and other widgets.
    QFont font ("Courier");
    ui->WelcomeScreenStartButton_2->setFont(font);
    //This is an example of how to add a picture to a label
    QPixmap pix (":/ImagesAndIcons/groceriespngresized.png");
    ui->WelcomeScreenPicture1_2->setPixmap(pix);
    ui->WelcomeScreenPicture1_2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);


    //this is an example of simple customization of a button using StyleSheets
    ui->WelcomeScreenButonCalendar_2->setStyleSheet("background:red");







}

WelcomeScreen::~WelcomeScreen()
{
    delete ui;

}

void WelcomeScreen::on_WelcomeScreenStartButton_2_clicked()
{
    /*On top is the method that gives functionality to the start button in the first window,
     * upon clicking it an instance of the second window is created. Setting Modal to true means
     * the user can only interact with that window when they click the button. */
    /*This code was refactored to use pointers as explained in main.cpp (look there). With pointers we
     * can use stylesheets and many other functionality*/

    ActionMenu *myActionMenu = new ActionMenu;
    myActionMenu->setModal(true);
    myActionMenu->setStyleSheet("background-color:orange");
    myActionMenu->exec();

}

void WelcomeScreen::on_WelcomeScreenButonCalendar_2_clicked()
{
    //Calendar goes here
    MyCalendar *myCalendar = new MyCalendar;
    myCalendar->setModal(true);
    myCalendar->exec();
}
