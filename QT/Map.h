/*
 * Map.h
 *
 *  Created on: Dec 4, 2016
 *      Author: ashlyhernandez
 */

#ifndef MAP_H_
#define MAP_H_

#include <QVector>
#include <QString>
using namespace std;


struct node
{
    QString key;
	int value;
};

class Map {
public:
	Map();	//constructo
	virtual ~Map(); //destructor
	int size() const; //returns size of map
	bool empty() const; // returns if vector is empty or not
    void insert(QString key, int value); //inserts key and value to map
    void erase(QString key); //erases element with key passed in
	vector<node> GetList(); //returns map list
	void clearList();

private:
	vector<node> list;
};

#endif /* MAP_H_ */

