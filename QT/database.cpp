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

    if(query.exec())
    {
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
    query.prepare("SELECT TEAM_NAME,STADIUM_NAME,SURFACE,LOCATION FROM STADIUM ORDER BY SEATING_CAP");

    if(query.exec())
    {
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

    if(query.exec())
    {
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


    if(query.exec())
    {
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


    if(query.exec())
    {
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
        query.prepare("INSERT INTO NODES (A, B, DISTANCE) VALUES (:A, :B, :distance)");
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

    /************************************************************************
     * NEED TO ADD A QUERY FOR ADDING SOUVENIRS TO THE SOUVINER TABLE
     ************************************************************************/


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
    QSqlQuery query;
    query.prepare("INSERT INTO SOUVENIRS (TEAM, SOUVENIR, PRICE) VALUES (:team, :item, :price)");
    query.bindValue(":team", team);
    query.bindValue(":item", item);
    query.bindValue(":price", price);
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
    QSqlQuery query;


    query.prepare("SELECT SOUVENIR, PRICE FROM SOUVENIRS WHERE TEAM = (:team)");
    query.bindValue(":team", team);
    if(query.exec())
    {
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
    QSqlQuery query(db);

    query.prepare("SELECT * FROM SOUVENIRS WHERE TEAM = (:team) AND SOUVENIR = (:name)");
    query.bindValue(":team", team);
    query.bindValue(":name",name );
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
    QSqlQuery query(db);

    query.prepare("DELETE FROM SOUVENIRS WHERE TEAM = (:team) AND SOUVENIR = (:name)");
    query.bindValue(":team", team);
    query.bindValue(":name",item );
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
    QSqlQuery query(db);
    query.prepare("UPDATE SOUVENIRS SET PRICE = (:price) WHERE TEAM = (:team) AND SOUVENIR = (:name)");
    query.bindValue(":team", team);
    query.bindValue(":name",item );
    query.bindValue(":price",price);
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
    double price = 0.2;
     QSqlQuery query(db);
     query.prepare("SELECT PRICE FROM SOUVENIRS WHERE TEAM = (:team) AND SOUVENIR = (:name)");
     query.bindValue(":team", team);
     query.bindValue(":name",item );
     if(query.exec())
     {
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
    QSqlQuery query(db);
    query.prepare("UPDATE STADIUM SET STADIUM_NAME = (:newStad) WHERE TEAM_NAME = (:team)");

    query.bindValue(":newStad", newStadium);
    query.bindValue(":team", team);
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
