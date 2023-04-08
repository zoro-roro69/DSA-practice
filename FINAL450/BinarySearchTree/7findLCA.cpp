#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


//Function to find the lowest common ancestor in a BST. 
// 3 cases
//  1. two values are > then the current , we go right
//  2. two values are < then the current, we go left
//  3. one of the value is  == to current, this node is the LCA
//  4. one val is > node and other is < the node, this is the LCA
Node* LCA(Node *root, int n1, int n2){
    if (root == NULL)
        return NULL;
    
    if (n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);
    else if (n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);
    else if (n1 == root->data || n2 == root->data)
        return root;
    else if ((n1 > root->data && n2 < root->data) || (n1 < root->data && n2 > root->data))
        return root;
}

int main(){

    return 0;
}