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
   fillTeamComboBoxs(); //fill the team combo box in the souvenir tab in the admin area

    fillAdminTeamTable(); //fill up the admin team table


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


//fills up the combo box of TEAMS in the souvenirs AND TEAMS AREA FOR UPDATE tab of admin area
/**
 * @brief ::MainWindow::fillTeamComboBoxs
 */
void::MainWindow::fillTeamComboBoxs()
{
    ui->InfoTeamCombobox->clear();
    ui->AdminTeamSouvCombo->clear(); //clear it out, this way Las Vegas will be in the correct spot alphabetically
     ui->AdminTeamSouvCombo_2->clear();
    QVector<QString> teams = db.GetAllTeams();
    for(int i = 0; i < teams.size(); i++)
    {
        ui->AdminTeamSouvCombo->addItem(teams[i]);
        ui->AdminTeamSouvCombo_2->addItem(teams[i]);
        ui->InfoTeamCombobox->addItem(teams[i]);

    }
    //PROCESSING - used for formating total seating capacity
    QLocale l = QLocale::system();
    ui->SeatingCapDispLabel->setText("Total Seating Capacity: " + l.toString(db.seatingSum()));

}

/**
 * @brief MainWindow::fillAdminTeamTable
 */
void MainWindow::fillAdminTeamTable()
{
    ClearTable(ui->TeamsAdminTable);
    QVector<QString> names;     //CALC - names of teams
    QVector<QString> stadiums;  //CALC - stadium names
    QVector<float>   capacitys; //CALC - stadium capacitys
    QVector<QString> locations; //CALC - stadium locations
    ui->TeamsAdminTable->insertColumn(0);
    ui->TeamsAdminTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));
    ui->TeamsAdminTable->insertColumn(1);
    ui->TeamsAdminTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Stadium Name"));
    ui->TeamsAdminTable->insertColumn(2);
    ui->TeamsAdminTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Seating Capacity"));
    ui->TeamsAdminTable->insertColumn(3);
    ui->TeamsAdminTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Location"));


    //PROCESSING - gets information from database
    db.GetTeamBySeatingCapacity(names, stadiums, capacitys, locations);


    //PROCESSING - adds a row in table for each team
    for(int index = 0; index < names.size(); index++)
    {
        //PROCESSING - inserts a row to the table and sets information in the table
        ui->TeamsAdminTable->insertRow(index);
        ui->TeamsAdminTable->setItem(index,0,new QTableWidgetItem(names[index]));
        ui->TeamsAdminTable->setItem(index,1,new QTableWidgetItem(stadiums[index]));
        ui->TeamsAdminTable->setItem(index,2,new QTableWidgetItem(QString::number(capacitys[index])));
        ui->TeamsAdminTable->setItem(index,3,new QTableWidgetItem(locations[index]));
    }
    ui->TeamsAdminTable->resizeColumnsToContents();
    ui->TeamsAdminTable->resizeRowsToContents();
    ui->TeamsAdminTable->horizontalHeader()->setStretchLastSection(true);

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
                fillTeamComboBoxs(); //refill the admin souvenir combobox so lv's items can be modifield
                on_comboBox_TeamInfo_currentIndexChanged(ui->comboBox_TeamInfo->currentIndex()); //update the information tab on the fly, refresh no longer needed
                fillAdminTeamTable(); //update admin team table
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

    ui->AdminItemCombo->clear();
    ClearTable(ui->AdminSouvTable);
    //qDebug() << arg1;
    QString team =  arg1; //ui->AdminTeamSouvCombo->currentText();
    ui->AdminTeamIndLabel->setText("Modifying: The " + team);

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
       ui->AdminItemCombo->addItem(names[i]);
       ui->AdminSouvTable->setItem(i,1,new QTableWidgetItem(QString::number(prices[i], 'f', 2)));
    }
   ui->AdminSouvTable->resizeColumnsToContents();
   ui->AdminSouvTable->resizeRowsToContents();
    ui->AdminSouvTable->horizontalHeader()->setStretchLastSection(true);

}

//add new souvenir for a team
void MainWindow::on_NewItemAddButton_clicked()
{
    QString souvName = ui->NewItemNameInput->text().trimmed();
    QString team = ui->AdminTeamSouvCombo->currentText();
    double price = ui->NewItemPriceInput->value();

    if(!souvName.isEmpty())
    {
        if(db.AddSouvenir(team, souvName, price))
        {
            on_AdminTeamSouvCombo_currentTextChanged(ui->AdminTeamSouvCombo->currentText()); //update the item table
            QMessageBox::information(this, tr("Success!"),
                                     souvName + " was added for team: " + team);
            //reset the input
            ui->NewItemNameInput->clear();
            ui->NewItemPriceInput->setValue(1.00);

        }
        else
        {
            QMessageBox::information(this, tr("Error!"),
                                     team + " already offers this item");
        }
    }
    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 "Please enter all fields");
    }

}


void MainWindow::on_AdminDeleteSouv_clicked()
{
    QString team = ui->AdminTeamSouvCombo->currentText();
    QString item = ui->AdminItemCombo->currentText();
    if(db.DeleteItem(team, item))
    {
        on_AdminTeamSouvCombo_currentTextChanged(ui->AdminTeamSouvCombo->currentText()); //update the item table
        QMessageBox::information(this, tr("Deleted!"),
                                 item + " was removed for team: " + team);
    }
    else
    {
        QMessageBox::information(this, tr("Error!"),
                                 "Error occured, bug Nick on discord");
    }
}

void MainWindow::on_AdminUpdateSouv_clicked()
{
    QString team = ui->AdminTeamSouvCombo->currentText();
    QString item = ui->AdminItemCombo->currentText();
    double newPrice = ui->UpdateItemPriceInput->value();
    if(db.UpdateItem(team, item, newPrice))
    {
        on_AdminTeamSouvCombo_currentTextChanged(ui->AdminTeamSouvCombo->currentText()); //update the item table
        QMessageBox::information(this, tr("Success!"),
                   "Price for: " + item + " updated");
    }
}
//fills the double combo box for price update to the price of the item selected
void MainWindow::on_AdminItemCombo_currentTextChanged(const QString &arg1)
{
    QString item = arg1;
    QString team = ui->AdminTeamSouvCombo->currentText();
    ui->UpdateItemPriceInput->setValue(db.getItemPrice(team, item));


}



//update stadium names
void MainWindow::on_updateStadNutton_clicked()
{
    QString team = ui->AdminTeamSouvCombo_2->currentText();
    QString newName = ui->AdminStadiumUpdateIn->text().trimmed();

    if(!newName.isEmpty())
    {
        if(db.updateStadium(team, newName))
        {
            fillAdminTeamTable();
            ui->AdminStadiumUpdateIn->clear();
            QMessageBox::information(this, tr("Success!"),
                       team + " is now located at " + newName);
        }
    }
    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 "Please enter all fields");
    }

}

/**
 * @brief MainWindow::on_InfoTeamCombobox_currentIndexChanged
 * @param arg1
 */
void MainWindow::on_InfoTeamCombobox_currentIndexChanged(const QString &arg1)
{
    //PROCESSING - clear table
    ClearTable(ui->TeamInfo);

    QVector<QString> name;      //CALC - vector of team names
    QVector<QString> stadium;   //CALC - vector of stadium names
    QVector<double>  seating;   //CALC - vector of seating capacities
    QVector<QString> location;  //CALC - vector of locations
    QVector<QString> conference;//CALC - vector of conferences
    QVector<QString> surface;   //CALC - vector of surfaces
    QVector<QString> roof;      //CALC - vector of roofs
    QVector<QString> player;    //CALC - vector of players

    //PROCESSING - Gets all of teams info name
    db.GetAllTeamInfo(name, stadium, seating, location, conference, surface, roof, player);

    //PROCESSING - loops through each name in vector and fills table based on choice in combo
    //              box
    for(int i = 0; i < name.size(); i++)
    {
        //PROCESSING - fills table based on choice in combo box
        if(name[i] == arg1)
        {
            //PROCESSING - inserts column and sets name to name of team
            ui->TeamInfo->insertColumn(0);
            ui->TeamInfo->setHorizontalHeaderItem(0, new QTableWidgetItem(name[i]));

            //PROCESSING - inserts row and sets row header to stadium
            //              adds stadium name to row
            ui->TeamInfo->insertRow(0);
            ui->TeamInfo->setVerticalHeaderItem(0, new QTableWidgetItem("Stadium"));
            ui->TeamInfo->setItem(0,0, new QTableWidgetItem(stadium[i]));

            //PROCESSING - inserts row and sets row header to Seating Capacity
            //              adds seating capacity
            ui->TeamInfo->insertRow(1);
            ui->TeamInfo->setVerticalHeaderItem(1, new QTableWidgetItem("Seating Capacity"));
            ui->TeamInfo->setItem(1,0, new QTableWidgetItem(QString::number(seating[i])));

            //PROCESSING - inserts row and sets row header to Location
            //              adds location to row
            ui->TeamInfo->insertRow(2);
            ui->TeamInfo->setVerticalHeaderItem(2, new QTableWidgetItem("Location"));
            ui->TeamInfo->setItem(2,0, new QTableWidgetItem(location[i]));

            //PROCESSING - inserts row and sets row header to Conference
            //              adds conference to row
            ui->TeamInfo->insertRow(3);
            ui->TeamInfo->setVerticalHeaderItem(3, new QTableWidgetItem("Conference"));
            ui->TeamInfo->setItem(3,0, new QTableWidgetItem(conference[i]));

            //PROCESSING - inserts row and sets row header to Stadium name
            //              adds stadium name to row
            ui->TeamInfo->insertRow(4);
            ui->TeamInfo->setVerticalHeaderItem(4, new QTableWidgetItem("Stadium Name"));
            ui->TeamInfo->setItem(4,0, new QTableWidgetItem(surface[i]));

            //PROCESSING - inserts row and sets row header to Roof Type
            //              adds roof type to row
            ui->TeamInfo->insertRow(5);
            ui->TeamInfo->setVerticalHeaderItem(5, new QTableWidgetItem("Roof Type"));
            ui->TeamInfo->setItem(5,0, new QTableWidgetItem(roof[i]));

            //PROCESSING - inserts row and sets row header to Star Player
            //              adds star player to row
            ui->TeamInfo->insertRow(6);
            ui->TeamInfo->setVerticalHeaderItem(6, new QTableWidgetItem("Star Player"));
            ui->TeamInfo->setItem(6,0, new QTableWidgetItem(player[i]));

            //PROCESSING - resizes rows and columns of table
            ui->TeamInfo->resizeColumnsToContents();
            ui->TeamInfo->resizeRowsToContents();
            ui->TeamInfo->horizontalHeader()->setStretchLastSection(true);
        }
    }
}

