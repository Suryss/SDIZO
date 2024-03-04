#include "ShortestPath.h"
#include "Graph.h"
#include "Heap.h"
#include <iostream>

using namespace std;

void ShortestPath::showResult() {
	if (circle) {
		cout << "Uwaga graf zawiera ujemne cykle !!!" << endl << endl;
	}
	cout << " End   Dist   Path" << endl;
	for (int i = 0; i < countOfVertices; i++) {
		printf("%4d | %4d | ", i, distances[i]);
		path[i]->showListForShortestPath();
	}

	cout << endl << endl;
}
void ShortestPath::createMemory(int** sPath, int start) {
	path = new List * [countOfVertices];
	distances = new int[countOfVertices];
	for (int i = 0; i < countOfVertices; i++) {
		path[i] = new List();
		distances[i] = sPath[i][1];
		int vertice = i;
		while (true) {
			//jeœli siê nie powtarzaj¹ to dodajemy do œcie¿ki
			bool was = false;
			if (path[i]->find(vertice) != -1) {
				was = true;
			}
			
			if (!was) {
				path[i]->pushFront(vertice, 0);
				if (vertice == start) {
					break;
				}
				else {
					vertice = sPath[vertice][0];
				}
			}
			else {
				break;
			}
		}
	}
}
void ShortestPath::dijkstraOnMatrix(Graph* graph) {
	Heap* heap = new Heap();
	countOfVertices = graph->countOfVertices;
	//Tworzymy tablicê rodziców/dystansów, oraz kopiec
	int** sPath = new int* [countOfVertices];
	for (int i = 0; i < countOfVertices; i++) {
		heap->push(i, graph->startVertice);
		int* tab = new int[2];
		tab[0] = INT32_MAX; //parent
		tab[1] = INT32_MAX;	//distance
		sPath[i] = tab;
	}
	sPath[graph->startVertice][1] = 0;
	//pobieramy dane z kopca 
	while (heap->noEmpty()) {
		int vertice = heap->pop();
		//ustawiamy drogi do s¹siadów
		for (int i = 0; i < countOfVertices; i++) {
			if (graph->matrix[vertice][i] != INT32_MAX) {
				if (sPath[i][1] > sPath[vertice][1] + graph->matrix[vertice][i]) {
					heap->findAndChange(i, graph->matrix[vertice][i] + sPath[vertice][1]);
					sPath[i][0] = vertice;
					sPath[i][1] = graph->matrix[vertice][i] + sPath[vertice][1];
				}
			}
		}
		heap->floyd();
	}
	//sprawdzamy czy wystêpuj¹ cykle ujemne
	isCircle(sPath, graph);

	//dodajemy uzyskane informacje do naszej pamiêci
	createMemory(sPath, graph->startVertice);
}

void ShortestPath::dijkstraOnList(Graph* graph) {
	Heap* heap = new Heap();
	countOfVertices = graph->countOfVertices;
	//Tworzymy tablicê rodziców/dystansów, oraz kopiec
	int** sPath = new int* [countOfVertices];
	for (int i = 0; i < countOfVertices; i++) {
		heap->push(i, graph->startVertice);
		int* tab = new int[2];
		tab[0] = INT32_MAX; //parent
		tab[1] = INT32_MAX;	//distance
		sPath[i] = tab;
	}
	sPath[graph->startVertice][1] = 0;
	//pobieramy dane z kopca 
	while (heap->noEmpty()) {
		int vertice = heap->pop();
		List* list = graph->list[vertice];
		ListItem* listItem = list->head;
		while (listItem) {
			if (sPath[listItem->vertice][1] > sPath[vertice][1] + listItem->edgeCost) {
				heap->findAndChange(listItem->vertice, listItem->edgeCost + sPath[vertice][1]);
				sPath[listItem->vertice][0] = vertice;
				sPath[listItem->vertice][1] = listItem->edgeCost + sPath[vertice][1];
			}
			listItem = listItem->next;

		}
		heap->floyd();

	}

	//sprawdzamy czy wystêpuj¹ cykle ujemne
	isCircle(sPath, graph);

	//dodajemy uzyskane informacje do naszej pamiêci
	createMemory(sPath, graph->startVertice);

}
void ShortestPath::bellmanFordOnMatrix(Graph* graph) {
	
	countOfVertices = graph->countOfVertices;
	//Tworzymy tablicê rodziców/dystansów
	int** sPath = new int* [countOfVertices];
	for (int i = 0; i < countOfVertices; i++) {
		int* tab = new int[2];
		tab[0] = INT32_MAX; //parent
		tab[1] = INT32_MAX;	//distance
		sPath[i] = tab;
	}
	sPath[graph->startVertice][1] = 0;
	int border = countOfVertices;
	bool was = false;
	for (int i = graph->startVertice; i < border; i++) {
		//ustawiamy drogi do s¹siadów
		for (int j = 0; j < countOfVertices; j++) {
			if (graph->matrix[i][j] != INT32_MAX ) {
				if (sPath[j][1] > sPath[i][1] + graph->matrix[i][j]) {
					sPath[j][0] = i;
					sPath[j][1] = graph->matrix[i][j] + sPath[i][1];
				}
			}
		}
		if (graph->startVertice != 0 && i + 1 == border && !was ) {
			border = graph->startVertice;
			i = 0;
			was = true;
		}
	}

	//sprawdzamy czy wystêpuj¹ cykle ujemne
	isCircle(sPath, graph);

	//dodajemy uzyskane informacje do naszej pamiêci
	createMemory(sPath, graph->startVertice);
}
void ShortestPath::bellmanFordOnList(Graph* graph) {

	countOfVertices = graph->countOfVertices;
	//Tworzymy tablicê rodziców/dystansów
	int** sPath = new int* [countOfVertices];
	for (int i = 0; i < countOfVertices; i++) {
		int* tab = new int[2];
		tab[0] = INT32_MAX; //parent
		tab[1] = INT32_MAX;	//distance
		sPath[i] = tab;
	}
	sPath[graph->startVertice][1] = 0;
	int border = countOfVertices;
	bool was = false;
	for (int i = graph->startVertice; i < border; i++) {
		//ustawiamy drogi do s¹siadów
		List* list = graph->list[i];
		ListItem* listItem = list->head; 
		while (listItem) {
			if (sPath[listItem->vertice][1] > sPath[i][1] + listItem->edgeCost) {
				sPath[listItem->vertice][0] = i;
				sPath[listItem->vertice][1] = listItem->edgeCost + sPath[i][1];
			}
			listItem = listItem->next;

		}
		if (graph->startVertice != 0 && i + 1 == border && !was) {
			border = graph->startVertice;
			i = 0;
			was = true;
		}
	}

	//sprawdzamy czy wystêpuj¹ cykle ujemne
	isCircle(sPath, graph);
	
	//dodajemy uzyskane informacje do naszej pamiêci
	createMemory(sPath, graph->startVertice);


}
void ShortestPath::isCircle(int** sPath, Graph* graph) {
	circle = false;
	bool t = true;
	for (int i = 0; i < countOfVertices && t; i++) {
		for (int j = 0; j < countOfVertices && t; j++) {
			if (graph->matrix[i][j] != INT32_MAX) {
				if (sPath[j][1] > sPath[i][1] + graph->matrix[i][j]) {
					circle = true;
					t = false;
				}
			}
		}
	}
}