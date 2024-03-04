#include "MST.h"
#include "Heap.h"
#include <iostream>

using namespace std;

void MST::showResult() {

	int mst = 0;

	cout << " Edges   Weight" << endl;
	for (int i = 0; i < countOfEdges; i++) {
		printf(" (%2d-%2d)", mstEdges[i][0], mstEdges[i][1]);
		printf("%7d\n", mstEdges[i][2]);
		mst += mstEdges[i][2];
	}

	cout << endl << "MST = " << mst << endl << endl;
}
void MST::primOnMatrix(Graph* graph) {
	//Tworzymy tablicê po³¹czonych wierzcho³ków, oraz kopiec
	Heap* heap = new Heap();
	countOfEdges = graph->countOfVertices - 1;
	int** connectedVertices = new int*[graph->countOfVertices];
	for (int i = 0; i < graph->countOfVertices; i++) {
		heap->push(i, 0);
		int* tab = new int[3];
		tab[0] = INT32_MAX;
		tab[1] = INT32_MAX;
		connectedVertices[i] = tab;
	}
	//pobieramy dane z kopca 
	while (heap->noEmpty()) {
		int vertice = heap->pop();
		//ustawiamy drogi do s¹siadów
		for (int i = 0; i < graph->countOfVertices; i++) {
			if (graph->matrix[vertice][i] != INT32_MAX) {
				if (heap->find(i) && graph->matrix[vertice][i] < heap->getKey(i)) {
					heap->findAndChange(i, graph->matrix[vertice][i]);
					connectedVertices[i][0] = vertice;
					connectedVertices[i][1] = graph->matrix[vertice][i];
				}
			}
		}
		heap->floyd();
	}
	createListOfEdges(connectedVertices);
}void MST::primOnList(Graph* graph) {
	//Tworzymy tablicê po³¹czonych wierzcho³ków, oraz kopiec
	Heap* heap = new Heap();
	countOfEdges = graph->countOfVertices - 1;
	int** connectedVertices = new int*[graph->countOfVertices];
	for (int i = 0; i < graph->countOfVertices; i++) {
		heap->push(i, 0);
		int* tab = new int[2];
		tab[0] = INT32_MAX;
		tab[1] = INT32_MAX;
		connectedVertices[i] = tab;
	}
	//pobieramy dane z kopca 
	while (heap->noEmpty()) {
		int vertice = heap->pop();
		//ustawiamy drogi do s¹siadów
		List* list = graph->list[vertice];
		ListItem* listItem = list->head;
		while(listItem) {
			
			if (heap->find(listItem->vertice) && listItem->edgeCost < heap->getKey(listItem->vertice)) {
				heap->findAndChange(listItem->vertice, listItem->edgeCost);
			
				connectedVertices[listItem->vertice][0] = vertice;
				connectedVertices[listItem->vertice][1] = listItem->edgeCost;
			}
			listItem = listItem->next;
			
		}
		heap->floyd();
	}
	createListOfEdges(connectedVertices);
}
void MST::createListOfEdges(int** connectedVertices) {
	mstEdges = new int* [countOfEdges];

	for (int i = 1; i < countOfEdges+1; i++) {
		int* tab = new int[3];
		tab[0] = i;
		tab[1] = connectedVertices[i][0];
		tab[2] = connectedVertices[i][1];
		mstEdges[i - 1] = tab;
	}
}

void MST::kruskalOnMatrix(Graph* graph) {
	//tworzymy krawêdzie i sety
	countOfEdges = graph->countOfVertices-1;
	int countOfVertices = graph->countOfVertices;
	int** edges = new int* [graph->countOfEdges];
	//przechowuje 0-set, 1-rank, 2-parent
	int** groups = new int* [countOfVertices];
	
	for (int i = 0, k = 0; i < countOfVertices; i++) {
		int* group = new int[3];
		group[0] = i;
		group[1] = 0;
		group[2] = i;
		groups[i] = group;
		//ustawiamy drogi do s¹siadów
		for (int j = i+1; j < countOfVertices; j++) {
			if (graph->matrix[i][j] != INT32_MAX) {
				
				int* edge = new int[3];
				edge[0] = i;
				edge[1] = j;
				edge[2] = graph->matrix[i][j];
				edges[k] = edge;
				k++;
			}
		}
	}
	//Tworzymy  kopiec
	Heap* heap = new Heap();
	for (int i = 0; i < graph->countOfEdges; i++) {
		heap->pushForKruskal(i, edges[i][2]);
	}
	//Przechowuje rozwi¹zanie
	mstEdges = new int* [countOfEdges];
	//pobieramy dane z kopca 
	
	for (int i = 0; heap->noEmpty(); ) {
		int edge = heap->pop();
		int u = edges[edge][0];
		int v = edges[edge][1];
		if (findSet(groups, u) != findSet(groups, v)) {
			mstEdges[i] = edges[edge];
			unionSets(groups, u, v);
			i++;
		}
	}
}	
void MST::kruskalOnList(Graph* graph) {
	//tworzymy krawêdzie i sety
	countOfEdges = graph->countOfVertices - 1;
	int countOfVertices = graph->countOfVertices;
	int** edges = new int* [graph->countOfEdges];
	//przechowuje 0-set, 1-rank, 2-parent
	int** groups = new int* [countOfVertices];

	for (int i = 0, k = 0; i < countOfVertices; i++) {
		int* group = new int[3];
		group[0] = i;
		group[1] = 0;
		group[2] = i;
		groups[i] = group;
		//ustawiamy drogi do s¹siadów
		List* list = graph->list[i];
		ListItem* listItem = list->head;
		while (listItem) {
			if (listItem->vertice > i) {
				int* edge = new int[3];
				edge[0] = i;
				edge[1] = listItem->vertice;
				edge[2] = listItem->edgeCost;
				edges[k] = edge;
				k++;
			}
			
			listItem = listItem->next;
		}
	}
	//Tworzymy  kopiec
	Heap* heap = new Heap();
	for (int i = 0; i < graph->countOfEdges; i++) {
		heap->pushForKruskal(i, edges[i][2]);
	}
	//Przechowuje rozwi¹zanie
	mstEdges = new int* [countOfEdges];
	//pobieramy dane z kopca 

	for (int i = 0; heap->noEmpty(); ) {
		int edge = heap->pop();
		int u = edges[edge][0];
		int v = edges[edge][1];
		if (findSet(groups, u) != findSet(groups, v)) {
			mstEdges[i] = edges[edge];
			unionSets(groups, u, v);
			i++;
		}
	}
}
int MST::findSet(int** groups, int x) {
	if (groups[x][2] != x)
		groups[x][2] = findSet(groups, groups[x][2]);
	return groups[x][2];
}
void MST::unionSets(int** groups, int u, int v) {
	u = findSet(groups, u);
	v = findSet(groups, v);
	if (groups[u][1] < groups[v][1]) {
		groups[u][2] = v;
	}
	else {
		groups[v][2] = u;
	}

	if (groups[u][1] == groups[v][1]) {
		groups[u][1]++;
	}


}