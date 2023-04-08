#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left, *right;
};


void inOrder(Node *root, vector <int> &in_order){
    if (root == NULL)
        return ;
    else{
        inOrder(root->left, in_order);
        in_order.push_back(root->data);
        inOrder(root->right, in_order);
    }
}

Node *buildTree(vector <int> &in_order, int start, int end){
    if (start >end)
        return NULL;
    int mid = start + (end-start)/2;

    Node *root = new Node();    
    root->data = in_order[mid];
    buildTree(in_order, start, mid-1);
    buildTree(in_order, mid+1, end);

    return root;

}


Node* buildBalancedTree(Node* root){
    vector <int> in_order;
    inOrder(root, in_order);

    return buildTree(in_order, 0, in_order.size()-1);

}


int main(){

    return 0;
}