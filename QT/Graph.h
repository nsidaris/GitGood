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

/*!
   * \file Graph.h
   * \brief  Header for graph class
   *
   * This file contains all of the declarations of the graph class
   */

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
/*!
   * \brief NumberToString:NOT USED
   *
   * Casts a numeric type to a string
   * \param Number
   * \return string representation of the number
   */
  string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }


  /*!
 * \brief The status enum: NOT USED
 *
 * Used for the BFS AND DFS
 */
enum status
{
	NOT_VISITED,
	VISITED
};


/*!
 * \brief The Graph class
 *
 * This class represents a graph with the adjacency matrix
 */
class Graph {
public:
	//Constructor
    /*!
     * \brief Graph
     *
     *
     */
	Graph();

	//Destructor
	virtual ~Graph();

	//Returns a list of incident edges
    /*!
     * \brief incidentEdges
     *
     * Gets incident edges for a vertex
     * \param vertex
     * \return 2d vector of edges
     */
	vector< vector< int > > incidentEdges(int vertex);

	//Checks whether there is an edge between vertices passed in
    /*!
     * \brief IsAdjacentTo
     *
     * Checks if 2 vertices are adjecent
     * \param vertex1
     * \param vertex2
     * \return T/F if they are adjacent
     */
	bool IsAdjacentTo(int vertex1, int vertex2);

	//Traverses through list using DFS algorithm
    /*!
     * \brief DFS: NOT USED
     *
     * Performs a Depth First Search from startingVertex
     * \param startingVertex source
     * \return list in order of DFS
     */
	vector<int> DFS(int startingVertex);

	//returns multi-dimension vector of levels, each level contains the cities that are at that level

    /*!
     * \brief BFS: NOT USED
     *
     * Performs a breadth first search on the graph from startingVertex
     * \param startingVertex
     * \return list order in BFS
     */
	vector< int > BFS(int startingVertex);

	//CALC - returns the total distance traveled by DFS or BFS
    /*!
     * \brief GetTotalDistanceTraveled: NOT USED
     *
     * Returns total distance for DFS and BFS
     * \return
     */
	float GetTotalDistanceTraveled() const;

    /*!
     * \brief Dijkstra
     *
     * Determines efficient order from a source using dijkstra's algorithm
     *
     * Based on this: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
     * \param src
     * \param dist
     * \param dijkstraList
     */
    void Dijkstra(int src, QVector<int> &dist, QVector<int> &dijkstraList);



    /*!
     * \brief MST
     *
     * Finds the minimun spanning tree for the graph
     * \param distTraveled total cost
     * \param first  first edge
     * \param second second edge
     * \param dist   costs
     */
    void MST(int &distTraveled, QVector<int> &first, QVector<int> &second, QVector<int> &dist);


    //new methods not in original assignment
    /*!
     * \brief fill
     *
     * Empties the graph and refills it. Called at start of the program and whenever Las Vegas is added
     * \param size Number of items
     * \param start front edges
     * \param end back edges
     * \param dist costs
     */
    void fill(int size, QVector<int> &start, QVector<int> &end, QVector<int> &dist);



protected:
	//CALC - resets the vector of visited or unvisited node

    /*!
     * \brief resetVisited:DEPRECATED
     */
	void resetVisited();
    /*!
     * \brief minDistance
     *
     * Finds next item for Dijkstra
     * \param dist distance
     * \param sptSet set of visisted
     * \return
     */
    int minDistance(QVector<int> dist, QVector<bool> sptSet);
    /*!
     * \brief minKey
     *
     * Finds the next item for MST
     * \param key list to check
     * \param mstSet set of visited
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
