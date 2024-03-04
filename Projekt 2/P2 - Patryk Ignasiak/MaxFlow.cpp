#include "MaxFlow.h"
#include <iostream>

using namespace std;

void MaxFlow::fordFulkerson(Graph* graph, bool onMatrix) {
	maxFlow = 0;
	countOfEdges = graph->countOfEdges;
	countOfVertices = graph->countOfVertices;
	if (onMatrix) {
		rGraph = createRGraphFromMatrix(graph->matrix);
	}
	else {
		rGraph = createRGraphFromList(graph->list);
	}
	
	int* parent = new int[countOfVertices];
	
	while (isPath(rGraph, graph->startVertice, graph->endVertice, parent)) {
		int pathFlow = INT32_MAX;
		//Szukanie przep³ywu w œcie¿ce
		for (int v = graph->endVertice; v != graph->startVertice; v = parent[v]) {
			int u = parent[v];
			
			if (pathFlow > rGraph[u][v]) {
				pathFlow = rGraph[u][v];
			}
		}

		//Aktualizacja rGraph
		for (int v = graph->endVertice; v != graph->startVertice; v = parent[v]) {
			int u = parent[v];
			rGraph[u][v] -= pathFlow;
			if (rGraph[v][u] == INT32_MAX) {
				rGraph[v][u] = 0;
			}
			rGraph[v][u] += pathFlow;
		}
		maxFlow += pathFlow;
	}
}
int** MaxFlow::createRGraphFromMatrix(int** matrix) {
	int** rGraph = new int* [countOfVertices];

	for (int i = 0; i < countOfVertices; i++) {
		int* rRow = new int[countOfVertices];
		for (int j = 0; j < countOfVertices; j++) {
			rRow[j] = matrix[i][j];
		}
		rGraph[i] = rRow;

	}

	return rGraph;
}
int** MaxFlow::createRGraphFromList(List** list) {
	int** rGraph = new int* [countOfVertices];

	for (int i = 0; i < countOfVertices; i++) {
		int* rRow = new int[countOfVertices];
		for (int j = 0; j < countOfVertices; j++) {
			rRow[j] = INT32_MAX;
		}
		rGraph[i] = rRow;
		ListItem* listItem = list[i]->head;
		while (listItem != NULL) {
			rGraph[i][listItem->vertice] = listItem->edgeCost;
			listItem = listItem->next;
		}
	}

	return rGraph;
}
bool MaxFlow::isPath(int** rGraph, int start, int end, int* parent){
	bool* visited = new bool[countOfVertices];
	for (int i = 0; i < countOfVertices; i++) {
		visited[i] = false;
	}
	List* queue = new List();
	queue->pushFront(start, 0);
	while (!queue->isEmpty()) {
		int u = queue->popFront();
		if (!visited[u]) {
			visited[u] = true;
			for (int i = 0; i < countOfVertices; i++) {
				if (visited[i] == false && rGraph[u][i] != INT32_MAX && rGraph[u][i] != 0) {
					parent[i] = u;
					queue->pushFront(i, 0);
				}
			}
		}
	}
	return (visited[end] == true);
}
void MaxFlow::showResult() {
	int** edges = new int* [countOfEdges];
	int k = 0;
	cout << " Edge  Flow(max/used) " << endl;
	for (int i = 0; i < countOfVertices; i++) {
		for (int j = 0; j < countOfVertices; j++) {
			if (rGraph[i][j] != INT32_MAX) {
				bool isUnique = true;

				for (int x = 0; x < k; x++) {

					if (i == edges[x][1] && j == edges[x][0]) {
						isUnique = false;
					}
				}
				if (isUnique) {

					cout << " (" << i << "-" << j << ") | ";
					if (rGraph[j][i] == INT32_MAX) {
						cout << rGraph[i][j] << " / 0" << endl;
					}
					else {
						cout << rGraph[i][j] + rGraph[j][i] << " / " << rGraph[j][i] << endl;
					}

					int* edge = new int[2];
					edge[0] = i;
					edge[1] = j;
					edges[k] = edge;
					k++;
				}
			}
		}
	}
	cout << endl << "MaxFlow: " << maxFlow << endl;
}



