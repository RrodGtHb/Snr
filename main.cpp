#include "welcomescreen.h"
//#include "shoppinglist.h"

#include <QApplication>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //to add more functionality to the app is necessary to work with pointers
    /*this is why this code was changed from
     * WelcomeScreen w;
     * w.show();
     *
     * to:
     * WelcomeScreen *w = new WelcomeScreen;
     * w->show();
     *
     * the *w makes it a pointer.
     * Now we have ways to set background color and other functionality we did not have.
     */

    WelcomeScreen *w = new WelcomeScreen;
    w->setStyleSheet("background-color:orange;");
    w->show();




    return a.exec();
}
