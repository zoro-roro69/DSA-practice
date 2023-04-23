#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution
{
    Node* helper(Node *root, Node *parent){
        if (root == NULL)
            return NULL;
        
        //here we are doing two things
        //first we find the leftmost node in this subtree, which will be the inorder succesor of the parent node
        //and then we find the inorder successor for the current Node as well
        
        Node *leftmost = helper(root->left, root);
        Node *succesor = helper(root->right, parent);
        
        if (succesor == NULL){
            root->right = parent;
            if (parent)
                parent->left = root;
        }else{
            root->right = succesor;
            succesor->left = root;
        }
        if (leftmost != NULL)
            return leftmost; //it will become succesor of parent
        return root;
    }
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        return helper(root, NULL);
    }
};


//method 2
// The idea is to do in-order traversal of the binary tree. While doing 
// inorder traversal, keep track of the previously visited node in a 
// variable, say prev. For every visited node, make it next to the prev 
// and set previous of this node as prev.

void helper(Node *node, Node * &prev){
    if (node == NULL)
        return ;
    
    helper(node->left, prev);
    //prev will be pointing to previous of current element
    node->left = prev;
    if (prev)
        prev->right = node;
    
    prev = node;

    helper(node->right, prev);
}

Node* binaryTreeToDLL(Node *node){
    Node *prev = NULL;

    helper(node, prev);
    while(node->left)
        node = node->left;
    return node;
}

int main(){

    return 0;
}