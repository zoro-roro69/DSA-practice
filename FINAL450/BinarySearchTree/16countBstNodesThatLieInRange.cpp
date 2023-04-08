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

int getCount(Node *root, int l, int h){
    if (root == NULL)
        return 0;
    else{
        if (root->data > h){
            return getCount(root->left, l, h);
        }
        else if(root->data < l){
            return getCount(root->right, l, h);
        }else{ //within the range
            return 1 + getCount(root->left, l, h) + getCount(root->right, l , h);
        }
    }
}

int main(){


    return 0;
}