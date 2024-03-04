#pragma once
#include "List.h"
#include "Graph.h"
class ShortestPath
{
	//�cie�ka do wierzcho�ka
	List** path = NULL;
	//dystans do wierzcho�ka
	int* distances = NULL;
	//Liczba wierzcho�k�w
	int countOfVertices = 0;

	//czy jest cykl ujemny
	bool circle = false;

	//tworzy miejsce do przechowywania naszych �cie�ek
	//oraz wype�nia je danymi
	void createMemory(int** sPath, int start);

	//Sprawdza czy wyst�pi�y cykle ujemne
	void isCircle(int** sPath, Graph* graph);
	
public:
	//Wy�wietla wyniki
	void showResult();

	//Algorytm Dijkstry na macierzy
	void dijkstraOnMatrix(Graph* graph);

	//Algorytm Dijkstry na li�cie
	void dijkstraOnList(Graph* graph);

	//Algorytm Bellmana-Forda na macierzy
	void bellmanFordOnMatrix(Graph* graph);

	//Algorytm Bellmana-Forda na li�cie
	void bellmanFordOnList(Graph* graph);

};

