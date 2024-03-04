#include "BST.h"
#include <iostream>
#include "BSTNode.h"
#include "Data.h"

using namespace std;

void BST::loadData(string filename) {
	//Tworzy obiekt obs³uguj¹cy dane
	Data data = Data();  
	//wczytuje dane do tablicy pomocniczej
	int* tab = data.fromFile(filename);

	//jeœli uda³o siê pobraæ dane z pliku to dodajemy je do drzewa
	if (tab != NULL) {
		BSTNode* parent = NULL; 
		sizeBst = tab[0];
		for (int i = 1; i <= tab[0]; i++) {
			//Szukamy miejsca do wstawienia
			BSTNode* temp = root;
			while (temp) {
				parent = temp;
				if (tab[i] < temp->key) {
					temp = temp->left;
				}
				else {
					temp = temp->right;
				}
			} 
			//Tworzymy wêze³ i wstawiamy, ustawiaj¹c wszystkie wymagane wskaŸniki
			BSTNode* node = new BSTNode(tab[i], NULL, NULL, parent);
			if (root == NULL) {
				root = node; 
			}
			else {
				if (tab[i] < parent->key) {
					parent->left = node;
				}
				else {
					parent->right = node;
				}
			}
		}
		//Równowa¿ymy drzewo
		DSW(); 
	}
}
void BST::preorder(BSTNode* node) {
	if (node == NULL) {
		return;
	}
	cout << node->key << ", ";
	preorder(node->left);
	preorder(node->right); 
	if (node == root) {
		cout << endl << endl; 
	}
}
void BST::postorder(BSTNode* node) {
	if (node == NULL) {
		return;
	}
	postorder(node->left);
	postorder(node->right);
	cout << node->key << ", ";
	if (node == root) {
		cout << endl << endl;
	}
}
void BST::inorder(BSTNode* node) {
	if (node == NULL) {
		return;
	}
	inorder(node->left);
	cout << node->key << ", ";
	inorder(node->right);
	if (node == root) {
		cout << endl << endl;
	}
}
void BST::showBST(string sp, string sn, BSTNode* node) {
	//Jeœli drzewo nie jest puste to je wyœwietlamy
	if (root != NULL) {
		string s;
		string cr, cl, cp;
		cr = cl = cp = "  ";
		cr[0] = 184; cr[1] = 151;
		cl[0] = 39; cl[1] = 151;
		cp[0] = 124;

		if (node != NULL)
		{
			s = sp;
			if (sn == cr) s[s.length() - 2] = ' ';
			showBST(s + cp, cr, node->right);

			s = s.substr(0, sp.length() - 2);

			cout << s << sn << node->key << endl;

			s = sp;
			if (sn == cl) s[s.length() - 2] = ' ';
			showBST(s + cp, cl, node->left);
		}
	}
}
void BST::rotationRight(BSTNode* node) {
	//Jeœli istnieje lewe dziecko dla podanego wêz³a to wykonujemy rotacjê 
	//Ustawiaj¹c wszystkie wymagane wskaŸniki
	if (node->left != NULL) {
		BSTNode* temp = node->left->right;
		node->left->parent = node->parent;
		if (node->parent != NULL) {
			if (node == node->parent->right) {
				node->parent->right = node->left;
			}
			else {
				node->parent->left = node->left;
			}

		}
		else {
			root = node->left;
			node->left->parent = NULL;
		}
		node->left->right = node;
		node->parent = node->left;
		node->left = temp;
		if (temp != NULL) {
			temp->parent = node;
		}
	}
}
void BST::rotationLeft(BSTNode* node) {
	//Jeœli istnieje prawe dziecko dla podanego wêz³a to wykonujemy rotacjê 
	//Ustawiaj¹c wszystkie wymagane wskaŸniki
	if (node->right != NULL) {
		BSTNode* temp = node->right->left;
		node->right->parent = node->parent;
		if (node->parent != NULL) {
			if (node == node->parent->right) {
				node->parent->right = node->right;
			}
			else {
				node->parent->left = node->right;
			}
		}
		else {
			root = node->right;
			node->right->parent = NULL;
		}
		node->right->left = node;
		node->parent = node->right;
		node->right = temp;

		if (temp != NULL) {
			temp->parent = node;
		}
	}
}
void BST::DSW() {
	//Prostujemy drzewo
	createLinearTree();
	//Równowa¿ymy drzewo
	createBalancedTree();
}
void BST::createLinearTree() {
	//prostujemy drzewo wykonuj¹c rotacje w prawo
	BSTNode* temp = root;
	while (temp != NULL) {
		if (temp->left != NULL) {
			rotationRight(temp);
			temp = temp->parent;
		}
		else {
			temp = temp->right;
		}
	}
}
void BST::createBalancedTree() {
	//Równowa¿ymy drzewo wykonuj¹c rotacje w lewo dla w³aœciwych wêz³ów
	int m = pow(2, floor(log2(sizeBst + 1))) - 1;
	BSTNode* temp = root;
	for (int i = sizeBst - m; i > 0; i--) {
		rotationLeft(temp);
		temp = temp->parent->right;
	}
	while (m > 1) {
		m = floor(m / 2);
		temp = root;
		for (int i = 0; i < m; i++) {
			rotationLeft(temp);
			temp = temp->parent->right;
		}
	}
}
BSTNode* BST::find(int key) {
	//Wyszukujemy wêze³ o podanym kluczu stosuj¹c w³asnoœci drzewa bst
	BSTNode* node = root;
	while ((node != NULL) && (node->key != key)) {
		if (key < node->key) {
			node = node->left;
		}
		else {
			node = node->right;
		}
	}
	return node;
}
void BST::deleteNode(int key) {
	//Jeœli s¹ elementy w drzewie to usuwamy element o podanym kluczu
	if (root != NULL) {
		if (sizeBst == 1) {
			if (root->key == key) {
				delete root;
				sizeBst--;
			}
		}
		else {
			//Jeœli rozmiar jest wiêkszy od 1 to wyszukujemy wêz³a i nastêpnie go usuwamy
			//Jeœli nie ma dzieci to usuwamy
			//Jeœli ma dzieci to szukamy nastêpnika
			//I przeprowadzamy wszystkie wymagane zmiany wskaŸników
			BSTNode* node = find(key);
			if (node != NULL) {
				BSTNode* temp = NULL;
				BSTNode* temp2 = NULL;
				if (node->left == NULL || node->right == NULL) {
					temp = node;
				}
				else {
					temp = successor(node);
				}

				if (temp->left != NULL) {
					temp2 = temp->left;
				}
				else
				{
					temp2 = temp->right;
				}
				if (temp2 != NULL) {
					temp2->parent = temp->parent;
				}
				if (temp->parent == NULL) {
					root = temp2;
				}
				else {
					if (temp == temp->parent->left) {
						temp->parent->left = temp2;
					}
					else {
						temp->parent->right = temp2;
					}
				}
				if (temp != node) {
					node->key = temp->key;
				}
				delete temp;
				sizeBst--;
				//Równowa¿ymy drzewo
				DSW();
			}
		}
	}
}
BSTNode* BST::successor(BSTNode* node) {
	if (node->right != NULL) {
		return searchMinKey(node->right);
	}
	BSTNode* temp = node->parent;
	while (temp != NULL && temp->left != node) {
		node = temp;
		temp = temp->parent;
	}
	return temp;
}
BSTNode* BST::searchMinKey(BSTNode* node) {
	while (node->left != NULL) {
		node = node->left;
	}
	return node;
}
BSTNode* BST::searchMaxKey(BSTNode* node) {
	while (node->right != NULL) {
		node = node->right;
	}
	return node;
}

void BST::insertNode(int key) {
	BSTNode* temp = root;
	BSTNode* parent = NULL; //rodzic
	//Szukamy miejsca dla naszego wêz³a
	while (temp != NULL) {
		parent = temp;
		if (key < temp->key) {
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	//Tworzymy wêze³ i ustawiamy wszystkie wymagane wskaŸniki
	BSTNode* node = new BSTNode(key, NULL, NULL, parent);

	if (parent == NULL) {
		root = node; 
	}
	else
	{
		if (key < parent->key) {
			parent->left = node;
		}
		else {
			parent->right = node;
		}
	}
	sizeBst++;
	//równowa¿ymy drzewo
	DSW();
}
BSTNode* BST::getRoot(){
	return root;
}