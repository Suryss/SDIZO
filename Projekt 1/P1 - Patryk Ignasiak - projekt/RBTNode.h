#pragma once
#pragma warning(default : 26444)
class RBTNode
{
public:
	//Klucz wêz³a
	int keyRB;
	//WskaŸnik na lewe dziecko
	RBTNode* left;
	//WskaŸnik na prawe dziecko
	RBTNode* right;
	//WskaŸnik na rodzica
	RBTNode* parent;
	//Kolor wêz³a
	// R - czerwony, B - czarny
	char color;
	//Tworzy element listy
	//Jako argumenty przyjmuje wartoœæ, wskaŸnik na lewe, prawe dziecko i na rodzica, ustawia kolor wêz³a
	RBTNode(int key, RBTNode* left, RBTNode* right, RBTNode* parent, char color);
};

