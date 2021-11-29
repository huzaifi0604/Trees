#pragma once
#include <iostream>
using namespace std;
template<class T, class T1>
struct Node {
	T data;
	T1 key;
	Node<T, T1>* left;
	Node<T, T1>* right;
	Node() {
		left = right = NULL;
	}
	Node(T data, T1 key) {
		this->key = key;
		this->data = data;
		left = right = NULL;
	}
};
template<class T, class T1>
class Tree {
public:
	Node<T, T1>* root;
	Tree() {
		root = NULL;
	}
	void insert(Node<T, T1> node) {
		if (!root) {
			Node<T, T1>* newnode = new Node<T, T1>(node.data, node.key);
			root = newnode;
		}
		else {
			Node<T, T1>* curr = root;
			while (curr) {
				if (node.key > curr->key) {
					if (curr->right) {
						curr = curr->right;
					}
					else {
						
						Node<T, T1>* newone = new Node<T, T1>(node.data, node.key);
						curr->right = newone;
						return;
					}
				}
				else if (node.key < curr->key) {
					if (curr->left) {
						curr = curr->left;
					}
					else {
						Node<T, T1>* newone = new Node<T, T1>(node.data, node.key);
						curr->left = newone;
						return;
					}
				}
				else
					return;

			}
		}
	}
	bool retrieve(T1 key) {
		if (key == root->key) {
			cout << "Data Found At root" << endl;
			return true;
		}
		else {
			Node<T, T1>* curr = root;
			while (curr) {
				if (key < curr->key) {
					if (curr->left && curr->left->key != key) {
						curr = curr->left;
					}
					else if (curr->left && curr->left->key == key) {
						cout << "Data Found in the left Subtree" << endl;
						return true;
					}
				}
				else if (key > curr->key) {
					if (curr->right && curr->right->key != key) {
						curr = curr->right;
					}
					else if (curr->right && curr->right->key == key) {
						cout << "Data Found in the right Subtree" << endl;
						return true;
					}
				}
			}
		}
		return false;
	}

	void displayInOrder() {
		cout << "\t\tDisplaying tree in IN Order\n";
		in_order(root);
	}
	void in_order(Node<T, T1>* node) {
		if (node != NULL) {
			in_order(node->left);
			cout << node->key << " " << node->data << endl;
			in_order(node->right);
		}
	}
	void pre_order(Node<T, T1>* node) {
		if (node) {
			cout << node->key << " " << node->data << endl;
			pre_order(node->left);
			pre_order(node->right);
		}
	}
	void displayPreOrder() {
		cout << "\t\tDisplaying tree in IN Order\n";
		pre_order(root);
	}
	void displayPostOrder() {
		cout << "\t\tDisplaying tree in IN Order\n";
		post_order(root);
	}
	void post_order(Node<T, T1>* node) {
		if (node) {
			post_order(node->left);
			post_order(node->right);
			cout << node->key << " " << node->data << endl;
		}
	}
};
