#pragma once
enum Color { RED, BLACK };
class Node{
	int key;
	Node* left;
	Node* right;
	Node* parent;
	Color color;
public:
	//Konstruktor dla wêz³a RBT
	Node(int key, Node* left, Node* right, Node* parent, Color color);

	//Konstruktor dla wêz³a BST
	Node(int key, Node* left, Node* right, Node* parent);
};

