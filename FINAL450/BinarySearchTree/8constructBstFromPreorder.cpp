#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node (int val){
        data = val;
        this->left = this->right = NULL;
    }
};

int binarySearch(vector <int> &arr, int start, int end, int key){

    while(start <= end){
        int mid = start + (end-start)/2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            end = mid-1;
        else
            start = mid+1;

    }
    //in our case element will always exist
    return 0; //dummy return

}

Node *helper(vector <int> &pre_order, vector <int> &in_order, int &i, int start, int end){
    if (start > end || i >=pre_order.size()){
        i--;
        return NULL;
    }

    Node *root = new Node(pre_order[i]);
    cout << root->data << endl;
    int ind = binarySearch(in_order, start, end, pre_order[i]);
    root->left = helper(pre_order, in_order, ++i, start, ind-1);
    root->right = helper(pre_order, in_order, ++i, ind+1, end);

    return root;
}
Node *constructTree(vector <int> &pre_order){
    vector <int> in_order = pre_order;
    sort(in_order.begin(), in_order.end());

    int ind = 0;
    return helper(pre_order, in_order, ind, 0, pre_order.size()-1);

}


void inOrderTraversal(Node *root){
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);

}

//we can also contrtuct the given BST just by inerting all elements in the bst in the
// order of preorder, example if preorder is this {10, 5, 1, 7, 40, 50}
// then we first insert 10, then 5, 1, 7 and so on

int main(){

    vector <int> pre_order {10, 5, 1, 7, 40, 50};
    Node *root = constructTree(pre_order);


    inOrderTraversal(root);
    cout << endl;

    cout << "tree" << endl;

    cout << root->left->left->data << endl; //1
    cout << root->left->data << endl; //5
    cout << root->left->right->data << endl; //7
    cout << root->data << endl; //10
    cout << root->right->data << endl; //40
    cout << root->right->right->data << endl; //50


    return 0;
}