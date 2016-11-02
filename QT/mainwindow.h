#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void ClearTable(QTableWidget *table);

private slots:
    void on_comboBox_TeamInfo_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    Database       db;
};

#endif // MAINWINDOW_H
