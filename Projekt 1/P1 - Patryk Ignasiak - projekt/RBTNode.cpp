#include "RBTNode.h"


RBTNode::RBTNode(int key, RBTNode* left, RBTNode* right, RBTNode* parent, char color) {
	this->keyRB = key;
	this->left = left;
	this->right = right;
	this->parent = parent;
	this->color = color;
}