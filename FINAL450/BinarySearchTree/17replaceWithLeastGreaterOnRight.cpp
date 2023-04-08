#include <bits/stdc++.h>
using namespace std;

vector<int> findLeastGreater(vector<int>& arr, int n) {

    set <int> s;

    s.insert(arr[n-1]);
    arr[n-1] = -1;

    for (int i=n-2;i>=0;i--){
        int cur = arr[i];
        auto it = s.upper_bound(cur);
        if (it == s.end())
            arr[i] = -1;
        else
            arr[i] = *it;
        s.insert(cur);
    }

    return arr;    
}


//upper bound using bst
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
//upperbound in bst
Node *upperBoundBst(Node *root, int x){
    if (root == NULL)
        return NULL;
    if (root->data > x){
        Node *left = upperBoundBst(root->left, x);
        if (left)
            return left;
        return root;
    }else{
        return upperBoundBst(root->right, x);
    }
}


int main(){
    // vector <int> arr{8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    // findLeastGreater(arr, arr.size());

    // for (int i=0;i<arr.size();i++)
    //     cout << arr[i] << " ";
    // cout << endl;

    vector <int> arr2{1,3,5,7,8,10};
    Node *root = buildBst(arr2, 0, arr2.size()-1);

    Node *node = upperBoundBst(root, 3);
    if (node)
        cout << node->data << endl;
    else
        cout << -1 << endl;

    return 0;
}