/* maze.h -----------------------------------------------------------
authors: Alfredo Antolinez, Anthony Rodriguez, Christian A. Rodriguez
Header file of the class library for the class maze
-------------------------------------------------------------------*/

#ifndef MAZE_H_
#define MAZE_H_

#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Function/Class Declarations
template <class T>

class Maze {
private:
	/* "Head nodes" of adjacency lists */
	class VertexInfo {
	public:
		T data;
		vector<int> adjacencyLists;
	};

public:
   /* Function Members */
   Maze(const int);
   /*----------------------------------------------------------------
   Purpose: Take in the size of the grid.
   Precondition: None.
   Postcondition: Size of grid is set as global variable.
   ----------------------------------------------------------------*/

   void depthFirstSearch();
   /*----------------------------------------------------------------
   Purpose: DFS of maze via depthFirstSearchAux().
   Precondition: None.
   Postcondition: Maze is searched via DFS.
   ----------------------------------------------------------------*/

   void breadthFirstSearch();
   /*----------------------------------------------------------------
   Purpose: BFS of a maze.
   Precondition: None.
   Postcondition: Maze is searched via BFS.
   ----------------------------------------------------------------*/

   void dijkstrasAlgorithm();
   /*----------------------------------------------------------------
   Purpose: Shortest Path Search of a maze.
   Precondition: None.
   Postcondition: The shortest path of a maze (if it exists) is 
   searched.
   ----------------------------------------------------------------*/

   void directionHelper(stack<int>&);
   /*----------------------------------------------------------------
   Purpose: Prints out Anthony Rodriguez BFS Algorithm file.
   Precondition: An organized path of the maze that is indicated by 
   the indices of the maze from the BFS algorithm; indices are 
   converted to directions.
   Postcondition: Opens the path in a directional manner.
   ----------------------------------------------------------------*/
   void directionHelper1(stack<int>&);
   /*----------------------------------------------------------------
   Purpose: Prints out Alfredo Antolinez DFS Algorithm file.
   Precondition: An organized path of the maze that is indicated by
   the indices of the maze from the DFS algorithm; indices are
   converted to directions.
   Postcondition: Opens the path in a directional manner.
   ----------------------------------------------------------------*/
   void directionHelper2(stack<int>&);
   /*----------------------------------------------------------------
   Purpose: Prints out Christian Rodriguez Dijkstra's Algorithm file.
   Precondition: An organized path of the maze that is indicated by
   the indices of the maze from the Dijkstra's algorithm; indices are
   converted to directions.
   Postcondition: Opens the path in a directional manner.
   ----------------------------------------------------------------*/
   void outputAdjacency(int);
   /*----------------------------------------------------------------
   Purpose: Output adjacency list.
   Precondition: Location.
   Postcondition: Prints out all appropriate adjacency lists.
   ----------------------------------------------------------------*/
   void addAdjacency(int);
   /*----------------------------------------------------------------
   Purpose: Creates adjacency list.
   Precondition: Location.
   Postcondition: Items are placed into adjacency list one at a time.
   ----------------------------------------------------------------*/
   void read(ifstream &);
   /*----------------------------------------------------------------
   Purpose: Read data from input file.
   Precondition: Existing input file.
   Postcondition: All items are read one at a time.
   ----------------------------------------------------------------*/
   void copyData(int);
   /*----------------------------------------------------------------
   Purpose: Copies data from input file.
   Precondition: Location.
   Postcondition: Input data is copied.
   ----------------------------------------------------------------*/
   void output(int);
   /*----------------------------------------------------------------
   Purpose: Output data.
   Precondition: Location.
   Postcondition: Data is output.
   ----------------------------------------------------------------*/
private:
	/* Data Members */
	vector<VertexInfo> myAdjacencyLists;
	int gridSize;

	
	/* Private Function Member */
	void depthFirstSearchAux(int, int, vector<string>&, vector<int>&,
		vector<int>&, vector<int>&);
	/*----------------------------------------------------------------
	Purpose: Recursive DFS maze.
	Precondition: start is a vertex; unvisited[i] is true if vertex i 
	has not et been visited, and is false otherwise.
	Postcondition: Vector unvisited has become updated.
	----------------------------------------------------------------*/
};

// Function/Class Implementations
template <class T>
Maze<T>::Maze(const int size) {
	gridSize = size;

}

template <class T>
void Maze<T>::read(ifstream & inFile) {
	VertexInfo head;
	inFile >> head.data;
	myAdjacencyLists.push_back(head);
}

template <class T>
void Maze<T>::copyData(int location) {
	VertexInfo temp;
	temp.data = myAdjacencyLists[location].data;
	myAdjacencyLists.push_back(temp);
}

template <class T>
void Maze<T>::output(int location) {
	cout << myAdjacencyLists[location].data << " ";
}

template <class T>
void Maze<T>::outputAdjacency(int location) {
	for (vector<int>::iterator it = myAdjacencyLists[location].adjacencyLists.begin(); 
		it != myAdjacencyLists[location].adjacencyLists.end(); it++) {
		int tmp = *it;
		
		if (it == (myAdjacencyLists[location].adjacencyLists.end() - 1)) {
			cout << tmp;
		}
		else {
			cout << tmp << " -> ";
		}
	}
}

// This function uses the vertices that are currently being looked at 
// to discover the vertices in which the maze can move to through 
//mathematical calculations.
template <class T>
void Maze<T>::addAdjacency(int location) {
	int gridSizeSquared = gridSize * gridSize;
	int n = location;
	int i = myAdjacencyLists[location].data;	// i = data in position

	if (i > 0) {
		if (location < gridSizeSquared) {
			// Perform horizontal/vertical adjacency
			int up = n - i * gridSize;
			int right = n + i;
			int down = n + i * gridSize;
			int left = n - i;

			// check up
			if (up >= 0)	{
				myAdjacencyLists[location].adjacencyLists.push_back(up);
			}
			// check right (newposition/3 > oldposition/3)
			if (right / gridSize <= n / gridSize) {
				myAdjacencyLists[location].adjacencyLists.push_back(right);
			}
			// check down
			if (down < gridSizeSquared) {
				myAdjacencyLists[location].adjacencyLists.push_back(down);
			}
			//check left aka: cereal
			if (left / gridSize == n / gridSize && left >= 0) {
				myAdjacencyLists[location].adjacencyLists.push_back(left);
			}

		}
		if (location >= gridSizeSquared){
			int up_left = n - i * (gridSize + 1);
			int up_right = n - i * (gridSize - 1);
			int down_right = n + i * (gridSize + 1);
			int down_left = n + i * (gridSize - 1);

			// check if northwest
			if ((up_left >= gridSizeSquared) && (up_left % gridSize <= n % gridSize)) {
				myAdjacencyLists[location].adjacencyLists.push_back(up_left);
			}
			//check if northeast
			if ((up_right >= gridSizeSquared) && (up_right % gridSize >= n % gridSize)) {
				myAdjacencyLists[location].adjacencyLists.push_back(up_right);
			}
			//check if southeast
			if ((down_right < (gridSizeSquared + gridSizeSquared) && (down_right % gridSize >= n % gridSize))) {
				myAdjacencyLists[location].adjacencyLists.push_back(down_right);
			}
			// check if southwest
			if ((down_left < (gridSizeSquared + gridSizeSquared) && (down_left % gridSize <= n % gridSize))) {
				myAdjacencyLists[location].adjacencyLists.push_back(down_left);
			}
		}

	}
	else{
		i = abs(i);

		int up = n - i * gridSize;
		int right = n + i;
		int down = n + i * gridSize;
		int left = n - i;
		if (location < gridSizeSquared){
			// check up
			if (up >= 0)	{
				myAdjacencyLists[location + gridSizeSquared].adjacencyLists.push_back(up);
			}
			// check right (newposition/3 > oldposition/3)
			if (right / gridSize <= n / gridSize) {
				myAdjacencyLists[location + gridSizeSquared].adjacencyLists.push_back(right);
			}
			// check down
			if (down < gridSizeSquared) {
				myAdjacencyLists[location + gridSizeSquared].adjacencyLists.push_back(down);
			}
			//check left
			if (left / gridSize == n / gridSize && left >= 0) {
				myAdjacencyLists[location + gridSizeSquared].adjacencyLists.push_back(left);
			}
		}
		// Perform diagonal adjacency
		int up_left = n - i * (gridSize + 1) + gridSizeSquared;
		int up_right = n - i * (gridSize - 1) + gridSizeSquared;
		int down_right = n + i * (gridSize + 1) + gridSizeSquared;
		int down_left = n + i * (gridSize - 1) + gridSizeSquared;
		if (location < gridSizeSquared){
			// check if northwest
			if ((up_left >= gridSizeSquared) && (up_left % gridSize <= n % gridSize)) {
				myAdjacencyLists[location].adjacencyLists.push_back(up_left);
			}
			//check if northeast
			if ((up_right >= gridSizeSquared) && (up_right % gridSize >= n % gridSize)) {
				myAdjacencyLists[location].adjacencyLists.push_back(up_right);
			}
			//check if southeast
			if ((down_right < (gridSizeSquared + gridSizeSquared) && (down_right % gridSize >= n % gridSize))) {
				myAdjacencyLists[location].adjacencyLists.push_back(down_right);
			}
			// check if southwest
			if ((down_left < (gridSizeSquared + gridSizeSquared) && (down_left % gridSize <= n % gridSize))) {
				myAdjacencyLists[location].adjacencyLists.push_back(down_left);
			}
		}
	}
}

template <class T>
void Maze<T>::breadthFirstSearch()
{
	int s = 0;	// Starting position 0
	int realSize = 2 * gridSize*gridSize;	// Adjacency List size
	vector<string> status;	// vector of statuses
	vector<int> parent;	// vector stores the location of vertices parents
	vector<int> distance;	// distance

	// Loop initializes all nodes as undiscovered originally
	for (int i = 0; i < realSize; i++)
	{
		status.push_back("undiscovered");
		parent.push_back(0);
		distance.push_back(-1);
	}

	status[s] = "discovered";	// mark starting node as discovered
	parent[s] = 0;	// marks parent node as parent of itself
	distance[s] = 0;	// marks distance 0

	queue<int> container;	// queue to hold vertices numbers
	queue<int> path;	
	container.push(s);
	path.push(s);
	int temp;	// temporary variable

	// traverses adjacency list to find the possible path
	while (!container.empty())
	{
		temp = container.front();
		container.pop();

		// loop to iterate through the possible adjacency edges
		for (vector<int>::iterator it = myAdjacencyLists[temp].adjacencyLists.begin();
			it != myAdjacencyLists[temp].adjacencyLists.end(); it++)
		{
			int i = *it;
			// discoveres nodes still undiscovered
			if (status[i] == "undiscovered")
			{
				status[i] = "discovered";
				distance[i] = distance[temp] + 1;
				parent[i] = temp;
				container.push(i);
				path.push(i);
			}
		}
		status[temp] = "processed";
	}

	// loop pushes resulting path into stack to display later
	stack<int> content;
	for (unsigned int i = gridSize*gridSize - 1; i != 0;)
	{
		if (i == gridSize*gridSize - 1)
			content.push(i);

		content.push(parent[i]);
		i = parent[i];
	}
	directionHelper(content);	// output file

}

template <class T>
void Maze<T>::directionHelper(stack<int>& content)
{
	ofstream output;
	output.open("RodriguezAnthony.txt", ios::app);	
	output << endl;
	if( output.is_open()){
	int temp1, temp2, temp3;
	temp2 = content.top();
	content.pop();
   while(!content.empty()){
	temp1 = temp2;
	temp2 = content.top();
	content.pop();
	
	//cout << " Current Numbers: " << temp1 << " " << temp2 ; 
	if(temp2 % gridSize == temp1 % gridSize){
		if( temp2/gridSize > temp1/gridSize)
		{
			output << "S ";
		}
		else 
			output << "N ";
	}
	if(temp2 /gridSize == temp1 /gridSize){
		if ( temp2 % gridSize > temp1 % gridSize)
		{
			output << "E ";
		}
		else
			output << "W ";
	} 
	if( temp2 / gridSize != temp1 / gridSize && temp2 % gridSize != temp1 % gridSize){
		if ( temp2 / gridSize > temp1 / gridSize){ //downleft or downright
			if ( temp2 % gridSize >	temp1 % gridSize){
				output << "SE ";
			}
			else
				output << "SW ";
		}
		else // upleft or upright
		{
			if ( temp2 % gridSize < temp1% gridSize){
				output << "NE " ;
			}
			else
				output << "NW ";
		}
	}

	}
	output << endl;
	}
}

template <class T>
void Maze<T>::directionHelper1(stack<int>& content)
{

	ofstream output;
	output.open("AntolinezAlfredo.txt", ios::app);	
	output << endl;
	if( output.is_open()){
	int temp1, temp2, temp3;
	temp2 = content.top();
	content.pop();
   while(!content.empty()){
	temp1 = temp2;
	temp2 = content.top();
	content.pop();
	
	//cout << " Current Numbers: " << temp1 << " " << temp2 ; 
	if(temp2 % gridSize == temp1 % gridSize){
		if( temp2/gridSize > temp1/gridSize)
		{
			output << "S ";
		}
		else 
			output << "N ";
	}
	if(temp2 /gridSize == temp1 /gridSize){
		if ( temp2 % gridSize > temp1 % gridSize)
		{
			output << "E ";
		}
		else
			output << "W ";
	} 
	if( temp2 / gridSize != temp1 / gridSize && temp2 % gridSize != temp1 % gridSize){
		if ( temp2 / gridSize > temp1 / gridSize){ //downleft or downright
			if ( temp2 % gridSize >	temp1 % gridSize){
				output << "SE ";
			}
			else
				output << "SW ";
		}
		else // upleft or upright
		{
			if ( temp2 % gridSize < temp1% gridSize){
				output << "NE " ;
			}
			else
				output << "NW ";
		}
	}

	}
	output << endl;
	}
}

template <class T>
void Maze<T>::directionHelper2(stack<int>& content)
{

	ofstream output;
	output.open("RodriguezChristian.txt", ios::app);	
	output << endl;
	if( output.is_open()){
	int temp1, temp2, temp3;
	temp2 = content.top();
	content.pop();
   while(!content.empty()){
	temp1 = temp2;
	temp2 = content.top();
	content.pop();
	
	//cout << " Current Numbers: " << temp1 << " " << temp2 ; 
	if(temp2 % gridSize == temp1 % gridSize){
		if( temp2/gridSize > temp1/gridSize)
		{
			output << "S ";
		}
		else 
			output << "N ";
	}
	if(temp2 /gridSize == temp1 /gridSize){
		if ( temp2 % gridSize > temp1 % gridSize)
		{
			output << "E ";
		}
		else
			output << "W ";
	} 
	if( temp2 / gridSize != temp1 / gridSize && temp2 % gridSize != temp1 % gridSize){
		if ( temp2 / gridSize > temp1 / gridSize){ //downleft or downright
			if ( temp2 % gridSize >	temp1 % gridSize){
				output << "SE ";
			}
			else
				output << "SW ";
		}
		else // upleft or upright
		{
			if ( temp2 % gridSize < temp1% gridSize){
				output << "NE " ;
			}
			else
				output << "NW ";
		}
	}

	}
	output << endl;
	}
}


template <class T>
void Maze<T>::depthFirstSearch()
{
	int realSize = 2 * gridSize*gridSize;	// adjacency list size
	vector<string> status;	// vector of statuses
	vector<int> parent;		// vector of parents
	vector<int> distance;	// vector of distances
	vector<int> f;			// vector of f's given
	int time;				// time

	// initializes all vertices to undiscovered
	for (int i = 0; i < realSize; i++)
	{
		status.push_back("undiscovered");
		parent.push_back(0);
		f.push_back(0);
		distance.push_back(-1);
	}

	time = 0;	// sets time to 0

	// loops through several instances of recursive DFS
	for (int i = 0; i < realSize; i++)
	{
		if (status[i] == "undiscovered")
		{
			depthFirstSearchAux(i, time, status, parent, distance, f);
		}
	}

	// iterates loop to push search results into stack
	stack<int> content;
	for (unsigned int i = gridSize*gridSize - 1; i != 0;)
	{
		if (i == gridSize*gridSize - 1)
			content.push(i);

		content.push(parent[i]);
		i = parent[i];
	}

	directionHelper1(content);	// output file
	
}

template <class T>
void Maze<T>::depthFirstSearchAux(int current, int time, vector<string>& status, vector<int>& parent,
	vector<int>& distance, vector<int>& f)
{
	status[current] = "discovered";	// 
	time = time + 1;	// increment time by 1
	distance[current] = time;	// set time to current distance

	// iterates through adjacency list to set status as undiscovered
	for (vector<int>::iterator it = myAdjacencyLists[current].adjacencyLists.begin();
		it != myAdjacencyLists[current].adjacencyLists.end(); it++)
	{
		int i = *it;
		if (status[i] == "undiscovered")
		{
			parent[i] = current;
			depthFirstSearchAux(i, time, status, parent, distance, f);
		}
	}
	status[current] = "processed";	// set status as processed
	time = time + 1;

	f[current] = time;
}

template <class T>
void Maze<T>::dijkstrasAlgorithm() {
	int start = 0;									// Start of Maze
	int destination = myAdjacencyLists.size() - 1;	// End of Maze
	int vertices = myAdjacencyLists.size();	// Number of vertices
	vector<int> distLabel(vertices, -1);	// distance labels for vertices
	vector<int> predLabel(vertices);		// predecessor labels for vertices


	distLabel[start] = 0;		// labeling 0 as start
	int distance = 0;			// distance from start of vertex
	int vertex;					// a vertex

	queue<int> vertexQueue;		// queue of vertices
	vertexQueue.push(start);	// pushing start into the queue 

	stack<int> content;			// stack to contain results

	// loop if label is below 0 and queue is not empty
	while (distLabel[destination] < 0 && !vertexQueue.empty()) {
		vertex = vertexQueue.front();	// store queue contents into vertex
		vertexQueue.pop();				// pop queue contents
		// check if distance label is greater than distance
		if (distLabel[vertex] > distance)
			distance++;	// increment distance
		// iterate through the myAdjacencyLists
		for (vector<int>::iterator it = myAdjacencyLists[vertex].adjacencyLists.begin();
			it != myAdjacencyLists[vertex].adjacencyLists.end(); it++) {
			// check if the distance label is less than 0
			if (distLabel[*it] < 0) {
				distLabel[*it] = distance + 1;	// insert distance + 1 into distance label
				predLabel[*it] = vertex;		// insert vertex into predecessor label
				vertexQueue.push(*it);			// push *it into the queue
			}
		}
		distance++;	// increment distance
		
		// Reconstruct shortest path
		vector<int> path(distance + 1);		// path of vector type
		// check if distance label is greater than equal to zero
		if (distLabel[destination] >= 0) {
			path[distance] = destination;	// insert destination into path
			// iterate through the distance
			for (int k = distance - 1; k >= 0; k--) {
				path[k] = predLabel[path[k + 1]];	// set path equal to the predecessor label
				content.push(path[k]);	// push path into content stack
				//cout << path[k] << " ";
				// break if reached 0
				if (path[k] == 0)
					break;
			}
		}
	}
	directionHelper2(content);
}

#endif /* MAZE_H_ */
