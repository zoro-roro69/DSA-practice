#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;

    Node *right;
    Node *left;

    Node (int val){

        data = val;
        left = right = NULL;
    }
};

struct Result{
    int size;
    int max_size;
    bool isbst;

    int low;
    int high;

    Result(){
        size = 0;
        max_size = 0;
        isbst = true;
        low = INT_MAX;
        high = INT_MIN;
    }
};

Result *helper(Node *root){
    if (root == NULL){
        Result *res = new Result(); //bst of size 0
    }else{
        Result *left_res = helper(root->left);
        Result *right_res = helper(root->right);

        Result *res = new Result();

        if (root->data > left_res->high && root->data < right_res->low){
            //then current node is bst
            res->size = left_res->size + right_res->size + 1;
            res->low = min(left_res->low, root->data);
            res->high = max(right_res->high, root->data);

        }else{
            //not bst
            res->size = 0;
            // res->low = root->data;
            // res->high = root->data;

            res->low = INT_MIN;
            res->high = INT_MAX;
        }

        res->max_size = max(max(res->size, left_res->max_size), right_res->size);

        return res;
    }
}

int largestBst(Node *root){
    Result *res = helper(root);
    return res->max_size;
}


int main(){

    return 0;
}