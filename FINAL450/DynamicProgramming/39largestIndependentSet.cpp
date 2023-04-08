#include <bits/stdc++.h>
using namespace std;

// Given a Binary Tree, find size of the Largest Independent Set(LIS) in it. 
// A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset. 
// For example, consider the following binary tree. The largest independent set(LIS)
//  is {10, 40, 60, 70, 80} and size of the LIS is 5.

struct Node{
    int data;
    Node *left;
    Node *right;
};

int f(Node *root){
    if (root == NULL)
        return 0;

    int including = 1;
    int excluding = 0;
    if (root->left)
        including += f(root->left->left) + f(root->left->right);
    
    if (root->right)
        including += f(root->right->left) + f(root->right->right);

    excluding = f(root->left) + f(root->right);

    return max(including, excluding);

}

// Time complexity of the above naive recursive approach is exponential. 
// It should be noted that the above function computes the same subproblems again and again.

//consider tree
//     10
//  20     30
//40 50       60

//here when we are at root (10) we explore 20, 30, 40, 50, and 60
//when we are ar 20 we again explore 40, 50 so clearly there is an overlap
//to above solution we can apply memoization, we store the result of each node in the struct of node itself

struct Node2{
    int data;
    Node2 *left;
    Node2 *right;
    int dp;
};

void init(Node2 *root){
    if (!root)
        return;

    root->dp = -1;
    init(root->left);
    init(root->right);
    
}

//make sure to initialise dp value in all nodes
int f2(Node2 *root){
    //base case pending
    if (root == NULL)
        return 0;
    if (root->dp != -1){ //already visited
        return root->dp;
    }

    int including = 1;
    int excluding = 0;
    if (root->left)
        including += f2(root->left->left) + f2(root->left->right);
    
    if (root->right)
        including += f2(root->right->left) + f2(root->right->right);

    excluding = f2(root->left) + f2(root->right);

    root->dp = max(including, excluding);
    return root->dp;

}

int main(){


    return 0;
}