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
void printVector(vector <int> v){
    for (auto x:v)
        cout << x << " ";
    cout <<endl;
}

//when we dont want to change original tree
Node * mirror(Node *root){
    if (root == NULL)
        return NULL;

    Node *new_node = new Node(root->data);
    new_node->left = mirror(root->right);
    new_node->right = mirror(root->left);

    return new_node;
    
}

//when we need to change the original tree
//just swap left and right nodes
void mirror2(Node *root){
    if (root == NULL)
        return ;

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror2(root->left);
    mirror2(root->right);

}

 vector<int> levelOrder(Node* node)
    {
        queue <Node*> q;
        q.push(node);
        
        vector <int> res;
        while(!q.empty()){
            Node *top = q.front(); q.pop();
            
            res.push_back(top->data);
            if (top->left)
                q.push(top->left);
                
            if (top->right)
                q.push(top->right);
            
        }
        
        return res;
      
      
    }
int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->right = new Node(3);

    vector <int> v = levelOrder(root);
    printVector(v);
    // root = mirror(root);
    mirror2(root);
    v = levelOrder(root);
    printVector(v);

    return 0;
}