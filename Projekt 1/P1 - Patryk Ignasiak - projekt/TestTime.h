#pragma once
#include "Data.h"
#include <string>
class TestTime
{
	//iloœæ powtórzeñ
	const int repeat = 20;
	
	//iloœæ struktur
	static const int structs = 19;

	//rozmiary
	int structSize[structs] = { 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 250000, 500000, 750000, 1000000, 1250000, 1500000, 1750000, 2000000, 2250000, 2500000 };
	
	//tablica przechowywuj¹ca czasy
	long long times[structs][7];

	//Tworzy obiekt do obs³ugi danych
	Data ttdata = Data();

	//Nazwa pliku z tstowymi danymi
	std::string filename = "testfile";

	//losowa wartoœæ
	int randomInt();
public:
	//testy dla tablicy
	void array();
	
	//testy dla listy
	void list();

	//testy dla kopca
	void heap();

	//testy dla bst
	void bst();

	//testy dla rbt
	void rbt();


};

