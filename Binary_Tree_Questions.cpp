// q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Muhammad Huzaifa
20I-0604
Assignment# 02
Binary Trees Questions
*/

#include <iostream>
#include <queue>
using namespace std;

template<class T>
struct bnode {      //Binary Tree's Node
    T data;
    bnode<T>* left;
    bnode<T>* right;        //Declaring data
    bnode() {
        left = right = NULL;    //Default constructor
    }
    bnode(T val) {              //Parametarized Constructor
        data = val;
        left = right = NULL;
    }
};

template<class T>
struct node {       //List's node
    T data;
    node<T>* next;      //Declaring data
    node() {
        next = NULL;    //Default constructor
    }
    node(T val) {       // Parametarized constructor
        data = val;
        next = NULL;
    }
};

template<class T>
class list {
public:
    node<T>* head;
    list() {
        head = NULL;        //Deafault constructor
    }
    void insert(T data) {
        if (!head) {                                //Inserting 1st node
            node<T>* newnode = new node<T>(data);
            newnode->next = head;
            head = newnode;
        }
        else {
            node<T>* curr = head;
            while (curr->next) {            //Inserting node at end of list
                curr = curr->next;
            }
            curr->next = new node<T>(data);

        }
    }
    void display() {                //Function for displaying list's Data
        if (!head) {
            cout << "Sorry! List is Empty" << endl;//Checking Empty List
        }
        else {
            node<T>* i = head;
            cout << "List Data: ";
            while (i) {
                cout << i->data << " ";//Printing data
                i = i->next;//Moving to next node
            }
        }
    }
};

template<class T>
class binary_tree {
    //Q # 02
    int height_of_tree(bnode<T>* node) {
        if (!node) {                        //returning height if root is null
            return 0;
        }
        else {
            int h1 = height_of_tree(node->left);        //recursive function for left child
            int h2 = height_of_tree(node->right);       //recursive function for right child
            if (h1 >= h2) {   
                return h1+1;  //returning height+1 bcz root got excluded at first
            }
            else {
                return h2+1;  // same is previous if
            }
        }

    }
    //Q # 02
    void list_storage(bnode<T>* root) {
        queue<bnode<T>*> store;             //creating queue object
        store.push(root);                   //Pushing root in queue
        int temp = 0;
        while (store.size() >= 1) {         //Loop runs until queue gets empty
            int size = store.size();
            list<T>* obj = new list<T>;     //Creating a dynamic object for list so at every level data gets stored in different list
            node<T>* prev = NULL;
            for (int i = 0; i < size; i++) {  //loop runs till size of queue
                bnode<T>* treenode = store.front();//creating tree's node
                node<T>* listnode = new node<T>;    //Creating list's node
                if (treenode != NULL) {
                    listnode->data = treenode->data;        //data in tree's node gets stored in respective list's node
                    listnode->next = NULL;                  //If node of binary tree is not equal to NULL
                }
                if (prev != NULL)
                    prev->next = listnode;          //Setting list's previous node to newly created node
                if (i == 0)
                    obj->head = listnode;           //if its 1st iteration then head is new node
                store.pop();
                prev = listnode;
                if (treenode->left)
                    store.push(treenode->left);     //Recursive function for left child
                if (treenode->right)
                    store.push(treenode->right);    //Recursive Function for right child
            }
            obj->display();
            cout << "\n";
        }
    }
    //Q # 03
    bool check_balanced(bnode<T>* node) {
        if (!node) {
            return true;
        }
        else {
            int count1 = height_of_tree(node->left);
            int count2 = height_of_tree(node->right);       //recursive functions for left and right child
            check_balanced(node->left);
            check_balanced(node->right);        //checking height of every node subtree
            if ((count1 - count2) > 1 || (count2 - count1 > 1)) {
                cout << "Tree is not Balanced" << endl;
                return false;       //if difference of height of left & right subtree is > 1 then tree isn't blanaced
            }
            if (((count1 - count2) <= 1 || (count2 - count1) <= 1) && check_balanced(node->left) && check_balanced(node->right)) {
                return true;
            }
        }
    }

    //Q # 05
    //Function for checking root of subtree in tree by data
    bnode<T>* check(bnode<T>* node, T node_data) {
        if (!node) {
            return NULL;            //returns NULL if root is NULL
        }
        if (node_data == node->data) {
            return node;                    //returns root if data matches
        }
        bnode<T>* check_right = check(node->right, node_data);
        bnode<T>* check_left = check(node->left, node_data);        //recursive functions for let and right childs
        if (check_right) {
            return check_right;
        }                                                  //Conditions for left & right child
        if (check_left) {
            return check_left;
        }
        return NULL;
    }
    //Function for checking whole subtree in original tree
    bool equal_nodes(bnode<T>* prime_root, bnode<T>* secon_root) {
        if (prime_root != NULL and secon_root != NULL)
            if (prime_root->data != secon_root->data) {
                return false;      //returning false if data of original and subtree's roots doesn't matches
            }
        if (prime_root == NULL and secon_root == NULL) {
            return true;    //returning true if both original and subtrees are NULL
        }
        if (prime_root == NULL or secon_root == NULL) {
            return false; //returning false if one of them is NULL 
        }
        //returning with recursive functions for left and right children starting from root
        return equal_nodes(prime_root->left, secon_root->left) and equal_nodes(prime_root->right, secon_root->right);
    }
    // Function for finding total paths for same target
    int path_finder(bnode<T>* node, int* node_array, int target, int level) {
        int total_paths = 0, i = level, sum = 0; //Declaring variables
        if (node == NULL) {
            return 0;       //returns zero if root is NULL
        }
        node_array[level] = node->data; //Arrays with size of each level of tree
        while (i >= 0) {
            sum += node_array[i];       //Sum of all elements in the array (nodes on each level)
            if (sum == target) {
                total_paths += 1;   // If sum of nodes in array becomes equal to target sum, total paths gets incremented 
            }
            i--;
        }
        //Adding Total paths for left chils + right childs
        int left=path_finder(node->left, node_array, target, level + 1);    //recursive function for left child
        int right = path_finder(node->right, node_array, target, level + 1); //recursive function for right child
        total_paths += left + right;
        return total_paths; //Returning Total Paths
    }
public:
    bnode<T>* root;
    binary_tree() { //Default Constructor
        root = NULL;
    }

    void insert(T data) {
        if (!root) {
            bnode<T>* newnode = new bnode<T>(data);     //Inserting 1st node
            root = newnode;
        }
        else {
            queue<bnode<T>*> obj;//Queue object
            obj.push(root);       //Pushing root in queue
            while (true) {
                bnode<T>* temp = obj.front();
                obj.pop();                      //Poping front node's data
                if (temp->left) {
                    obj.push(temp->left);       //Pushing left child if it isn't equal to null
                }
                else {
                    temp->left = new bnode<T>(data);//Inserting data at left child if it is null
                    break;
                }
                if (temp->right) {
                    obj.push(temp->right);         //Pushing right child if it isn't equal to null
                }
                else {
                    temp->right = new bnode<T>(data);//Inserting data at right child if it is null
                    break;
                }
            }
        }
    }
    //Q # 02
    void tree_height() {//Function Calling height of tree function
        cout << "Height of tree is: " << height_of_tree(root);
    }

    void storing_in_lists() {           //Function calling list_storage function
        list_storage(root);
    }
    //Q # 03
    void balanced_tree() {          //Function for checking balanced 
        if (check_balanced(root))
            cout << "Tree Is Balanced: " << check_balanced(root) <<endl;        //Conditions for balanced tree Output
        else
            cout << "Tree Is not Balanced: " << check_balanced(root) << endl;
    }

    bool subtree_checker(bnode<T>* node) {          //Function for subtree Checker
        if (height_of_tree(node) > height_of_tree(root)) {
            return false;       //Returns false of height of subtree is greater then original tree
        }
        //Calling equal_nodes function to check if subtree nodes have same values in original tree
        return equal_nodes(check(root, node->data), node);      
    }

    int total_paths(int num) {
        int array[3];             // Its Actually int array[height_of_tree]; BUT visual studio can;t take size of array as this 
        return path_finder(root, array, num, 0);
    }

    void display() {
        if (!root) {            //checking if tree is empty
            return;
        }
        else {
            queue<bnode<T>*> obj;   //creating a queue object
            bnode<T>* i = root;
            obj.push(i);            //pushing root into queue
            cout << "Tree Data: ";
            while (!obj.empty()) {
                i = obj.front();       
                cout << i->data << " ";  //Displaying data at the front of queue
                obj.pop();
                if (i->left) {
                    obj.push(i->left);  //Recursive function for left child
                }
                if (i->right) {
                    obj.push(i->right);     //recursive function for right child
                }
            }
        }
    }
};

int main() {
    binary_tree<int> t1,t2,t3;
    int input;
    //inserting data in binary tree
    for (int i = 1; i <= 10; i ++) {                            
        t1.insert(i);
    }
    //Displaying tree data
    cout << "\n\t\tDisplaying Tree Data\n";
    t1.display();                                                
    cout << "\n\t\tDisplaying Height of Tree\n";
    //Displaying height of tree
    t1.tree_height();                                           
   /* cout << "\n";
    list<int> l1;
    for (int i = 1; i < 10; i++) {
        l1.insert(i);                       //Inserting Elements in list
    }
    cout << "Displaying List's Test Data" << endl;
    l1.display();*/                           //Displaying elements of list
    cout << "\n\t\tDisplaying every level of tree in a saperate list\n" << endl;
    //Storing tree elements in lists
    t1.storing_in_lists();                                      
    cout << "\n\t\tChecking For Balanced Tree\n";
    //Calling Function for balanced tree checker
    t1.balanced_tree();                                          
    cout << "\n\t\tChecking for Subtree\n" << endl;
    //Inserting subtree's Data
    for (int i = 0; i < 3; i++) {
        cout << "Enter what do you wanna insert as subtree: ";
        cin >> input;
        t2.insert(input);                                        
    }
    //Calling Function for subtree checker
    cout << "\n\t\tDisplaying is inserted tree a subtree or not\n" << endl;
    cout << t1.subtree_checker(t2.root);
    //Function for total paths for same target
   cout << "\n\t\tChecking for Total paths for same target\n" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Enter tree value: ";
        cin >> input;
        t3.insert(input);//Getting input of tree to find total paths for same target
    }
    //Calling Function
    cout<<"\nTotal Paths To reach 08 are: "<<t3.total_paths(8)<<endl;
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
