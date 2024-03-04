#pragma once
class Menu
{
	//Przechowuje typ test�w 
	//true - testy czas�w
	//false - testy struktury
	static bool isTimeTest;
	
public:
	//Obs�uguje menu tablicy
	void arrayMenu();

	//Obs�uguje menu listy
	void listMenu();

	//Obs�uguje menu kopca
	void heapMenu();

	//Obs�uguje menu drzewa BST
	void bstMenu();

	//Obs�uguje menu drzewa RBT
	void rbtMenu();

	//Obs�uguje menu g��wne
	//Dla test�w czas�w - uruchamia wybranie opcji uruchamia testy automatyczne dla struktury
	//Dla test�w struktury - przechodzi do menu wybranej struktury
	void mainMenu();

	//Wybieranie typu test�w
	void chooseTestType();

	//Wy�wietla jaki tryb test�w jest w��czony
	void showTestType();
};

