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

string toString(int val){
    string res = "";

    while(val){
        int rem = val%10;
        val = val/10;
        res += (rem - '0');
    }
    reverse(res.begin(), res.end());
    
    return res;
}


string helper(Node *root, unordered_map <string, int> &mp, vector <Node*> &v){
    if (!root)
        return "";

    string left_res = helper(root->left, mp, v);
    string right_res = helper(root->right, mp, v);

    string res = "(" + left_res + right_res + toString(root->data) + ")";

    if (mp.find(res)==mp.end()) {
        mp[res] = 1;
    }else{
        if (mp[res]< 2)
            v.push_back(root);
        mp[res]++;   
        
    }

    return res;

}

vector <Node *> printAllDups(Node *root){

    vector <Node *> res;
    unordered_map <string, int> mp;
    helper(root, mp, res);


    // for (auto x:mp){
    //     if (x.second.count >1)
    //         res.push_back(x.second.root);
    // }

    return res;

}



int main(){


    return 0;
}