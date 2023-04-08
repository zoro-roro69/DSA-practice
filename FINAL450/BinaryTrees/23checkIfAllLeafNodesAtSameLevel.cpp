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


int leaf_lvl = 0;
bool leafAtSameLevel(Node *root, int &cur_lvl){
    if (!root)
        return true;

    cur_lvl++;
    if (root->left == NULL && root->right == NULL ){ //leaf node
        if (leaf_lvl == 0 || leaf_lvl == cur_lvl){
            leaf_lvl = cur_lvl;
            return true;
        }
        return true;
    }
    bool left_res = true;
    bool right_res = true;
    if (root->left)
        left_res = leafAtSameLevel(root, cur_lvl);

    if (!left_res)
        return false;

    if (root->right)
        right_res = leafAtSameLevel(root, cur_lvl);

    if (!right_res)
        return false;

    cur_lvl--;
    
    return true;
}
bool check(Node *root){
    leaf_lvl = 0;
    int cur_lvl = 0;
    return leafAtSameLevel(root, cur_lvl);

}

int main(){

    return 0;
}