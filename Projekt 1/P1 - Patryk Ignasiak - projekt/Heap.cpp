#include "Heap.h"
#include <iostream>
#include "Data.h"

using namespace std;

void Heap::loadData(string filename, bool choose) {
	//Tworzy obiekt obs�uguj�cy dane
	Data data = Data();
	//wczytuje dane do tablicy pomocniczej
	int* tab = data.fromFile(filename);

	//je�li uda�o si� pobra� dane z pliku to dodajemy je do kopca
	if (tab != NULL) {
		heapSize = tab[0];
		heap = new int[heapSize];
		for (int i = 1; i <= heapSize; i++) {
			heap[i - 1] = tab[i];
		}
		//budowanie kopca maksymalnego
		if (choose) {
			floyd(floor((heapSize - 1) / 2));
		}
		else {
			buildHeap();
		}		
	}
}

void Heap::showHeapArray() {
	//Je�li w kopcu s� dane to go wy�wietlamy
	if (heap != NULL) {
		cout << "\nKopiec:" << endl;
		cout << "Index:   |";

		for (int i = 0; i < heapSize; i++) {
			printf("%2d|", i);
		}

		cout << "\nWarto��: |";

		for (int i = 0; i < heapSize; i++) {
			printf("%2d|", heap[i]);
		}
		cout << endl;
	}
	else {
		cout << "\nNie mo�na wy�wietli� kopca - brak danych" << endl;
	}

}
//Gotowe wy�wietlanie z internetu
void Heap::showHeap(string sp, string sn, int v){
	//Je�li w kopcu s� dane to go wy�wietlamy
	if (heapSize > 0) {
		string s;
		string cr, cl, cp;
		cr = cl = cp = "  ";
		cr[0] = 184; cr[1] = 151;
		cl[0] = 39; cl[1] = 151;
		cp[0] = 124;

		if (v < heapSize)
		{
			s = sp;
			if (sn == cr) s[s.length() - 2] = ' ';
			showHeap(s + cp, cr, 2 * v + 2);

			s = s.substr(0, sp.length() - 2);

			cout << s << sn << heap[v] << endl;

			s = sp;
			if (sn == cl) s[s.length() - 2] = ' ';
			showHeap(s + cp, cl, 2 * v + 1);
		}
	}
}
void Heap::buildHeap() {
	//Je�li rozmiar kopca jest wi�kszy od 1 to go budujemy
	if (heapSize > 1) {
		for (int i = 0; i < log2(heapSize); i++) {
			for (int j = 0; j < heapSize; j++)
				heapifyDown(j);
		}
	}
}
void Heap::heapifyDown(int i) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;

	if (left < heapSize && right < heapSize) {
		if (heap[left] > heap[i] || heap[right] > heap[i]) {
			if (heap[left] > heap[right]) {
				largest = left;
			}
			else {
				largest = right;
			}
		}
	}
	else if (left < heapSize) {
		if (heap[left] > heap[i]) {
			largest = left;
		}
	}
	if (largest != i) {
		int temp = heap[i]; 
		heap[i] = heap[largest];
		heap[largest] = temp;
		heapifyDown(largest);
	}
}
void Heap::heapifyUp(int i) {
	int parent = floor((i-1)/2);
	int smallest = i;

	if (heap[parent] < heap[i]) {
		smallest = parent;
	}
	
	if (smallest != i) {
		int temp = heap[i];
		heap[i] = heap[smallest];
		heap[smallest] = temp;
		heapifyUp(smallest);
	}
}
void Heap::pop() {
	//Je�li w kopcu s� elementy to usuwamy element ze szczytu
	if (heapSize > 0) {
		heapSize--;
		//zamieniamy element ze szczytu z elementem ostatnim 
		heap[0] = heap[heapSize];

		//relokowanie tablicy
		int* temp = heap;
		heap = new int[heapSize];

		for (int i = 0; i < heapSize; i++) {
			heap[i] = temp[i];
		}
		delete[] temp;
		//znajdujemy odpowiednie miejsce dla nowego elementu na szczycie
		heapifyDown(0);
	}
	else {
		delete[] heap;
	}
	
}
void Heap::push(int number) {

	heapSize++;
	//relokujemy tablic� 
	int* temp = heap; 
	heap = new int[heapSize]; 

	for (int i = 0; i < heapSize; i++) { 
		heap[i] = temp[i]; 
	}
	delete[] temp;
	//Wstawiamy nasz nowy element
	heap[heapSize - 1] = number; 

	//je�li rozmiar jest wi�kszy ni� 1, do szukamy miejsca dla naszego elementu
	if (heapSize > 1) {
		heapifyUp(heapSize - 1);
	}
	
}
int Heap::find(int number) {
	//je�li w kopcu s� elementy to wyszukujemy podany element
	if (heapSize > 0) {
		//sprawdzamy czy podana warto�� jest wi�ksza od warto�ci na szczycie
		if (number > heap[0]) {
			return -1;
		}
		else {
			for (int i = 0; i < heapSize; i++) {
				if(heap[i]==number){
					return i;
				}
			}
			return -1;
		}
	}
	else {
		return -1;
	}
}
void Heap::floyd(int i) {
	//budujemy kopiec od ostatniego rodzica
	for (i; i >= 0; i--) {
		heapifyDown(i);
	}

}