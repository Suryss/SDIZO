#pragma once
#include "Graph.h"

class Menu
{
	//typ test�w
	bool isTimeTest = false;

	//Obiekt grafu
	Graph* graph;

	//Menu dla minimalnego drzewa rozpinaj�cego
	void mstMenu();

	//Menu dla najkr�tszej �cie�ki w grafie
	void pathMenu();

	//Menu dla maksymalnego przep�ywu
	void flowMenu();

	//Wybieranie typu test�w
	void chooseTestType();

	//Wy�wietla jaki tryb test�w jest w��czony
	void showTestType();
public:
	//Obs�uguje menu g��wne
	//Dla test�w czas�w - uruchamia wybranie opcji uruchamia testy automatyczne dla struktury
	//Dla test�w struktury - przechodzi do menu wybranej struktury
	void mainMenu();

};

