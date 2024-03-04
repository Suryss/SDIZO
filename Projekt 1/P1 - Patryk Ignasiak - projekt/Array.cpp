#include "Array.h"
#include "Data.h"
#include <iostream>

using namespace std;

void Array::loadData(string filename){
	//Tworzy obiekt obs³uguj¹cy dane
	Data data = Data();
	//wczytuje dane do tablicy pomocniczej
	int* tab = data.fromFile(filename);

	//jeœli uda³o siê pobraæ dane z pliku to dodajemy je do naszej tablicy dynamicznej 
	if (tab != NULL) {
		size = tab[0];
		array = new int[size];
		for (int i = 1; i <= size; i++) {
			array[i - 1] = tab[i];
		}
	}
	
}
void Array::showArray() {
	//Jeœli w tablicy s¹ dane to j¹ wyœwietlamy
	if (array != NULL) {
		cout << "\nTablica:"<<endl;
		cout << "Index:   |";

		for (int i = 0; i < size; i++) {
			printf("%2d|", i);
		}

		cout << "\nWartoœæ: |";

		for (int i = 0; i < size; i++) {
			printf("%2d|", array[i]);
		}

		cout << endl;
	}
	else {
		cout << "\nNie mo¿na wyœwietliæ tablicy - brak danych" << endl;
	}
	
}
void Array::pushFront(int number) {
	//zapisujemy wskaŸnik na pierwszy element do zmiennej pomocniczej
	int* temp = array;
	size++;

	//lokujemy nowy wskaŸnik tablicy o nowym rozmiarze
	array = new int[size];

	//wstawiamy element na pocz¹tek
	array[0] = number;

	//przenosimy dane do nowej tablicy
	for (int i = 1; i < size; i++) {
		array[i] = temp[i - 1];
	}
	//usuwamy star¹ tablicê
	delete[] temp;
}
void Array::pushBack(int number) {
	//zapisujemy wskaŸnik na pierwszy element do zmiennej pomocniczej
	int* temp = array;
	size++;
	//lokujemy nowy wskaŸnik tablicy o nowym rozmiarze
	array = new int[size];
	
	//przenosimy dane do nowej tablicy
	for (int i = 0; i < size-1; i++) {
		array[i] = temp[i];
	}
	//wstawiamy element na koniec
	array[size-1] = number;

	//usuwamy star¹ tablicê
	delete[] temp;
}
void Array::pushOnIndex(int index, int number) {
	//Jeœli podany indeks jest poprawny to dodajemy na wybran¹ pozycjê
	if (index >= 0 && index < size) {
		//zapisujemy wskaŸnik do zmiennej pomocniczej
		int* temp = array;
		size++;
		//lokujemy nowy wskaŸnik tablicy o nowym rozmiarze
		array = new int[size];
		int x = 0;

		//przenosimy dane do nowej tablicy
		for (int i = 0; i < size; i++) {
			if (i == index) {
				array[i] = number;
				x++;
			}
			else {
				array[i] = temp[i - x]; // musimy zmniejszyæ i o 1 dla starej tablicy, gdy wstawimy nowy element do tablicy
			}
		}
		//usuwamy star¹ tablicê
		delete[] temp;
	}
	else {
		cout << "Podono b³êdny indeks tablicy!!!" << endl;
	}
}
void Array::popFront() {
	//sprawdzamy czy s¹ elementy w tablicy
	if (size != 0) {
		//zapisujemy wskaŸnik do zmiennej pomocniczej
		int* temp = array;
		size--;
		//lokujemy nowy wskaŸnik tablicy o nowym rozmiarze
		array = new int[size];
		//przenosimy dane do nowej tablicy
		for (int i = 0; i < size; i++) {
			array[i] = temp[i + 1];
		}
		//usuwamy star¹ tablicê
		delete[] temp;
	}
	else {
		cout << "Tablica jest pusta - brak elementów do usuniêcia" << endl;
	}
	
}
void Array::popBack() {
	//sprawdzamy czy s¹ elementy w tablicy
	if (size != 0) {
		//zapisujemy wskaŸnik do zmiennej pomocniczej
		int* temp = array;
		size--;

		//lokujemy nowy wskaŸnik tablicy o nowym rozmiarze
		array = new int[size];

		//przenosimy dane do nowej tablicy
		for (int i = 0; i < size; i++) {
			array[i] = temp[i];
		}
		//usuwamy star¹ tablicê
		delete[] temp;
	}
	else {
	cout << "Tablica jest pusta - brak elementów do usuniêcia" << endl;
	}
}
void Array::popOnIndex(int index) {
	//sprawdzamy czy s¹ elementy w tablicy
	if (size != 0) {
		//sprawdzamy czy podano poprawny index
		if (index >= 0 && index < size) {
			//zapisujemy wskaŸnik do zmiennej pomocniczej
			int* temp = array; 
			size--;

			//lokujemy nowy wskaŸnik tablicy o nowym rozmiarze
			array = new int[size];
			int x = 0;

			//przenosimy dane do nowej tablicy
			for (int i = 0; i < size; i++) {
				if (i == index) {
					x++;
				}
				array[i] = temp[i + x];
			}
			//usuwamy star¹ tablicê
			delete[] temp;
		}
		else {
			cout << "Podono b³êdny indeks tablicy!!!" << endl;
		}
	}
	else {
		cout << "Tablica jest pusta - brak elementów do usuniêcia" << endl;
	}
}
int Array::find(int number) {
	//Przesukujemy tablicê i zwracamy indeks jeœli znajdziemy podan¹ wartoœæ
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