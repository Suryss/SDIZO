#pragma once
#include <string>

class Data
{
	//iloœæ powtórzeñ procedury 
	const int repeat = 20;
	//iloœæ rozmiarów struktór
	static const int structs = 19;

public:



	//Pobiera dane z pliku, zapisuje je w tablicy i zwraca wskaŸnik wcelu za³adowania ich do struktury
	int* fromFile(std :: string filename);

	//Generowanie danych i zapisywanie ich do pliku
	void generateData(int size, std::string filename, int min, int max);

	//Zapisywanie czasów z automatycznych testów czasów
	void saveTimeTestResult(long long times[structs][7], std::string filename, int structSize[]);
	
};

