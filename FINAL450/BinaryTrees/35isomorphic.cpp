#include <bits/stdc++.h>
using namespace std;


// Two trees are called isomorphic if one can be obtained from another by a series of flips, i.e.
//  by swapping left and right children of several nodes. Any number of nodes at any level can have 
//  their children swapped. Two empty trees are isomorphic.`

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


bool isIsomorphic(Node *root1,Node *root2){
    if (!root1 && !root2) //if both are null
        return true;
    if ((!root1) ^ (!root2)) //if one of them is null
        return false;

    if (root1->data != root2->data)
        return false;

    return isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right) ||
           isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);
    
}

int main(){

    return 0;
}