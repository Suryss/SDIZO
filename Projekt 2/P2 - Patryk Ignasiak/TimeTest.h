#pragma once
#include "Data.h"
#include "Graph.h"
#include "MST.h"
#include "ShortestPath.h"
#include "MaxFlow.h"
class TimeTest
{
    //liczba wierzcho³ków
    int countOfVertices = 20;
    //gêstoœci
    int filling[4] = { 25, 50, 75, 99 };
    //Wierzcho³ki
    int vertices[20] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200 };
    //Czasy
    long long times[160][5];
    //Deklaracja obiektów
    Data data = Data();
    Graph* graph;
    MST* mstObj;
    ShortestPath* sPath; 
    MaxFlow* mf; 
public:
    //testy mst
    void mst();
    //testy najkrótszej œcie¿ki
    void shortestPath();
    //testy maksymalnego przep³ywu
    void fordFulkerson();
};

