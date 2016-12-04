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
     *
     * \param name
     * \param stadium
     * \param surface
     * \param location
     */
    void GetTeamsSurfaceBySeating(QVector<QString> &name, QVector<QString> &stadium, QVector<QString> &surface,QVector<QString> &location);
    /*!
     * \brief GetPlayersByTeamname
     *
     * Gets star players and teams
     * \param names
     * \param players
     */
    void GetPlayersByTeamname(QVector<QString> &names, QVector<QString> &players);
    /*!
     * \brief GetNFLStadiums
     *
     * Gets all nfs stadiums and team names
     * \param stadium
     * \param name
     */

    void GetNFLStadiums(QVector<QString> &stadium,QVector<QString> &name );
    /*!
     * \brief GetOpenStadiums
     *
     * gets all open roofed stadiums and team names
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
     *
     * adds a souvenir for a team
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



    /*!
     * \brief getItemPrice
     *
     * gets the price of an items
     * \param team
     * \param item
     * \return
     */
    double getItemPrice(QString team, QString item);
    /*!
     * \brief updateStadium
     *
     * updates stadium name
     * \param team
     * \param newStadium
     */
    bool updateStadium(QString team, QString newStadium);
    /*!
     * \brief GetAllTeamInfo
     * \param name
     * \param stadium
     * \param seating
     * \param location
     * \param conference
     * \param surface
     * \param roof
     * \param player
     */

    /*!
     * \brief updateSeatCap
     * \param team
     * \param newSeatCap
     * \return
     */
    bool updateSeatCap(QString team, int newSeatCap) ;

    /*!
     * \brief GetAllTeamInfo
     * \param name
     * \param stadium
     * \param seating
     * \param location
     * \param conference
     * \param surface
     * \param roof
     * \param player
     */
    void GetAllTeamInfo(QVector<QString> &name, QVector<QString> &stadium, QVector<double> &seating,
                        QVector<QString> &location, QVector<QString> &conference,
                        QVector<QString> &surface, QVector<QString> &roof, QVector<QString> &player);

    /*!
     * \brief seatingSum
     * \return
     */
    int seatingSum();

    /*!
     * \brief getNodes
     * \param start
     * \param end
     * \param dist
     */
    void getNodes(QVector<int> &start, QVector<int> &end, QVector<int> &dist);

    /*!
     * \brief getCount
     * \return
     */
    int getCount();


    /*!
     * \brief getTeam
     * \param stadium
     * \param name
     */
    void getTeamsAndStadiums(QVector<QString> &stadium,QVector<QString> &name );


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
