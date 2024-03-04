#pragma once
#include <string>
#include "BSTNode.h"
class BST
{
	//wskaŸnik na korzeñ drzewa bst
	BSTNode* root = NULL;  
	//rozmiar drzewa 
	int sizeBst = 0;
public:

	//Dodawanie danych z pliku do drzewa
	void loadData(std::string filename);

	//Wyœwietlanie w kolejnoœci preorder
	//Jako argument przyjmuje korzeñ - getRoot()
	void preorder(BSTNode* node);

	//Wyœwietlanie w kolejnoœci postoreder
	//Jako argument przyjmuje korzeñ - getRoot()
	void postorder(BSTNode* node);

	//Wyœwietlanie w kolejnoœci inorder
	//Jako argument przyjmuje korzeñ - getRoot()
	void inorder(BSTNode* node);

	//Wyœwietlanie drzewa - - gotowiec z internetu z drobnymi modyfikacjami
	//pierwsze wywo³anie - showHeap("", "", getRoot() )
	void showBST(std::string sp, std::string sn, BSTNode* node); 

	//Algorytm równowarzenia drzewa
	void DSW();

	//Wyszukiwanie klucza zwaca wêze³
	BSTNode* find(int key);

	//Usuwanie wêz³a
	void deleteNode(int key);

	//Wstawianie wêz³a
	void insertNode(int key);

	//Zwraca wskaŸnik na korzeñ drzewa
	BSTNode* getRoot();
private:
	//Prostowanie drzewa
	void createLinearTree();

	//Tworzenie zrównowarzonego drzewa
	void createBalancedTree();

	//Rotacja w lewo
	//Jako argument przyjmuje wêze³ wzglêdem którego ma zrobiæ rotacjê
	void rotationLeft(BSTNode* node);

	//Rotacja w prawo
	//Jako argument przyjmuje wêze³ wzglêdem którego ma zrobiæ rotacjê
	void rotationRight(BSTNode* node);

	//Szukanie nastêpnika
	//Jako argument przyjmuje wêze³ dla którego ma znaleŸæ nastêpnika
	BSTNode* successor(BSTNode* node);

	//Szukanie najmniejszego klucza
	//startuj¹c od podanego wêz³a
	BSTNode* searchMinKey(BSTNode* node);

	//Szukanie najwiêkszego klucza
	//startuj¹c od podanego wêz³a
	BSTNode* searchMaxKey(BSTNode* node);


};

