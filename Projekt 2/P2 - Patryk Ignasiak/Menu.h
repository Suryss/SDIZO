#pragma once
#include "Graph.h"

class Menu
{
	//typ testów
	bool isTimeTest = false;

	//Obiekt grafu
	Graph* graph;

	//Menu dla minimalnego drzewa rozpinaj¹cego
	void mstMenu();

	//Menu dla najkrótszej œcie¿ki w grafie
	void pathMenu();

	//Menu dla maksymalnego przep³ywu
	void flowMenu();

	//Wybieranie typu testów
	void chooseTestType();

	//Wyœwietla jaki tryb testów jest w³¹czony
	void showTestType();
public:
	//Obs³uguje menu g³ówne
	//Dla testów czasów - uruchamia wybranie opcji uruchamia testy automatyczne dla struktury
	//Dla testów struktury - przechodzi do menu wybranej struktury
	void mainMenu();

};

