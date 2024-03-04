#pragma once
#include <string>
class Heap
{
	//WskaŸnik na pocz¹tek tablicy przechowuj¹cej dane kopca
	int* heap = NULL;
	//Rozmiar kopca
	int heapSize = 0;

	//kopcowanie w dó³
	void heapifyDown(int i);

	//kopcowanie w górê
	void heapifyUp(int i);
public:
	//Wczytuje dane do kopca
	//Jako arhumenty przyjmuje nazwê pliku, oraz wybur algorytmu do budowy kopca
	//true - Algorytm Floyda, false - standardowe budowanie
	void loadData(std::string filename, bool choose);

	//wyœwietlenie kopca jako tablicy
	void showHeapArray();

	//wyœwietlenie Kopca - gotowiec z internetu z drobnymi modyfikacjami
	//pierwsze wywo³anie - showHeap("", "", 0)
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

