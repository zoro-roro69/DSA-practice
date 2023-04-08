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

Node *constructTree(string &str, int &k){
    if (k>=str.size())
        return NULL;

    if (str[k]=='(' || str[k]==')')
        return NULL;
    
    int val = str[k] - '0';
    Node *new_node = new Node(val);
    k++;
    if (k>=str.size() || str[k] == ')')
        return new_node;
    else { // '('
        k++; //k is now at integer
        new_node->left = constructTree(str, k);    //1(2)(3)
        k++; //k was at ')', now its at ')' or '('
        if (k>=str.size() || k == ')')
            return new_node;
        else{
            k++; //k is now at integer
            new_node->right = constructTree(str, k);
            k++;
        }
        return new_node;
    }
}

void inorderTraversal(Node *root){
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}


void preorderTraversal(Node *root){
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){

    string str = "1(2(3(4)(5))())(6(7)(8(9)(0)))";
    int k = 0;
    Node *node = constructTree(str, k);
    preorderTraversal(node);

    return 0;
}