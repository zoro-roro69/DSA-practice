#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int rightViewHelper(Node *root, int max_ht, int cur_ht, vector <int> &res){
    if (root == NULL)
            return max_ht;

    if (max_ht < cur_ht){
        res.push_back(root->data);
        max_ht = cur_ht;
    }
    
    max_ht = rightViewHelper(root->right, max_ht, cur_ht+1, res);
    int r = rightViewHelper(root->left, max_ht, cur_ht+1, res);
    max_ht = max(max_ht, r);
    
    return max_ht;
    
        
}

//can also be done as last node in level order traversal


vector<int> rightView(Node *root)
{
    // Your Code here
    vector <int> res;
    rightViewHelper(root, -1, 0, res);
    return res;
}