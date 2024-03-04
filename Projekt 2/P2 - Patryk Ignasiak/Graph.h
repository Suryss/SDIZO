#pragma once
#include "List.h"
#include <fstream>


class Graph
{
	//Nieskoñczonoœæ
	const int INF = INT32_MAX;
	
	//Odczyt lini z pliku
	bool fileReadLine(std::ifstream& file, int tab[], int size);

	//Tworzy macierz s¹siedztwa
	void createMatrix();

	//Tworzy listê s¹siadów
	void createList();
public:
	//Liczba krawêdzi
	int countOfEdges = 0;

	//Liczba wierzcho³ków
	int countOfVertices = 0;

	//Wierzcho³ek pocz¹tkowy
	int startVertice = 0;

	//Wierzcho³ek koñcowy
	int endVertice = 0;

	//Macierz s¹siadów
	int** matrix = NULL;

	//Lista s¹siadówS
	List** list = NULL;

	//Odczyt danych z pliku
	void fileReadGraph(std::string fileName, bool isMST);
	
	//Wyœwietla macierz
	void showMatrix();
	
	//Wyœwietla listê
	void showList();

};

