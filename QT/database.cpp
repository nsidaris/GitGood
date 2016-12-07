#include "database.h"

/*!
   * \file database.cpp
   * \brief  Source for database wrapper class
   *
   * This file contains all of the declarations of the database class
   */

/*
 * "../Database/football.db"
 */
Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../Database/football.db");


    //connectes to database and outpts message if connection
    // was successfull
    if(!db.open())
        qDebug() << "Not connected to DB.";
    else if(db.open())
        qDebug() << "Connected to DB.";
}

/**
 * @brief Database::GetAllTeams
 * @return
 */
QVector<QString> Database::GetAllTeams()
{
    QSqlQuery        query; //CALC - variable to access the database
    QVector<QString> teams;

    query.prepare("SELECT TEAM_NAME FROM STADIUM ORDER BY TEAM_NAME ASC");

    /* executes query - outputs error if query not executed*/
    if(query.exec())
    {
        /* adds teams selected from database to vector to return */
        while(query.next())
        {
            teams.push_back(query.value(0).toString());
        }//END - while
    }
    else
    {
        qDebug()<< query.lastError();
    }//END - if

    return teams;
}

/**
 * @brief Database::GetAFCTeams
 * @return
 */
QVector<QString> Database::GetAFCTeams()
{
    QSqlQuery        query; //CALC - variable to access the database
    QVector<QString> teams;

    //PROCESSING - sql statement to retrieve info from the database
    query.prepare("SELECT TEAM_NAME FROM STADIUM WHERE CONFERENCE = 'AFC' ORDER BY TEAM_NAME ASC");

    //PROCESSING - executes the query
    if(query.exec())
    {
        //PROCESSING - loops through the query and outputs data to console for testing
        while(query.next())
        {
            teams.push_back(query.value(0).toString());
            //qDebug() << query.value(0).toString();
        }
    }
    else
    {
        qDebug()<< query.lastError();
    }

    return teams;
}

/**
 * @brief Database::GetNationalConferenceTeams
 * @return
 */
QVector<QString> Database::GetNationalConferenceTeams()
{
    QSqlQuery        query; //CALC - variable to access the database
    QVector<QString> teams;

    //PROCESSING - sql statement to retrieve info from the database
    query.prepare("SELECT TEAM_NAME FROM STADIUM WHERE CONFERENCE = 'NFC' ORDER BY TEAM_NAME ASC");

    //PROCESSING - executes the query
    if(query.exec())
    {
        //PROCESSING - loops through the query and outputs data to console for testing
        while(query.next())
        {
            teams.push_back(query.value(0).toString());
            //qDebug() << query.value(0).toString();
        }
    }
    else
    {
        qDebug()<< query.lastError();
    }

    return teams;
}

/**
 * @brief Database::GetTeamBySeatingCapacity
 * @param name
 * @param stadium
 * @param capacity
 * @param location
 */
void Database::GetTeamBySeatingCapacity(QVector<QString>& name, QVector<QString>& stadium,
                                        QVector<float>& capacity, QVector<QString>& location)
{
    QSqlQuery query; //CALC - variable to access the database

    //PROCESSING - sql statement to retrieve info from the database
    query.prepare("SELECT TEAM_NAME,STADIUM_NAME,SEATING_CAP,LOCATION FROM STADIUM ORDER BY SEATING_CAP");

    //PROCESSING - executes the query
    if(query.exec())
    {
        //PROCESSING - loops through the query storing data from database to vectors
        while(query.next())
        {
            name.push_back(query.value(0).toString());
            stadium.push_back(query.value(1).toString());
            capacity.push_back(query.value(2).toFloat(0));
            location.push_back(query.value(3).toString());
        }//END - while
    }//END - if
}

/**
 * @brief Database::GetTeamsSurfaceBySeating
 * @param name
 * @param stadium
 * @param surface
 * @param location
 */
void Database::GetTeamsSurfaceBySeating(QVector<QString> &name, QVector<QString> &stadium, QVector<QString> &surface,QVector<QString> &location)
{
    QSqlQuery query; //CALC - variable to access the database

    //PROCESSING - sql statement to retrieve info from the database
    query.prepare("SELECT TEAM_NAME,STADIUM_NAME,SURFACE,LOCATION FROM STADIUM ORDER BY SURFACE");

    /* executes query - outputs error message if query not sucessful*/
    if(query.exec())
    {
        /* adds data selected from database to appropiate vectors*/
        while(query.next())
        {
            name.push_back(query.value(0).toString());
            stadium.push_back(query.value(1).toString());
            surface.push_back(query.value(2).toString());
            location.push_back(query.value(3).toString());
        }//END - while
    }
    else
    {
        qDebug()<< query.lastError();
    }
}

/**
 * @brief Database::GetPlayersByTeamname
 * @param names
 * @param players
 */
void Database::GetPlayersByTeamname(QVector<QString> &names, QVector<QString> &players)
{
    QSqlQuery query; //CALC - variable to access the database

    query.prepare("SELECT TEAM_NAME, STAR_PLAYER FROM STADIUM ORDER BY TEAM_NAME");

    /*executes query - outputs error message if not successful*/
    if(query.exec())
    {
        /* added names and players to appropiate vectors*/
        while(query.next())
        {
            names.push_back(query.value(0).toString());
           players.push_back(query.value(1).toString());
        }//END - while
    }
    else
    {
        qDebug()<< query.lastError();
    }
}

/**
 * @brief Database::GetNFLStadiums
 * @param stadium
 * @param name
 */
void Database::GetNFLStadiums(QVector<QString> &stadium,QVector<QString> &name )
{
    QSqlQuery query; //CALC - variable to access the database

    query.prepare("SELECT STADIUM_NAME, TEAM_NAME FROM STADIUM ORDER BY TEAM_NAME");

    /*executes query - outputs error message if not successful*/
    if(query.exec())
    {
        /* added names and stadiums selected from database to appropiate vectors*/
        while(query.next())
        {
            stadium.push_back(query.value(0).toString());
            name.push_back(query.value(1).toString());
        }
    }
    else
    {
         qDebug()<< query.lastError();
    }
}

/**
 * @brief Database::GetOpenStadiums
 * @param stadium
 * @param name
 */
void Database::GetOpenStadiums(QVector<QString> &stadium,QVector<QString> &name)
{
    QSqlQuery query; //CALC - variable to access the database

    query.prepare("SELECT STADIUM_NAME, TEAM_NAME FROM STADIUM WHERE ROOF_TYPE = 'O' ORDER BY STADIUM_NAME");

    /*executes query - outputs error message if not successful*/
    if(query.exec())
    {
         /* added names and stadiums selected from database to appropiate vectors*/
        while(query.next())
        {
            stadium.push_back(query.value(0).toString());
            name.push_back(query.value(1).toString());
        }
    }
    else
    {
         qDebug()<< query.lastError();
    }
}

/**
 * @brief Database::AddLasVegas
 * - Adds Las Vegas to the Database
 * @return true/false if query was executing
 */


bool Database::AddLasVegas(QString name, QString stadium, int capacity, QString location,
                           QString conference, QString surface, QString roof, QString star,
                           int A, QVector<int> B, QVector<float> distance)
{
    bool success = false;
    QSqlQuery query;    //CALC - variable to access the database

    /************************************************************************
     * PROCESSING - Inserts Las Vegas stadium information into the stadium
     * table
     ************************************************************************/
    query.prepare("INSERT INTO STADIUM (TEAM_NAME, STADIUM_NAME, SEATING_CAP, LOCATION, CONFERENCE, "
                  "SURFACE, ROOF_TYPE, STAR_PLAYER) VALUES (:name, :stadium, :capacity, :location, :conference, "
                  ":surface, :roof, :star)");

    //PROCESSING - binds all the variables to their corresponding values
    query.bindValue(":name", name);
    query.bindValue(":stadium", stadium);
    query.bindValue(":capacity", capacity);
    query.bindValue(":location", location);
    query.bindValue(":conference", conference);
    query.bindValue(":surface", surface);
    query.bindValue(":roof", roof);
    query.bindValue(":star", star);

    //PROCESSING - returns true is the query was executed.
    //              returns false if the query was not executed
    if(query.exec())
    {
        success = true;
    }
    else
    {
        success = false;
    }


    /************************************************************************
     * PROCESSING - Inserts all nodes to and from Las Vegas into nodes table
     ************************************************************************/
    for(int i = 0; i < B.size(); i++)
    {
        query.prepare("INSERT INTO node (A, B, DISTANCE) VALUES (:A, :B, :distance)");
        query.bindValue(":A", A);
        query.bindValue(":B", B[i]);
        query.bindValue(":distance", distance[i]);

        /*PROCESSING - returns true is the query was executed
                returns false if the query was not executed */
        if(query.exec())
        {
            success = true;
        }
        else
        {
            success = false;
        }
    }//END - for(int i = 0; i < A.size(); i++)

    return success;
}

/**
 * @brief Database::AddSouvenir
 * @param team
 * @param item
 * @param price
 * @return
 */
bool Database::AddSouvenir(QString team, QString item, float price)
{
    QSqlQuery query;    //CALC - accesses database

    /* sql statement to get access datavase*/
    query.prepare("INSERT INTO SOUVENIRS (TEAM, SOUVENIR, PRICE) VALUES (:team, :item, :price)");
    query.bindValue(":team", team);
    query.bindValue(":item", item);
    query.bindValue(":price", price);

     /* checks if team exits - if TRUE executes query*/
    if(!Exists(item, team))
    {
        if(query.exec())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }


}

/**
 * @brief Database::GetSouvenirs
 * @param names
 * @param prices
 * @param team
 */
void Database::GetSouvenirs(QVector<QString> &names, QVector<double> &prices, QString team)
{
    QSqlQuery query; //CALC - variable to access database

    /* sql statment to get info from database*/
    query.prepare("SELECT SOUVENIR, PRICE FROM SOUVENIRS WHERE TEAM = (:team)");
    query.bindValue(":team", team);
    if(query.exec())
    {
         /* added names and prices selected from database to appropiate vectors*/
        while(query.next())
        {
            names.push_back(query.value(0).toString());
            prices.push_back(query.value(1).toDouble());
        }
    }
    else
    {
        qDebug()<< query.lastError();
    }
}

/**
 * @brief Database::Exists
 * @param name
 * @param team
 * @return
 */
bool Database::Exists(QString name, QString team)
{
    QSqlQuery query(db); //accesses database

    //sql statement to get info from database
    query.prepare("SELECT * FROM SOUVENIRS WHERE TEAM = (:team) AND SOUVENIR = (:name)");
    query.bindValue(":team", team);
    query.bindValue(":name",name );

    //executes query
    if(query.exec())
    {
        if(query.next())
        {
            // qDebug() << "Exists";
            return true;
        }
        else
        {
            //qDebug() << "Non existant";
            return false;
        }
    }
    else
    {
        qDebug() << query.lastError();
        return false;
    }
}

/**
 * @brief Database::DeleteItem
 * @param team
 * @param item
 * @return
 */
bool Database::DeleteItem(QString team, QString item)
{
    QSqlQuery query(db); //accesses database

    //sql statement to delete item passed in from selected team from database
    query.prepare("DELETE FROM SOUVENIRS WHERE TEAM = (:team) AND SOUVENIR = (:name)");
    query.bindValue(":team", team);
    query.bindValue(":name",item );

    //exuctes query
    if(query.exec())
    {
        return true;
    }
    else
    {
        qDebug() << query.lastError();
        return false;
    }
}

/**
 * @brief Database::UpdateItem
 * @param team
 * @param item
 * @param price
 * @return
 */
bool Database::UpdateItem(QString team, QString item, double price)
{
    QSqlQuery query(db);    //accesses database

    //sql statement to update item with name and price passed in
    query.prepare("UPDATE SOUVENIRS SET PRICE = (:price) WHERE TEAM = (:team) AND SOUVENIR = (:name)");
    query.bindValue(":team", team);
    query.bindValue(":name",item );
    query.bindValue(":price",price);

    //executes query
    if(query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Database::getItemPrice
 * @param team
 * @param item
 * @return
 */
double Database::getItemPrice(QString team, QString item)
{
    double price = 0.2; //price of item
     QSqlQuery query(db);//accesses database

     //gets prices and souvenirs from database
     query.prepare("SELECT PRICE FROM SOUVENIRS WHERE TEAM = (:team) AND SOUVENIR = (:name)");
     query.bindValue(":team", team);
     query.bindValue(":name",item );

     //executes query
     if(query.exec())
     {
         //gets price from query and saves it to variable to return
         if(query.next())
         {
              price = query.value(0).toDouble();
         }
     }
     else
     {
         qDebug() << query.lastError();
     }
     return price;
}

/**
 * @brief Database::updateStadium
 * @param team
 * @param newStadium
 * @return
 */
bool Database::updateStadium(QString team, QString newStadium)
{
    QSqlQuery query(db); //variable to access stadium

    //sql statement to update stadium name and team name with variable passed in
    query.prepare("UPDATE STADIUM SET STADIUM_NAME = (:newStad) WHERE TEAM_NAME = (:team)");
    query.bindValue(":newStad", newStadium);
    query.bindValue(":team", team);

    //executes sql statement
    if(query.exec())
    {
        return true;
    }
    else
    {
        qDebug() << query.lastError();
    }

    return false;
}

bool::Database::updateSeatCap(QString team, int newSeatCap)
{
    QSqlQuery query(db); //variable to access database

    //sql statement to update seating capacity with new capacity passed in to team passed in
    query.prepare("UPDATE STADIUM SET SEATING_CAP = (:newSeat) WHERE TEAM_NAME = (:team)");/////////////////////////////////
    query.bindValue(":newSeat", newSeatCap);
    query.bindValue(":team", team);

    //executes the query
    if(query.exec())
    {
        return true;
    }
    else
    {
        qDebug() << query.lastError();
    }

    return false;
}

/**
 * @brief Database::GetAllTeamInfo
 * @param name
 * @param stadium
 * @param seating
 * @param location
 * @param conference
 * @param surface
 * @param roof
 * @param player
 */
void Database::GetAllTeamInfo(QVector<QString>& name, QVector<QString>& stadium, QVector<double>& seating,
                              QVector<QString>& location, QVector<QString>& conference,
                              QVector<QString>& surface, QVector<QString>& roof, QVector<QString>& player)
{
    QSqlQuery query(db);//CALC - variable to access database

    //PROCESSING - sql statement to get information from stadium
    query.prepare("SELECT * FROM STADIUM");

    //PROCESSING - executes statement
    if(query.exec())
    {
        //PROCESSING - loops through query and adds teams information to vectors
        while(query.next())
        {
            name.push_back(query.value(1).toString());
            stadium.push_back(query.value(2).toString());
            seating.push_back(query.value(3).toDouble(0));
            location.push_back(query.value(4).toString());

            //PROCESSING - adds conference name based on input.
            //          AFC = American Football Conference
            //          NFC = National Football Conference
            if(query.value(5).toString() == "AFC")
            {
                conference.push_back("American Football Conference");
            }
            else
            {
                conference.push_back("National Football Conference");
            }

            surface.push_back(query.value(6).toString());

            //PROCESSING - adds conference name based on input.
            //          O = Open
            //          F = Fixed
            //          R = Retractable
            if(query.value(7).toString() == "O")
            {
                roof.push_back("Open");
            }
            else if(query.value(7).toString() == "F")
            {
                roof.push_back("Fixed");
            }
            else
            {
                roof.push_back("Retractable");
            }

            player.push_back(query.value(8).toString());

        }//END while
    }//END if
    else
    {
        qDebug() << query.lastError();
    }
}

void Database::GetOneTeamInfo(QString &name, QString &stadium, double &seating, QString &location, QString &conference, QString &surface, QString &roof, QString &player)
{
    QSqlQuery query(db);//CALC - variable to access database

    //PROCESSING - sql statement to get information from stadium
    query.prepare("SELECT STADIUM_NAME, SEATING_CAP, LOCATION, CONFERENCE, SURFACE, ROOF_TYPE, STAR_PLAYER FROM STADIUM"
                  " WHERE TEAM_NAME = :team");
    query.bindValue(":team",name);

    //PROCESSING - executes statement
    if(query.exec())
    {
        //PROCESSING - loops through query and adds teams information to vectors
        while(query.next())
        {
            stadium = query.value(0).toString();
            seating = query.value(1).toDouble(0) ;
            location = query.value(2).toString();

            //PROCESSING - adds conference name based on input.
            //          AFC = American Football Conference
            //          NFC = National Football Conference
            if(query.value(3).toString() == "AFC")
            {
                conference = "American Football Conference";
            }
            else
            {
                conference = "National Football Conference" ;
            }

            surface = query.value(4).toString();

            //PROCESSING - adds conference name based on input.
            //          O = Open
            //          F = Fixed
            //          R = Retractable
            if(query.value(5).toString() == "O")
            {
                roof = "Open";
            }
            else if(query.value(5).toString() == "F")
            {
                roof = "Fixed";
            }
            else
            {
                roof = "Retractable";
            }

            player = query.value(6).toString();

        }//END while
    }//END if
    else
    {
        qDebug() << query.lastError() << "\toneTeam";
    }
}

int Database::seatingSum()
{
    int sum = 0;
    QSqlQuery query(db);//CALC - variable to access database

    //PROCESSING - sql statement to get information from stadium
    query.prepare("SELECT SUM(SEATING_CAP)FROM STADIUM");
    if(query.exec())
    {
        if(query.next())
        {
            sum = query.value(0).toInt();
        }
    }
    else
    {
        qDebug() << query.lastError();
    }
    return sum;

}


void Database::getNodes(QVector<int> &start, QVector<int> &end, QVector<int> &dist)
{
     QSqlQuery query(db);//CALC - variable to access database

     //query to get all information in the node table
     query.prepare("SELECT * FROM node");

     //executes query
     if(query.exec())
     {
         //pushes back a node, b node, and distance to appropiate vectors
            while(query.next())
            {
                start.push_back(query.value(0).toInt()); //a
                end.push_back(query.value(1).toInt());   //b
                dist.push_back(query.value(2).toInt());  //dist
            }
     }
     else
     {
         qDebug() << query.lastError();
     }




}
int Database::getCount()
{
    QSqlQuery query(db);//CALC - variable to access database

    //sql statement to get count from stadium
    query.prepare("SELECT count(*) FROM STADIUM");

    //executes sql statement
    if(query.exec())
    {
        //returns the count of teams in the database
        if(query.next())
        {
            return query.value(0).toInt();
        }
    }
    else
    {
        qDebug() << query.lastError();
    }
    return 0;

}
void Database::getTeamsAndStadiums(QVector<QString> &stadium,QVector<QString> &name )

{
    QSqlQuery query(db);    //accesses database

    //sql statement to get stadium name, team name from stadium
    query.prepare("SELECT STADIUM_NAME, TEAM_NAME FROM STADIUM");

    //executes query
    if(query.exec())
    {
        //saves stadium names and team names to appropiate vectors
        while(query.next())
        {
            stadium.push_back(query.value(0).toString());
            name.push_back(query.value(1).toString());
        }
    }
    else
    {
         qDebug()<< query.lastError();
    }
}

QVector<int> Database::TeamNamesToNodes(QVector<QString> &teams)
{
    QVector<int> teamNumbers;
    QSqlQuery query(db);

    for(int i = 0; i < teams.size(); i++)
    {
        query.prepare("SELECT TEAM FROM STADIUM WHERE TEAM_NAME = :team");
        query.bindValue(":team", teams[i]);

        if(query.exec())
        {
            while(query.next())
            {
                teamNumbers.push_back(query.value(0).toInt(0));
            }
        }
        else
        {
             qDebug()<< query.lastError();
        }
    }
    return teamNumbers;
}

int Database::GetTeamNumber(QString team)
{
    QSqlQuery query(db);
    int number;

    query.prepare("SELECT TEAM FROM STADIUM WHERE TEAM_NAME = :team");
    query.bindValue(":team", team);

    if(query.exec())
    {
        while(query.next())
        {
            number = query.value(0).toInt(0);
            //qDebug() << number;
        }
    }
    else
    {
         qDebug()<< query.lastError();
    }

    return number;
}

QString Database::GetTeamName(int number)
{
    QSqlQuery query(db);

    QString team;
    query.prepare("SELECT TEAM_NAME FROM STADIUM WHERE TEAM = :team");
    query.bindValue(":team", number);

    if(query.exec())
    {
        while(query.next())
        {
            team = query.value(0).toString();
        }
    }
    else
    {
         qDebug()<< query.lastError() << "\tteam name";
    }

    return team;
}

QString Database::GetTeamName(QString stadium)
{
    QSqlQuery query(db);

    QString team;
    query.prepare("SELECT TEAM_NAME FROM STADIUM WHERE STADIUM_NAME = :team");
    query.bindValue(":team", stadium);

    if(query.exec())
    {
        while(query.next())
        {
            team = query.value(0).toString();
        }
    }
    else
    {
         qDebug()<< query.lastError() << "\tteam name";
    }

    return team;
}
