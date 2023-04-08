#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node *left;
    Node *right;

    Node(int v = 0){
        data = v;
        left = right = NULL;
    }
};

Node *lca(Node *root, int v1, int v2){

    //Your code here 
    if (!root) //root == NULL
        return NULL;

    if (root->data == v1 || root->data == v2)
        return root;

    Node *left_res = lca(root->left, v1, v2);
    Node *right_res = lca(root->right, v1, v2);

    if (!left_res && !right_res) //if both are NULL
        return NULL;
    if (left_res && right_res)
        return root; //if both are not NULL , that means this is the LCA and each subtree contains each value

    if (left_res)
        return left_res; //left res is lca

    return right_res; //right res is lca

}


int main(){

    return 0;
}