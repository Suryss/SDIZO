#pragma once
#include "List.h"
#include "Graph.h"
class ShortestPath
{
	//œcie¿ka do wierzcho³ka
	List** path = NULL;
	//dystans do wierzcho³ka
	int* distances = NULL;
	//Liczba wierzcho³ków
	int countOfVertices = 0;

	//czy jest cykl ujemny
	bool circle = false;

	//tworzy miejsce do przechowywania naszych œcie¿ek
	//oraz wype³nia je danymi
	void createMemory(int** sPath, int start);

	//Sprawdza czy wyst¹pi³y cykle ujemne
	void isCircle(int** sPath, Graph* graph);
	
public:
	//Wyœwietla wyniki
	void showResult();

	//Algorytm Dijkstry na macierzy
	void dijkstraOnMatrix(Graph* graph);

	//Algorytm Dijkstry na liœcie
	void dijkstraOnList(Graph* graph);

	//Algorytm Bellmana-Forda na macierzy
	void bellmanFordOnMatrix(Graph* graph);

	//Algorytm Bellmana-Forda na liœcie
	void bellmanFordOnList(Graph* graph);

};

