// q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Muhammad Huzaifa
20I-0604
Assignment# 02
Binary Search Trees Questions
*/

#include <iostream>
#include <queue>
using namespace std;

template<class T>
struct node {
    T data;
    node<T>* left;
    node<T>* right;                 //declaring nodes' data and children
    node() {
        left = right = NULL;
    }
    node(T ndata) {                //parametarized constructor
        data = ndata;
        left = right = NULL;
    }
};

template<class T>
class BST {
    node<T>* root;
    void display(node<T>* node) {       //Declaring Function private
        if (!node)                      //          |
            return;                     //          |
        else {                          //Bcz of root and Recursion
            cout << node->data << " ";
            display(node->left);
            display(node->right);
        }
    }
    //Function for calculating height of tree
    int tree_height(node<T>* node) {
        if (!node) {                        //returning height if root is null
            return 0;
        }
        else {
            int h1 = tree_height(node->left);        //recursive function for left child
            int h2 = tree_height(node->right);       //recursive function for right child
            if (h1 >= h2) {
                return h1 + 1;  //returning height+1 bcz root got excluded at first
            }
            else {
                return h2 + 1;  // same is previous if
            }
        }
    }
public:
    //Default Constructor
    BST() {             
        root = NULL;
    }
    // Function for Inserting a node in tree
    void insert(T ndata) {          
        if (!root) {
            root = new node<T>(ndata);      //Inserting 1st node
        }
        else {
            node<T>* curr = root;
            while (curr) {
                if (ndata < curr->data) {
                    if (curr->left) {           // if data to be inserted is less then root 
                        curr = curr->left;      // then inserting node at root's left child
                    }
                    else {
                        curr->left = new node<T>(ndata);
                        return;
                    }

                }
                else if (ndata > curr->data) {
                    if (curr->right) {          // If data to be inserted is greater then root
                        curr = curr->right;     // then inserting it at root's right child
                    }
                    else {
                        curr->right = new node<T>(ndata);
                        return;
                    }
                }
                else
                    return;
            }
        }
    }
    void display() {
        display(root);          //calling private function
    }

    void minimal_height_BST(T arr[], T first, T last) {     //Function for converting array(sorted)
        // Base Case                                         into Binary Search Array
        if (last < first)
            return;
        else{
            T mid = (first + last) / 2;
            insert(arr[mid]);
            minimal_height_BST(arr, first, mid - 1);        //recursive function for left child
            minimal_height_BST(arr, mid + 1, last);         //recursive function for right child
        }
    }
    void height_of_tree() {
        cout<<"\nHeight of tree is: "<<tree_height(root)<<endl;
    }
    
};

int main()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    BST<int> tree;                                          // object for BST class
    tree.minimal_height_BST(arr, 0, 9);
    tree.display();                                         //Calling Functions
    tree.height_of_tree();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
