#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
//Function to find the height of a binary tree.
int height(Node* node){
    // code here 
    if (node == NULL)
        return 0;
        
    return 1 + max(height(node->left), height(node->right));
}

//without recurssion, using level order traversal
int height2(Node *node){

    int ht = 0;
    queue <Node *> q;

    q.push(node);

    while(!q.empty()){
        int size = q.size(); //size of current level
        ht++;
        while(size){
            Node *front = q.front(); q.pop();
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
            size--;
        }
    }

    return ht;

}