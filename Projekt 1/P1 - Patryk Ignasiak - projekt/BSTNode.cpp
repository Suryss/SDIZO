#include "BSTNode.h"

BSTNode::BSTNode(int key, BSTNode* left, BSTNode* right, BSTNode* parent) {
	//Przypisujemy argumenty do p�l obiektu
	this->key = key;
	this->left = left;
	this->right = right;
	this->parent = parent;
}
