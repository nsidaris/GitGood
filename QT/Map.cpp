/*
 * Map.cpp
 *
 *  Created on: Dec 4, 2016
 *      Author: ashlyhernandez
 */

#include "Map.h"

Map::Map() {
	// TODO Auto-generated constructor stub

}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

//returns size of list
int Map::size() const
{
	return list.size();
}

// returns true if list is empty, false if not
bool Map::empty() const
{
	return list.empty();
}

//Inserts key and value into map
void Map::insert(QString key, int value)
{
	node i;
	i.key = key;
	i.value = value;

	list.push_back(i);
}

//erases element of specified key
void Map::erase(QString key)
{
	vector<node>::iterator it = list.begin();

	int i = 0;
	while(it != list.end())
	{
		if(list[i].key == key)
		{
			list.erase(it);
		}
		i++;
		it++;
	}
}

//return map
vector<node> Map::GetList()
{
	return list;
}

void Map::clearList()
{
	list.clear();
}

