#include "ListItem.h"

ListItem::ListItem(int vertice, int edgeCost, ListItem* previous, ListItem* next) {
	//Przypisanie wartoœci do pól obiektu
	this->vertice = vertice;
	this->edgeCost = edgeCost;
	this->previous = previous;
	this->next = next;
}
