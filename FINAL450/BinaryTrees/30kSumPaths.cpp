#include <bits/stdc++.h>
using namespace std;



// print all k paths that sum to k 

// A binary tree and a number k are given. Print every path in the tree with sum of the nodes in the path as k. 
// A path can start from any node and end at any node and must be downward only, i.e. they need not be root node
//  and leaf node; and negative numbers can also be there in the tree.
// "emphasize on downward only"


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

void printVector(vector <int> &path, int start){

    for (;start<path.size();start++)
        cout << path[start] << " ";
    cout << endl;
}

void helper(Node *root, vector <int> &path, int k){
    if (!root)
        return;

    path.push_back(root->data);

    helper(root->left, path, k);
    helper(root->right, path, k);

    int sum_ending_here = 0;
    for (int j = path.size()-1;j>=0;j--) {
        sum_ending_here += path[j];
        if (sum_ending_here == k){
            printVector(path,j);
        }
    }

    path.pop_back();
    

}

void printKSumPaths(Node *root, int k){
    if (!root)
        return;

    vector <int> path;
    helper(root, path, k);
    
    return;

}


int main(){

    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);

    root->right = new Node(-1);  
    root->right->left = new Node(4);  
    root->right->right = new Node(5);  
    root->right->left->left = new Node(1);  
    root->right->left->right = new Node(2);  

    root->right->right = new Node(5);  
    root->right->right->right = new Node(6);  

    printKSumPaths(root, 5);

    return 0;
}


