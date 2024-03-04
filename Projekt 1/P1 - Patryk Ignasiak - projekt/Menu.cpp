#include "Menu.h"
#include "Array.h"
#include "List.h"
#include <iostream>
#include <chrono>
#include "Data.h"
#include "Heap.h"
#include "TestTime.h"
#include "BST.h"
#include "RBT.h"

using namespace std;
bool Menu::isTimeTest = false;
void Menu::arrayMenu() {
	//Tworzy obiekt tablicy 
	Array* array = new Array(); 
	
	//Przechowuje wyb�r u�ytkownika
	int nr;
	//obs�uguje zap�tlenie menu
	bool menu = true;

	while (menu) {
		showTestType();

		cout << "Menu tablicy" << endl;
		cout << "1. Dodaj dane z pliku do tablicy" << endl;
		cout << "2. Wy�wietl tablic�" << endl;
		cout << "3. Dodaj element na pocz�tek tablicy" << endl;
		cout << "4. Dodaj element na koniec tablicy" << endl;
		cout << "5. Dodaj element na wybran� pozycje tablicy" << endl;
		cout << "6. Usu� pierwszy element z tablicy" << endl;
		cout << "7. Usu� ostatni element z tablicy" << endl;
		cout << "8. Usu� element na wybranej pozycji z tablicy" << endl;
		cout << "9. Wyszukaj element w tablicy" << endl;
		cout << "0. Powr�t" << endl;
		cout << "Wybierz numer: ";
		cin >> nr;

		//Wywo�ywanie wybranej operacji
		switch (nr) {
		case 1: {
			string filename;

			cout << "Podaj nazw� pliku: ";
			cin >> filename;
			array->loadData(filename);
		} break;
		case 2: {
			array->showArray();
		} break;
		case 3: {
			int number;

			cout << "Podaj liczb� do wstawienia:" << endl;
			cin >> number;

			auto start = chrono::steady_clock::now();
			array->pushFront(number);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "Dodanie elementu na pocz�tek zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;
		}break;
		case 4: {
			int number;

			cout << "Podaj liczb� do wstawienia:" << endl;
			cin >> number;

			auto start = chrono::steady_clock::now();
			array->pushBack(number);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;
			cout << "Dodanie elementu na koniec zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;

		}break;
		case 5: {
			int number, index;

			cout << "Podaj liczb� do wstawienia:" << endl;
			cin >> number;
			cout << "Podaj index na kt�ry ma by� wstawiona liczba:" << endl;
			cin >> index;

			auto start = chrono::steady_clock::now();
			array->pushOnIndex(index, number);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "Dodanie elementu na pozycj� o podanym indeksie zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;
		} break;
		case 6: {
			auto start = chrono::steady_clock::now();
			array->popFront();
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "Usuni�cie elementu z pocz�tku zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;
		}break;
		case 7: {
			auto start = chrono::steady_clock::now();
			array->popBack();
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "Usuni�cie elementu z ko�ca zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;
		}break;
		case 8: {
			int index;

			cout << "Podaj index liczby do usuni�cia:" << endl;
			cin >> index;

			auto start = chrono::steady_clock::now();
			array->popOnIndex(index);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "Usuni�cie elementu z podanej pozycji zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;
		}break;
		case 9: {
			int number, index;

			cout << "Podaj liczb� do wyszukania:" << endl;
			cin >> number;

			auto start = chrono::steady_clock::now();
			index = array->find(number);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "Dodanie elementu na koniec zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;

			if (index != -1) {
				cout << "Podana liczba znajduje si� na pozycji ";
				cout << index << endl;
			}
			else {
				cout << "Nie uda�o si� znale�� podanego elementu w tablicy" << endl;
			}
		}break;
		default: menu = false;
		}
		//Po ka�dej operacji z wyj�tkiem wy�wietlenia tablicy i wyj�cia z menu wy�wietlamy tablic�
		if (menu && nr != 2) {
			array->showArray();
		}
	}
}
void Menu::listMenu() {
	//Tworzy obiekt listy
	List* list = new List(); 
	
	//Przechowuje wyb�r u�ytkownika
	int nr;
	//obs�uguje zap�tlenie menu
	bool menu = true;

	while (menu) {
		showTestType();

		cout << "Menu listy" << endl;
		cout << "1. Dodaj dane z pliku do listy" << endl;
		cout << "2. Wy�wietl list�" << endl;
		cout << "3. Wy�wietl list� od ty�u" << endl;
		cout << "4. Dodaj element na pocz�tek listy" << endl;
		cout << "5. Dodaj element na koniec listy" << endl;
		cout << "6. Dodaj element na wybran� pozycje listy" << endl;
		cout << "7. Usu� pierwszy element z listy" << endl;
		cout << "8. Usu� ostatni element z listy" << endl;
		cout << "9. Usu� element na wybranej pozycji z listy" << endl;
		cout << "10. Wyszukaj element w li�cie" << endl;
		cout << "0.Powr�t" << endl;
		cout << "Wybierz numer: ";
		cin >> nr;

		switch (nr) {
		case 1: {
			string filename;

			cout << "Podaj nazw� pliku: ";
			cin >> filename;

			list->loadData(filename);
		} break;
		case 2: {
			list->showList();
		} break;
		case 3: {
			list->showListReverse();
		} break;
		case 4: {
			int number;

			cout << "Podaj liczb� do wstawienia:" << endl;
			cin >> number;

			auto start = chrono::steady_clock::now();
			list->pushFront(number);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "Dodanie elementu na pocz�tek zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;


		}break;
		case 5: {
			int number;

			cout << "Podaj liczb� do wstawienia:" << endl;
			cin >> number;

			auto start = chrono::steady_clock::now();
			list->pushBack(number);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "Dodanie elementu na koniec zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;


		}break;
		case 6: {
			int number, index;

			cout << "Podaj liczb� do wstawienia:" << endl;
			cin >> number;
			cout << "Podaj index na kt�ry ma by� wstawiona liczba:" << endl;
			cin >> index;

			auto start = chrono::steady_clock::now();
			list->pushOnIndex(index, number);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "Dodanie elementu na pozycj� o podanym indeksie zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;

		} break;
		case 7: {
			auto start = chrono::steady_clock::now();
			list->popFront();
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "Usuni�cie elementu z pocz�tku zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;

		}break;
		case 8: {
			auto start = chrono::steady_clock::now();
			list->popBack();
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "Usuni�cie elementu z ko�ca zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;

		}break;
		case 9: {
			int index;

			cout << "Podaj index liczby do usuni�cia:" << endl;
			cin >> index;

			auto start = chrono::steady_clock::now();
			list->popOnIndex(index);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "Usuni�cie elementu z podanej pozycji zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;

		}break;
		case 10: {
			int number, index;

			cout << "Podaj liczb� do wyszukania:" << endl;
			cin >> number;


			auto start = chrono::steady_clock::now();
			index = list->find(number);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "Dodanie elementu na koniec zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;

			if (index != -1) {
				cout << "Podana liczba znajduje si� na pozycji ";
				cout << index << endl;
			}
			else {
				cout << "Nie uda�o si� znale�� podanego elementu w li�cie" << endl;
			}
		}break;
		default: menu = false;
		}
		//Po ka�dej operacji z wyj�tkiem wy�wietlenia listy i wyj�cia z menu wy�wietlamy list�
		if (menu && nr != 2) {
			list->showList();
		}
	}
}
void Menu::heapMenu() {
	//Tworzy obiekt kopca
	Heap* heap = new Heap(); 
	
	//Przechowuje wyb�r u�ytkownika
	int nr;
	//obs�uguje zap�tlenie menu
	bool menu = true;

	while (menu) {
		showTestType();

		cout << "Menu kopca" << endl;
		cout << "1. Dodaj dane z pliku do kopca" << endl;
		cout << "2. Dodaj dane z pliku do kopca (algorytm floyda)" << endl;
		cout << "3. Wy�wietl kopiec" << endl;
		cout << "4. Dodaj element do kopca" << endl;
		cout << "5. Usu� element z kopca" << endl;
		cout << "6. Wyszukaj element w kopcu" << endl;
		cout << "0.Powr�t" << endl;
		cout << "Wybierz numer: ";
		cin >> nr;

		switch (nr) {
		case 1: {
			string filename;

			cout << "Podaj nazw� pliku: ";
			cin >> filename;

			heap->loadData(filename, false);

		} break;
		case 2: {
			string filename;

			cout << "Podaj nazw� pliku: ";
			cin >> filename;

			heap->loadData(filename, true);
		} break;
		case 3: {
			heap->showHeapArray();
			heap->showHeap("", "", 0);
		} break;
		case 4: {
			int number;

			cout << "Podaj liczb� do wstawienia:" << endl;
			cin >> number;

			auto start = chrono::steady_clock::now();
			heap->push(number);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "\nDodanie elementu na pocz�tek zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;


		}break;
		case 5: {
			auto start = chrono::steady_clock::now();
			heap->pop();
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "\nUsuni�cie elementu z pocz�tku zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;

		}break;
		case 6: {
			int number, index;

			cout << "Podaj liczb� do wyszukania:" << endl;
			cin >> number;

			auto start = chrono::steady_clock::now();
			index = heap->find(number);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "\nDodanie elementu na koniec zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;

			if (index != -1) {
				cout << "Podana liczba znajduje si� na pozycji ";
				cout << index << endl;
			}
			else {
				cout << "Nie uda�o si� znale�� podanego elementu w li�cie" << endl;
			}
		}break;
		default: menu = false;
		}
		//Po ka�dej operacji z wyj�tkiem wy�wietlenia kopca i wyj�cia z menu wy�wietlamy kopiec
		if (menu && nr != 3) {
			heap->showHeapArray();
			heap->showHeap("", "", 0);
		}
	}
}
void Menu::bstMenu() {
	//Tworzy obiekt drzewa bst
	BST* bst = new BST();
	
	//Przechowuje wyb�r u�ytkownika
	int nr;
	//obs�uguje zap�tlenie menu
	bool menu = true;

	while (menu) {
		showTestType();

		cout << "Menu drzewa BST" << endl;
		cout << "1. Dodaj dane z pliku do drzewa" << endl;
		cout << "2. Wy�wietl drzewo BST" << endl;
		cout << "3. Wy�wietlanie preorder" << endl;
		cout << "4. Wy�wietlanie inorder" << endl;
		cout << "5. Wy�wietlanie postorder" << endl;
		cout << "6. Dodaj element do drzewa" << endl;
		cout << "7. Usu� element z drzewa" << endl;
		cout << "8. Wyszukaj element w drzewie" << endl;
		cout << "0.Powr�t" << endl;
		cout << "Wybierz numer: ";
		cin >> nr;

		switch (nr) {
		case 1: {
			string filename;

			cout << "Podaj nazw� pliku: ";
			cin >> filename;

			bst->loadData(filename);

		} break;
		case 2: {
			bst->showBST("", "", bst->getRoot());
		} break;
		case 3: {
			bst->preorder(bst->getRoot());
		} break;
		case 4: {
			bst->inorder(bst->getRoot());
		} break;
		case 5: {
			bst->postorder(bst->getRoot());
		} break;
		case 6: {
			int number;

			cout << "Podaj liczb� do wstawienia:" << endl;
			cin >> number;

			auto start = chrono::steady_clock::now();
			bst->insertNode(number);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "\nDodanie elementu do drzewa zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;

		}break;
		case 7: {
			int number;

			cout << "Podaj liczb� do usuni�cia:" << endl;
			cin >> number;

			auto start = chrono::steady_clock::now();
			bst->deleteNode(number);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "\nUsuni�cie elementu z drzewa zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;

		}break;
		case 8: {
			int number;
			//Wska�nik na w�ze�
			BSTNode* node;

			cout << "Podaj klucz do wyszukania:" << endl;
			cin >> number;

			auto start = chrono::steady_clock::now();
			node = bst->find(number);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "\nWyszukiwanie elementu w drzewie zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;

			//Trudno w drzewie wskaza� dok�adne po�o�enie w�z�a
			//Wi�c wy�wietlam szczeg�owe informacje
			if (node != NULL) {
				if (node->parent == NULL) {
					cout << "Podany klucz jest korzeniem" << endl;
				}
				else {
					cout << "Podany klucz jest dzieckiem: " << node->parent->key << endl;
				}
				if (node->left != NULL && node->right != NULL) {
					cout << "Podany klucz ma dwoje dzieci: " << node->left->key << ", " << node->right->key << endl;
				}
				else if (node->left != NULL) {
					cout << "Podany klucz ma jedno dziecko: " << node->left->key << endl;
				}
				else {
					cout << "Podany klucz jest li�ciem" << endl;
				}
			}
			else {
				cout << "Podany klucz nie znajduje si� w drzewie" << endl;
			}
		}break;
		default: menu = false;
		}
		//Po ka�dej operacji z wyj�tkiem wy�wietlenia bst i wyj�cia z menu wy�wietlamy bst
		if (menu && nr != 2) {
			bst->showBST("", "", bst->getRoot());
		}
	}
}
void Menu::rbtMenu() {
	//Tworzy obiekt drzewa RB
	RBT* rbt = new RBT();
	//Przechowuje wyb�r u�ytkownika
	int nr;
	//obs�uguje zap�tlenie menu
	bool menu = true;

	while (menu) {
		showTestType();

		cout << "Menu drzewa czerwono-czarnego" << endl;
		cout << "1. Dodaj dane z pliku do drzewa" << endl;
		cout << "2. Wy�wietl drzewo RBT" << endl;
		cout << "3. Dodaj element do drzewa" << endl;
		cout << "4. Usu� element z drzewa" << endl;
		cout << "5. Wyszukaj element w drzewie" << endl;
		cout << "0.Powr�t" << endl;
		cout << "Wybierz numer: ";
		cin >> nr;

		switch (nr) {
		case 1: {
			string filename;

			cout << "Podaj nazw� pliku: ";
			cin >> filename;

			rbt->loadData(filename);

		} break;
		case 2: {
			rbt->showRBT("", "", rbt->getRoot());
		} break;
		case 3: {
			int number;

			cout << "Podaj liczb� do wstawienia:" << endl;
			cin >> number;

			auto start = chrono::steady_clock::now();
			rbt->insertNode(number);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;
			cout << "\nDodanie elementu do drzewa zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;

		}break;
		case 4: {
			int number;
			cout << "Podaj liczb� do usuni�cia:" << endl;
			cin >> number;

			auto start = chrono::steady_clock::now();
			rbt->deleteNode(number);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "\nUsuni�cie elementu z drzewa zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;
		}break;
		case 5: {
			int number;
			//Wska�nik na w�ze�
			RBTNode* node; 

			cout << "Podaj klucz do wyszukania:" << endl;
			cin >> number;

			auto start = chrono::steady_clock::now();
			node = rbt->find(number);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			cout << "\nWyszukiwanie elementu w drzewie zajmuje [ns]: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(duration).count() << endl;

			//Trudno w drzewie wskaza� dok�adne po�o�enie w�z�a
			//Wi�c wy�wietlam szczeg�owe informacje
			if (node != NULL) {
				cout << "Podany klucz jest koloru: ";
				if (node->color == 'R') {
					cout << "Czerwonego" << endl;
				}
				else {
					cout << "Czarnego" << endl;
				}
				if (node->parent == NULL) {
					cout << "Podany klucz jest korzeniem" << endl;
				}
				else {
					cout << "Podany klucz jest dzieckiem: " << node->parent->keyRB << endl;
				}
				if (node->left != NULL && node->right != NULL) {
					cout << "Podany klucz ma dwoje dzieci: " << node->left->keyRB << ", " << node->right->keyRB << endl;
				}
				else if (node->left != NULL) {
					cout << "Podany klucz ma jedno dziecko: " << node->left->keyRB << endl;
				}
				else {
					cout << "Podany klucz jest li�ciem" << endl;
				}
			}
			else {
				cout << "Podany klucz nie znajduje si� w drzewie" << endl; 
			}
		}break;
		default: menu = false;
		}
		//Po ka�dej operacji z wyj�tkiem wy�wietlenia rbt i wyj�cia z menu wy�wietlamy rbt
		if (menu && nr != 2) {
			rbt->showRBT("", "", rbt->getRoot());
		}
	}
}
void Menu::mainMenu() {
	//Tworzy obiekt test�w automatycznych
	TestTime testtime = TestTime(); 
	//Przechowuje wyb�r u�ytkownika
	int nr;
	//obs�uguje zap�tlenie menu
	bool menu = true;

	while (menu) {
		showTestType();

		cout << "Menu" << endl;
		cout << "1. Tablica dynamiczna" << endl;
		cout << "2. Lista dwukierunkowa" << endl;
		cout << "3. Kopiec binarny" << endl;
		cout << "4. Drzewo poszukiwa� binarnych (BST)" << endl;
		cout << "5. Drzewo czerwono-czarne" << endl;
		cout << "6. Ustaw/zmie� typ test�w" << endl;
		cout << "7. Wygeneruj dane do test�w" << endl;
		cout << "0. Wyj�cie" << endl;
		cout << "Wybierz numer: ";
		cin >> nr;
		system("CLS");

		//Wywo�uje odpowiednie menu lub test w zale�no�ci od zmiennej - isTimeTest
		switch (nr) {
		case 1: {
			if (isTimeTest) {
				testtime.array();
			}
			else {
				arrayMenu();
			}

		}break;
		case 2: {
			if (isTimeTest) {
				testtime.list();
			}
			else {
				listMenu();
			}

		}break;
		case 3: {
			if (isTimeTest) {
				testtime.heap();
			}
			else {
				heapMenu();
			}

		} break;
		case 4: {
			if (isTimeTest) {
				testtime.bst();
			}
			else {
				bstMenu();
			}
		}break;
		case 5: {
			if (isTimeTest) {
				testtime.rbt();
			}
			else {
				rbtMenu();
			}
		} break;
		case 6: chooseTestType(); break;
		case 7: {
			//Tworzy obiekt obs�uguj�cy dane
			Data data = Data();
			int size;
			string filename;

			cout << "Podaj liczb� danych do wygenerowania: ";
			cin >> size;
			cout << "Podaj nazw� pliku do zapisania danych: ";
			cin >> filename;
			cout << "Trwa generowanie danych..." << endl;

			data.generateData(size, filename, 0, 99);
			system("CLS");

		}break;
		default: exit(0);
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