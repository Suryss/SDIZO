#pragma once
#include <string>

class Data
{
	//ilo�� powt�rze� procedury 
	const int repeat = 20;
	//ilo�� rozmiar�w strukt�r
	static const int structs = 19;

public:



	//Pobiera dane z pliku, zapisuje je w tablicy i zwraca wska�nik wcelu za�adowania ich do struktury
	int* fromFile(std :: string filename);

	//Generowanie danych i zapisywanie ich do pliku
	void generateData(int size, std::string filename, int min, int max);

	//Zapisywanie czas�w z automatycznych test�w czas�w
	void saveTimeTestResult(long long times[structs][7], std::string filename, int structSize[]);
	
};

