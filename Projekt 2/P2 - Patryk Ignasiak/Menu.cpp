#include "Menu.h"
#include <iostream>
#include "TimeTest.h"
#include "MST.h"
#include <chrono>
#include "ShortestPath.h"
#include "Data.h"
#include "MaxFlow.h"

using namespace std;

void Menu::mainMenu() {
	//Tworzy obiekt test�w automatycznych
	TimeTest timeTest = TimeTest();
	//Przechowuje wyb�r u�ytkownika
	int nr;
	//obs�uguje zap�tlenie menu
	bool menu = true;

	while (menu) {
		showTestType();

		cout << "Menu" << endl;
		cout << "1. Wyznaczenie minimalnego drzewa rozpinaj�cego" << endl;
		cout << "2. Wyznaczenie najkr�tszej drogi w grafie" << endl;
		cout << "3. Wyznaczenie maksymalnego przep�ywu" << endl;
		cout << "4. Ustaw/zmie� typ test�w" << endl;
		cout << "5. Wygeneruj dane do test�w" << endl;
		cout << "0. Wyj�cie" << endl;
		cout << "Wybierz numer: ";
		cin >> nr;
		system("CLS");

		//Wywo�uje odpowiednie menu lub test w zale�no�ci od zmiennej - isTimeTest
		switch (nr) {
		case 1: {
			if (isTimeTest) {
				timeTest.mst();
			}
			else {
				mstMenu();
			}
		}break;
		case 2: {
			if (isTimeTest) {
				timeTest.shortestPath();
			}
			else {
				pathMenu();
			}
		}break;
		case 3: {
			if (isTimeTest) {
				timeTest.fordFulkerson();
			}
			else {
				flowMenu();
			}
		} break;
		case 4: chooseTestType(); break;
		case 5: {
			//Tworzy obiekt obs�uguj�cy dane
			Data data = Data();
			int vertices, percent, min, max, choose;
			string filename;
			bool isMST = false;

			cout << "Podaj rozmiar grafu: ";
			cin >> vertices;

			cout << "Podaj g�sto�� grafu[%]: ";
			cin >> percent;

			cout << "Podaj minimaln� wag� kraw�dzi: ";
			cin >> min;

			cout << "Podaj maksymaln� wag� kraw�dzi: ";
			cin >> max;

			cout << "Je�li chcesz znale�� MST podaj 1 : ";
			cin >> choose;

			cout << "Podaj nazw� pliku do zapisania danych: ";
			cin >> filename;
			cout << "Trwa generowanie danych..." << endl;

			if (choose == 1) {
				isMST = true;
			}
			data.generateData(vertices, percent,  filename, min, max, isMST);
			system("CLS");

		}break;
		default: exit(0);
		}
	}
}
void Menu::mstMenu() {
	graph = new Graph(); 
	MST mst = MST();
	//Przechowuje wyb�r u�ytkownika
	int nr;
	//obs�uguje zap�tlenie menu
	bool menu = true, data = false;

	while (menu) {
		cout << endl << "Menu - Minimalne drzewo rozpinaj�ce" << endl;
		cout << "1. Wczytanie grafu z pliku" << endl;
		cout << "2. Wy�wietlenie grafu macierzowo i listowo" << endl;
		cout << "3. Algorytm Kruskala" << endl;
		cout << "4. Algorytm Prima" << endl;
		cout << "0. Powr�t" << endl;

		cout << "Wybierz numer: ";
		cin >> nr;

		switch (nr) {
		case 1: {
			string filename;
			cout << "Podaj nazw� pliku: ";
			cin >> filename;
			
			graph->fileReadGraph(filename, true);
			data = true;
		}break;
		case 2: {
			if (data) {
				graph->showMatrix();
				graph->showList();
			}
			else {
				cout << "Graf jest pusty!!!" << endl;
			}
		}break;
		case 3: {
			if (data) {
				cout << "\nAlgorytm na li�cie" << endl;

				auto start = chrono::steady_clock::now();
				mst.kruskalOnList(graph);
				auto end = chrono::steady_clock::now();

				mst.showResult();
			
				auto duration = end - start;

				cout << "Algorytm Kruskala na li�cie zajmuje [ns]: ";
				cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl << endl;

				cout << "Algorytm na macierzy" << endl;

				start = chrono::steady_clock::now();
				mst.kruskalOnMatrix(graph);
				end = chrono::steady_clock::now();

				mst.showResult();

				duration = end - start;

				cout << "Algorytm Kruskala na macierzy zajmuje [ns]: ";
				cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;
			}
			else {
				cout << "Graf jest pusty!!!" << endl;
			}

		} break;
		case 4: {
			if (data) {
				cout << "\nAlgorytm na li�cie" << endl; 

				auto start = chrono::steady_clock::now(); 
				mst.primOnList(graph); 
				auto end = chrono::steady_clock::now();  

				mst.showResult(); 

				auto duration = end - start; 
			 
				cout << "Algorytm Prima na li�cie zajmuje [ns]: "; 
				cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl <<endl; 
			  
				cout << "Algorytm na macierzy" << endl; 

				start = chrono::steady_clock::now(); 
				mst.primOnMatrix(graph); 
				end = chrono::steady_clock::now(); 

				mst.showResult(); 

				duration = end - start; 
			 
				cout << "Algorytm Prima na macierzy zajmuje [ns]: ";
				cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl; 
			}
			else {
				cout << "Graf jest pusty!!!" << endl;
			}
		} break;
		default: menu=false;
		}
		if (nr != 2 && menu && data) {
			graph->showMatrix();
			graph->showList();
		}
	}
}
void Menu::pathMenu() {
	graph = new Graph();
	ShortestPath sp = ShortestPath();
	//Przechowuje wyb�r u�ytkownika
	int nr;
	//obs�uguje zap�tlenie menu
	bool menu = true, data = false;

	while (menu) {
		cout << endl << "Menu - Najkr�tsza �cie�ka w grafie" << endl;
		cout << "1. Wczytanie grafu z pliku" << endl;
		cout << "2. Wy�wietlenie grafu macierzowo i listowo" << endl;
		cout << "3. Algorytm Dijkstry" << endl;
		cout << "4. Algorytm  Bellmana-Forda" << endl;
		cout << "0. Powr�t" << endl;

		cout << "Wybierz numer: ";
		cin >> nr;

		switch (nr) {
		case 1: {
			string filename;
			cout << "Podaj nazw� pliku: ";
			cin >> filename;

			graph->fileReadGraph(filename, false);
			data = true;
		}break;
		case 2: {
			if (data) {
				graph->showMatrix();
				graph->showList();
			}
			else {
				cout << "Graf jest pusty!!!" << endl;
			}
		}break;
		case 3: {
			if (data) {
				cout << "\nAlgorytm na li�cie" << endl;

				auto start = chrono::steady_clock::now();
				sp.dijkstraOnList(graph);
				auto end = chrono::steady_clock::now();

				sp.showResult();

				auto duration = end - start;

				cout << "Algorytm Dijkstry na li�cie zajmuje [ns]: ";
				cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl << endl;

				cout << "Algorytm na macierzy" << endl;

				start = chrono::steady_clock::now();
				sp.dijkstraOnMatrix(graph);
				end = chrono::steady_clock::now();

				sp.showResult();

				duration = end - start;

				cout << "Algorytm Dijkstry na macierzy zajmuje [ns]: ";
				cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;
			}
			else {
				cout << "Graf jest pusty!!!" << endl;
			}
		} break;
		case 4: {
			if (data) {
				cout << "\nAlgorytm na li�cie" << endl;

				auto start = chrono::steady_clock::now();
				sp.bellmanFordOnList(graph);
				auto end = chrono::steady_clock::now();

				sp.showResult();

				auto duration = end - start;

				cout << "Algorytm Bellmana-Forda na li�cie zajmuje [ns]: ";
				cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl << endl;

				cout << "Algorytm na macierzy" << endl;

				start = chrono::steady_clock::now();
				sp.bellmanFordOnMatrix(graph);
				end = chrono::steady_clock::now();

				sp.showResult();

				duration = end - start;

				cout << "Algorytm Bellmana-Forda na macierzy zajmuje [ns]: ";
				cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;
			}
			else {
				cout << "Graf jest pusty!!!" << endl;
			}
		} break;
		default: menu = false;
		}
		if (nr != 2 && menu && data) {
			graph->showMatrix();
			graph->showList();
		}
	}
}
void Menu::flowMenu() {
	graph = new Graph();
	//Przechowuje wyb�r u�ytkownika
	int nr;
	//obs�uguje zap�tlenie menu
	bool menu = true, data = false;
	MaxFlow mf = MaxFlow();

	while (menu) {
		cout << endl << "Menu - Maksymalny przep�yw" << endl;
		cout << "1. Wczytanie grafu z pliku" << endl;
		cout << "2. Wy�wietlenie grafu macierzowo i listowo" << endl;
		cout << "3. Algorytm  Forda-Fulkersona" << endl;
		cout << "0. Powr�t" << endl;

		cout << "Wybierz numer: ";
		cin >> nr;

		switch (nr) {
		case 1: {
			string filename;
			cout << "Podaj nazw� pliku: ";
			cin >> filename;

			graph->fileReadGraph(filename, false);
			data = true;
		}break;
		case 2: {
			if (data) {
				graph->showMatrix();
				graph->showList();
			}
			else {
				cout << "Graf jest pusty!!!" << endl;
			}
		}break;
		case 3: {
			if (data) {
				cout << "\nWierzcho�ek statrowy: " << graph->startVertice << endl;
				cout << "Wierzcho�ek ko�cowy: " << graph->endVertice << endl;
				cout << "\nAlgorytm na li�cie" << endl;

				auto start = chrono::steady_clock::now();
				mf.fordFulkerson(graph, false);
				auto end = chrono::steady_clock::now();

				mf.showResult();

				auto duration = end - start;

				cout << "Algorytm FordaFulkersona na li�cie zajmuje [ns]: ";
				cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl << endl;

				cout << "Algorytm na macierzy" << endl;

				start = chrono::steady_clock::now();
				mf.fordFulkerson(graph, true);
				end = chrono::steady_clock::now();

				mf.showResult();

				duration = end - start;

				cout << "Algorytm Forda-Fulkersona na macierzy zajmuje [ns]: ";
				cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;
			}
			else {
				cout << "Graf jest pusty!!!" << endl;
			}
		} break;
		default: menu = false;
		}
		if (nr != 2 && menu && data) {
			graph->showMatrix();
			graph->showList();
		}
	}
}
void Menu::chooseTestType() {
	int nr;

	cout << "1. Testy struktury" << endl;
	cout << "2. Testy czasu" << endl;
	cout << "0. Powr�t" << endl;
	cout << "Wybierz numer: ";
	cin >> nr;
	system("CLS");

	//Ustawiamy wybrany typ
	switch (nr) {
	case 1: isTimeTest = false; break;
	case 2: isTimeTest = true; break;
	default: mainMenu();
	}
}
void Menu::showTestType() {
	if (isTimeTest) {
		cout << "\nTesty czasu \n" << endl;
	}
	else {
		cout << "\nTesty struktury \n" << endl;
	}
}