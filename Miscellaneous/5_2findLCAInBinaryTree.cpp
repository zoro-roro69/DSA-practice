#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


//this works for BST only not for Binary Tree :)
//logn solution
Node* lcaBST(Node* root ,int v1 ,int v2 ){
    if (root == NULL)
        return NULL;
    if (root->data == v1 || root->data == v2)
        return root;
    if (root->data < v1 && root->data < v2)
        return lcaBST(root->right, v1, v2);
    if (root->data > v1 && root->data > v2)
        return lcaBST(root->left, v1, v2);

    return root;
}


//O(n) solution for binary tree :)
Node *lca(Node *root, int v1, int v2){
    if (root == NULL)
        return NULL;
    
    if (root->data == v1 || root->data == v2)
        return root;

    Node *left = lca(root->left, v1, v2);
    Node *right = lca(root->right, v1, v2);

    if (left && right)
        return root;
    
    if (left)
        return left;
    if (right)
        return right;
    
    return NULL; //v1, v2 doest exist
}

int main(){
    return 0;
}