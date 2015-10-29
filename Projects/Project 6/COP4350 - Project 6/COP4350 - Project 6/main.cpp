/* maze.h -----------------------------------------------------------
authors: Alfredo Antolinez, Anthony Rodriguez, Christian A. Rodriguez
Main file of the class library for the class maze
-------------------------------------------------------------------*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "maze.h"
#include<iomanip>

using namespace std;

int main() {
	ifstream inFile;
	ofstream outFile;

	inFile.open("input.txt");

	if (!inFile) {
		cerr << "The file could not be opened";

		return -1;
	}

	int instances = 0;
	inFile >> instances;

	vector< Maze<int> > object;
	object.reserve(instances);

	for (int i = 0; i < instances; i++) {
		int gridSize = 0;
		inFile >> gridSize;

		object.push_back(Maze<int>(gridSize));

		for (int j = 0; j < gridSize * gridSize; j++) {
			object[i].read(inFile);
		}
		cout << "\n" << "Object Number " << i << "\nAdjacency List" << endl;

		for (int j = 0; j < gridSize * gridSize; j++) {
			object[i].copyData(j);
		}

		for (int j = 0; j < 2 * gridSize * gridSize; j++) {
			object[i].addAdjacency(j);
		}

		for (int j = 0; j < 2 * gridSize * gridSize; j++) {
			cout << "Vertex " << j << ": ";
			object[i].outputAdjacency(j);
			cout << endl;
		}
		
		ofstream output;
		output.open("RodriguezAnthony", ios::app);
		cout << "RodriguezAnthony File Opened for writing." << endl;
		output << endl;
		output << "BreadthFirstSearch for Object " << i << ": " << endl;
		object[i].breadthFirstSearch();
		output.close();
		cout << "RodriguezAnthony File Closed for writing." << endl;
		output.open("AntolinezAlfredo", ios::app);
		cout << "AntolinezAlfredo File Opened for writing." << endl;
		output << endl;
		output << "DepthFirstSearch for Object " << i << ": " << endl;
		object[i].depthFirstSearch();
		output.close();
		cout << "AntolinezAlfredo File Closed for writing." << endl;
		output.open("RodriguezChristian", ios::app);
		cout << "RodriguezChristian File Opened for writing." << endl;
		output << endl;
		output << "Dijkstra's Algorithm for Object " << i << ": " << endl;
		object[i].dijkstrasAlgorithm();
		output.close();
		cout << "RodriguezChristian File Closed for writing." << endl;
	}

	cin.ignore();
	return 0;
}
