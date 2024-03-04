#pragma once
#include <string>
class Array
{
	//Wska�nik na pocz�tek tablicy
	int* array = NULL; 
	//Rozmiar tablicy
	int size = 0;
public:
	//Dodaje dane z pliku do tablicy
	void loadData(std::string filename);
	
	//Wy�wietlanie tablicy
	void showArray();

	//Dodanie nowego elementu na pocz�tek tablicy 
	//jako argument przyjmuje warto�� tego elementu
	void pushFront(int number);

	//Dodanie nowego elementu na koniec tablicy 
	//jako argument przyjmuje warto�� tego elementu
	void pushBack(int number);

	//Dodanie nowego elementu na podany przez u�ytkownika index tablicy 
	//jako argument przyjmuje docelowy index oraz warto�� tego elementu
	void pushOnIndex(int index, int number);

	//Usuni�cie elementu z pocz�tku tablicy 
	void popFront();

	//Usuni�cie elementu z ko�ca tablicy 
	void popBack();

	//Usuni�cie elementu z podanego przez u�ytkownika indeksie tablicy 
	//jako argument przyjmuje index elementu do usuni�cia
	void popOnIndex(int index);

	//Wyszukiwanie podanej przez u�ytkownika warto�ci
	//zwraca index lub -1 gdzy nie znajdzie podanej warto�ci
	int find(int number);

	//zwraca rozmiar tablicy
	int getSize();
};

