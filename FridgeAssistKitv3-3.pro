#-------------------------------------------------
#
# Project created by QtCreator 2016-09-02T12:10:12
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FridgeAssistKitv3-3
TEMPLATE = app


SOURCES += main.cpp\
        welcomescreen.cpp \
    actionmenu.cpp \
    inventorychange.cpp \
    custominput.cpp \
    mycalendar.cpp \
    userlist.cpp

HEADERS  += welcomescreen.h \
    actionmenu.h \
    inventorychange.h \
    custominput.h \
    mycalendar.h \
    userlist.h

FORMS    += welcomescreen.ui \
    actionmenu.ui \
    inventorychange.ui \
    custominput.ui \
    mycalendar.ui \
    userlist.ui
