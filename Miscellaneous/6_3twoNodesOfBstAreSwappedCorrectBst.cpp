#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

class Solution1{
    void inOrder(Node *root, vector <Node *> &arr){
        if (root == NULL)
            return ;
        inOrder(root->left, arr);
        arr.push_back(root);
        inOrder(root->right, arr);
    }

    Node *correctBST(struct Node *root) {
        // code here
        vector <Node *> inorder;

        inOrder(root, inorder);

        int ind1 = -1;
        int ind2 = -1;

        for (int i=0;i<inorder.size()-1;i++){
            if (inorder[i]->data < inorder[i+1]->data){
                if (ind1 == -1)
                    ind1 = i;
                else
                    ind2 = i+1; //IMPORTANT, remember this, ind2 is set to= i+1
            }
        }
        if (ind2 == -1)
            ind2 = ind1+1;
        swap(inorder[ind1]->data, inorder[ind2]->data);

        return root;
    }
};


class Solution2{

    void inOrder(Node *root, Node * &prev, Node * &first, Node * &second){
        if (root == NULL)
            return ;
        inOrder(root->left, prev, first, second);
        if (prev != NULL && root->data < prev->data){
            if (first == NULL)
                first = prev;
            second = root;
        }
        prev = root;
        inOrder(root->right, prev, first, second);
    }

    Node *correctBST(struct Node *root) {
        // code here

        Node *prev = NULL;
        Node *first = NULL;
        Node *second = NULL;

        inOrder(root, prev, first, second);

        if (first && second)
            swap(first->data, second->data);
        return root;
        
    }
};

int main(){


    return 0;
}