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


int maxSumNoAdjacent(Node *root){
    if (!root)
        return;

    int including = root->data;

    if (root->left)
        including += maxSumNoAdjacent(root->left->left) + maxSumNoAdjacent(root->left->right);

    if (root->right)
        including += maxSumNoAdjacent(root->right->left) + maxSumNoAdjacent(root->right->right);

    int excluding = maxSumNoAdjacent(root->left) + maxSumNoAdjacent(root->right);

    return max(including, excluding);
}


//with memoization

unordered_map <Node*, int> dp;
int maxSumNoAdjacent2(Node *root){
    if (!root)
        return 0;

    if (dp.find(root) != dp.end())
        return dp[root];

    int including = root->data;

    if (root->left)
        including += maxSumNoAdjacent2(root->left->left)
            + maxSumNoAdjacent2(root->left->right);

    if (root->right)
        including += maxSumNoAdjacent2(root->right->left) + 
        maxSumNoAdjacent2(root->right->right);

    int excluding = maxSumNoAdjacent2(root->left) + maxSumNoAdjacent2(root->right);

    dp[root] = max(including, excluding);

    return dp[root];
}


//simple traversal solution
//the idea is to return two values max_including = max sum including the root node
//and max_exlcuding = max sum exlcuding the root node

struct MyRes{
    int max_including;
    int max_excluding;

    MyRes(){
        max_including = max_excluding = 0;
    }
};

MyRes* maxSumNoAdjacent3(Node *root){
    if (!root)
        return new MyRes();

    MyRes *left_res = maxSumNoAdjacent3(root->left);
    MyRes *right_res = maxSumNoAdjacent3(root->right);

    MyRes *res = new MyRes();

    res->max_excluding = max({left_res->max_including + right_res->max_including,
                              left_res->max_excluding + right_res->max_excluding,
                              left_res->max_excluding + right_res->max_including,
                              left_res->max_including + right_res->max_excluding
                              });
    res->max_including = root->data + left_res->max_excluding + right_res->max_excluding;

    return res;

}


int main(){


    return 0;
}