#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "database.h"
#include "login.h"
#include<QMessageBox>
#include <QStringList>

namespace Ui {
class MainWindow;
}

/*!
 * \brief The MainWindow class
 *
 * MainWindow Class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow
     *
     * Constructor for mainwindow
     * \param parent
     */
    explicit MainWindow(QWidget *parent = 0); //MA
    ~MainWindow();



private slots:
    void on_comboBox_TeamInfo_currentIndexChanged(int index); //select option in information tab

    void on_loginButton_clicked(); //login button

    void on_AddLV_Button_clicked();

    void on_AdminTeamSouvCombo_currentTextChanged(const QString &arg1);

    void on_NewItemAddButton_clicked();



    void on_AdminDeleteSouv_clicked();

    void on_AdminUpdateSouv_clicked();

    void on_AdminItemCombo_currentTextChanged(const QString &arg1);

private:

    Ui::MainWindow *ui;
    //-----------------------------------------------------------
    /*
     * METHODS
     */

    /*!
     * \brief ClearTable
     *
     * Clears a qTable widget for reuse
     * \param table
     */
    void ClearTable(QTableWidget *table);

    /*!
     * \brief fillAdminSouvenirComboBox
     */
    void fillAdminSouvenirComboBox();

    //-----------------------------------------------------------
    /*
     * INSTANCES(Of other custom objects)
     */
     Login logWindow; //instance of the login window
      Database db;    //instance of the database class

    //-----------------------------------------------------------
    /*
     * VARIABLES
     */
    bool isLoggedIn; //determines whether or not an admin is logged in
    //-----------------------------------------------------------

};

#endif // MAINWINDOW_H
