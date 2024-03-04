#include "Data.h"
#include <string>
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

void Data::generateData(int vertices, int filling, string filename, int min, int max, bool isMST) {
	srand(time(NULL));
	int maxEdges = 0;
	for (int i = vertices - 1; i > 0; i--) {
		maxEdges += i;
	}

	if (!isMST) {
		maxEdges *= 2;
	}

	int edges = maxEdges * filling / 100;
	//Losujemy wierzcho³ek startowy i koñcowy
	int startVertice = rand() % vertices;
	int endVertice = rand() % vertices;
	while(startVertice == endVertice) {
		endVertice = rand() % vertices; 
	}

	random_device rd; 
	mt19937 gen(rd()); 
	uniform_int_distribution<> distValue(min, max); 
	uniform_int_distribution<> distVertice(0, vertices-1); 

	//Tworzymy plik i zapisujemy rozmiar
	ofstream file(filename);

	file << edges << " " << vertices << " " << startVertice << " " << endVertice << endl;

	file.close();

	//otwieramy plik do nadpisania
	//i zapisujemy generowane dane
	file.open(filename, ios_base::app);

	int** edgesMemory = new int*[edges];
	int k = 0;
	//drzewo rozpinaj¹ce
	for (int i = 0; i < vertices - 1; i++)
	{
		file << i << " " << i + 1 << " " << distValue(gen) << endl; 

		int* edge = new int[2];
		edge[0] = i;
		edge[1] = i+1;
		edgesMemory[k] = edge;
		k++;
	}
	//pozosta³e krawêdzie
	for (int i = 0; i < edges - vertices + 1; i++) {
		int firstVertice = distVertice(gen); 
		int secondVertice = distVertice(gen);
		while (firstVertice == secondVertice) { 
			secondVertice = distVertice(gen); 
		}

		bool isUnique = true;

		for (int j = 0; j < k; j++) {
			if (isMST) {
				if ((firstVertice == edgesMemory[j][0] && secondVertice == edgesMemory[j][1])
					|| (secondVertice == edgesMemory[j][0] && firstVertice == edgesMemory[j][1])) {
					isUnique = false;
				}
			}
			else {
				if (firstVertice == edgesMemory[j][0] && secondVertice == edgesMemory[j][1]) {
					isUnique = false;
				}
			}
		}
		if (isUnique) {
			file << firstVertice << " " << secondVertice << " " << distValue(gen) << endl;

			int* edge = new int[2];
			edge[0] = firstVertice;
			edge[1] = secondVertice;
			edgesMemory[k] = edge;
			k++;
		}
		else {
			i--;
		}
	}
	file.close();
}
void Data::saveTimeTestResult(long long times[160][5], string filename, string line) {
	//tworzymy plik
	ofstream file(filename);

	file << line <<endl;

	file.close();

	
	file.open(filename, ios_base::app);
	//zapisujemy œrednie czasy i parametry
	for (int i = 0; i < 160; i++) {
		for (int j = 0; j < 5; j++) {
			if (j < 3){
				file << times[i][j];
				file << "; ";
			}
			else {
				file << times[i][j]/100;
				file << "; ";
			}
			
		}
		file << "\n";
	}
	file.close();
}