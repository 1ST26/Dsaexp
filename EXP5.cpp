#include<iostream>
#include<stdlib.h>
using namespace std;

class node {
public:
    int data;
    int lbit, rbit;
    node *left, *right;
};

class TBT {
private:
    node *root, *dummy;
public:
    TBT() {
        root = NULL;
        dummy = NULL;
    }
    void create(int num);
    void insert(node *trav, node *temp);
    void preorder();
    void display();
};

void TBT::create(int num) {
    node *trav, *temp;
    temp = new node();
    temp->data = num;
    temp->lbit = 0;
    temp->rbit = 0;
    if (root == NULL) {
        dummy = new node;
        dummy->data = -9999;
        dummy->lbit = 0;
        dummy->rbit = 1;
        dummy->left = temp;
        dummy->right = dummy;
        temp->left = dummy;
        temp->right = dummy;
        root = temp;
    }
    else {
        trav = root;
        insert(trav, temp);
    }
}

void TBT::insert(node *trav, node *temp) {
    if (temp->data < trav->data) {
        if (trav->lbit == 0) {
            temp->left = trav->left;
            temp->right = trav;
            trav->left = temp;
            trav->lbit = 1;
        }
        else {
            insert(trav->left, temp);
        }
    }
    else if (temp->data > trav->data) {
        if (trav->rbit == 0) {
            temp->right = trav->right;
            temp->left = trav;
            trav->right = temp;
            trav->rbit = 1;
        }
        else {
            insert(trav->right, temp);
        }
    }
}

void TBT::preorder() {
    node *trav;
    trav = root;
    while (trav != dummy) {
        cout << trav->data << endl;
        if (trav->lbit == 1) {
            trav = trav->left;
        }
        else {
            while (trav->rbit == 0 && trav->right != dummy) {
                trav = trav->right;
            }
            trav = trav->right;
        }
    }
}

void TBT::display() {
    int n, i, data;
    cout << "\nEnter the number of nodes: ";
    cin >> n;
    cout << "\nEnter the data in the Nodes: ";
    for (i = 0; i < n; i++) {
        cin >> data;
        create(data);
    }
    cout << "\nPreorder Traversal:\n";
    preorder();
}

int main() {
    TBT T;
    T.display();
    return 0;
}
