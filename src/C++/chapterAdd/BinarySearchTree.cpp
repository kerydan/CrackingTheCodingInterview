// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class node {
public:
private:
};

class bsp_tree {

	struct node {
		node(int val, node* parent = NULL) : val(val), parent(parent), left(NULL), right(NULL) {}
		node* parent;
		node* left;
		node* right;
		int val;
	};

	node *root;
public:
	bsp_tree() : root() {};
	void print() { traverse(); };

	void traverse() {
		node* cur = root;
		while (cur) {
			while (cur->left) {
				cur = cur->left;
			}

			do {
				cout << cur->val << " ";
				while (cur->parent&& cur == cur->parent->right)
				{
					cur = cur->parent;
				}
				cur = cur->parent;
			} while (cur && !cur->right);
			if (!cur)
				return;

			if (cur) {
				cout << cur->val << " ";
				cur = cur->right;
			}
		}

	}

	bool add(int val) {
		node* n = new node(val);
		if (NULL == root) {
			root = n;
			return true;
		}
		else {
			node* par = root;
			while (true) {
				if (val == par->val) {
					delete n;
					return false;
				}
				else if (val < par->val) {
					if (NULL == par->left) {
						par->left = n;
						n->parent = par;
						return true;
					}
					else
						par = par->left;
				}
				else {
					if (NULL == par->right) {
						par->right = n;
						n->parent = par;
						return true;
					}
					else
						par = par->right;
				}
			}
			return true;
		}

	};
};



int main()
{
	bsp_tree t;
	t.add(5);
	t.add(3);
	t.add(2);
	t.add(7);
	t.add(6);
	t.add(10);
	t.add(8);
	t.print();

	return 0;
}

