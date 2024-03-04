#include "List.h"
#include "ListItem.h"
#include <iostream>
#include "Data.h"

using namespace std;

void List::loadData(string filename) {
	//Tworzy obiekt obs³uguj¹cy dane
	Data data = Data();	
	//wczytuje dane do tablicy pomocniczej
	int* tab = data.fromFile(filename);

	//jeœli uda³o siê pobraæ dane z pliku to ³adujemy je do listy
	if (tab != NULL) {
		for (int i = 1; i <= tab[0]; i++) {
			//Tworzymy element listy
			ListItem* item = new ListItem(tab[i], tail, NULL);
			//Wstawiamy i edytujemy wskaŸniki na g³owê i ogon
			if (tail != NULL) {
				tail->next = item;
			}
			tail = item;
			if (head == NULL) {
				head = item;
			}
		}
	}	
}
void List::showList() {
	//Jeœli w liœcie s¹ dane to j¹ wyœwietlamy
	if (head != NULL) { 
		//Zmienna pomocnicza do obs³ugi pêtli
		ListItem* temp = head;  

		cout << "\nLista:" << endl;
		cout << "Wartoœci: |";
		
		while (temp) { 
			printf("%2d|", temp->number); 
			temp = temp->next;
		}
		cout << endl;
	}
	else {
		cout << "\nNie mo¿na wyœwietliæ listy - brak danych" << endl;
	}
}
void List::showListReverse() {
	//Jeœli w tablicy s¹ dane to j¹ wyœwietlamy od ty³u 
	if (head != NULL) {
		//Zmienna pomocnicza do obs³ugi pêtli
		ListItem* temp = tail;
		cout << "\nLista od ty³u:" << endl;
		cout << "Wartoœci: |";

		while (temp) {
			printf("%2d|", temp->number);
			temp = temp->previous;
		}
		cout << endl;
	}
	else {
		cout << "\nNie mo¿na wyœwietliæ listy - brak danych" << endl;
	}
}
void List::pushFront(int number) {
	//tworzymy nowy element i wstawiamy w odpowiednim miejscu
	ListItem* item = new ListItem(number, NULL, head);

	if (head == NULL) {
		head = item;
		tail = item;
	}
	else {
		head->previous = item;
		head = item;
	}
}
void List::pushBack(int number) {
	//tworzymy nowy element i wstawiamy w odpowiednim miejscu
	ListItem* item = new ListItem(number, tail, NULL);

	if (head == NULL) {
		head = item;
		tail = item;
	}
	else {
		tail->next = item;
		tail = item;
	}
}
void List::pushOnIndex(int index, int number) {

	if (index > 0) {
		//tworzymy nowy element, szukamy dla niego miejsce i wstawiamy go do tablicy
		ListItem* temp = head->next;

		for (int i = 1; temp; i++) {
			if (i == index) {
				ListItem* item = new ListItem(number, temp->previous, temp->next);
				temp->next->previous = item;
				temp->previous->next = item;
				
				return;
			}
			if (temp->next != tail) {
				temp = temp->next;
			}
			else {
				pushBack(number);
				return;
			}
		}
	}
	else if (index == 0) {
		pushFront(number);
	}
	else {
		cout << "Podono b³êdny indeks !!!" << endl;
	}
}
void List::popFront() {
	//sprawdzamy czy s¹ elementy w tablicy jeœli tak to usuwamy pierwszy element
	if (head != NULL) {
		//Zmienna pomocnicza do przechowania wskaŸnika na element do usuniêcia
		ListItem* temp = head;

		//Ustawienie nowej g³owy
		head = head->next;
		head->previous = NULL;

		delete temp;
	}
	else {
		cout << "Brak elementów do usuniêcia!!!" << endl; 
	}
}
void List::popBack() {
	//sprawdzamy czy s¹ elementy w tablicy jeœli tak to usuwamy usuwamy element
	if (tail != NULL) {
		//Zmienna pomocnicza do przechowania wskaŸnika na element do usuniêcia
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
		cout << "Brak elementów do usuniêcia!!!" << endl;
	}
}
void List::popOnIndex(int index) {
	//sprawdzamy czy s¹ elementy w tablicy jeœli tak to wyszukujemy odpowiedni element i go usuwamy
	if (head != NULL) {
		if (index > 0) {
			//Zmienna pomocnicza do obs³ugi pêtli
			ListItem* temp = head->next;
			for (int i = 1; temp; i++) {
				if (i == index) {
					//zmiana wskaŸników s¹siadów
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
			cout << "Podono b³êdny indeks !!!" << endl;
		}
	}
	else {
		cout << "Brak elementów do usuniêcia!!!" << endl;
	}
}
int List::find(int number) {
	//Zmienna pomocnicza do obs³ugi pêtli
	ListItem* temp = head;
	
	for (int i = 0; temp; i++) {
		if (temp->number == number) {
			return i;
		}
		temp = temp->next;
	}
	return -1;
}
ListItem* List::find2(int number) {
	//Zmienna pomocnicza do obs³ugi pêtli
	ListItem* temp = head;

	while(temp) {
		if (temp->number == number) {
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}