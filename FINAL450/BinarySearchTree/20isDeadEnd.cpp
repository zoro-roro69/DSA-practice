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

bool helper(Node *root, int low, int high){
    if (root == NULL){
        if (low == INT_MIN || high == INT_MAX)
            return false; //not a dead end
        if (high-low>1)
            return false; //not a dead end

        return true; //dead end
    }
    bool left_res = helper(root->left, low, min(root->data, high));
    bool right_res = helper(root->right, max(low, root->data), high);

    if (root->left == NULL && root->right == NULL)
        return left_res && right_res;
    if (root->left == NULL){
        return right_res;
    }
    if (root->right == NULL)
        return left_res;
    
    return left_res && right_res;
}

bool isDeadEnd(Node *root){
    return helper(root, 1, INT_MAX);
}

int main(){

    return 0;
}