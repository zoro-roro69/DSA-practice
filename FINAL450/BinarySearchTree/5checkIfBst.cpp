#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;

    Node *right;
    Node *left;

    Node (int val){

        data = val;
        left = right = NULL;
    }
};

bool helper(Node *root, int left, int right){
    if (root == NULL)
        return true;
    if (root->data >= left && root->data <= right)
        return helper(root->left, left, root->data) && helper(root->right, root->data, right);
    return false;
}

bool isBst(Node *root){

    return helper(root, INT_MIN, INT_MAX);

}


int main(){


    return 0;
}