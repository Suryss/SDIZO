#pragma once
class ListItem
{
public:
	//Wierzcho�ek
	int vertice;
	//Koszt kraw�dzi
	int edgeCost;
	//Poprzedni element w li�cie
	ListItem* previous;
	//Nast�pny element w li�cie
	ListItem* next;

	//Tworzy element listy
	//Jako argumenty przyjmuje wierzcho�ek, koszt kraw�dzi, wska�nik na poprzedni element i na nast�pny
	ListItem(int vertice, int edgeCost, ListItem* previous, ListItem* next);
};

