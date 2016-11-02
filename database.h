#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QString>
#include <QVector>

class Database
{
public:
    /**
     * @brief Database
     */
    Database();

    /**
     * @brief GetNationalConferenceTeams
     * @return
     */
    QVector<QString> GetNationalConferenceTeams();


private:
    QSqlDatabase db;  ///< accesses database
};

#endif // DATABASE_H
