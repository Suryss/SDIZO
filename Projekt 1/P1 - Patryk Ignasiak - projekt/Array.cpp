#include "Array.h"
#include "Data.h"
#include <iostream>

using namespace std;

void Array::loadData(string filename){
	//Tworzy obiekt obs�uguj�cy dane
	Data data = Data();
	//wczytuje dane do tablicy pomocniczej
	int* tab = data.fromFile(filename);

	//je�li uda�o si� pobra� dane z pliku to dodajemy je do naszej tablicy dynamicznej 
	if (tab != NULL) {
		size = tab[0];
		array = new int[size];
		for (int i = 1; i <= size; i++) {
			array[i - 1] = tab[i];
		}
	}
	
}
void Array::showArray() {
	//Je�li w tablicy s� dane to j� wy�wietlamy
	if (array != NULL) {
		cout << "\nTablica:"<<endl;
		cout << "Index:   |";

		for (int i = 0; i < size; i++) {
			printf("%2d|", i);
		}

		cout << "\nWarto��: |";

		for (int i = 0; i < size; i++) {
			printf("%2d|", array[i]);
		}

		cout << endl;
	}
	else {
		cout << "\nNie mo�na wy�wietli� tablicy - brak danych" << endl;
	}
	
}
void Array::pushFront(int number) {
	//zapisujemy wska�nik na pierwszy element do zmiennej pomocniczej
	int* temp = array;
	size++;

	//lokujemy nowy wska�nik tablicy o nowym rozmiarze
	array = new int[size];

	//wstawiamy element na pocz�tek
	array[0] = number;

	//przenosimy dane do nowej tablicy
	for (int i = 1; i < size; i++) {
		array[i] = temp[i - 1];
	}
	//usuwamy star� tablic�
	delete[] temp;
}
void Array::pushBack(int number) {
	//zapisujemy wska�nik na pierwszy element do zmiennej pomocniczej
	int* temp = array;
	size++;
	//lokujemy nowy wska�nik tablicy o nowym rozmiarze
	array = new int[size];
	
	//przenosimy dane do nowej tablicy
	for (int i = 0; i < size-1; i++) {
		array[i] = temp[i];
	}
	//wstawiamy element na koniec
	array[size-1] = number;

	//usuwamy star� tablic�
	delete[] temp;
}
void Array::pushOnIndex(int index, int number) {
	//Je�li podany indeks jest poprawny to dodajemy na wybran� pozycj�
	if (index >= 0 && index < size) {
		//zapisujemy wska�nik do zmiennej pomocniczej
		int* temp = array;
		size++;
		//lokujemy nowy wska�nik tablicy o nowym rozmiarze
		array = new int[size];
		int x = 0;

		//przenosimy dane do nowej tablicy
		for (int i = 0; i < size; i++) {
			if (i == index) {
				array[i] = number;
				x++;
			}
			else {
				array[i] = temp[i - x]; // musimy zmniejszy� i o 1 dla starej tablicy, gdy wstawimy nowy element do tablicy
			}
		}
		//usuwamy star� tablic�
		delete[] temp;
	}
	else {
		cout << "Podono b��dny indeks tablicy!!!" << endl;
	}
}
void Array::popFront() {
	//sprawdzamy czy s� elementy w tablicy
	if (size != 0) {
		//zapisujemy wska�nik do zmiennej pomocniczej
		int* temp = array;
		size--;
		//lokujemy nowy wska�nik tablicy o nowym rozmiarze
		array = new int[size];
		//przenosimy dane do nowej tablicy
		for (int i = 0; i < size; i++) {
			array[i] = temp[i + 1];
		}
		//usuwamy star� tablic�
		delete[] temp;
	}
	else {
		cout << "Tablica jest pusta - brak element�w do usuni�cia" << endl;
	}
	
}
void Array::popBack() {
	//sprawdzamy czy s� elementy w tablicy
	if (size != 0) {
		//zapisujemy wska�nik do zmiennej pomocniczej
		int* temp = array;
		size--;

		//lokujemy nowy wska�nik tablicy o nowym rozmiarze
		array = new int[size];

		//przenosimy dane do nowej tablicy
		for (int i = 0; i < size; i++) {
			array[i] = temp[i];
		}
		//usuwamy star� tablic�
		delete[] temp;
	}
	else {
	cout << "Tablica jest pusta - brak element�w do usuni�cia" << endl;
	}
}
void Array::popOnIndex(int index) {
	//sprawdzamy czy s� elementy w tablicy
	if (size != 0) {
		//sprawdzamy czy podano poprawny index
		if (index >= 0 && index < size) {
			//zapisujemy wska�nik do zmiennej pomocniczej
			int* temp = array; 
			size--;

			//lokujemy nowy wska�nik tablicy o nowym rozmiarze
			array = new int[size];
			int x = 0;

			//przenosimy dane do nowej tablicy
			for (int i = 0; i < size; i++) {
				if (i == index) {
					x++;
				}
				array[i] = temp[i + x];
			}
			//usuwamy star� tablic�
			delete[] temp;
		}
		else {
			cout << "Podono b��dny indeks tablicy!!!" << endl;
		}
	}
	else {
		cout << "Tablica jest pusta - brak element�w do usuni�cia" << endl;
	}
}
int Array::find(int number) {
	//Przesukujemy tablic� i zwracamy indeks je�li znajdziemy podan� warto��
	for (int i = 0; i < size; i++) {
		if (array[i] == number) {
			return i;
		}
	}
	return -1;
}
int Array::getSize() {
	return size;
}