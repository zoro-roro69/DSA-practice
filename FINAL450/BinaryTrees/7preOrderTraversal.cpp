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

//preorder -- root left right
void preOrderRecur(Node *root){
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderRecur(root->left);
    preOrderRecur(root->right);
}


void preOrderIter(Node *root){
    if (root == NULL)
        return;
    stack <Node *> st;
    st.push(root);

    while(!st.empty()){
        Node *top = st.top(); st.pop();
        cout << top->data << " ";
        if (top->right)
            st.push(top->right);
        if (top->left)
            st.push(top->left);
    }

}

int main(){

    Node *root = new Node(1);
    root->left =  new Node(2);
    root->right =  new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    preOrderRecur(root); cout << endl;
    preOrderIter(root); cout << endl;

    return 0;
}