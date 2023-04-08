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


vector <int> zigZagTraversal(Node* root){
    if (root == NULL)
        return {};

    vector <int> res;

    bool flag = true;
    vector <Node *> cur_lvl;
    cur_lvl.push_back(root);
    bool flag = true;

    while(!cur_lvl.empty()){
        vector <Node *> temp;
        stack <int> st;
        for (auto node:cur_lvl){
            if (flag)
                res.push_back(node->data);
            else{
                st.push(node->data);
            }
            if (node->left)
                temp.push_back(node->left);
            if (node->right)
                temp.push_back(node->right);
        }

        if (!flag){
            while(!st.empty()){
                res.push_back(st.top()); st.pop();
            }
        }

        cur_lvl = temp;
        flag = !flag;
    }

    return res;

}


//using two stacks
vector <int> zigZagTraversal2(Node *root){
    if (root == NULL)
        return {};
    vector <int> res;

    stack <Node *> cur_lvl;
    cur_lvl.push(root);
    bool flag = true;
    
    while(!cur_lvl.empty()){
        stack <Node *> next_lvl;
        while(!cur_lvl.empty()){
            
            Node *top = cur_lvl.top(); cur_lvl.pop();
            res.push_back(top->data);
            if (flag){ //left to right

                if (top->left)
                    next_lvl.push(top->left);
                if (top->right)
                    next_lvl.push(top->right);

            }else{ //right to left
                if (top->right)
                    next_lvl.push(top->right);
                if (top->left)
                    next_lvl.push(top->left);
            }
        }
        
        flag = !flag;
        cur_lvl = next_lvl;
    }

    return res;

}
int main(){



    return 0;
}