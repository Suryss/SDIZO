#pragma once
class ListItem
{
public:
	//Wartoœæ
	int number;
	//Poprzedni element w liœcie
	ListItem* previous;
	//Nastêpny element w liœcie
	ListItem* next;

	//Tworzy element listy
	//Jako argumenty przyjmuje wartoœæ, wskaŸnik na poprzedni element i na nastêpny
	ListItem(int number, ListItem* previous, ListItem* next);

};

