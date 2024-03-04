#pragma once
#include <string>
#include "RBTNode.h"
class RBT
{
	RBTNode* root = NULL;
public:
	//Dodawanie danych z pliku do drzewa
	void loadData(std::string filename);

	//Wstawianie w�z�a
	void insertNode(int key);
	
	//Wy�wietlanie drzewa - - gotowiec z internetu z drobnymi modyfikacjami
	//pierwsze wywo�anie - showHeap("", "", getRoot() )
	void showRBT(std::string sp, std::string sn, RBTNode* node);

	//Zwraca wska�nik na korze� drzewa
	RBTNode* getRoot();

	//Wyszukiwanie klucza zwaca w�ze�
	RBTNode* find(int keyRB);

	//Usuwanie w�z�a
	void deleteNode(int keyRB);

private:
	//Naprawia drzewo po dodawaniu
	//jako argument przyjmuje dodawany w�ze�
	void repairTreeInsert(RBTNode* node);

	//Naprawia drzewo po usuwaniu
	//Jako argument przyjmuje wska�nik na w�ze� z kt�rym b�dzie zamieniany usuwany w�ze�
	void repairTreeDelete(RBTNode* node);

	//Rotacja w prawo
	//Jako argument przyjmuje w�ze� wzgl�dem kt�rego ma zrobi� rotacj�
	void rotationRight(RBTNode* node);

	//Rotacja w lewo
	//Jako argument przyjmuje w�ze� wzgl�dem kt�rego ma zrobi� rotacj�
	void rotationLeft(RBTNode* node);

	//Szukanie nast�pnika
	//Jako argument przyjmuje w�ze� dla kt�rego ma znale�� nast�pnika
	RBTNode* successor(RBTNode* node);

	//Szukanie najmniejszego klucza
	//startuj�c od podanego w�z�a
	RBTNode* searchMinkeyRB(RBTNode* node);
};

