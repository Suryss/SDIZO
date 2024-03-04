#pragma once
#include <string>
class Array
{
	//WskaŸnik na pocz¹tek tablicy
	int* array = NULL; 
	//Rozmiar tablicy
	int size = 0;
public:
	//Dodaje dane z pliku do tablicy
	void loadData(std::string filename);
	
	//Wyœwietlanie tablicy
	void showArray();

	//Dodanie nowego elementu na pocz¹tek tablicy 
	//jako argument przyjmuje wartoœæ tego elementu
	void pushFront(int number);

	//Dodanie nowego elementu na koniec tablicy 
	//jako argument przyjmuje wartoœæ tego elementu
	void pushBack(int number);

	//Dodanie nowego elementu na podany przez u¿ytkownika index tablicy 
	//jako argument przyjmuje docelowy index oraz wartoœæ tego elementu
	void pushOnIndex(int index, int number);

	//Usuniêcie elementu z pocz¹tku tablicy 
	void popFront();

	//Usuniêcie elementu z koñca tablicy 
	void popBack();

	//Usuniêcie elementu z podanego przez u¿ytkownika indeksie tablicy 
	//jako argument przyjmuje index elementu do usuniêcia
	void popOnIndex(int index);

	//Wyszukiwanie podanej przez u¿ytkownika wartoœci
	//zwraca index lub -1 gdzy nie znajdzie podanej wartoœci
	int find(int number);

	//zwraca rozmiar tablicy
	int getSize();
};

