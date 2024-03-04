#include "TimeTest.h"

#include <chrono>
#include <iostream>

using namespace std;

void TimeTest::mst() {
	int z = 0;
	string line = "Reprezentacja; Iloœæ wierzcho³ków; Gêstoœæ; Kruskal[us]; Prim[us]";
	for (int i = 0; i < countOfVertices; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 100; k++) {
				data.generateData(vertices[i], filling[j], "testfile", 0, 99, true);

				graph = new Graph();
				graph->fileReadGraph("testfile", true);
				mstObj = new MST();
				//Lista
				auto start = chrono::steady_clock::now();
				mstObj->kruskalOnList(graph);
				auto end = chrono::steady_clock::now();
				auto duration = end - start;

				times[z][0] = 0; //0 - lista, 1 - macierz
				times[z][1] = vertices[i]; //iloœæ wierzcho³ków
				times[z][2] = filling[j]; //iloœæ gêstoœæ
				times[z][3] += chrono::duration_cast<chrono::microseconds>(duration).count(); //Kruskal

				start = chrono::steady_clock::now();
				mstObj->primOnList(graph);
				end = chrono::steady_clock::now();
				duration = end - start;

				times[z][4] += chrono::duration_cast<chrono::microseconds>(duration).count(); //Prim
				z++;

				//Macierz
				start = chrono::steady_clock::now();
				mstObj->kruskalOnMatrix(graph);
				end = chrono::steady_clock::now();
				duration = end - start;

				times[z][0] = 1; //0 - lista, 1 - macierz
				times[z][1] = vertices[i]; //iloœæ wierzcho³ków
				times[z][2] = filling[j]; //iloœæ gêstoœæ
				times[z][3] += chrono::duration_cast<chrono::microseconds>(duration).count(); //Kruskal

				start = chrono::steady_clock::now();
				mstObj->primOnMatrix(graph);
				end = chrono::steady_clock::now();
				duration = end - start;

				times[z][4] += chrono::duration_cast<chrono::microseconds>(duration).count(); //Prim
				z--;
				delete mstObj;
				delete graph;
			}
			cout << z << endl;
			z += 2;
		}
	}
	
	data.saveTimeTestResult(times, "mst.txt", line);
}
void TimeTest::shortestPath() {
	int z = 0;
	string line = "Reprezentacja; Iloœæ wierzcho³ków; Gêstoœæ; Dijkstra[us]; Bellman-Ford[us]";
	for (int i = 0; i < countOfVertices; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 100; k++) {
				data.generateData(vertices[i], filling[j], "testfile", 0, 99, true);

				graph = new Graph();
				graph->fileReadGraph("testfile", true);
				sPath = new ShortestPath();
				//Lista
				auto start = chrono::steady_clock::now();
				sPath->dijkstraOnList(graph);
				auto end = chrono::steady_clock::now();
				auto duration = end - start;

				times[z][0] = 0; //0 - lista, 1 - macierz
				times[z][1] = vertices[i]; //iloœæ wierzcho³ków
				times[z][2] = filling[j]; //iloœæ gêstoœæ
				times[z][3] += chrono::duration_cast<chrono::microseconds>(duration).count(); //Kruskal

				start = chrono::steady_clock::now();
				sPath->bellmanFordOnList(graph);
				end = chrono::steady_clock::now();
				duration = end - start;

				times[z][4] += chrono::duration_cast<chrono::microseconds>(duration).count(); //Prim
				z++;

				//Macierz
				start = chrono::steady_clock::now();
				sPath->dijkstraOnMatrix(graph);
				end = chrono::steady_clock::now();
				duration = end - start;

				times[z][0] = 1; //0 - lista, 1 - macierz
				times[z][1] = vertices[i]; //iloœæ wierzcho³ków
				times[z][2] = filling[j]; //iloœæ gêstoœæ
				times[z][3] += chrono::duration_cast<chrono::microseconds>(duration).count(); //Kruskal

				start = chrono::steady_clock::now();
				sPath->bellmanFordOnMatrix(graph);
				end = chrono::steady_clock::now();
				duration = end - start;

				times[z][4] += chrono::duration_cast<chrono::microseconds>(duration).count(); //Prim
				z--;

				delete sPath;
				delete graph;
			}
			cout << z << endl;
			z += 2;
		}
	}

	data.saveTimeTestResult(times, "sPath.txt", line);

}
void TimeTest::fordFulkerson() {
	int z = 0;
	string line = "Reprezentacja; Iloœæ wierzcho³ków; Gêstoœæ; Ford-Fulkerson [us]; -";
	for (int i = 0; i < countOfVertices; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 100; k++) {
				data.generateData(vertices[i], filling[j], "testfile", 0, 99, true);

				graph = new Graph();
				graph->fileReadGraph("testfile", true);
				mf = new MaxFlow();
				//Lista
				auto start = chrono::steady_clock::now();
				mf->fordFulkerson(graph, false);
				auto end = chrono::steady_clock::now();
				auto duration = end - start;

				times[z][0] = 0; //0 - lista, 1 - macierz
				times[z][1] = vertices[i]; //iloœæ wierzcho³ków
				times[z][2] = filling[j]; //iloœæ gêstoœæ
				times[z][3] += chrono::duration_cast<chrono::microseconds>(duration).count(); //Ford-Fulkerson

				
				z++;

				//Macierz
				start = chrono::steady_clock::now();
				mf->fordFulkerson(graph, true);
				end = chrono::steady_clock::now();
				duration = end - start;

				times[z][0] = 1; //0 - lista, 1 - macierz
				times[z][1] = vertices[i]; //iloœæ wierzcho³ków
				times[z][2] = filling[j]; //iloœæ gêstoœæ
				times[z][3] += chrono::duration_cast<chrono::microseconds>(duration).count(); //Ford-Fulkerson

				z--;

				delete sPath;
				delete graph;
			}
			cout << z << endl;
			z += 2;
		}
	}

	data.saveTimeTestResult(times, "maxFlow.txt", line);
}