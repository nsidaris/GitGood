#include "database.h"

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



