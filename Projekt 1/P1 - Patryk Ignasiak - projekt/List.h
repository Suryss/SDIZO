#pragma once
#include "ListItem.h"
#include <string>
class List
{
	//WskaŸnik na g³owê
	ListItem* head = NULL;
	//WskaŸnik na ogon
	ListItem* tail = NULL;
public:

	//Dodawanie danych z pliku do listy
	void loadData(std::string filename);

	//Wyœwietlanie listy
	void showList();

	//Wyœwietlenie listy od ty³u
	void showListReverse();

	//Dodanie nowego elementu na pocz¹tek listy 
	//jako argument przyjmuje wartoœæ tego elementu
	void pushFront(int number);

	//Dodanie nowego elementu na koniec listy 
	//jako argument przyjmuje wartoœæ tego elementu
	void pushBack(int number);

	//Dodanie nowego elementu na podany przez u¿ytkownika index listy 
	//jako argument przyjmuje docelowy index oraz wartoœæ tego elementu
	void pushOnIndex(int index, int number);

	//Usuniêcie elementu z pocz¹tku listy
	void popFront();

	//Usuniêcie elementu z koñca listy
	void popBack();

	//Usuniêcie elementu z podanego przez u¿ytkownika indeksu listy 
	//jako argument przyjmuje index elementu do usuniêcia
	void popOnIndex(int index);

	//Wyszukiwanie podanej przez u¿ytkownika wartoœci
	//zwraca wskaŸnik na dany element lub NULL gdzy nie znajdzie podanej wartoœci
	int find(int number);

	//Druga wersja wyszukiwania (wyko¿ystywana przy dochodzeniu dlaczego wyszukiwanie ma z³o¿onoœæ O(n^2)
	ListItem* find2(int number);

};

