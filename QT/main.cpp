#include "mainwindow.h"
#include <QApplication>

/*!
   * \file main.cpp
   * \brief  main
   *
   * This file contains the mainwindow instance
   */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setFixedSize(w.size()); //prevent resizing, only took 3 projects to figure this out

    return a.exec();
}
/**
\mainpage Git Good - Football Trip Planner


Project 2 for CS1D Fall 2016 at Saddleback College

Tools and languages used:
- Qt creator: C++ implementation, ui design, database interfacing
- SqliteStudio: Sql database creation and management
- Doxygen - HTML Documentation(What you see now)
- Excel - UML Diagram
- Waffle IO - Agile Management
- Github - Code storage and version control



© 2016 Git Good. All Rights Reserved.
*/
