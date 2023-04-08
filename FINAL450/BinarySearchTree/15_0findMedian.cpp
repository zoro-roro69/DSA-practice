#include <bits/stdc++.h>
using namespace std;

//find median of BST, expected time complexit - O(n)
// expected space complexity - O(1)

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int countNodes(Node *root){
    if (root == NULL)
        return 0;
    else{
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

Node *getKthElement(Node *root, int &k){
    if (root == NULL)
        return NULL;
    Node *left_res = getKthElement(root->left, k);
    if (left_res)
        return left_res;
    k--;
    if (k == 0)
        return root;
    
    return getKthElement(root->right, k);

}

// 5,[1,4]
// 1 2 3 4 5 6 7 8 9 10
float medianOfBst(Node *root){
    int n = countNodes(root);
    if (n%2){ //n is odd
        int k = n/2+1;
        Node *x = getKthElement(root, k);
        return x->data;
    }else{

        int k = n/2;
        Node *x = getKthElement(root, k);
        k = n/2+1;
        Node *y = getKthElement(root, k);
        return (float)(x->data + y->data)/2;
    }
}

void inOrderPrint(Node *root){
    if (!root)
        return;
    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
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

int main(){
    vector <int> arr{1,2,3,4,5,6,7, 8, 9,10};
    Node *root = buildBst(arr, 0, arr.size()-1);

    inOrderPrint(root);
    cout << endl;
    cout <<"median:" << medianOfBst(root) << endl;
    return 0;
}