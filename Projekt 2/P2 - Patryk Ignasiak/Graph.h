#pragma once
#include "List.h"
#include <fstream>


class Graph
{
	//Niesko�czono��
	const int INF = INT32_MAX;
	
	//Odczyt lini z pliku
	bool fileReadLine(std::ifstream& file, int tab[], int size);

	//Tworzy macierz s�siedztwa
	void createMatrix();

	//Tworzy list� s�siad�w
	void createList();
public:
	//Liczba kraw�dzi
	int countOfEdges = 0;

	//Liczba wierzcho�k�w
	int countOfVertices = 0;

	//Wierzcho�ek pocz�tkowy
	int startVertice = 0;

	//Wierzcho�ek ko�cowy
	int endVertice = 0;

	//Macierz s�siad�w
	int** matrix = NULL;

	//Lista s�siad�wS
	List** list = NULL;

	//Odczyt danych z pliku
	void fileReadGraph(std::string fileName, bool isMST);
	
	//Wy�wietla macierz
	void showMatrix();
	
	//Wy�wietla list�
	void showList();

};

