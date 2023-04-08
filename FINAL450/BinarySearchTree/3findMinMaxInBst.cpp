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

// Function to find the minimum element in the given BST.
int minValue(Node* root) {
    // Code here
    if (!root)
        return -1;
    
    while(root->left!=NULL)
        root = root->left;
    return root->data;
}


int maxValue(Node *root){
    if (!root)
        return -1;
    
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}

int main(){

    return 0;
}