#include "Node.h"

int key;
Node* left;
Node* right;
Node* parent;
Color color;

Node::Node(int key, Node* left, Node* right, Node* parent, Color color) {
	this->key = key;
	this->left = left;
	this->right = right;
	this->parent = parent;
	this->color = color;
}
Node::Node(int key, Node* left, Node* right, Node* parent) {
	this->key = key;
	this->left = left;
	this->right = right;
	this->parent = parent;
}