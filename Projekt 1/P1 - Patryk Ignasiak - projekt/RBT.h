#pragma once
#include <string>
#include "RBTNode.h"
class RBT
{
	RBTNode* root = NULL;
public:
	//Dodawanie danych z pliku do drzewa
	void loadData(std::string filename);

	//Wstawianie wêz³a
	void insertNode(int key);
	
	//Wyœwietlanie drzewa - - gotowiec z internetu z drobnymi modyfikacjami
	//pierwsze wywo³anie - showHeap("", "", getRoot() )
	void showRBT(std::string sp, std::string sn, RBTNode* node);

	//Zwraca wskaŸnik na korzeñ drzewa
	RBTNode* getRoot();

	//Wyszukiwanie klucza zwaca wêze³
	RBTNode* find(int keyRB);

	//Usuwanie wêz³a
	void deleteNode(int keyRB);

private:
	//Naprawia drzewo po dodawaniu
	//jako argument przyjmuje dodawany wêze³
	void repairTreeInsert(RBTNode* node);

	//Naprawia drzewo po usuwaniu
	//Jako argument przyjmuje wskaŸnik na wêze³ z którym bêdzie zamieniany usuwany wêze³
	void repairTreeDelete(RBTNode* node);

	//Rotacja w prawo
	//Jako argument przyjmuje wêze³ wzglêdem którego ma zrobiæ rotacjê
	void rotationRight(RBTNode* node);

	//Rotacja w lewo
	//Jako argument przyjmuje wêze³ wzglêdem którego ma zrobiæ rotacjê
	void rotationLeft(RBTNode* node);

	//Szukanie nastêpnika
	//Jako argument przyjmuje wêze³ dla którego ma znaleŸæ nastêpnika
	RBTNode* successor(RBTNode* node);

	//Szukanie najmniejszego klucza
	//startuj¹c od podanego wêz³a
	RBTNode* searchMinkeyRB(RBTNode* node);
};

