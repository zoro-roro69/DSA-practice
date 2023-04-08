#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int largestSumSubTree(Node *root, int &max_sum){
    if (!root)
        return 0;

    int left_sum = largestSumSubTree(root->left, max_sum);
    int right_sum = largestSumSubTree(root->right, max_sum);

    int cur_sum = left_sum + right_sum + root->data;
    max_sum = max(cur_sum, max_sum);
    
    return cur_sum;
}


int main(){


    return 0;
}