#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
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


void inOrder2(Node *root, vector <int> &in_order, int &i){
    if (root == NULL)
        return ;
    else{
        inOrder2(root->left, in_order, i);
        root->data = in_order[i++];
        inOrder2(root->right, in_order, i);
    }
}   

Node *binaryTreeToBST (Node *root){

    vector <int> in_order;
    inOrder(root, in_order);

    sort(in_order.begin(), in_order.end());
    int i = 0;
    inOrder2(root, in_order, i);
    return root;
}

int main(){

    return 0;
}