#-------------------------------------------------
#
# Project created by QtCreator 2016-11-01T16:49:10
#
#-------------------------------------------------

QT       += core gui sql
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GitGood
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    login.cpp \
    Graph.cpp \

HEADERS  += mainwindow.h \
    database.h \
    login.h \
    Graph.h \

FORMS    += mainwindow.ui \
    login.ui

RESOURCES += \
    resource.qrc

DISTFILES += \
    Teams/Minnesota Vikings.jpg

