#pragma once
#pragma warning(default : 26444)
class BSTNode
{
public:
	//Klucz wÍz≥a
	int key;
	//Wskaünik na lewe dziecko
	BSTNode* left;
	//Wskaünik na prawe dziecko
	BSTNode* right;
	//Wskaünik na rodzica
	BSTNode* parent;

	//Tworzy element listy
	//Jako argumenty przyjmuje wartoúÊ, wskaünik na lewe, prawe dziecko i na rodzica
	BSTNode(int key, BSTNode* left, BSTNode* right, BSTNode* parent);
};

