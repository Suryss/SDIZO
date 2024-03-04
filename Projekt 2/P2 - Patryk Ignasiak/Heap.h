#pragma once
#include <string>
class Heap
{
	//Wska�nik na pocz�tek tablicy przechowuj�cej dane kopca
	int** heap = NULL;
	//Rozmiar kopca
	int heapSize = 0;

	//kopcowanie w d�
	void heapifyDown(int i);

	//kopcowanie w g�r�
	void heapifyUp(int i);
public:
	//wy�wietlenie kopca jako tablicy
	void showHeapArray();

	//usuwanie
	int pop();

	//dodawanie
	void push(int vertice, int start);

	void pushForKruskal(int edge, int value);

	//wyszukiwanie ze zmian� warto�ci
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

