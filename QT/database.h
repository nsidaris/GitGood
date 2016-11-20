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
    /*!
     * \brief AddLasVegas
     * \param name
     * \param stadium
     * \param capacity
     * \param location
     * \param conference
     * \param surface
     * \param roof
     * \param star
     * \param A
     * \param B
     * \param distance
     * \return
     */
    bool AddLasVegas(QString name, QString stadium, int capacity,
                     QString location, QString conference, QString surface,
                     QString roof, QString star, int A, QVector<int> B,
                     QVector<float> distance);
    /*!
     * \brief AddSouvenir
     * \param team
     * \param item
     * \param price
     * \return
     */

    bool AddSouvenir(QString team, QString item, float price);


    /*!
     * \brief GetSouvenirs
     *
     * Gets souvenirs for a team
     * \param names
     * \param prices
     * \param team
     */
    void GetSouvenirs(QVector<QString> &names, QVector<double> &prices, QString team);
    /*!
     * \brief DeleteItem
     *
     * Removes an item from a team
     * \param team
     * \param item
     * \return
     */

    bool DeleteItem(QString team, QString item);

    /*!
     * \brief UpdateItem
     *
     * updates item's price
     *
     * \param team
     * \param item
     * \param price
     * \return
     */

    bool UpdateItem(QString team, QString item, double price);



    double getItemPrice(QString team, QString item);


protected:
    /*!
     * \brief Exists
     *
     * Checks if an item exists, used to prevent duplicates
     * \param name
     * \param team
     * \return
     */
    bool Exists(QString name, QString team);



private:
    QSqlDatabase db;  ///< accesses database
};

#endif // DATABASE_H
