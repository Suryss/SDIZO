#pragma once
#include "ListItem.h"
#include <cstddef>
class List
{
	
	//WskaŸnik na ogon
	ListItem* tail = NULL;
public:
	//WskaŸnik na g³owê
	ListItem* head = NULL;

	//Wyœwietlanie listy
	void showList();

	//Lista dla najkrótszej œcie¿ki
	void showListForShortestPath();

	//Dodanie nowego elementu na pocz¹tek listy 
	//jako argument przyjmuje wartoœæ tego elementu
	void pushFront(int vertice, int edgeCost);

	//Usuniêcie elementu z pocz¹tku listy
	int popFront();

	//Usuniêcie elementu z koñca listy
	void popBack();

	//Usuniêcie elementu z podanego przez u¿ytkownika indeksu listy 
	//jako argument przyjmuje index elementu do usuniêcia
	void popOnIndex(int index);

	//Wyszukiwanie podanej przez u¿ytkownika wartoœci
	//zwraca wskaŸnik na dany element lub NULL gdzy nie znajdzie podanej wartoœci
	int find(int vertice);

	//Sprawdzenie czy jest pusta
	bool isEmpty();
};