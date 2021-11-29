#include <iostream>
#include <queue>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node() {
        left = right = NULL;
    }
    node(int val) {
        data = val;
        left = right = NULL;
    }
};

class tree {
    node* root;
public:
    tree() {
        root = NULL;
    }

    void insert(int data) {
        queue<int> tree;
        if (!root) {
            node* newnode = new node(data);
            root = newnode;

        }
        else {
            queue<node*> tree;
            tree.push(root);
            while (1) {
                node* temp= tree.front();
                //cout << "root data: "<<temp->data << endl;
                tree.pop();
                if (temp->left) {
                    tree.push(temp->left);
                }
                else {
                    temp->left = new node(data);
                  //  cout << "temp->left->data: "<<temp->left->data << endl;
                    break;
                }
                if (temp->right) {
                    tree.push(temp->right);
                }
                else {
                    temp->right = new node(data);
                    //cout << "temp->right->data"<<temp->right->data << endl;
                    break;
                }

            }

        }

    }
    bool replace(int old_data, int new_data) {
        if (!root) {
            cout << "your Treee is Empty" << endl;
        }
        
        else {
            queue<node*> tree;
            tree.push(root);
            if (root->data == old_data) {
                root->data = new_data;
                return true;
            }
            while (1) {
                node* curr = tree.front();
                tree.pop();
               
                if (!curr->left) {
                    return false;
                }
                else if(curr->left) {
                    if (curr->left->data == old_data) {
                        curr->left->data = new_data;
                        return true;
                    }
                }
                if (!curr->right) {
                    return false;
                }
                else if (curr->right) {
                    if (curr->right->data == old_data) {
                        curr->right->data = new_data;
                    }
                }
                tree.push(curr->left);
                tree.push(curr->right);
            }
        }
    }
    void display() {
        if (!root) {
            return ;
        }
        else {
            queue<node*> tree;
            node* i = root;
            tree.push(i);
            while (!tree.empty()) {
                i = tree.front();
                cout << i->data << " ";
                tree.pop();
                if (i->left) {
                    tree.push(i->left);
                }
                if (i->right) {
                    tree.push(i->right);
                }
            }
        }
    }
};

int main()
{
    tree t1;
    int array[6] = {3,4,5,1,2,7};
    for (int i = 0; i < 6; i++) {
        t1.insert(array[i]);
    }
    cout << "Displaying Tree Data" << endl;
    t1.display();
    cout << "\nReplacing Tree Data ..." << endl;
    t1.replace(7, 6);
    cout << "Displaying Tree Data After Replacing" << endl;
    t1.display();
    return 0;
}
