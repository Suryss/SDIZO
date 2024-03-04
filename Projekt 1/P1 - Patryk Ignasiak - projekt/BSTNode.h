#pragma once
#pragma warning(default : 26444)
class BSTNode
{
public:
	//Klucz w�z�a
	int key;
	//Wska�nik na lewe dziecko
	BSTNode* left;
	//Wska�nik na prawe dziecko
	BSTNode* right;
	//Wska�nik na rodzica
	BSTNode* parent;

	//Tworzy element listy
	//Jako argumenty przyjmuje warto��, wska�nik na lewe, prawe dziecko i na rodzica
	BSTNode(int key, BSTNode* left, BSTNode* right, BSTNode* parent);
};

