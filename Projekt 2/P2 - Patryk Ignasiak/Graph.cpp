#include "Graph.h"
#include <string>
#include <iostream>
#include <sstream>
#include "List.h"

using namespace std;


bool Graph::fileReadLine(ifstream &file, int tab[], int size)
{
	string s;
	getline(file, s);

	if (file.fail() || s.empty())
		return(false);

	istringstream in_ss(s);

	for (int i = 0; i < size; i++)
	{
		in_ss >> tab[i];
		if (in_ss.fail())
			return(false);
	}
	return(true);
}
void Graph::fileReadGraph(std::string fileName, bool isMST)
{
	ifstream file;
	int tab[4];
	file.open(fileName.c_str());

	if (file.is_open())
	{
		if (fileReadLine(file, tab, 4))
		{
			//przypisujemy podstawowe parametry grafu
			this->countOfEdges = tab[0];
			this->countOfVertices = tab[1];
			this->startVertice = tab[2];
			this->endVertice = tab[3];

			//Tworzymy macierz
			createMatrix();
			//Tworzymy Listê
			createList();
			
			//Pobieramy z pliku s¹siadów i dodajemy do macierzy i listy
			for (int i = 0; i < countOfEdges; i++)
				if (fileReadLine(file, tab, 3))
				{
					matrix[tab[0]][tab[1]] = tab[2];
					list[tab[0]]->pushFront(tab[1], tab[2]);
					if (isMST) {
						matrix[tab[1]][tab[0]] = tab[2];
						list[tab[1]]->pushFront(tab[0], tab[2]);
					}
				}
				else
				{
					cout << "File error - READ EDGE" << endl;
					break;
				}
		}
		else
			cout << "File error - READ INFO" << endl;
		file.close();
	}
	else
		cout << "File error - OPEN" << endl;
}

void Graph::createMatrix() {
	//Tworzymy masierz o wymiarach VxV i wype³niamy j¹ "nieskoñczonoœciami"
	matrix = new int* [countOfVertices];
	for (int i = 0; i < countOfVertices; i++) {
		matrix[i] = new int[countOfVertices];
		for (int j = 0; j < countOfVertices; j++) {
			matrix[i][j] = INF;
		}
	}
}

void Graph::showMatrix() {
	cout << endl << "Macierz s¹siedztwa" << endl << endl;
	cout << "  ";
	for (int i = 0; i < countOfVertices; i++) {
		printf("%2d ", i);
	}
	cout << endl;
	for (int i = 0; i < countOfVertices; i++) {
		printf("%2d ", i);
		for (int j = 0; j < countOfVertices; j++) {
			if (matrix[i][j] != INT32_MAX) {
				printf("%2d ", matrix[i][j]);
			}
			else {
				cout << " ~" << " ";
			}
			
		}
		cout << endl;
	}
}
void Graph::createList() {
	//Tworzymy listê s¹siadów
	list = new List* [countOfVertices];
	for (int i = 0; i < countOfVertices; i++) {
		list[i] = new List();
	}
}
void Graph::showList() {
	cout << endl << "Lista s¹siadów" << endl;
	cout << "v(c), gdzie v - wierzcho³ek, c - koszt krawêdzi" << endl << endl;
	for (int i = 0; i < countOfVertices; i++) {
		cout << i << ":";
		list[i]->showList();
		cout << endl;
	}
}