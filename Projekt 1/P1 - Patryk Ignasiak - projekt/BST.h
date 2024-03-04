#pragma once
#include <string>
#include "BSTNode.h"
class BST
{
	//wska�nik na korze� drzewa bst
	BSTNode* root = NULL;  
	//rozmiar drzewa 
	int sizeBst = 0;
public:

	//Dodawanie danych z pliku do drzewa
	void loadData(std::string filename);

	//Wy�wietlanie w kolejno�ci preorder
	//Jako argument przyjmuje korze� - getRoot()
	void preorder(BSTNode* node);

	//Wy�wietlanie w kolejno�ci postoreder
	//Jako argument przyjmuje korze� - getRoot()
	void postorder(BSTNode* node);

	//Wy�wietlanie w kolejno�ci inorder
	//Jako argument przyjmuje korze� - getRoot()
	void inorder(BSTNode* node);

	//Wy�wietlanie drzewa - - gotowiec z internetu z drobnymi modyfikacjami
	//pierwsze wywo�anie - showHeap("", "", getRoot() )
	void showBST(std::string sp, std::string sn, BSTNode* node); 

	//Algorytm r�wnowarzenia drzewa
	void DSW();

	//Wyszukiwanie klucza zwaca w�ze�
	BSTNode* find(int key);

	//Usuwanie w�z�a
	void deleteNode(int key);

	//Wstawianie w�z�a
	void insertNode(int key);

	//Zwraca wska�nik na korze� drzewa
	BSTNode* getRoot();
private:
	//Prostowanie drzewa
	void createLinearTree();

	//Tworzenie zr�wnowarzonego drzewa
	void createBalancedTree();

	//Rotacja w lewo
	//Jako argument przyjmuje w�ze� wzgl�dem kt�rego ma zrobi� rotacj�
	void rotationLeft(BSTNode* node);

	//Rotacja w prawo
	//Jako argument przyjmuje w�ze� wzgl�dem kt�rego ma zrobi� rotacj�
	void rotationRight(BSTNode* node);

	//Szukanie nast�pnika
	//Jako argument przyjmuje w�ze� dla kt�rego ma znale�� nast�pnika
	BSTNode* successor(BSTNode* node);

	//Szukanie najmniejszego klucza
	//startuj�c od podanego w�z�a
	BSTNode* searchMinKey(BSTNode* node);

	//Szukanie najwi�kszego klucza
	//startuj�c od podanego w�z�a
	BSTNode* searchMaxKey(BSTNode* node);


};

