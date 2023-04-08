#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

//postorder -- left right root
void postOrderRecur(Node *root){
    if (root == NULL)
        return;

    postOrderRecur(root->left);
    postOrderRecur(root->right);
    cout << root->data << " ";
}

void postOrderIter(Node *root){
    if (root == NULL)
        return;

    stack <Node *> st;
    st.push(root);

    while(!st.empty()){
        Node *top = st.top();
        if (top!=NULL){
            st.push(NULL);
            st.push(top->right);
            st.push(top->left);
        }else{
            while(st.top()==NULL){
                st.pop();
            }
            cout << st.top()->data << " ";
            st.pop();
        }

    }
    cout << endl;

}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(4);

    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->left->left = new Node(6);

    root->right->right = new Node(7);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);

    // Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    postOrderRecur(root); cout << endl;
    postOrderIter(root); cout << endl;
    return 0;
}