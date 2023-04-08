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

void printDiagonalView(Node *root){
    if (root == NULL)
        return;
    
    queue <Node *> q;
    q.push(root);

    while(!q.empty()){
        int cur_len = q.size();
        for (int i=0;i<cur_len;i++){
            Node *front = q.front(); q.pop();
            cout << front->data << " ";

            if (front->left)
                q.push(front->left);
            
            Node *right = front->right;
            while(right){
                cout << right->data << " ";
                if (right->left)
                    q.push(right->left);
                right = right->right;
            }
        }
        cout << endl;
    }
    return;
}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(3);
    root->right->left = new Node(7);
    root->right->right = new Node(6);

    printDiagonalView(root);

    return 0;
}