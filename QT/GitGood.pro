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
    database.cpp

HEADERS  += mainwindow.h \
    database.h

FORMS    += mainwindow.ui

RESOURCES += \

DISTFILES += \
    football.db

