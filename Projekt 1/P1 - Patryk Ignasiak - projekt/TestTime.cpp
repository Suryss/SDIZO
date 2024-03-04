#include "TestTime.h"
#include "Array.h"

#include <iostream>
#include <chrono>
#include "List.h"
#include "Heap.h"
#include <cstdio>
#include "BST.h"
#include <random>
#include "RBT.h"

using namespace std;

void TestTime::array() {
	Array* array = new Array();
	int x = 0;
	for (int i = 0; i < structs; i++) {
		ttdata.generateData(structSize[i], filename, INT32_MIN, INT32_MAX);
		array->loadData(filename);

		//wype³niamy tablicê zerami
		for (int j = 0; j < repeat; j++) {
			times[i][j] = 0;
		}
		//testujemy tablicê
		for (int j = 0; j < repeat; j++) {
			

			int randomNumber = randomInt();
			auto start = chrono::steady_clock::now();
			array->pushFront(randomNumber);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;
			
			times[i][0] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			start = chrono::steady_clock::now();
			array->popFront();
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][3] +=chrono::duration_cast<chrono::nanoseconds>(duration).count();

			randomNumber = randomInt();
			start = chrono::steady_clock::now();
			array->pushBack(randomNumber);
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][2] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			start = chrono::steady_clock::now();
			array->popBack();
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][5] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			randomNumber = randomInt();
			int indexR = abs(randomNumber % structSize[i]);
			start = chrono::steady_clock::now();
			array->pushOnIndex(indexR, randomNumber);
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][1] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			randomNumber = randomInt();
			indexR = abs(randomNumber % structSize[i]);
			start = chrono::steady_clock::now();
			array->popOnIndex(indexR);
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][4] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			randomNumber = randomInt();
			start = chrono::steady_clock::now();
			int index = array->find(randomNumber);
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][6] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			x += index;
		}
	}
	//zapisujemy wyniki
	ttdata.saveTimeTestResult(times, "Array.txt", structSize);
	cout << x; 
	system("CLS");
	remove(filename.c_str());
}
void TestTime::list() {
	List* list = new List();
	int x = 0;

	for (int i = 0; i < structs; i++) {
		ttdata.generateData(structSize[i], filename, INT32_MIN, INT32_MAX);
		list->loadData(filename);
		//wype³niamy tablicê zerami
		for (int j = 0; j < repeat; j++) {
			times[i][j] = 0;
		}
		//testujemy listê
		for (int j = 0; j < repeat; j++) {
			
			int randomNumber = randomInt();
			auto start = chrono::steady_clock::now();
			list->pushFront(randomNumber);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			times[i][0] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			start = chrono::steady_clock::now();
			list->popFront();
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][3] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			randomNumber = randomInt();
			start = chrono::steady_clock::now();
			list->pushBack(randomNumber);
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][2] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			start = chrono::steady_clock::now();
			list->popBack();
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][5] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			randomNumber = randomInt();
			int indexR = abs(randomNumber % structSize[i]);
			start = chrono::steady_clock::now();
			list->pushOnIndex(indexR, randomNumber);
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][1] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			randomNumber = randomInt();
			indexR = abs(randomNumber % structSize[i]);
			start = chrono::steady_clock::now();
			list->popOnIndex(indexR);
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][4] += chrono::duration_cast<chrono::nanoseconds>(duration).count();
			
			int index; 
			randomNumber = randomInt();
			start = chrono::steady_clock::now();
			index = list->find(randomNumber);
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][6] += chrono::duration_cast<chrono::nanoseconds>(duration).count();
			
			x += index;
			
			ListItem* item;
			randomNumber = randomInt();
			start = chrono::steady_clock::now();
			item = list->find2(randomNumber);
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][0] += chrono::duration_cast<chrono::nanoseconds>(duration).count();
			cout << item;
			system("CLS");
		}
	}
	//zapisujemy wyniki
	ttdata.saveTimeTestResult(times, "List.txt", structSize);
	cout << x;
	system("CLS");
	remove(filename.c_str());
}
void TestTime::heap() {
	
	int x = 0;
	for (int i = 0; i < structs; i++) {
		
		ttdata.generateData(structSize[i], filename, INT32_MIN, INT32_MAX);
		//wype³niamy tablicê zerami
		for (int j = 0; j < repeat; j++) {
			times[i][j] = 0;
		}
		//testujemy kopiec
		for (int j = 0; j < repeat; j++) {
			Heap* heap = new Heap();
			heap->loadData(filename, true);
			auto start = chrono::steady_clock::now();
			heap->floyd((structSize[i] - 1) / 2);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;
			times[i][0] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			heap = new Heap();
			heap->loadData(filename, true);
		    start = chrono::steady_clock::now();
			heap->buildHeap();
			end = chrono::steady_clock::now();
			duration = end - start;
			times[i][1] += chrono::duration_cast<chrono::nanoseconds>(duration).count();
			

			int randomNumber = randomInt();
			start = chrono::steady_clock::now();
			heap->push(randomNumber);
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][0] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			start = chrono::steady_clock::now();
			heap->pop();
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][1] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			randomNumber = randomInt();
			start = chrono::steady_clock::now();
			int index = heap->find(randomNumber);
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][2] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			x += index;

		}
	}
	//zapisujemy wyniki
	ttdata.saveTimeTestResult(times, "Heap.txt", structSize);
	cout << x;
	system("CLS");
	remove(filename.c_str());
}
void TestTime::bst() {
	BST* bst = new BST();

	BSTNode* node;
	for (int i = 0; i < structs; i++) {
		ttdata.generateData(structSize[i], filename, INT32_MIN, INT32_MAX);
		bst->loadData(filename);
		//wype³niamy tablicê zerami
		for (int j = 0; j < repeat; j++) {
			times[i][j] = 0;
		}
		//testujemy bst
		for (int j = 0; j < repeat; j++) {

			int randomNumber = randomInt();
			auto start = chrono::steady_clock::now();
			bst->insertNode(randomNumber);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			times[i][0] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			randomNumber = randomInt();
			start = chrono::steady_clock::now();
			bst->deleteNode(randomNumber);
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][1] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			randomNumber = randomInt();
			start = chrono::steady_clock::now();
			node = bst->find(randomNumber);
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][2] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			start = chrono::steady_clock::now();
			bst->DSW();
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][3] += chrono::duration_cast<chrono::nanoseconds>(duration).count();
			
			
			if (node != NULL) {
				cout << node;
				system("CLS");
			}

		}
	}
	//zapisujemy wyniki
	ttdata.saveTimeTestResult(times, "BST.txt", structSize);

	remove(filename.c_str());
}
void TestTime::rbt() {
	RBT* rbt = new RBT();

	RBTNode* node;
	for (int i = 0; i < structs; i++) {
		ttdata.generateData(structSize[i], filename, INT32_MIN, INT32_MAX);
		rbt->loadData(filename);
		//wype³niamy tablicê zerami
		for (int j = 0; j < repeat; j++) {
			times[i][j] = 0;
		}
		//testujemy rbt
		for (int j = 0; j < repeat; j++) {

			int randomNumber = randomInt();
			auto start = chrono::steady_clock::now();
			rbt->insertNode(randomNumber);
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			times[i][0] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			randomNumber = randomInt();
			start = chrono::steady_clock::now();
			rbt->deleteNode(randomNumber);
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][1] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			randomNumber = randomInt();
			start = chrono::steady_clock::now();
			node = rbt->find(randomNumber);
			end = chrono::steady_clock::now();
			duration = end - start;

			times[i][2] += chrono::duration_cast<chrono::nanoseconds>(duration).count();

			if (node != NULL) {
				cout << node;
				system("CLS");
			}

		}
	}
	//zapisujemy wyniki
	ttdata.saveTimeTestResult(times, "RBT.txt", structSize);


	remove(filename.c_str());
}
int TestTime::randomInt() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(INT32_MIN, INT32_MAX);

	return dist(gen);
}