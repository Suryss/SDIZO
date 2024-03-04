#pragma once
enum Color { RED, BLACK };
class Node{
	int key;
	Node* left;
	Node* right;
	Node* parent;
	Color color;
public:
	//Konstruktor dla w�z�a RBT
	Node(int key, Node* left, Node* right, Node* parent, Color color);

	//Konstruktor dla w�z�a BST
	Node(int key, Node* left, Node* right, Node* parent);
};

