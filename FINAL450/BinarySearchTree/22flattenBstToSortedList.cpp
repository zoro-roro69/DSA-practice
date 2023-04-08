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


void printList(TreeNode *head);


void flattenInorder(TreeNode* &root) {

    TreeNode *prev = NULL;

    TreeNode *cur = root;

    while(cur != NULL){
        if (cur->left == NULL){
            if (prev)
                prev->right = cur;

            cur->left = prev;
            prev = cur;
            cur = cur->right;
        }else{
            TreeNode *pred = cur->left;
            while(pred->right && pred->right != cur){
                pred = pred->right;
            }
            if (pred->right == cur){ //backlink already formed
                //here prev == pred
                //in normal morris traversal we would have removed the backlink now
                if (prev)
                    prev->right = cur;

                cur->left = prev;
                prev = cur;
                cur = cur->right;
            }else{
                //form the backlink
                pred->right = cur;
                cur = cur->left;
            }
        }
    }

    while(root->left)
        root = root->left;

    printList(root);

}

//flatten preorder recursive
//take smaller example to learn the intuition
// 5
//2 7
TreeNode *prev_node = NULL;
void flattenPreorderRecursive(TreeNode *root){
    if (root == NULL){
        return;
    }else{

        flattenPreorderRecursive(root->right);
        flattenPreorderRecursive(root->left);

        root->right = prev_node;
        root->left = NULL;

        prev_node = root;

        return;

    }
}


//morris traversal
void flattenPreorder(TreeNode* &root) {

    TreeNode *cur = root;
    TreeNode *prev = NULL;

    while(cur != NULL){
        if (cur->left != NULL){
            TreeNode *pred = cur->left;
            while(pred->right != NULL){
                pred = pred->right;
            }
            //backlink but this time it is pointing to right of cur
            pred->right = cur->right;

            cur->right = cur->left;
            // cur->left = prev;
            cur->left = NULL;
        }
        // prev = cur;

        cur = cur->right;
    }
}

//creates a balanced bst from given sorted array
TreeNode *buildBst(vector <int> &arr, int start, int end){
    if (start>end)
        return NULL;
    int mid = start + (end-start)/2;
    TreeNode *root = new TreeNode(arr[mid]);
    root->left = buildBst(arr, start, mid-1);
    root->right = buildBst(arr, mid+1, end);

    return root;
}

void printList(TreeNode *head){

    while(head){
        cout << head->val << " ";
        head = head->right;
    }
    cout << endl;
}


void inOrderPrint(TreeNode *root){
    if (!root)
        return;
    inOrderPrint(root->left);
    cout << root->val << " ";
    inOrderPrint(root->right);
}

int main(){

    vector <int> arr1{2,5, 6};
    vector <int> arr2{0,6,9,13,20};
    TreeNode *root1 = buildBst(arr1, 0, arr1.size()-1);
    TreeNode *root2 = buildBst(arr2, 0, arr2.size()-1);

    // flattenInorder(root1);
    // printList(root1);

    // root1 = buildBst(arr1, 0, arr1.size()-1);
    // inOrderPrint(root1); cout << endl;
    flattenPreorderRecursive(root2);
    printList(root2);
    printList(root2);
    return 0;
}