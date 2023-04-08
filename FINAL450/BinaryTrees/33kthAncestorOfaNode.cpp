#include <bits/stdc++.h>
using namespace std;


struct Node{

    int data;
    Node *left;
    Node *right;

    Node(int v = 0){
        data = v;
        left = right = NULL;
    }
};

int ans = -1;
int kthAncestor(Node *root, int key, int k){
    if (!root)
        return 0; //not found

    if (root->data == key)
        return 1;

    int left_res = kthAncestor(root->left, key, k);
    if (left_res){
        if (left_res == k){
            ans = root->data;
            return left_res;
        }else{
            return left_res + 1;
        }
    }

    int right_res = kthAncestor(root->right, key, k);

    if (right_res){
        if (right_res == k){
            ans = root->data;
            return right_res;
        }else
            return  right_res + 1;

    }

    return 0;
}

int main(){


    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);

    ans = -1;
    kthAncestor(root, 3, 2);
    cout << ans << endl;

    return 0;
}