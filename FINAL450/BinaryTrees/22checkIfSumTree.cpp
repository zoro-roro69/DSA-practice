#include <bits/stdc++.h>
using namespace std;

//check if binary tree is a sum tree

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool isSumTree(Node *root){
    if (!root)
        return true;
    
    if (root->left == NULL && root->right == NULL) //leaf node
        return true;
    int left_sum = 0;
    if (root->left){ 
        if ((root->left->left || root->left->right)) //left node is not the leaf
            left_sum = (root->left->data)*2;
        else{
            left_sum = root->left->data; //left is leaf node
        }
    }

    int right_sum = 0;
    if (root->right){
        if ((root->right->left || root->right->right)){ //right is not leaf nde
            right_sum = (root->right->data)*2;
        }else
            right_sum = root->right->data; //right is leaf node
    }

    if (root->data != left_sum + right_sum)
        return false;

    return isSumTree(root->left) && isSumTree(root->right);

}


int main(){


    return 0;
}