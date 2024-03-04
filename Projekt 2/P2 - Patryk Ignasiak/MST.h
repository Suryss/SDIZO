#pragma once
#include <cstddef>
#include "Graph.h"
class MST
{
	//Lista kraw�dzi
	int** mstEdges = NULL;
	
	//Liczba kraw�dzie
	int countOfEdges = 0;

	//Dodawanie kraw�dzi do listy kraw�dzi
	void createListOfEdges(int** connectedVertices);

	//Znajduje set
	int findSet(int** groups, int x);

	//��czy sety
	void unionSets(int** groups, int u, int v);
	
public:
	//Wy�wietlanie 
	void showResult();

	//Algorytm Prima dla macierzy s�siedztwa
	void primOnMatrix(Graph* graph);

	//Algorytm Prima dla listy s�siad�w
	void primOnList(Graph* graph);
	
	//Algorytm Kruskala dla macierzy s�siedztwa
	void kruskalOnMatrix(Graph* graph);

	//Algorytm Kruskala dla macierzy s�siedztwa
	void kruskalOnList(Graph* graph);
	
};

