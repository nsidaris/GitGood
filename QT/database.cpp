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






