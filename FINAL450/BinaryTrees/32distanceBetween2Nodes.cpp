#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node *left;
    Node *right;

    Node(int v = 0){
        data = v;
        left = right = NULL;
    }
};


struct Result{
    Node *node;
    int ht;

    Result(Node *n = NULL, int h = 0){
        ht = h;
        node= n;
    }
};

Result *lca(Node *root, int v1, int v2){

    //Your code here 
    if (!root) //root == NULL
        return NULL;

    if (root->data == v1 || root->data == v2){
        Result *res = new Result(root,1);
        return res;
    }

    Result *left_res = lca(root->left, v1, v2);
    Result *right_res = lca(root->right, v1, v2);

    if (!left_res && !right_res) //if both are NULL
        return NULL;
    if (left_res && right_res){
        //if both are not NULL , that means this is the LCA and each subtree contains each value
        Result *res = new Result(NULL); //null to mark that both childs were in different subtree
        res->ht = left_res->ht + right_res->ht;

        return res; 
        
        }

    if (left_res){
        left_res->ht++;
        return left_res; //left res is lca
    }

    right_res->ht++;
    return right_res; //right res is lca

}

int findHt(Node *root, int key){
    if (!root)
        return 0;
    if (root->data == key)
        return 1;

    int left = findHt(root->left, key);
    if (left)
        return left+1;

    int right = findHt(root->right, key);

    if (right)
        return right+1;

    return 0;
}

int findDist(Node* root, int a, int b) {
    // Your code here
    Result *res = lca(root, a, b); 
    
    if (res->node == NULL)
        return res->ht;

    //else this means both lie in same subtree
    int key = res->node->data == a ? b:a;

    int dist = findHt(root, key);
    return dist-1;


}

int main(){

    return 0;
}