#include "ListItem.h"

ListItem::ListItem(int vertice, int edgeCost, ListItem* previous, ListItem* next) {
	//Przypisanie warto�ci do p�l obiektu
	this->vertice = vertice;
	this->edgeCost = edgeCost;
	this->previous = previous;
	this->next = next;
}
