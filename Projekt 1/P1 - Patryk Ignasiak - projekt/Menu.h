#pragma once
class Menu
{
	//Przechowuje typ testów 
	//true - testy czasów
	//false - testy struktury
	static bool isTimeTest;
	
public:
	//Obs³uguje menu tablicy
	void arrayMenu();

	//Obs³uguje menu listy
	void listMenu();

	//Obs³uguje menu kopca
	void heapMenu();

	//Obs³uguje menu drzewa BST
	void bstMenu();

	//Obs³uguje menu drzewa RBT
	void rbtMenu();

	//Obs³uguje menu g³ówne
	//Dla testów czasów - uruchamia wybranie opcji uruchamia testy automatyczne dla struktury
	//Dla testów struktury - przechodzi do menu wybranej struktury
	void mainMenu();

	//Wybieranie typu testów
	void chooseTestType();

	//Wyœwietla jaki tryb testów jest w³¹czony
	void showTestType();
};

