#include "database.h"

Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("football.db");

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
    //query.prepare("SELECT TEAM_NAME FROM STADIUM WHERE CONFERENCE = NFC ORDER BY TEAM_NAME ASC");

    query.prepare("SELECT * FROM STADIUM");

    qDebug() << "prepare";

    //PROCESSING - executes the query
    if(query.exec())
    {
        qDebug() << "exec";
        //PROCESSING - loops through the query and outputs data to console for testing
        while(query.next())
        {
            teams.push_back(query.value(1).toString());
            qDebug() << query.value(1).toString();
        }
    }

    return teams;
}
