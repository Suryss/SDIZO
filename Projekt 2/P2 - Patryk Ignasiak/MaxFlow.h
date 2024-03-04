#pragma once
#include "Graph.h"
class MaxFlow
{
	//Maksymalny przep³yw
	int maxFlow = 0;

	//Liczba wierzcho³ków
	int countOfVertices = 0;

	//Liczba krawêdzi
	int countOfEdges = 0;

	//Graf rezuidalny
	int** rGraph;

	//Tworzenie grafu z macierzy
	int** createRGraphFromMatrix(int** matrix);

	//tworzenie grafu z listy
	int** createRGraphFromList(List** matrix);

	//Sprawdzenie czy s¹ jeszcze œcie¿ki i generowanie jej za pomoc¹ DFS
	bool isPath(int** rGraph, int start, int end, int* parent);
public:

	//Algorytm
	void fordFulkerson(Graph* graph, bool onMatrix);

	//Wyœwietlenie wyników
	void showResult();

};

