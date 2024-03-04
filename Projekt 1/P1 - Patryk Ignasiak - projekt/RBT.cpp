#include "RBT.h"
#include "RBTNode.h"
#include <iostream>
#include "Data.h"

using namespace std;

void RBT::loadData(string filename) {
	//Tworzy obiekt obs³uguj¹cy dane
	Data data = Data();
	//wczytuje dane do tablicy pomocniczej
	int* tab = data.fromFile(filename);

	//jeœli uda³o siê pobraæ dane z pliku to dodajemy je do drzewa
	if (tab != NULL) {
		RBTNode* parent = NULL;
		for (int i = 1; i <= tab[0]; i++) {
			insertNode(tab[i]);
		}
	}
}
void RBT::insertNode(int keyRB) {
	RBTNode* temp = root;
	RBTNode* parent = NULL; //rodzic
	//Szukamy miejsca dla naszego wêz³a
	while (temp != NULL) {
		parent = temp;
		if (keyRB < temp->keyRB) {
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	//Tworzymy wêze³ i ustawiamy wszystkie wymagane wskaŸniki
	RBTNode* node = new RBTNode(keyRB, NULL, NULL, parent, 'R');

	if (parent == NULL) {
		root = node;
		root->color = 'B';
	}
	else
	{
		if (keyRB < parent->keyRB) {
			parent->left = node;
		}
		else {
			parent->right = node;
		}
	}
	//Naprawiamy drzewo po wstawieniu 
	repairTreeInsert(node);
	
}
void RBT::repairTreeInsert(RBTNode* node) {
	//jeœli wêze³ nie jest korzeniem to naprawiamy
	if (node->parent != NULL) {
		//jeœli rodzic jest czerwony
		if (node->parent->color == 'R') {
			RBTNode* grandparent = node->parent->parent;
			RBTNode* uncle = grandparent->left;
			char uColor = 'B';
			if (grandparent->left == node->parent) {
				uncle = grandparent->right;
			}
			if (uncle != NULL) {
				uColor = uncle->color;
			}
			//Jeœli stryj jest czerwony to zmieniamy kolory i naprawiamy wzglêdem dziadka
			if (uColor == 'R') {
				uncle->color = 'B';
				if (grandparent != root) {
					grandparent->color = 'R';
					repairTreeInsert(grandparent);
				}
				node->parent->color = 'B';
			}
			else {
				if (node->parent == grandparent->left) {
					//Jeœli stryj jest czarny, a wstawiany element jest lewym synem
					//to rotacja w prawo
					if (node == node->parent->left) {
						rotationRight(grandparent);
						grandparent->color = 'R';
						node->parent->color = 'B';
					}
					else {
						//Jeœli stryj jest czarny, a wstawiany element jest lewym synem
						//to dwie rotacje pierwsza w lewo druga w prawo
						rotationLeft(node->parent);
						rotationRight(grandparent);
						grandparent->color = 'R';
						node->color = 'B';
					}
				}
				else {
					//analogicznie jak wy¿ej tylko odwrócone strony
					if (node == node->parent->right) {
						rotationLeft(grandparent);
						grandparent->color = 'R';
						node->parent->color = 'B';
					}
					else {
						rotationRight(node->parent);
						rotationLeft(grandparent);
						grandparent->color = 'R';
						node->color = 'B';
					}
				}
			}
		}
	}
}
void RBT::rotationRight(RBTNode* node) {
	//Jeœli istnieje lewe dziecko dla podanego wêz³a to wykonujemy rotacjê 
	//Ustawiaj¹c wszystkie wymagane wskaŸniki
	if (node->left != NULL) {
		RBTNode* temp = node->left->right;
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
void RBT::rotationLeft(RBTNode* node) {
	//Jeœli istnieje prawe dziecko dla podanego wêz³a to wykonujemy rotacjê 
	//Ustawiaj¹c wszystkie wymagane wskaŸniki
	if (node->right != NULL) {
		RBTNode* temp = node->right->left;
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
void RBT::showRBT(string sp, string sn, RBTNode* node) {
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
			showRBT(s + cp, cr, node->right);

			s = s.substr(0, sp.length() - 2);

			cout << s << sn << node->keyRB <<node->color<< endl;

			s = sp;
			if (sn == cl) s[s.length() - 2] = ' ';
			showRBT(s + cp, cl, node->left);
		}
	}
}
RBTNode* RBT::getRoot() {
	return root;

}
RBTNode* RBT::find(int keyRB) {
	//Wyszukujemy wêze³ o podanym kluczu stosuj¹c w³asnoœci drzewa bst
	RBTNode* node = root;
	while ((node != NULL) && (node->keyRB != keyRB)) {
		if (keyRB < node->keyRB) {
			node = node->left;
		}
		else {
			node = node->right;
		}
	}
	return node;
}
void RBT::deleteNode(int keyRB) {
	//Jeœli s¹ elementy w drzewie to usuwamy element o podanym kluczu
	if (root != NULL) {
		//wyszukujemy wêz³a i nastêpnie go usuwamy
		//Jeœli nie ma dzieci to usuwamy
		//Jeœli ma dzieci to szukamy nastêpnika
		//I przeprowadzamy wszystkie wymagane zmiany wskaŸników
		RBTNode* node = find(keyRB);
		if (node != NULL) {
			RBTNode* temp = NULL;
			RBTNode* temp2 = NULL;
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
			//Jeœli kolor usuwanego wêz³a nie jest czerwony to musimy naprawiæ drzewo
			if (temp->color != 'R') {
				repairTreeDelete(temp);
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
				node->keyRB = temp->keyRB;
			}
			
			delete temp;
			
			
		}
			
		
	}
}
RBTNode* RBT::successor(RBTNode* node) {
	if (node->right != NULL) {
		return searchMinkeyRB(node->right);
	}
	RBTNode* temp = node->parent;
	while (temp != NULL && temp->left != node) {
		node = temp;
		temp = temp->parent;
	}
	return temp;
}
RBTNode* RBT::searchMinkeyRB(RBTNode* node) {
	while (node->left != NULL) {
		node = node->left;
	}
	return node;
}
void RBT::repairTreeDelete(RBTNode* node) {
	bool temp = true;
	while(node != root && node->color == 'B' && temp) {
		if (node->parent->left == node) {
			RBTNode* brother = node->parent->right;
			if (brother != NULL) {
				//Jeœli brat czerwony to rotacja w lewo i zmiana kolorów
				if (brother->color == 'R') {
					rotationLeft(node->parent);
					node->parent->color = 'R';
					brother->color = 'B';
					brother = node->parent->right;
				}
				if (brother != NULL) {
					char lColor = 'B';
					char rColor = 'B';
				
					if (brother->left != NULL) {
						lColor = brother->left->color;
					}

					if (brother->right != NULL) {
						rColor = brother->right->color;
					}
					//Jeœli brat ma dwoje czarnych dzieci 
					//zmieniamy kolor brata na czerwony 
					//i przenosimy problem o jeden poziom wy¿ej
					if (lColor == 'B' && rColor == 'B') {
						brother->color = 'R';
						node = node->parent;
					}
					else {
						//Jeœli grat ma czerwone i czarne dziecko
						//to rotacja w lewo i zmiana kolorów
						if (lColor == 'R' && rColor == 'B') {
							rotationLeft(node->parent);
							brother->parent->color = 'B';
							brother->color = 'R';
						}
						//Jeœli prawy potomek brata jest czerwony 
						//to rotacja w lewo i zmiana kolorów
						rotationLeft(node->parent);
						brother->right->color = 'B';
						brother->color = node->parent->color;
						node->parent->color = 'B';
					}
				}
				else {
					temp = false;
				}
			}
			else {
				temp = false;
			}
			
		}
		else
		{
			//Analogiznie jak wy¿ej tylko odwrócone strony
			RBTNode* brother = node->parent->left;
			if (brother != NULL) {
				if (brother->color == 'R') {
					rotationRight(node->parent);
					node->parent->color = 'R';
					brother->color = 'B';
					brother = node->parent->left;
				}
				if (brother != NULL) {
					char lColor = 'B';
					char rColor = 'B';

					if (brother->left != NULL) {
						lColor = brother->left->color;
					}

					if (brother->right != NULL) {
						rColor = brother->right->color;
					}
					if (rColor == 'B' && lColor == 'B') {
						brother->color = 'R';
						node = node->parent;
					}
					else {
						if (rColor == 'R' && lColor == 'B') {
							rotationRight(node->parent);
							brother->parent->color = 'B';
							brother->color = 'R';
						}
						rotationRight(node->parent);
						brother->left->color = 'B';
						brother->color = node->parent->color;
						node->parent->color = 'B';
					}
				}
				else {
					temp = false;
				}
			}
			else {
				temp = false;
			}
		}
	}
	node->color = 'B';
}