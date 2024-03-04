#pragma once
#include "ListItem.h"
#include <string>
class List
{
	//Wska�nik na g�ow�
	ListItem* head = NULL;
	//Wska�nik na ogon
	ListItem* tail = NULL;
public:

	//Dodawanie danych z pliku do listy
	void loadData(std::string filename);

	//Wy�wietlanie listy
	void showList();

	//Wy�wietlenie listy od ty�u
	void showListReverse();

	//Dodanie nowego elementu na pocz�tek listy 
	//jako argument przyjmuje warto�� tego elementu
	void pushFront(int number);

	//Dodanie nowego elementu na koniec listy 
	//jako argument przyjmuje warto�� tego elementu
	void pushBack(int number);

	//Dodanie nowego elementu na podany przez u�ytkownika index listy 
	//jako argument przyjmuje docelowy index oraz warto�� tego elementu
	void pushOnIndex(int index, int number);

	//Usuni�cie elementu z pocz�tku listy
	void popFront();

	//Usuni�cie elementu z ko�ca listy
	void popBack();

	//Usuni�cie elementu z podanego przez u�ytkownika indeksu listy 
	//jako argument przyjmuje index elementu do usuni�cia
	void popOnIndex(int index);

	//Wyszukiwanie podanej przez u�ytkownika warto�ci
	//zwraca wska�nik na dany element lub NULL gdzy nie znajdzie podanej warto�ci
	int find(int number);

	//Druga wersja wyszukiwania (wyko�ystywana przy dochodzeniu dlaczego wyszukiwanie ma z�o�ono�� O(n^2)
	ListItem* find2(int number);

};

