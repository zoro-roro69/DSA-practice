#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;

    Node *next;
    Node *right;
    Node *left;

    Node (int val){

        data = val;
        left = right = next = NULL;
    }
};


Node *helper(Node *root, Node *parent){
    if (!root)
        return NULL;
    
    Node *leftmost = helper(root->left, root);
    Node *successor = helper(root->right, parent);
    if (successor == NULL)
        root->next = parent;
    if (leftmost == NULL)
        return root;
    return leftmost;

}


void populateNext(Node *root){

    helper(root, NULL);

}

int main(){

    return 0;
}