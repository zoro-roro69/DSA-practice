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

void morrisTraversalInorder(Node *root){

    Node *cur = root;
    while(cur){
        Node *left = cur->left;

        if (left == NULL){
            cout << cur->data << " ";
            cur = cur->right;
        }else{
            Node *prev = left; 
            //we will now find inorder predecessor, and then point its right node to the cur (this will act as
            // back link)
            while(prev->right && prev->right != cur){
                prev = prev->right;
            }
            if (prev->right == NULL){
                prev->right = cur; //back link, prev is currently pointing to the inorder predecessor of cur node
                cur = cur->left;
            }else{ 
                //prev->right is already pointing the cur, that means we have already 
                // traversed left subtree of cur node
                prev->right = NULL; //now we remove the back link link that we earlier created
                //we print the root now
                cout << cur->data << " ";

                cur = cur->right; //we move on to the right subtree
            }
        }

    }

    cout << endl;
}

// although this approach works but in this there is no way to remove the backlinks after
// during traversal
void morrisTraversalPreOrder(Node *root){ //preorder = root, left, right

    Node *cur = root;

    while(cur){
        cout << cur->data << " " ;

        Node *left = cur->left;
        if (left == NULL){
            cur = cur->right;
        }else{
            Node *prev = left;
            while(prev->right){
                prev = prev->right;
            }

            prev->right = cur->right; //inorder predecessor of cur points to right of cur

            cur = cur->left;
        }
    }

    cout << endl;
}

//in this we slightly modify the inorder version
void morrisTraversalPreorder2(Node *root){

    Node *cur = root;
    while(cur){
        Node *left = cur->left;

        if (left == NULL){
            cout << cur->data << " ";
            cur = cur->right;
        }else{
            Node *prev = left; 
            //we will now find inorder predecessor, and then point its right node to the cur (this will act as
            // back link)
            while(prev->right && prev->right != cur){
                prev = prev->right;
            }
            if (prev->right == NULL){
                prev->right = cur; //back link, prev is currently pointing to the inorder predecessor of cur node
                //now before going left, we print the current node
                cout << cur->data << " ";
                cur = cur->left;
            }else{ 
                //prev->right is already pointing the cur, that means we have already 
                // traversed left subtree of cur node
                prev->right = NULL; //now we remove the back link link that we earlier created

                cur = cur->right; //we move on to the right subtree
            }
        }
    }
    cout << endl;
}



//preorder nnd inorder traversal can be done with no extra space, but for post order 
// requires extra space
// post order = left, right, root
void morrisTraversalPostOrder(Node *root){

    vector <int> postorder; //initially we will store the reverse post order and then reverse this array
    //reverse post order = root, right, left
    Node *cur = root;

    while(cur != NULL){

        // cout << cur->data << endl;
        if (cur->right == NULL){
            postorder.push_back(cur->data);
            cur = cur->left;
        }else{
            Node *successor = cur->right;

            while(successor->left!= NULL && successor->left != cur){
                successor = successor->left;
            }

            if (successor->left == NULL){ //successor now points to inorder succesor of cur
                successor->left = cur; //creating backlink
                postorder.push_back(cur->data);
                cur = cur->right;
            }else{
                //backlink already exists
                successor->left = NULL;
                cur = cur->left;
            }
        }
    }

    reverse(postorder.begin(), postorder.end());

    for (int x:postorder)
        cout << x << " ";
    cout << endl;


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

void inOrderPrint(Node *root){
    if (!root)
        return;
    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}

int main(){

    vector <int> arr{1,2,3,4,5,6,7,8,9};
    Node *root = buildBst(arr, 0, arr.size()-1);
    inOrderPrint(root);
    cout << endl;
    morrisTraversalInorder(root);
    morrisTraversalPreorder2(root);
    // morrisTraversalPreOrder(root); //in this now the tree is modified with thread links
    morrisTraversalPostOrder(root);
    return 0;
}