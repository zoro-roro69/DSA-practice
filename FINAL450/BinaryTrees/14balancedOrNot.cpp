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

struct Res{
    bool balanced;
    int ht;

    Res(bool b, int h){
        balanced = b;
        ht = h;
    }
};
Res* helperIsBalanced(Node *root){
    if (root == NULL){
        return new Res(true, 0);
    }

    Res *left = helperIsBalanced(root->left);
    if (left->balanced == false)
        return left;
    
    Res *right = helperIsBalanced(root->right);
    if (right->balanced == false)
        return right;

    int diff = left->ht - right->ht;
    if (!(diff==-1 || diff==1))
        return new Res(false, 0);

    return new Res(true, max(left->ht, right->ht)+1);

}

//Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    Res *res = helperIsBalanced(root);
    return res->balanced;   
}


//better way
//returns ht, if unbalanced then return -1
int height(Node *root){
    if (root == NULL)
        return 0;

    int left_ht = height(root->left);
    if (left_ht == -1)
        return -1;

    int right_ht = height(root->right);
    if (right_ht == -1)
        return -1;

    int diff = abs(left_ht - right_ht);
    if (diff > 1)
        return -1;
    return max(left_ht, right_ht) + 1;
}

bool isBalanced2(Node *root){
    return height(root) != -1;
}

int main(){

    return 0;
}