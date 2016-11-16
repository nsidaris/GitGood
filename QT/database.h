#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QString>
#include <QVector>
/*!
   * \file database.h
   * \brief  Header for database wrapper class
   *
   * This file contains all of the declarations of the database class
   */


/*!
 * \brief The database class
 *
 * Manages the sqlite database of all NFL info
 */
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

    /*!
     * \brief GetTeamsSurfaceBySeating
     * \param name
     * \param stadium
     * \param surface
     * \param location
     */
    void GetTeamsSurfaceBySeating(QVector<QString> &name, QVector<QString> &stadium, QVector<QString> &surface,QVector<QString> &location);
    /*!
     * \brief GetPlayersByTeamname
     * \param names
     * \param players
     */
    void GetPlayersByTeamname(QVector<QString> &names, QVector<QString> &players);
    /*!
     * \brief GetNFLStadiums
     * \param stadium
     * \param name
     */

    void GetNFLStadiums(QVector<QString> &stadium,QVector<QString> &name );
    /*!
     * \brief GetOpenStadiums
     * \param stadium
     * \param name
     */
    void GetOpenStadiums(QVector<QString> &stadium,QVector<QString> &name);

    bool AddLasVegas(QString name, QString stadium, int capacity, QString location, QString conference, QString surface, QString roof, QString star, int A, QVector<int> B, QVector<float> distance);


private:
    QSqlDatabase db;  ///< accesses database
};

#endif // DATABASE_H
