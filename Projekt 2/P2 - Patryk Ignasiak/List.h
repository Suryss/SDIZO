#pragma once
#include "ListItem.h"
#include <cstddef>
class List
{
	
	//Wska�nik na ogon
	ListItem* tail = NULL;
public:
	//Wska�nik na g�ow�
	ListItem* head = NULL;

	//Wy�wietlanie listy
	void showList();

	//Lista dla najkr�tszej �cie�ki
	void showListForShortestPath();

	//Dodanie nowego elementu na pocz�tek listy 
	//jako argument przyjmuje warto�� tego elementu
	void pushFront(int vertice, int edgeCost);

	//Usuni�cie elementu z pocz�tku listy
	int popFront();

	//Usuni�cie elementu z ko�ca listy
	void popBack();

	//Usuni�cie elementu z podanego przez u�ytkownika indeksu listy 
	//jako argument przyjmuje index elementu do usuni�cia
	void popOnIndex(int index);

	//Wyszukiwanie podanej przez u�ytkownika warto�ci
	//zwraca wska�nik na dany element lub NULL gdzy nie znajdzie podanej warto�ci
	int find(int vertice);

	//Sprawdzenie czy jest pusta
	bool isEmpty();
};