// P1 - Patryk Ignasiak.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//=========================================
//Autor: Patryk Ignasiak - 263889
//=========================================

#include <locale.h>
#include "Menu.h"
#include "P1 - Patryk Ignasiak.h"

using namespace std;

int main()
{
    //Ustawienie polskich znaków w programie
    setlocale(LC_CTYPE, "Polish");
    
    //Tworzymy obiekt i wywołujemy metodę menu głównego
    Menu menu = Menu();
    
    menu.mainMenu();
    
  
}

