#pragma once
#include <string>
class Heap
{
	//WskaŸnik na pocz¹tek tablicy przechowuj¹cej dane kopca
	int** heap = NULL;
	//Rozmiar kopca
	int heapSize = 0;

	//kopcowanie w dó³
	void heapifyDown(int i);

	//kopcowanie w górê
	void heapifyUp(int i);
public:
	//wyœwietlenie kopca jako tablicy
	void showHeapArray();

	//usuwanie
	int pop();

	//dodawanie
	void push(int vertice, int start);

	void pushForKruskal(int edge, int value);

	//wyszukiwanie ze zmian¹ wartoœci
	void findAndChange(int vertice, int valueOfEdge);

	//Algorytm Floyda do budowy kopca
	void floyd();

	//Sprawdzenie czy nie jest pusty
	bool noEmpty();

	//Wyszukiwanie
	bool find(int vertice);

	//pobieranie kluczza
	int getKey(int vertice);
};

