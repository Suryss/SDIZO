#include "ListItem.h"

ListItem::ListItem(int number, ListItem* previous, ListItem* next) {
	//Przypisanie warto�ci do p�l obiektu
	this->number = number;
	this->previous = previous;
	this->next = next;
}

