#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

    if (root == NULL)
        return {};

    deque <TreeNode*> dq;

    dq.push_back(root);

    bool flag = true;

    vector <vector <int>> res;

    while(!dq.empty()){
        vector <int> cur_lvl;
        int cur_size = dq.size();
        while(cur_size){
            TreeNode * node;
            if (flag){
                node = dq.front(); dq.pop_front();
                
                if (node->left)
                    dq.push_back(node->left);
                if (node->right)
                    dq.push_back(node->right);
            }else{
                node = dq.back(); dq.pop_back();
                if (node->right)
                    dq.push_front(node->right);
                if (node->left)
                    dq.push_front(node->left);
            }

            cur_lvl.push_back(node->val);
            cur_size--;
        }

        res.push_back(cur_lvl);
        flag = !flag;
    }

    return res;
    
}

int main(){


    return 0;
}