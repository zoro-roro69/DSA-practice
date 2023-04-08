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


//this actually returns the kth element not the kth largest :)
// 4 69 72 78 79 80
//consider this example here if k = 5
//then the 5th element in sorted order is 79
//but 5th largest element is 69 ( element which comes at 5th position when array is sorted in reverse)

int kthLargest(Node *root, int &k){
    //Your code here
    if (root == NULL)
        return 0; 

    int left_res = kthLargest(root->left, k);
    if (left_res)
        return left_res;
    
    k--;
    if (k == 0) //cur node is th kth element
        return root->data;
    
    int right_res = kthLargest(root->right, k);

    return right_res;
    

}

//modifcation to give kth largest element
// 
// return the Kth largest element in the given BST rooted at 'root'
// class Solution
// {
//     int kthLargesthelper(Node *root, int &k){
//         //Your code here
//         if (root == NULL)
//             return 0; 
    
//         int left_res = kthLargesthelper(root->left, k);
//         if (left_res)
//             return left_res;
        
//         k--;
//         if (k == 0) //cur node is th kth element
//             return root->data;
        
//         int right_res = kthLargesthelper(root->right, k);
    
//         return right_res;
        
    
//     }
    
//     int countNodesInBst(Node *root){
//         if (!root)
//             return 0;
        
//         return 1 + countNodesInBst(root->left) + countNodesInBst(root->right);
//     }
//     public:
//     int kthLargest(Node *root, int K)
//     {
//         //Your code here
//         int n  = countNodesInBst(root);
//         //cout << n << endl;
//          K = n-K+1; 
//          //cout << K << endl;
//         return kthLargesthelper(root, K);
//     }
// };


//kth largest using reverse inorder traversal right, root, left

int kthLargest(Node *root, int &k){
    if (root == NULL)
        return -1;
    
    int right_res = kthLargest(root->right, k);
    if (right_res != -1)
        return right_res;
    
    k--;
    if (k == 0)
        return root->data; //current element is the kth largest
    
    int left_res = kthLargest(root->left, k);
    
    return left_res;

}

int main(){

    vector <int> arr1{1,2,3,4,5,6,7};
    Node *root = buildBst(arr1, 0, arr1.size()-1);

    reverseInOrderPrint(root); //reverse order

    // for (int i=0;i<7;i++){
    //     int k = i+1;
    //     cout << kthLargest(root, k) << endl;
    // }

    return 0;
}