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

string toString(int val){

    string res = "";
    while(val){
        int temp = val%10;
        val /= 10;
        res += temp - '0';
    }
    reverse(res.begin(), res.end());

    return res;
}

string duplicateSubtree(Node *root, unordered_set <string> &mp, bool &flag){
    if (!root)
        return "";

    string res = "(";
    res += root->data;
    string left_res = duplicateSubtree(root->left, mp, flag);
    if (flag)
        return left_res;
    string right_res = duplicateSubtree(root->right, mp, flag); 
    if (flag)
        return right_res;
    
    res += left_res + right_res + ")";
    if (root->left || root->right){ //ht is atleas 2
        if (mp.find(res) != mp.end()){ //found
            flag = true;
            return res;
        }else{
            mp.insert(res);
            return res;
        }
    }

    return res;

}

int dupSub(Node *root){
    bool flag = false;
    unordered_set <string> mp;
    duplicateSubtree(root, mp, flag);
    return flag;
}

int main(){

    return 0;
}