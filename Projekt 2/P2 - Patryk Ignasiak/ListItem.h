#pragma once
class ListItem
{
public:
	//Wierzcho³ek
	int vertice;
	//Koszt krawêdzi
	int edgeCost;
	//Poprzedni element w liœcie
	ListItem* previous;
	//Nastêpny element w liœcie
	ListItem* next;

	//Tworzy element listy
	//Jako argumenty przyjmuje wierzcho³ek, koszt krawêdzi, wskaŸnik na poprzedni element i na nastêpny
	ListItem(int vertice, int edgeCost, ListItem* previous, ListItem* next);
};

