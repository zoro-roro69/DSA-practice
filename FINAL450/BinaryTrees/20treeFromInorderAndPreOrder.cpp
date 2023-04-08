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

class Solution{
    public:

    Node *helper(int n, int pre[], int &pre_ind, int in[], int si, int ei){
        if (pre_ind >= n || si>ei)
            return NULL;

        Node *new_node = new Node(pre[pre_ind]);
        for (int i = si; i<=ei ; i++){
            if (pre[pre_ind] == in[i]){
                pre_ind++;
                new_node->left = helper(n, pre, pre_ind, in, si, i-1);
                new_node->right = helper(n, pre, pre_ind, in, i+1, ei);
                break;
            }
        }
        return new_node;
        
    }

    Node* buildTree(int in[],int pre[], int n)
    {   
        int pre_ind = 0;
        return helper(n, pre, pre_ind, in, 0, n-1);
    }
};


int main(){


    return 0;
}