#pragma once
class ListItem
{
public:
	//Warto��
	int number;
	//Poprzedni element w li�cie
	ListItem* previous;
	//Nast�pny element w li�cie
	ListItem* next;

	//Tworzy element listy
	//Jako argumenty przyjmuje warto��, wska�nik na poprzedni element i na nast�pny
	ListItem(int number, ListItem* previous, ListItem* next);

};

