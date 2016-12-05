#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "database.h"
#include "login.h"
#include<QMessageBox>
#include <QStringList>
#include <QLocale>
#include <QMap>
#include <QList>
#include <QCheckBox>
#include <QRadioButton>
#include <QGridLayout>
#include "Graph.h"


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

signals:
    /*!
     * \brief CustomTrip
     */
    void CustomTrip(QVector<int>, int);


private slots:
    void on_comboBox_TeamInfo_currentIndexChanged(int index); //select option in information tab

    void on_loginButton_clicked(); //login button

    void on_AddLV_Button_clicked();

    void on_AdminTeamSouvCombo_currentTextChanged(const QString &arg1);

    void on_NewItemAddButton_clicked();



    void on_AdminDeleteSouv_clicked();

    void on_AdminUpdateSouv_clicked();

    void on_AdminItemCombo_currentTextChanged(const QString &arg1);

    void on_updateStadNutton_clicked();

    void on_InfoTeamCombobox_currentIndexChanged(const QString &arg1);

    void on_ChangeTeamInfo_Button_clicked();


    void on_NextStadium_Button_clicked();

    void on_VisitAll_Button_clicked();

    void on_TestButton_clicked();

    void on_VisitSelected_Button_clicked();

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    void on_BackButton_clicked();

private:

    Ui::MainWindow *ui; //mainwindow
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
    void fillTeamComboBoxs(); //fill all team combo boxes up

    /*!
     * \brief fillAdminTeamTable
     */
    void fillAdminTeamTable();//fill team table in admin tab


    /*!
     * \brief fillGraph
     * Fills the graph object up
     */
    void fillGraph();

    void FillTripLabels(QString name);


    void refreshMST();

    //add method to fill MST GUI once it is implemented


    //-----------------------------------------------------------
    /*
     * INSTANCES(Of other custom objects)
     */
     Login logWindow; //instance of the login window
      Database db;    //instance of the database class
      Graph graph;    //the adjacency matrix graph

    //-----------------------------------------------------------
    /*
     * VARIABLES
     */
    bool isLoggedIn; //determines whether or not an admin is logged in
    int nextStadiumClicked;
    QMap <QString, QMap<QString, int > > souvenirs;


    QVector<QString>masterTeamNameList; //list of teams in default db order
    QVector<QString>masterStadiumList; //list of all stadiums
    QVector<QRadioButton*> radioList;
    QList<QCheckBox*> checkboxList;
       QVector<int> dijkstraList;
       QVector<int> dist;
        QVector<int> customList;
        QVector<int> customDist;


    //-----------------------------------------------------------

};

#endif // MAINWINDOW_H
