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

//min swaps reqd to convert a Bt to binary tree

void inOrder(Node *root, vector <int> &v){
    if (!root)
        return;

    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right, v);
}


int minSwapsArr(vector <int> v){

    vector <int> sortedv;
    sortedv = v;
    sort(sortedv.begin(), sortedv.end());

    unordered_map <int, int> pos;
    for (int i=0;i<sortedv.size();i++){ 
        //assuming all numbers are unique
        //if not then make a string as key and use "v[i]-i" as  a key
        pos[sortedv[i]] = i;
    }

    int res = 0;

    for (int i=0;i<v.size();i++){
        if (i == pos[v[i]]){ //already at correct position
            continue;
        }else{
            int actual_pos = pos[v[i]];
            swap(v[i], v[actual_pos]);
            res++;
            i--;
        }
    }

    return res;

}

int minSwaps(Node *root){

    vector <int> v;
    inOrder(root,v);

    return minSwapsArr(v);
}

int main(){
    vector <int> a = { 2,1, 3 };
    cout << minSwapsArr(a) << endl;

    
    return 0;
}