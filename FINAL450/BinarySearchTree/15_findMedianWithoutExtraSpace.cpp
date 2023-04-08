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

//count Nodes by using morris traversal
int countNodes(Node *root){
    if (root == NULL)
        return 0;
    int count = 0;
    Node *cur = root;
    while(cur!=NULL){

        if (cur->left == NULL){
            count++;
            cur = cur->right;
        }else{
            Node *prev = cur->left;

            while(prev->right && prev->right != cur){
                prev = prev->right;
            }
            //prev now points at inorder prdecessor of cur
            if (prev->right == NULL){
                prev->right = cur; //backlink, thread
                cur = cur->left;
            }else{
                //backlink already exists, i.e we have traversed the left subtree
                prev->right = NULL; //removing link
                count++; //print cur and move on to the right
                cur = cur->right;
            }
        }
    }

    return count;
}



//[1,2,3,4,5,6,7,8,9,(10)]
float findMedian(Node *root){
    if (root == NULL)
        return 0;
    int n = countNodes(root);
    cout << "n: " << n << endl;
    //morris traversal
    int sum_ = 0;
    int count = n/2;

    count++;

    Node *cur = root;
    while(cur){
        if (cur->left == NULL){
            count--;
            if (count == 1 && n%2==0)
                sum_ += cur->data;
            
            if (count == 0){
                sum_ += cur->data;
                break;
            }
            cur = cur->right;
        }else{
            Node *prev = cur->left;
            while(prev->right && prev->right != cur){
                prev = prev->right;
            }

            if (prev->right == NULL){
                prev->right = cur;
                cur = cur->left;
            }else{
                prev->right = NULL;
                count--;

                if (count == 1 && n%2==0)
                    sum_ += cur->data;
                
                if (count == 0){
                    sum_ += cur->data;
                    break;
                }

                cur = cur->right;
            }
        }
    }
    return n%2 ? sum_ : (float) sum_/2;
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

    vector <int> arr{1,2,3,4,5,6,7, 8, 9,10,11,12};
    Node *root = buildBst(arr, 0, arr.size()-1);

    inOrderPrint(root);
    cout << endl;

    cout << findMedian(root) << endl;
    

    return 0;
}