/*!
 * Map.h
 *
 *  Created on: Dec 4, 2016
 *      Author: ashlyhernandez
 */
/*!
   * \file Map.h
   * \brief  Header for map class
   *
   * This file contains all of the declarations of the map class
   */
#ifndef MAP_H_
#define MAP_H_

#include <QVector>
#include <QString>
using namespace std;

/*!
 * \brief The node struct
 *
 * represents a node in the map
 */
struct node
{
    QString key;
	int value;
};

/*!
 * \brief The Map class
 *
 * This class represents a map to store items
 */
class Map {
public:

    /*!
     * \brief Map
     */
	Map();	//constructo
    /*!
     * \brief ~Map
     */
	virtual ~Map(); //destructor
    /*!
     * \brief size
     *
     * Gets the size of the map
     * \return size of map
     */
	int size() const; //returns size of map
    /*!
     * \brief empty
     *
     * Returns T/F if the map is empty
     * \return
     */
	bool empty() const; // returns if vector is empty or not
    /*!
     * \brief insert
     *
     * Inserts an element
     * \param key
     * \param value
     */
    void insert(QString key, int value); //inserts key and value to map
    /*!
     * \brief erase
     *
     * Erases an element
     * \param key
     */
    void erase(QString key); //erases element with key passed in
    /*!
     * \brief GetList
     *
     * Gets the map
     * \return list of map items
     */
	vector<node> GetList(); //returns map list
    /*!
     * \brief clearList
     *
     * Clears the map out
     */
	void clearList();

private:
	vector<node> list;
};

#endif /* MAP_H_ */

