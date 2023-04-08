#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

//bettert soltion than mine :)

class Solution {
public:
   
   void leaf_traversal(vector<int> &v,Node *root){
       if(root==NULL)
           return;
       if(root->left==NULL&&root->right==NULL)
           v.push_back(root->data);
       leaf_traversal(v,root->left);
       leaf_traversal(v,root->right);
       
   }
   void  left_traversal(vector<int> &v,Node * root){
       if(root==NULL)
           return;
       if(root->left!=NULL||root->right!=NULL)
           v.push_back(root->data);
       left_traversal(v,root->left);
       if(root->left==NULL)
           left_traversal(v,root->right);
   }
   
   void  right_traversal(stack<int> &s,Node * root){
       if(root==NULL)
           return;
       if(root->left!=NULL||root->right!=NULL)
           s.push(root->data);
       right_traversal(s,root->right);
       if(root->right==NULL)
           right_traversal(s,root->left);
   }
   
   vector <int> boundary(Node *root)
   {
       vector<int> v;
       Node* temp=root;
       stack<int> s;
       if(root==NULL)
           return v;
       v.push_back(root->data);
       left_traversal(v,root->left);
       leaf_traversal(v,root->left);
       leaf_traversal(v,root->right);
       right_traversal(s,root->right);
       while(!s.empty()){
           v.push_back(s.top());
           s.pop();
       }
       return v;
       
   }
};


void printLeaves(Node *node, vector <int> &res){
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL){
        //leaf
        res.push_back(node->data);
    }else{
        printLeaves(node->left, res);
        printLeaves(node->right, res);
    }
}

void printRightBoundary(Node *node, vector <int> &res){
    if (node == NULL)
        return;
    printLeaves(node->left, res);
    printRightBoundary(node->right, res);
    res.push_back(node->data);
}

vector <int> boundary(Node *root){
    if (root == NULL)
        return {};

    vector <int> res;
    res.push_back(root->data);
    //left side
    Node *cur = root->left;
    stack <Node *> st;
    Node *last_right = cur;

    while(cur || last_right){
        if (cur == NULL){
            cur = last_right;
            st.pop();
        }
        res.push_back(cur->data);
        if (cur->right)
            st.push(cur->right);
        last_right = cur->right;
        cur = cur->left;
    }

    //leaves
    while(!st.empty()){
        Node *top = st.top(); st.pop();
        printLeaves(top, res);
    }

    printRightBoundary(root->right, res);

    return res;

}



int main(){

}