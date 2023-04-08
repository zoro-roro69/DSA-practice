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
// example  
//        1
//    2       3
//        4       5
// left of this tree is - 1, 2, 4

int leftViewHelper(Node *root, int max_ht, int cur_ht, vector <int> &res){
    if (root == NULL)
        return max_ht;
    if (max_ht < cur_ht)
        res.push_back(root->data);

    max_ht = max(max_ht, cur_ht);
    max_ht = leftViewHelper(root->left, max_ht, cur_ht+1, res);
    int r =  leftViewHelper(root->right, max_ht, cur_ht+1, res);
    
    max_ht = max(max_ht, r);
    return max_ht;
}


vector<int> leftView(Node *root)
{
   vector <int> res;
   leftViewHelper(root, -1, 0, res);
   return res;
}

// we can see that left view is basically first node of level order traversal
// so while doing level order traversal we need to print the first node;

vector <int> leftViewIter(Node *root){
    if (root==NULL)
        return {};
    vector <int> res;

    queue <Node *> q;
    q.push(root);

    while(!q.empty()){
        int s = q.size(); //size of cur_level
        int count = 0;
        while(count < s){
            Node *front = q.front(); q.pop();
            if (count == 0){
                res.push_back(front->data);
            }
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);

            count++;
        }
    }

    return res;

}

int main(){

    return 0;
}