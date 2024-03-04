#include "List.h"
#include "ListItem.h"
#include <iostream>

using namespace std;

void List::showList() {
	//Je�li w li�cie s� dane to j� wy�wietlamy
	if (head != NULL) {
		//Zmienna pomocnicza do obs�ugi p�tli
		ListItem* temp = head;

		while (temp) {
			printf(" %2d(%d),", temp->vertice, temp->edgeCost);
			temp = temp->next;
		}
		cout << endl;
	}
	else {
		cout << "\nNie mo�na wy�wietli� listy - brak danych" << endl;
	}
}
void List::showListForShortestPath() {
	//Je�li w li�cie s� dane to j� wy�wietlamy
	if (head != NULL) {
		//Zmienna pomocnicza do obs�ugi p�tli
		ListItem* temp = head;

		while (temp) {
			printf("%2d ", temp->vertice);
			temp = temp->next;
		}
		cout << endl;
	}
	else {
		cout << "\nNie mo�na wy�wietli� listy - brak danych" << endl;
	}
}

void List::pushFront(int vertice, int edgeCost) {
	//tworzymy nowy element i wstawiamy w odpowiednim miejscu
	ListItem* item = new ListItem(vertice, edgeCost, NULL, head);

	if (head == NULL) {
		head = item;
		tail = item;
	}
	else {
		head->previous = item;
		head = item;
	}
}
int List::popFront() {
	//sprawdzamy czy s� elementy w tablicy je�li tak to usuwamy pierwszy element
	if (head != NULL) {
		//Zmienna pomocnicza do przechowania wska�nika na element do usuni�cia
		ListItem* temp = head;
		int vertice = head->vertice;

		//Ustawienie nowej g�owy
		head = head->next;
		if (head != NULL) {
			head->previous = NULL;
		}

		delete temp;

		return vertice;
	}
	else {
		return -1;
	}
}
void List::popBack() {
	//sprawdzamy czy s� elementy w tablicy je�li tak to usuwamy usuwamy element
	if (tail != NULL) {
		//Zmienna pomocnicza do przechowania wska�nika na element do usuni�cia
		ListItem* temp = tail;
		//Ustawienie nowego ogona
		tail = tail->previous;
		if (tail == NULL) {
			head = NULL;
		}
		else {
			tail->next = NULL;
		}

		delete temp;
	}
	else {
		cout << "Brak element�w do usuni�cia!!!" << endl;
	}
}
void List::popOnIndex(int index) {
	//sprawdzamy czy s� elementy w tablicy je�li tak to wyszukujemy odpowiedni element i go usuwamy
	if (head != NULL) {
		if (index > 0) {
			//Zmienna pomocnicza do obs�ugi p�tli
			ListItem* temp = head->next;
			for (int i = 1; temp; i++) {
				if (i == index) {
					//zmiana wska�nik�w s�siad�w
					temp->next->previous = temp->previous;
					temp->previous->next = temp->next;

					delete temp;
					return;
				}
				if (temp->next != tail) {
					temp = temp->next;
				}
				else {
					popBack();
					return;
				}
			}
		}
		else if (index == 0) {
			popFront();
		}
		else {
			cout << "Podono b��dny indeks !!!" << endl;
		}
	}
	else {
		cout << "Brak element�w do usuni�cia!!!" << endl;
	}
}
int List::find(int vertice) {
	//Zmienna pomocnicza do obs�ugi p�tli
	ListItem* temp = head;

	for (int i = 0; temp; i++) {
		if (temp->vertice == vertice) {
			return i;
		}
		temp = temp->next;
	}
	return -1;
}
bool List::isEmpty() {
	if (head == NULL) {
		return true;
	}
	
	return false;

}