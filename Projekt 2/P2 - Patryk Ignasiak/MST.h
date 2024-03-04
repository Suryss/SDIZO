#pragma once
#include <cstddef>
#include "Graph.h"
class MST
{
	//Lista krawêdzi
	int** mstEdges = NULL;
	
	//Liczba krawêdzie
	int countOfEdges = 0;

	//Dodawanie krawêdzi do listy krawêdzi
	void createListOfEdges(int** connectedVertices);

	//Znajduje set
	int findSet(int** groups, int x);

	//£¹czy sety
	void unionSets(int** groups, int u, int v);
	
public:
	//Wyœwietlanie 
	void showResult();

	//Algorytm Prima dla macierzy s¹siedztwa
	void primOnMatrix(Graph* graph);

	//Algorytm Prima dla listy s¹siadów
	void primOnList(Graph* graph);
	
	//Algorytm Kruskala dla macierzy s¹siedztwa
	void kruskalOnMatrix(Graph* graph);

	//Algorytm Kruskala dla macierzy s¹siedztwa
	void kruskalOnList(Graph* graph);
	
};

