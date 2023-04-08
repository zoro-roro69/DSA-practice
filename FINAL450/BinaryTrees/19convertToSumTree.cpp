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

int sumTree(Node *node){
    if (node == NULL)
        return 0;
    
    if (node->left == NULL && node->right == NULL){
        //making leaf nodes 0, it was asked in question to do so
        int val = node->data;
        node->data = 0;
        return val;
    }
    
    int left_sum = sumTree(node->left);
    int right_sum = sumTree(node->right);
    
    
    int val = node->data;
    node->data = left_sum + right_sum;
    return val + node->data;
    
}

void toSumTree(Node *node)
{   if (node == NULL)
        return;
    
    sumTree(node);
    
}

int main(){


}