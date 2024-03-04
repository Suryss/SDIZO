#pragma once
#include <string>
class Heap
{
	//Wska�nik na pocz�tek tablicy przechowuj�cej dane kopca
	int* heap = NULL;
	//Rozmiar kopca
	int heapSize = 0;

	//kopcowanie w d�
	void heapifyDown(int i);

	//kopcowanie w g�r�
	void heapifyUp(int i);
public:
	//Wczytuje dane do kopca
	//Jako arhumenty przyjmuje nazw� pliku, oraz wybur algorytmu do budowy kopca
	//true - Algorytm Floyda, false - standardowe budowanie
	void loadData(std::string filename, bool choose);

	//wy�wietlenie kopca jako tablicy
	void showHeapArray();

	//wy�wietlenie Kopca - gotowiec z internetu z drobnymi modyfikacjami
	//pierwsze wywo�anie - showHeap("", "", 0)
	void showHeap(std::string sp, std::string sn, int v);

	//budowa kopca
	void buildHeap();

	//usuwanie
	void pop();

	//dodawanie
	void push(int number);

	//wyszukiwanie
	int find(int number);

	//Algorytm Floyda do budowy kopca
	void floyd(int i);
};

