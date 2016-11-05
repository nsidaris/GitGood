/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Welcome_tab;
    QLabel *label;
    QWidget *Info_Tab;
    QTableView *Information_Table;
    QComboBox *comboBox_TeamInfo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1034, 632);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 1011, 551));
        tabWidget->setTabPosition(QTabWidget::North);
        Welcome_tab = new QWidget();
        Welcome_tab->setObjectName(QStringLiteral("Welcome_tab"));
        label = new QLabel(Welcome_tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 20, 541, 371));
        label->setPixmap(QPixmap(QString::fromUtf8("NFL-Shield.jpg")));
        label->setScaledContents(true);
        tabWidget->addTab(Welcome_tab, QString());
        Info_Tab = new QWidget();
        Info_Tab->setObjectName(QStringLiteral("Info_Tab"));
        Information_Table = new QTableView(Info_Tab);
        Information_Table->setObjectName(QStringLiteral("Information_Table"));
        Information_Table->setGeometry(QRect(240, 10, 741, 501));
        Information_Table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        comboBox_TeamInfo = new QComboBox(Info_Tab);
        comboBox_TeamInfo->setObjectName(QStringLiteral("comboBox_TeamInfo"));
        comboBox_TeamInfo->setGeometry(QRect(10, 200, 221, 41));
        tabWidget->addTab(Info_Tab, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1034, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Welcome_tab), QApplication::translate("MainWindow", "Welcome", 0));
        comboBox_TeamInfo->clear();
        comboBox_TeamInfo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Teams", 0)
         << QApplication::translate("MainWindow", "Stadiums", 0)
         << QApplication::translate("MainWindow", "American Footbal Conference Teams", 0)
         << QApplication::translate("MainWindow", "National Footbal Conference Teams", 0)
         << QApplication::translate("MainWindow", "Open Roof Stadiums", 0)
         << QApplication::translate("MainWindow", "Star Players", 0)
         << QApplication::translate("MainWindow", "Teams by Seating Capacity", 0)
         << QApplication::translate("MainWindow", "Teams By Surface Type", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(Info_Tab), QApplication::translate("MainWindow", "Information", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
