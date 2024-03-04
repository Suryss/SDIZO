#include "ListItem.h"

ListItem::ListItem(int number, ListItem* previous, ListItem* next) {
	//Przypisanie wartoœci do pól obiektu
	this->number = number;
	this->previous = previous;
	this->next = next;
}

