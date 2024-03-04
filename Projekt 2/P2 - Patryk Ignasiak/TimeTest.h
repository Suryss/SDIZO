#pragma once
#include "Data.h"
#include "Graph.h"
#include "MST.h"
#include "ShortestPath.h"
#include "MaxFlow.h"
class TimeTest
{
    //liczba wierzcho�k�w
    int countOfVertices = 20;
    //g�sto�ci
    int filling[4] = { 25, 50, 75, 99 };
    //Wierzcho�ki
    int vertices[20] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200 };
    //Czasy
    long long times[160][5];
    //Deklaracja obiekt�w
    Data data = Data();
    Graph* graph;
    MST* mstObj;
    ShortestPath* sPath; 
    MaxFlow* mf; 
public:
    //testy mst
    void mst();
    //testy najkr�tszej �cie�ki
    void shortestPath();
    //testy maksymalnego przep�ywu
    void fordFulkerson();
};

