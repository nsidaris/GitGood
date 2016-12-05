/*************************************************************************
 * AUTHOR        : Nick Sidaris
 * STUDENT ID    : 385623
 * Assignment 10 : DFS and BFS
 * CLASS 		 : CS1D
 * SECTION 		 : M/W 4:30 - 5:20
 * DUE DATE 	 : 11/21/2016
 * MST: http: www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
 * dijkstra: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
 *************************************************************************/
#ifndef GRAPH_H_
#define GRAPH_H_


#include<queue>
#include <stdio.h>
#include <limits.h>
#include<iostream>
#include<iomanip>
#include<string.h>
#include<QVector>
using namespace std;

#include <sstream>

template <typename T>
  string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

/****************************************************
 * assigns an integer value to the cities in the map
 ***************************************************/
enum cities
{
	LOS_ANGELES,
	SAN_FRANCISCO,
	SEATTLE,
	DENVER,
	CHICAGO,
	KANSAS_CITY,
	DALLAS,
	HOUSTON,
	BOSTON,
	NEW_YORK,
	ATLANTA,
	MIAMI,
};

enum status
{
	NOT_VISITED,
	VISITED
};


/*!
 * \brief The Graph class
 */
class Graph {
public:
	//Constructor
    /*!
     * \brief Graph
     */
	Graph();

	//Destructor
	virtual ~Graph();

	//Returns a list of incident edges
    /*!
     * \brief incidentEdges
     * \param vertex
     * \return
     */
	vector< vector< int > > incidentEdges(int vertex);

	//Checks whether there is an edge between vertices passed in
    /*!
     * \brief IsAdjacentTo
     * \param vertex1
     * \param vertex2
     * \return
     */
	bool IsAdjacentTo(int vertex1, int vertex2);

	//Traverses through list using DFS algorithm
    /*!
     * \brief DFS
     * \param startingVertex
     * \return
     */
	vector<int> DFS(int startingVertex);

	//returns multi-dimension vector of levels, each level contains the cities that are at that level

    /*!
     * \brief BFS
     * \param startingVertex
     * \return
     */
	vector< int > BFS(int startingVertex);

	//CALC - returns the total distance traveled by DFS or BFS
    /*!
     * \brief GetTotalDistanceTraveled
     * \return
     */
	float GetTotalDistanceTraveled() const;

    /*!
     * \brief Dijkstra
     * \param src
     * \param dist
     * \param dijkstraList
     */
    void Dijkstra(int src, QVector<int> &dist, QVector<int> &dijkstraList);
    void MST(int &distTraveled, QVector<int> &first, QVector<int> &second, QVector<int> &dist);


    //new methods not in original assignment
    /*!
     * \brief fill
     *
     * Empties the graph
     * \param size
     * \param start
     * \param end
     * \param dist
     */
    void fill(int size, QVector<int> &start, QVector<int> &end, QVector<int> &dist);



protected:
	//CALC - resets the vector of visited or unvisited node
	void resetVisited();
    /*!
     * \brief minDistance
     * \param dist
     * \param sptSet
     * \return
     */
    int minDistance(QVector<int> dist, QVector<bool> sptSet);
    /*!
     * \brief minKey
     * \param key
     * \param mstSet
     * \return
     */
	int minKey(vector<int> key, vector<bool> mstSet);




private:


    QVector< QVector<int> > matrix;	//CALC - contains edges of vertices
	//AdjacencyMatrix mapMatrix; //CALC - matrix of vertices and edges
	vector<int> visitedDFS;	   //CALC - vector of visited/unvisited nodes
	vector<int> visitedBFS;	   //CALC - vector of visited/unvisited nodes
	vector<int> dfsList;	   //CALC - List of vertices by DFS
	vector<int> bfsList;	  //CALC - matrix of vertices by BFS
	float totalDistance;	  //CALC - total distance traveled

    int size;
};

#endif /* GRAPH_H_ */
