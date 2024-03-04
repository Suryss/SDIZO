// P2 - Patryk Ignasiak.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//=========================================
//Autor: Patryk Ignasiak - 263889
//=========================================

#include <locale.h>
#include "Graph.h"
#include <iostream>
#include "MST.h"
#include "ShortestPath.h"
#include "Menu.h"
#include "Data.h"
#include "TimeTest.h"
#include "MaxFlow.h"
//#include "Menu.h"


using namespace std;

int main()
{
    //Ustawienie polskich znaków w programie
    setlocale(LC_CTYPE, "Polish");
    /*Graph* graph = new Graph();
    graph->fileReadGraph("w", false);
    graph->showMatrix();
    graph->showList();
    MaxFlow mf = MaxFlow();
    mf.fordFulkerson(graph, true);
    mf.showResult();*/
    //TimeTest tt = TimeTest();
    //tt.mst();
    //Data data = Data();
    //data.generateData(100, 50, "filename", 0, 99, true);
    Menu menu = Menu();
    menu.mainMenu();
    /*
    Graph* graph = new Graph();
    graph->fileReadGraph("w", true);
    graph->showMatrix();
    graph->showList();
    
    MST mst = MST();
    mst.primOnMatrix(graph);
    mst.showResult();

    mst.kruskalOnMatrix(graph);
    mst.showResult();

    mst.kruskalOnList(graph);
    mst.showResult();
    //mst.primOnList(graph);
    //mst.showResult();
    //ShortestPath sp = ShortestPath();
    //sp.dijkstraOnMatrix(graph);
    //sp.showResult();

    //sp.dijkstraOnList(graph);
    //sp.showResult();

   // sp.BellmanFordOnMatrix(graph);
    //sp.showResult();

   // sp.BellmanFordOnList(graph);
   // sp.showResult();
   */
}


