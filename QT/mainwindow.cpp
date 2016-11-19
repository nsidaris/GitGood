#include "mainwindow.h"
#include "ui_mainwindow.h"

/*!
   * \file mainwindow.cpp
   * \brief  Header for mainwindow class
   *
   * This file contains all of the definitions of the mainwindow class
   */
//Constructor and destructor
//------------------------------------------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->mainTab->removeTab(1); //hide admin tab
    ui->usersTab->setCurrentIndex(0); //set to home page in users tab
    isLoggedIn = false; //set logged in to false
    on_comboBox_TeamInfo_currentIndexChanged(0); //have information filled w/ option 1 on startup
    fillAdminSouvenirComboBox(); //fill the team combo box in the souvenir tab in the admin area


}

MainWindow::~MainWindow()
{
    delete ui;
}
//private mainwindow methods
//-------------------------------------------------------------------------------------------------------------------
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

   // ui->Information_Table->horizontalHeader()->setStretchLastSection(false);

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
//fills up the combo in the souvenirs tab of admin area
void::MainWindow::fillAdminSouvenirComboBox()
{
    ui->AdminTeamSouvCombo->clear(); //clear it out, this way Las Vegas will be in the correct spot alphabetically
    QVector<QString> teams = db.GetAllTeams();
    for(int i = 0; i < teams.size(); i++)
    {
        ui->AdminTeamSouvCombo->addItem(teams[i]);
    }

}



//Private Slots:
//-------------------------------------------------------------------------------------------------------------------

/**
 * @brief MainWindow::on_comboBox_TeamInfo_currentIndexChanged
 * @param index
 */
//this method is for the information tab and fills the table based on the option selected in the combo box, stories 1-8
void MainWindow::on_comboBox_TeamInfo_currentIndexChanged(int index)
{
    ClearTable(ui->Information_Table);
    ui->Information_Table->horizontalHeader()->setStretchLastSection(false);

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

/**
 * @brief MainWindow::on_AddLV_Button_clicked
 */
void MainWindow::on_AddLV_Button_clicked()
{
    QVector<QString> allTeams = db.GetAllTeams();   //CALC - vector of all teams
    int              A;                             //CALC - number of Las Vegas
    QVector<int>     B;                             //CALC - numbers of connected vertices
    QVector<float>   distance;                      //CALC - distances between vertices
    QVector<QString> items;                         //CALC - vector of souvenir names
    QVector<float> prices;                        //CALC - vector of souvenir prices
    bool valid;

    /**************************************************
     * PROCESSING - Sets the Las Vegas number to A
     *            - Pushes back connected vertices to B
     *            - pushes back corresponding distances
     *            - pushes back souvenirs to vector
     *            - pushes back prices to vector
    ****************************************************/
    A = 33;
    B.push_back(25);
    B.push_back(16);
    B.push_back(32);
    distance.push_back(350);
    distance.push_back(250);
    distance.push_back(300);
    items.push_back("Signed Helmet");
    items.push_back("Autographed Football");
    items.push_back("Team Pennat");
    items.push_back("Team Picture");
    items.push_back("Team Jersey");
    prices.push_back(72.99);
    prices.push_back(49.39);
    prices.push_back(17.99);
    prices.push_back(19.99);
    prices.push_back(185.99);

    //PROCESSING - Adds las vegas to the database if there are only 32 teams added
    if(allTeams.size() == 32)
    {
        //PROCESSING - adds las vegas to the database and shows message box saying it was added
        //              successfuly
        if(db.AddLasVegas("Las Vegas Gamblers", "Las Vegas Stadium", 66416, "Las Vegas, Nevada",
                          "NFC", "Kentucky Bluegrass", "O", "Kenny Rogers", A, B, distance))
        {
            for(int i = 0; i < items.size(); i++)
            {
                valid = db.AddSouvenir("Las Vegas Gamblers", items[i], prices[i]);
            }

            if(valid)
            {
                fillAdminSouvenirComboBox(); //refill the admin souvenir combobox so lv's items can be modifield
                on_comboBox_TeamInfo_currentIndexChanged(ui->comboBox_TeamInfo->currentIndex()); //update the information tab on the fly, refresh no longer needed
                QMessageBox::information(this, tr("Added"),
                                         "Las Vegas has been added");
            }
        }
    }
    //PROCESSING - shows message box saying Las vegas is already added
    else
    {
        QMessageBox::information(this, tr("Already Added!"),
                                 "Las Vegas is already in the system");
    }

}
//souvenir tab team selector, allows admin to pick which team's items to modify
void MainWindow::on_AdminTeamSouvCombo_currentTextChanged(const QString &arg1)
{

    ClearTable(ui->AdminSouvTable);
    //qDebug() << arg1;
    QString team =  arg1; //ui->AdminTeamSouvCombo->currentText();

    QVector<QString> names;
    QVector<double> prices;
    db.GetSouvenirs(names, prices, team);
    //qDebug() << names.size();


    //fill up the table
    ui->AdminSouvTable->insertColumn(0);
    ui->AdminSouvTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Item"));
    ui->AdminSouvTable->insertColumn(1);
    ui->AdminSouvTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Price"));


    for(int i = 0; i < names.size(); i++)
    {
       ui->AdminSouvTable->insertRow(i);
       ui->AdminSouvTable->setItem(i,0,new QTableWidgetItem(names[i]));
       ui->AdminSouvTable->setItem(i,1,new QTableWidgetItem(QString::number(prices[i], 'f', 2)));
    }
   ui->AdminSouvTable->resizeColumnsToContents();
   ui->AdminSouvTable->resizeRowsToContents();
    ui->AdminSouvTable->horizontalHeader()->setStretchLastSection(true);

}
