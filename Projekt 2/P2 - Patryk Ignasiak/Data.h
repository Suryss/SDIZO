#pragma once
#include <string>
class Data
{
public:
	//Generowanie grafu
	void generateData(int vertices, int filling, std::string filename, int min, int max, bool isMST);
	
	//Zapisywanie wyników testów
	void saveTimeTestResult(long long times[160][5], std::string filename, std::string line);
};

