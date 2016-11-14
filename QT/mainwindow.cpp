#include "mainwindow.h"
#include "ui_mainwindow.h"

/*!
   * \file mainwindow.cpp
   * \brief  Header for mainwindow class
   *
   * This file contains all of the definitions of the mainwindow class
   */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->mainTab->removeTab(1); //hide admin tab
    ui->usersTab->setCurrentIndex(0); //set to home page in users tab
    isLoggedIn = false; //set logged in to false
    on_comboBox_TeamInfo_currentIndexChanged(0); //have information filled w/ option 1 on startup


}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::ClearTable
 *
 * Clears a table widget for refreshing
 * @param table
 */
void MainWindow::ClearTable(QTableWidget *table)
{
    int row = table->rowCount();
    int col = table->columnCount();

    ui->Information_Table->horizontalHeader()->setStretchLastSection(false);

    //PROCESSING - removes all rows from table
    for(int i = 0; i < row; i++)
    {
        table->removeRow(0);
    }

    //PROCESSING - removes all columns from table
    for(int i = 0; i < col; i++)
    {
        table->removeColumn(0);
    }
}

/**
 * @brief MainWindow::on_comboBox_TeamInfo_currentIndexChanged
 * @param index
 */
//this method is for the information tab and fills the table based on the option selected in the combo box, stories 1-8
void MainWindow::on_comboBox_TeamInfo_currentIndexChanged(int index)
{
    ClearTable(ui->Information_Table);

    switch(index)
    {
    /* index == 0 -> List of all Teams */
    case 0:
    {
        //insert column
        ui->Information_Table->insertColumn(0);
        ui->Information_Table->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));

        QVector<QString> allTeams;
        allTeams = db.GetAllTeams();

        for(int index = 0; index < allTeams.size(); index++)
        {
            ui->Information_Table->insertRow(index);
            ui->Information_Table->setItem(index, 0, new QTableWidgetItem(allTeams[index]));
        }
        ui->Information_Table->resizeColumnsToContents();
        ui->Information_Table->resizeRowsToContents();
        ui->Information_Table->horizontalHeader()->setStretchLastSection(true);
    }
        break;

        /* index == 1 -> List of all Stadiums */
    case 1:
    {
        ui->Information_Table->insertColumn(0);
        ui->Information_Table->setHorizontalHeaderItem(0, new QTableWidgetItem("Stadium"));
        ui->Information_Table->insertColumn(1);
        ui->Information_Table->setHorizontalHeaderItem(1, new QTableWidgetItem("Team Name"));
        QVector<QString> stadium;
        QVector<QString> name;
        db.GetNFLStadiums(stadium, name);

        for(int index = 0; index < stadium.size(); index++)
        {
            //PROCESSING - inserts a row to the table and sets information in the table
            ui->Information_Table->insertRow(index);
            ui->Information_Table->setItem(index,0,new QTableWidgetItem(stadium[index]));
            ui->Information_Table->setItem(index,1,new QTableWidgetItem(name[index]));
        }
        ui->Information_Table->resizeColumnsToContents();
        ui->Information_Table->resizeRowsToContents();
        ui->Information_Table->horizontalHeader()->setStretchLastSection(true);


    }
        break;
        /* index == 2 -> List of AFC Teams */
    case 2:
    {
        //PROCESSING - inserts column into table
        ui->Information_Table->insertColumn(0);

        //PROCESSING - sets the name of the column header
        ui->Information_Table->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));

        //PROCESSING - Gets all of the national Conference Teams
        QVector<QString> afcTeams = db.GetAFCTeams();

        //PROCESSING - adds a row in table for each team
        for(int index = 0; index < afcTeams.size(); index++)
        {
            //PROCESSING - inserts a row to the table and sets information to the vector of teams
            ui->Information_Table->insertRow(index);
            ui->Information_Table->setItem(index,0,new QTableWidgetItem(afcTeams[index]));
        }
        ui->Information_Table->resizeColumnsToContents();
        ui->Information_Table->resizeRowsToContents();
        ui->Information_Table->horizontalHeader()->setStretchLastSection(true);

    }
        break;
        /* index == 3 -> List of all NFC Teams */
    case 3:
    {
        //PROCESSING - inserts column into table
        ui->Information_Table->insertColumn(0);

        //PROCESSING - sets the name of the column header
        ui->Information_Table->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));

        //PROCESSING - Gets all of the national Conference Teams
        QVector<QString> nfcTeams = db.GetNationalConferenceTeams();

        //PROCESSING - adds a row in table for each team
        for(int index = 0; index < nfcTeams.size(); index++)
        {
            //PROCESSING - inserts a row to the table and sets information to the vector of teams
            ui->Information_Table->insertRow(index);
            ui->Information_Table->setItem(index,0,new QTableWidgetItem(nfcTeams[index]));
        }
        ui->Information_Table->resizeColumnsToContents();
        ui->Information_Table->resizeRowsToContents();
        ui->Information_Table->horizontalHeader()->setStretchLastSection(true);
    }
        break;
        /* index == 4 -> List of all Open Roof Stadiums */
    case 4:
    {
        ui->Information_Table->insertColumn(0);
        ui->Information_Table->setHorizontalHeaderItem(0, new QTableWidgetItem("Stadium"));
        ui->Information_Table->insertColumn(1);
        ui->Information_Table->setHorizontalHeaderItem(1, new QTableWidgetItem("Team Name"));
        QVector<QString> stadium;
        QVector<QString> name;
        db.GetOpenStadiums(stadium, name);

        for(int index = 0; index < stadium.size(); index++)
        {
            //PROCESSING - inserts a row to the table and sets information in the table
            ui->Information_Table->insertRow(index);
            ui->Information_Table->setItem(index,0,new QTableWidgetItem(stadium[index]));
            ui->Information_Table->setItem(index,1,new QTableWidgetItem(name[index]));
        }
        ui->Information_Table->resizeColumnsToContents();
        ui->Information_Table->resizeRowsToContents();
        ui->Information_Table->horizontalHeader()->setStretchLastSection(true);



    }
        break;
        /* index == 5 -> List of all Star Players */
    case 5:
    {


        ui->Information_Table->insertColumn(0);
        ui->Information_Table->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));
        ui->Information_Table->insertColumn(1);
        ui->Information_Table->setHorizontalHeaderItem(1, new QTableWidgetItem("Star Player"));

        QVector<QString> names;     //CALC - names of teams
        QVector<QString> players;  //CALC - stadium names

        db.GetPlayersByTeamname(names, players);
        for(int index = 0; index < names.size(); index++)
        {
            //PROCESSING - inserts a row to the table and sets information in the table
            ui->Information_Table->insertRow(index);
            ui->Information_Table->setItem(index,0,new QTableWidgetItem(names[index]));
            ui->Information_Table->setItem(index,1,new QTableWidgetItem(players[index]));

        }
        ui->Information_Table->resizeColumnsToContents();
        ui->Information_Table->resizeRowsToContents();
        ui->Information_Table->horizontalHeader()->setStretchLastSection(true);


    }
        break;
        /* index == 6 -> List of Teams by Seating Capacity */
    case 6:
    {
        //PROCESSING - inserts column into table
        ui->Information_Table->insertColumn(0);
        ui->Information_Table->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));
        ui->Information_Table->insertColumn(1);
        ui->Information_Table->setHorizontalHeaderItem(1, new QTableWidgetItem("Stadium Name"));
        ui->Information_Table->insertColumn(2);
        ui->Information_Table->setHorizontalHeaderItem(2, new QTableWidgetItem("Seating Capacity"));
        ui->Information_Table->insertColumn(3);
        ui->Information_Table->setHorizontalHeaderItem(3, new QTableWidgetItem("Location"));

        QVector<QString> names;     //CALC - names of teams
        QVector<QString> stadiums;  //CALC - stadium names
        QVector<float>   capacitys; //CALC - stadium capacitys
        QVector<QString> locations; //CALC - stadium locations

        //PROCESSING - gets information from database
        db.GetTeamBySeatingCapacity(names, stadiums, capacitys, locations);

        //PROCESSING - adds a row in table for each team
        for(int index = 0; index < names.size(); index++)
        {
            //PROCESSING - inserts a row to the table and sets information in the table
            ui->Information_Table->insertRow(index);
            ui->Information_Table->setItem(index,0,new QTableWidgetItem(names[index]));
            ui->Information_Table->setItem(index,1,new QTableWidgetItem(stadiums[index]));
            ui->Information_Table->setItem(index,2,new QTableWidgetItem(QString::number(capacitys[index])));
            ui->Information_Table->setItem(index,3,new QTableWidgetItem(locations[index]));
        }
        ui->Information_Table->resizeColumnsToContents();
        ui->Information_Table->resizeRowsToContents();
        ui->Information_Table->horizontalHeader()->setStretchLastSection(true);
    }
        break;
        /* index == 7 -> List of Teams by Surface Type */
    case 7:
    {

        //PROCESSING - inserts column into table
        ui->Information_Table->insertColumn(0);
        ui->Information_Table->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));
        ui->Information_Table->insertColumn(1);
        ui->Information_Table->setHorizontalHeaderItem(1, new QTableWidgetItem("Stadium Name"));
        ui->Information_Table->insertColumn(2);
        ui->Information_Table->setHorizontalHeaderItem(2, new QTableWidgetItem("Surface Type"));
        ui->Information_Table->insertColumn(3);
        ui->Information_Table->setHorizontalHeaderItem(3, new QTableWidgetItem("Location"));

        QVector<QString> names;     //CALC - names of teams
        QVector<QString> stadiums;  //CALC - stadium names
        QVector<QString>   surface; //CALC - stadium capacitys
        QVector<QString> locations; //CALC - stadium locations
        db.GetTeamsSurfaceBySeating(names, stadiums, surface, locations);


        for(int index = 0; index < names.size(); index++)
        {
            //PROCESSING - inserts a row to the table and sets information in the table
            ui->Information_Table->insertRow(index);
            ui->Information_Table->setItem(index,0,new QTableWidgetItem(names[index]));
            ui->Information_Table->setItem(index,1,new QTableWidgetItem(stadiums[index]));
            ui->Information_Table->setItem(index,2,new QTableWidgetItem(surface[index]));
            ui->Information_Table->setItem(index,3,new QTableWidgetItem(locations[index]));
        }
        ui->Information_Table->resizeColumnsToContents();
        ui->Information_Table->resizeRowsToContents();
        //ui->Information_Table->horizontalHeader()->setStretchLastSection(true);
    }
        break;
    }
}
//perform admin login or logout
void MainWindow::on_loginButton_clicked()
{

    if(!isLoggedIn)
    {
        //user not logged in

        logWindow.exec();

        if(logWindow.getValid())
        {
            ui->mainTab->addTab(ui->admin, "Admin");
            ui->mainTab->setCurrentIndex(1);
            ui->loginButton->setText("Logout");
            isLoggedIn = true;
            QMessageBox::information(this, tr("Success"),
                                     "You are now logged in as: Admin, welcome.");
        }
        else
        {
            QMessageBox::information(this, tr("Aborted"),
                                     "Login failed/aborted.");
        }
    }
    else
    {
        //user logged in
        ui->mainTab->removeTab(1);
        isLoggedIn = false;
        QMessageBox::information(this, tr("Logged out"),
                                 "You have successfully logged out.");
    }


}
