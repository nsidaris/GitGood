/*************************************************************************
 * AUTHOR        : Nick Sidaris
 * STUDENT ID    : 385623
 * Assignment 10 : DFS and BFS
 * CLASS 		 : CS1D
 * SECTION 		 : M/W 4:30 - 5:20
 * DUE DATE 	 : 11/21/2016
 *************************************************************************/
#include "Graph.h"
#include<QDebug>

Graph::Graph()
{
	for(int i = 0; i < 12; i++)
	{
		visitedBFS.push_back(NOT_VISITED);
		visitedDFS.push_back(NOT_VISITED);
	}
	totalDistance = 0;

//	//PROCESSING - need to create a copy of the array because can't initialize
//		//				array in the header file.
//		int copy[12][12] =
//			{ {0,    381,  0,    1015, 0,    1663, 1435, 0,    0,   0,    0,   0}, //Los Angeles
//	  	    {381,  0,    807,  1267, 0,    0,    0,    0,    0,   0,    0,   0},
//		    {0,    807,  0,    1331, 2097, 0,    0,    0,    0,   0,    0,   0},
//		    {1015, 1267, 1331, 0,    1003, 599,  0,    0,    0,   0,    0,   0},
//		    {0,    0,    2097, 1003, 0,    533,  0,    0,    983, 787,  0,   0},
//		    {1663, 0,    0,    599,  533,  0,    496,  0,    0,   1260, 864, 0},
//			{1435, 0,    0,    0,    0,    496,  0,    239,  0,   0,    781, 0},
//			{0,    0,    0,    0,    0,    0,    239,  0,    0,   0,    810, 1187},
//			{0,    0,    0,    0,    983,  0,    0,    0,    0,   214,  0,   0},
//			{0,    0,    0,    0,    787,  1260, 0,    0,    214, 0,    888, 0},
//			{0,    0,    0,    0,     0,   864,  781,  810,  0,   888,  0,   661},
//			{0,    0,    0,    0,     0,   0,    0,    1187, 0,   0,    661, 0},
//		    };

//		vector<int> row;

//		//PROCESSING - copies values in copy array into private variable matrix
//		for(int i = 0; i < 12; i++)
//		{
//			for(int j = 0; j < 12; j++)
//			{
//				 row.push_back(copy[i][j]);
//			}
//			matrix.push_back(row);
//			row.clear();
//		}





}

Graph::~Graph()
{
	// TODO Auto-generated destructor stub
}

/******************************************************************************
 * incidentEdges(int vertex)
 * ----------------------------------------------------------------------------
 * Gets the matrix from adjacencyMatrix. Creates a vector for a list of edges
 * of the vertex passed in.
 * - returns a vector of edges
 *****************************************************************************/
vector< vector< int > > Graph::incidentEdges(int vertex)
{
	vector< vector<int> > edgeList;	//CACL - vector of edges
	vector<int>           city;
	vector<int>           edge;

	//CALC - matrix of all edges
	//vector< vector<int> > matrix = mapMatrix.GetMatrix();

	//PROCESSING - loops through the row of the vertex passed in of the matrix
	//				and pushes indexes greater than zero to edge list
	for(int i = 0; i < 12; i++)
	{
		//PROCESSING - if an index is greater than zero, pushes it to edgeList
		if(matrix[vertex][i] > 0)
		{
			//Pushes city to edge city list and edge to edgeList
			city.push_back(i);
			edge.push_back(matrix[vertex][i]);
		}
	}
	int j;		//CALC - second loop control variables
	int temp1;	//CALC - holds copy of value
	int temp2;  //CALC - holds copy of value

	//PROCESSING - insertion sort to sort the edgeList from least to greatest
	for(int index = 0; index < edge.size(); index++)
	{
		j = index;
		while(j > 0 && (edge[j] < edge[j - 1]) )
		{
			temp1 = edge[j];
			temp2 = city[j];

			edge[j] = edge[j-1];
			city[j] = city[j-1];

			edge[j-1] = temp1;
			city[j-1] = temp2;
			j--;
		}
	}

	//PROCESSING - pushes vector of cities to edgeList
	edgeList.push_back(city);

	//PROCESSING - pushes vector of edges to edgeList
	edgeList.push_back(edge);

	//PROCESSING - returns the edgeList
	return edgeList;
}

/******************************************************************************
 * IsAdjacentTo(int vertex1, int vertex2)
 * ----------------------------------------------------------------------------
 * Checks whether vertex2 is adjacent to vertex1
 ******************************************************************************/
bool Graph::IsAdjacentTo(int vertex1, int vertex2)
{
	//Vector that holds the matrix of the map
	//vector <vector<int> > matrix = mapMatrix.GetMatrix();

	//PROCESSING - checks if the index at row(vertex1) and  column(vertex 2) is
	//			greater than zero. If TRUE, returns TRUE
	if(matrix[vertex1][vertex2] > 0)
	{
		return true;
	}

	//PROCESSING - return FALSE if the index is zero
	return false;
}

/******************************************************************************
 * DFS(int startingVertex)
 * ----------------------------------------------------------------------------
 * Returns a list of vertices using DFS
 ******************************************************************************/
vector<int> Graph::DFS(int startingVertex)
{
	//CALC - list of edges to starting vertex
	vector< vector<int> > edgeList = incidentEdges(startingVertex);

	//PROCESSING - sets starting vector as visited
	visitedDFS[startingVertex] = VISITED;

	//PROCESSING - pushes starting vector to final DFS list
	dfsList.push_back(startingVertex);

	/**
	 * Loops through all cities in edge list
	 * 		-if city is already visited, moves to next city in list
	 * 		- if city is NOT visited, and there is an connecting edge,
	 * 		its recursively calls dfs to loop through those indices
	 */
	for(int city = 0; city < edgeList[1].size(); city++ )
	{
		//PROCESSING - calls DFS if the city is NOT visited and there is a
		//				connecting edge
		if(visitedDFS[ edgeList[0][city] ] == NOT_VISITED &&
				matrix[startingVertex][edgeList[0][city]] > 0)
		{
			//PROCESSING - sets total distance and recursively calls DFS
			totalDistance += matrix[startingVertex][edgeList[0][city]];
			DFS(edgeList[0][city]);
		}
	}

	return dfsList;
}

/******************************************************************************
 * resetVisited()
 * ----------------------------------------------------------------------------
 * resets the vector of visited or unvisited node
 ******************************************************************************/
void Graph::resetVisited()
{
	//	cerr << "start\n";
	//	int size = visited.size();
	//	for(int i = 0; i < size; i++)
	//	{
	//		visited.pop_back();
	//	}
	//	//PROCESSING - sets visisted vector to not visited
	//		for(int i = 0; i < 12; i++)
	//		{
	//			visited.push_back(NOT_VISITED);
	//		}
	//		cerr << "end\n";
}

/******************************************************************************
 * BFS(int startingVertex)
 * ----------------------------------------------------------------------------
 * returns a vector of vectors with each level having vertexes of a certain level
 ******************************************************************************/
vector<int> Graph::BFS(int startingVertex)
{
	totalDistance = 0;

	vector< vector<int> > edgeList;
	queue<int> queueTemp;

	queueTemp.push(startingVertex);
	visitedBFS[startingVertex] = VISITED;

	//algorithm from the slides on BFS
	while(!queueTemp.empty())
	{
		int front = queueTemp.front();

		bfsList.push_back(front);
		queueTemp.pop();

		//PROCESSING - Gets edge list with front of queuetemp
		edgeList = incidentEdges(front);

		for(int k = 0; k < edgeList[0].size(); k++)
		{
			if(visitedBFS[edgeList[0][k]] == NOT_VISITED)
			{
				visitedBFS[edgeList[0][k]] = VISITED;
				totalDistance += matrix[front][edgeList[0][k]];
				queueTemp.push(edgeList[0][k]);
			}
		}
	}

	return bfsList;
}

/******************************************************************************
 * GetTotalDistanceTraveled() const
 * ----------------------------------------------------------------------------
 * Returns the total distance traveled from the search
 ******************************************************************************/
float Graph::GetTotalDistanceTraveled() const
{
	return totalDistance;
}

int Graph::minDistance(QVector<int> dist, QVector<bool> sptSet)
{
	const int INTMAX = 99999;
	// Initialize min value
	int min = INTMAX;
	int min_index = 0;

    for (int v = 0; v < size; v++)
		if (sptSet[v] == false && dist[v] <= min)
		{
			min = dist[v], min_index = v;

		}



	return min_index;
}




void Graph::Dijkstra(int src, QVector<int> &dist, QVector<int> &dijkstraList)
{

	//vector< vector<int> > graph = mapMatrix.GetMatrix();

	//vector<int> dist;
    QVector<bool> sptSet;


	const int INTMAX = 99999;

	//cin.get();
	// Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < size; i++)
	{
		dist.push_back(INTMAX);
		sptSet.push_back(false); // = false;
	}



	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// cin.get();
	// Find shortest path for all vertices
    for (int count = 0; count < size-1; count++)
	{
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < size; v++)
		{
			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to  v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && matrix[u][v] && dist[u] != INT_MAX
					&& dist[u]+matrix[u][v] < dist[v])
			{
				dist[v] = dist[u] + matrix[u][v];

			}

		}


	}


	//vector<int> dijkstraList;
    for(int i = 0; i < size; i++)
	{
		dijkstraList.push_back(i);
	}

	int j;		//CALC - second loop control variables
	int temp1;	//CALC - holds copy of value
	int temp2;  //CALC - holds copy of value

	//PROCESSING - insertion sort to sort the edgeList from least to greatest
	for(int index = 0; index < dist.size(); index++)
	{
		j = index;
		while(j > 0 && (dist[j] < dist[j - 1]) )
		{
			temp1 = dist[j];
			temp2 = dijkstraList[j];

			dist[j] = dist[j-1];
			dijkstraList[j] = dijkstraList[j-1];

			dist[j-1] = temp1;
			dijkstraList[j-1] = temp2;
			j--;
		}
	}


}
void Graph::MST(int &distTraveled, QVector<int> &first, QVector<int> &second, QVector<int> &dist)
{
	const int INTMAX = 99999;
	//int parent[V]; // Array to store constructed MST
	vector<int> parent;
	//int key[V]; // Key values used to pick minimum weight edge in cut
	vector<int> key;
	//bool mstSet[V]; // To represent set of vertices not yet included in MST
	vector<bool> mstSet;
	//vector< vector<int> > graph = mapMatrix.GetMatrix();




	//cin.get();
	// Initialize all keys as INFINITE
    for (int i = 0; i < size; i++)
	{
		key.push_back(INTMAX);
		parent.push_back(0);
		mstSet.push_back(false);
	}
	//key[i] = INT_MAX, mstSet[i] = false;

	// Always include first 1st vertex in MST.
	key[0] = 0;	 // Make key 0 so that this vertex is picked as first vertex
	parent.push_back(-1); // = -1; // First node is always root of MST

	//cin.get();
	// The MST will have V vertices
    for (int count = 0; count < size-1; count++)
	{
		// Pick the minimum key vertex from the set of vertices
		// not yet included in MST
		int u = minKey(key, mstSet);

		// Add the picked vertex to the MST Set
		mstSet[u] = true;

		// Update key value and parent index of the adjacent vertices of
		// the picked vertex. Consider only those vertices which are not yet
		// included in MST
        for (int v = 0; v < size; v++)

			// graph[u][v] is non zero only for adjacent vertices of m
			// mstSet[v] is false for vertices not yet included in MST
			// Update the key only if graph[u][v] is smaller than key[v]
			if (matrix[u][v] && mstSet[v] == false && matrix[u][v] < key[v])
			{
				parent[v] = u;
				//parent.push_back(u);
				key[v] = matrix[u][v];
			}
	}

	distTraveled = 0;

    for(int i = 0; i < size; i++)
	{
		//cout << "here";
        //toAdd = printCity(parent[i]) + " - " + printCity(i) + " Weight: " + NumberToString(matrix[i][parent[i]]) +"";
		//cout << toAdd << endl;
    //	mstList.push_back(toAdd);

        first.push_back(parent[i]);
        second.push_back(i);
        dist.push_back(matrix[i][parent[i]]);

		distTraveled += matrix[i][parent[i]];
	}






	//printMST(parent, 12, graph);
}





int Graph::minKey(vector<int> key, vector<bool> mstSet)
{
	const int INTMAX = 99999;

	// Initialize min value
	int min = INTMAX, min_index;

    for (int v = 0; v < size; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}


void Graph::fill(int size, QVector<int> &start, QVector<int> &end, QVector<int> &dist)
{
    matrix.clear(); //clear it out

    this->size = size;
    vector<int> row;

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
             row.push_back(0);
        }
        matrix.push_back(row);
        row.clear();
    }

   // qDebug() << size;



    for(int i = 0; i < start.size(); i++)
    {

        matrix[start[i]-1][end[i]-1] = dist[i];
        matrix[end[i]-1][start[i]-1] = dist[i]; //make the edge work both ways
    }





}
