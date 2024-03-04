#pragma once
#include "Graph.h"
class MaxFlow
{
	//Maksymalny przep�yw
	int maxFlow = 0;

	//Liczba wierzcho�k�w
	int countOfVertices = 0;

	//Liczba kraw�dzi
	int countOfEdges = 0;

	//Graf rezuidalny
	int** rGraph;

	//Tworzenie grafu z macierzy
	int** createRGraphFromMatrix(int** matrix);

	//tworzenie grafu z listy
	int** createRGraphFromList(List** matrix);

	//Sprawdzenie czy s� jeszcze �cie�ki i generowanie jej za pomoc� DFS
	bool isPath(int** rGraph, int start, int end, int* parent);
public:

	//Algorytm
	void fordFulkerson(Graph* graph, bool onMatrix);

	//Wy�wietlenie wynik�w
	void showResult();

};

