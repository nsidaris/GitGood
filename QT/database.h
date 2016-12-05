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
     *
     * Gets all NFL Teams by team name
     * @return QVector of all team names
     */
    QVector<QString> GetAllTeams();

    /**
     * @brief GetAFCTeams
     *
     * NFL teams sorted by team name.

     * @return QVector of AFC Teams
     */
    QVector<QString> GetAFCTeams();
    
    /**
     * @brief GetNationalConferenceTeams
     *
     * Get NFC teams sorted by team name
     * @return QVector of AFC Teams
     */
    QVector<QString> GetNationalConferenceTeams();

    /**
     * @brief GetTeamBySeatingCapacity
     *
     * National Football Conference teams sorted by team name.
     *
     * @param name Team name
     * @param stadium stadium name
     * @param capacity Seating Capacity
     * @param location Stadium Location
     */
    void GetTeamBySeatingCapacity(QVector<QString> &name, QVector<QString> &stadium,
                                  QVector<float> &capacity, QVector<QString> &location);

    /*!
     * \brief GetTeamsSurfaceBySeating
     *
     * Gets team name, stadium, surface type and location by surface type
     *
     * \param name Team name
     * \param stadium Stadium name
     * \param surface Surface type
     * \param location Stadium Location
     */
    void GetTeamsSurfaceBySeating(QVector<QString> &name, QVector<QString> &stadium, QVector<QString> &surface,QVector<QString> &location);
    /*!
     * \brief GetPlayersByTeamname
     *
     * Gets star players and teams by team name
     * \param names team names
     * \param players star players
     */
    void GetPlayersByTeamname(QVector<QString> &names, QVector<QString> &players);
    /*!
     * \brief GetNFLStadiums
     *
     * Gets all nfs stadiums and team names by team name
     * \param stadium Stadiums
     * \param name Team names
     */

    void GetNFLStadiums(QVector<QString> &stadium,QVector<QString> &name );
    /*!
     * \brief GetOpenStadiums
     *
     * Gets all open roofed stadiums and team names
     * \param stadium stadiums
     * \param name team names
     */
    void GetOpenStadiums(QVector<QString> &stadium,QVector<QString> &name);
    /*!
     * \brief AddLasVegas
     *
     * Add the New Las Vegas team to the database along with souvenirs and distance nodes
     *
     * \param name Team name
     * \param stadium Stadium name
     * \param capacity Stadium seating cap
     * \param location City
     * \param conference AFC or NFC
     * \param surface Stadium surface type
     * \param roof  Roof type
     * \param star  Star Player
     * \param A     Start edge vector
     * \param B     End edge vector
     * \param distance edge weight/distance
     * \return
     */
    bool AddLasVegas(QString name, QString stadium, int capacity,
                     QString location, QString conference, QString surface,
                     QString roof, QString star, int A, QVector<int> B,
                     QVector<float> distance);
    /*!
     * \brief AddSouvenir
     *
     * Adds a souvenir for a team, prevents duplicates
     * \param team Team recieving the souvenir
     * \param item Item name
     * \param price Item price
     * \return T/F
     */

    bool AddSouvenir(QString team, QString item, float price);


    /*!
     * \brief GetSouvenirs
     *
     * Gets souvenirs for a team
     * \param names item names
     * \param prices item prices
     * \param team  item owner
     */
    void GetSouvenirs(QVector<QString> &names, QVector<double> &prices, QString team);
    /*!
     * \brief DeleteItem
     *
     * Removes an item from a team
     * \param team Item owner
     * \param item Item name
     * \return T/F
     */

    bool DeleteItem(QString team, QString item);

    /*!
     * \brief UpdateItem
     *
     * updates item's price
     *
     * \param team item owner
     * \param item item name
     * \param price New price
     * \return T/F
     */

    bool UpdateItem(QString team, QString item, double price);



    /*!
     * \brief getItemPrice
     *
     * gets the price of an item
     * \param team Item owner
     * \param item Item name
     * \return Item's price
     */
    double getItemPrice(QString team, QString item);
    /*!
     * \brief updateStadium
     *
     * updates stadium name
     * \param team Team name
     * \param newStadium New Stadium name
     */
    bool updateStadium(QString team, QString newStadium);


    /*!
     * \brief updateSeatCap
     *
     * Updates the Seating capacity of a stadium
     * \param team Team name
     * \param newSeatCap New seating capacity
     * \return T/F
     */
    bool updateSeatCap(QString team, int newSeatCap) ;

    /*!
     * \brief GetAllTeamInfo
     *
     * Gets all team information
     * \param name team names
     * \param stadium stadium names
     * \param seating seating capacity
     * \param location home cities
     * \param conference conferences(nfc or afc)
     * \param surface Surface grass type
     * \param roof   Roof types
     * \param player Star players
     */
    void GetAllTeamInfo(QVector<QString> &name, QVector<QString> &stadium, QVector<double> &seating,
                        QVector<QString> &location, QVector<QString> &conference,
                        QVector<QString> &surface, QVector<QString> &roof, QVector<QString> &player);

    /*!
     * \brief GetOneTeamInfo
     *
     * Gets info for one team
     * \param name team name
     * \param stadium stadium
     * \param seating seating cap
     * \param location home city
     * \param conference conference(nfc or afc)
     * \param surface surface type
     * \param roof roof type
     * \param player star players
     */
    void GetOneTeamInfo(QString &name, QString &stadium, double &seating,
                        QString &location, QString &conference,
                        QString &surface, QString &roof, QString &player);

    /*!
     * \brief seatingSum
     *
     * Finds the total seating cap
     * \return Total seating cap
     */
    int seatingSum();

    /*!
     * \brief getNodes
     * \param start Front edges
     * \param end Back edges
     * \param dist Edge costs
     */
    void getNodes(QVector<int> &start, QVector<int> &end, QVector<int> &dist);

    /*!
     * \brief getCount
     *
     * Gets total number of teams
     * \return number of teams
     */
    int getCount();


    /*!
     * \brief getTeamsAndStadiums();
     *
     * Gets list of team names and stadiums to fill master lists in mainwindow
     * \param stadium
     * \param name
     */
    void getTeamsAndStadiums(QVector<QString> &stadium,QVector<QString> &name );
    /*!
     * \brief TeamNamesToNodes
     *
     * Gets nodes for a team
     * \param teams teams to get nodes for
     * \return list of nodes
     */

    QVector<int> TeamNamesToNodes(QVector<QString>& teams);

    /*!
     * \brief GetTeamNumber
     *
     * Gets team number
     * \param team
     * \return tem number
     */
    int GetTeamNumber(QString team);
    /*!
    * \brief GetTeamName
    * \param number
    * \return Team name
    */
    QString GetTeamName(int number);

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
