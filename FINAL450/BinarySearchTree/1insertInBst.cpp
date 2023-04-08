#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node (int val){
        data = val;
        left = right = NULL;
    }
};

// Function to insert a node in a BST.
Node* insert(Node* root, int key) {
    if (root == NULL)
        return new Node(key);
    
    if (key > root->data){
        if (root->right)
            return insert(root->right, key);
        else //insert here
            return root->right = new Node(key);
    }else{
        if (root->left)
            return insert(root->left, key);
        else //insert here
            return root->left = new Node(key);
    }
}



Node *insert2(Node *root, int key){
    if (!root)
        return new Node(key);

    if (key > root->data)
        root->right = insert2(root->right, key);
    if (key < root->data)
        root->left = insert2(root->left, key);
    
    return root;
}

void inOrder(Node *root){
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main(){
    Node *root = new Node(1);
    insert(root, 2);
    insert(root, 6);
    insert(root, 3);
    insert(root, 5);
    insert(root, 0);

    inOrder(root);

    return 0;
}