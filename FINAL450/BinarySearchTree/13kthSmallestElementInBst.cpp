#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


void inOrderPrint(Node *root){
    if (!root)
        return;
    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}

void reverseInOrderPrint(Node *root){ //right, root, left
    if (!root)
        return;
    reverseInOrderPrint(root->right);
    cout << root->data << " ";
    reverseInOrderPrint(root->left);

}


//creates a balanced bst from given sorted array
Node *buildBst(vector <int> &arr, int start, int end){
    if (start>end)
        return NULL;
    int mid = start + (end-start)/2;
    Node *root = new Node(arr[mid]);
    root->left = buildBst(arr, start, mid-1);
    root->right = buildBst(arr, mid+1, end);

    return root;
}


int kthSmallestHelper(Node *root, int &k){
    if (root == NULL)
        return -1;
    
    int left_res = kthSmallestHelper(root->left, k);
    if (left_res != -1)
        return left_res;
    k--;
    if (k == 0)
        return root->data;

    int right_res = kthSmallestHelper(root->right, k);

    return right_res;
}

// Return the Kth smallest element in the given BST
int KthSmallestElement(Node *root, int k) {
    // add code here.
    return kthSmallestHelper(root, k);
}


int main(){

    vector <int> arr1{1,2,3,4,5,6,7};
    Node *root = buildBst(arr1, 0, arr1.size()-1);

    inOrderPrint(root);
    // for (int i=0;i<arr1.size();i++){
    //     int k = i+1;
    //     cout << KthSmallestElement(root, k) << endl;
    // }


    return 0;
}