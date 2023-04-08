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


    return 0;
}