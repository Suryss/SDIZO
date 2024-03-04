#pragma once
#pragma warning(default : 26444)
class RBTNode
{
public:
	//Klucz w�z�a
	int keyRB;
	//Wska�nik na lewe dziecko
	RBTNode* left;
	//Wska�nik na prawe dziecko
	RBTNode* right;
	//Wska�nik na rodzica
	RBTNode* parent;
	//Kolor w�z�a
	// R - czerwony, B - czarny
	char color;
	//Tworzy element listy
	//Jako argumenty przyjmuje warto��, wska�nik na lewe, prawe dziecko i na rodzica, ustawia kolor w�z�a
	RBTNode(int key, RBTNode* left, RBTNode* right, RBTNode* parent, char color);
};

