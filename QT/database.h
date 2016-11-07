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
     * @brief GetAllTeams
     * @return
     */
    QVector<QString> GetAllTeams();

    /**
     * @brief GetAFCTeams
     * @return
     */
    QVector<QString> GetAFCTeams();
    
    /**
     * @brief GetNationalConferenceTeams
     * @return
     */
    QVector<QString> GetNationalConferenceTeams();

    /**
     * @brief GetTeamBySeatingCapacity
     * @param name
     * @param stadium
     * @param capacity
     * @param location
     */
    void GetTeamBySeatingCapacity(QVector<QString> &name, QVector<QString> &stadium,
                                  QVector<float> &capacity, QVector<QString> &location);

    void GetTeamsSurfaceBySeating(QVector<QString> &name, QVector<QString> &stadium, QVector<QString> &surface,QVector<QString> &location);

    void GetPlayersByTeamname(QVector<QString> &names, QVector<QString> &players);


private:
    QSqlDatabase db;  ///< accesses database
};

#endif // DATABASE_H
