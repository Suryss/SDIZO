#include "Data.h"
#include <string>
#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int*  Data::fromFile(string filename){
	//otwieramy plik
	ifstream file(filename);
	if (file.is_open()) {
		cout << "Trwa ³adowanie danych..." << endl;
		int size = 1;
		//zapisujemy dane do tablicy
		int* tab = new int[size];

		int li;
		int i = -1;
		while (!file.eof() && i <= size) {
			i++;
			file >> li;
			if (i == 0) {

				delete[] tab;
				tab = new int[li + 1];
				size = li;
			}
			tab[i] = li;

		}

		file.close();
		//naprawiamy tablicê w razie potrzeby
		if (i < size) {
			int* temp = tab;
			tab = new int[i + 1];
			for (int j = 0; j <= i; j++) {
				if (j == 0) {
					tab[0] = i;
				}
				else {
					tab[j] = temp[j];
				}
			}
			delete[] temp;
		}
		//zwracamy tablicê
		cout << "Dane zosta³y za³adowane" << endl;
		return tab;
	}
	else {
		cout << "Nie znaleziono pliku: " << filename << endl;
		return NULL;
	}
	
}
void Data::generateData(int size, string filename, int min, int max) {
	int val;

	random_device rd; 
	mt19937 gen(rd()); 
	uniform_int_distribution<> dist(min, max); 
	
	//Tworzymy plik i zapisujemy rozmiar
	ofstream file(filename);
	
	file << size;

	file.close();

	//otwieramy plik do nadpisania
	//i zapisujemy generowane dane
	file.open(filename, ios_base::app);

	for (int i = 0; i < size; i++)
	{
		val = dist(gen); 

		file << "\n";
		file << val;
	}
	file.close();
}

void Data::saveTimeTestResult(long long times[structs][7], string filename, int structSize[]) {
	//tworzymy plik
	ofstream file(filename);

	file << structSize[0];

	file.close();

	//w pierwszym wierszu zapisujemy rozmiary struktur
	file.open(filename, ios_base::app);
	for (int i = 1; i < structs; i++) {
		file << ";";
		file << structSize[i];
	}
	file << ";\n";
	//zapisujemy œrednie czasy
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < structs; j++) {
			file << times[j][i]/repeat;
			file << ";";
		}
		file << "\n";
	}
	file.close();
}