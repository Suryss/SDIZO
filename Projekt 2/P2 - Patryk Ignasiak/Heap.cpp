#include "Heap.h"
#include <iostream>


using namespace std;

void Heap::showHeapArray() {
	//Jeœli w kopcu s¹ dane to go wyœwietlamy
	if (heap != NULL) {
		cout << "\nKopiec:" << endl;
		cout << "Index:   |";

		for (int i = 0; i < heapSize; i++) {
			printf("%2d|", heap[i][0]);
		}

		cout << "\nWartoœæ: |";

		for (int i = 0; i < heapSize; i++) {
			printf("%2d|", heap[i][1]);
		}
		cout << endl;
	}
	else {
		cout << "\nNie mo¿na wyœwietliæ kopca - brak danych" << endl;
	}

}
void Heap::heapifyDown(int i) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int smallest = i;

	if (left < heapSize && right < heapSize) {
		if (heap[left][1] < heap[i][1] || heap[right][1] < heap[i][1]) {
			if (heap[left][1] < heap[right][1]) {
				smallest = left;
			}
			else {
				smallest = right;
			}
		}
	}
	else if (left < heapSize) {
		if (heap[left][1] < heap[i][1]) {
			smallest = left;
		}
	}
	if (smallest != i) {
		int* temp = heap[i];
		heap[i] = heap[smallest];
		heap[smallest] = temp;
		heapifyDown(smallest);
	}
}
void Heap::heapifyUp(int i) {
	int parent = floor((i - 1) / 2);
	int largest = i;

	if (heap[parent][1] > heap[i][1]) {
		largest = parent;
	}

	if (largest != i) {
		int* temp = heap[i];
		heap[i] = heap[largest];
		heap[largest] = temp;
		heapifyUp(largest);
	}
}
int Heap::pop() {
	//Jeœli w kopcu s¹ elementy to usuwamy element ze szczytu
	if (heapSize > 1) {
		int vertice = heap[0][0];
		heapSize--;
		//zamieniamy element ze szczytu z elementem ostatnim 
		heap[0] = heap[heapSize];

		//relokowanie tablicy
		int** temp = heap;
		heap = new int*[heapSize];

		for (int i = 0; i < heapSize; i++) {
			heap[i] = temp[i];
		}
		delete[] temp;
		//znajdujemy odpowiednie miejsce dla nowego elementu na szczycie
		heapifyDown(0);
		return vertice;
	}
	else {
		int vertice = heap[0][0];
		delete[] heap;
		heapSize--;
		return vertice;
	}

}
void Heap::push(int vertice, int start) {
	int valueOfEdge = INT32_MAX;
	if (vertice == start) {
		valueOfEdge = 0;
	}
	heapSize++;
	//relokujemy tablicê 
	int** temp = heap;
	heap = new int*[heapSize];
	
	if (heapSize > 1) {
		for (int i = 0; i < heapSize; i++) {
			heap[i] = temp[i];
		}
		delete[] temp;
	}
	

	//Wstawiamy nasz nowy element
	int* tab = new int[2];
	tab[0] = vertice;
	tab[1] = valueOfEdge;
	heap[heapSize - 1] = tab;

	//jeœli rozmiar jest wiêkszy ni¿ 1, do szukamy miejsca dla naszego elementu
	if (heapSize > 1) {
		heapifyUp(heapSize - 1);
	}

}
void Heap::pushForKruskal(int edge, int value) {
	heapSize++;
	//relokujemy tablicê 
	int** temp = heap;
	heap = new int* [heapSize];

	if (heapSize > 1) {
		for (int i = 0; i < heapSize; i++) {
			heap[i] = temp[i];
		}
		delete[] temp;
	}


	//Wstawiamy nasz nowy element
	int* tab = new int[2];
	tab[0] = edge;
	tab[1] = value;
	heap[heapSize - 1] = tab;

	//jeœli rozmiar jest wiêkszy ni¿ 1, do szukamy miejsca dla naszego elementu
	if (heapSize > 1) {
		heapifyUp(heapSize - 1);
	}

}
void Heap::findAndChange(int vertice, int valueOfEdge) {
	//jeœli w kopcu s¹ elementy to wyszukujemy podany element
	if (heapSize > 0) {

		for (int i = 0; i < heapSize; i++) {
			if (heap[i][0] == vertice) {
				heap[i][1] = valueOfEdge;
			}
		}
	}
}
void Heap::floyd() {
	//budujemy kopiec od ostatniego rodzica
	for (int i = floor((heapSize - 1) / 2); i >= 0; i--) {
		heapifyDown(i);
	}
}
bool Heap::noEmpty() {
	if (heapSize > 0) {
		return true;
	}
	else {
		return false;
	}
}
bool Heap::find(int vertice) {
	for (int i = 0; i < heapSize; i++) {
		if (heap[i][0] == vertice) {
			return true;
		}
	}
	return false;
}

int Heap::getKey(int vertice) {
	for (int i = 0; i < heapSize; i++) {
		if (heap[i][0] == vertice) {
			return heap[i][1];
		}
	}
	return NULL;
}