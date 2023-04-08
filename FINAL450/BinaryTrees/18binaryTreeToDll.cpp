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


//solution 1
struct Res{
    Node *leftmost;
    Node *rightmost;
    
    Res(){
        leftmost = NULL;
        rightmost = NULL;
    }
};

Res *helper(Node *root){
    if (root == NULL)
        return new Res();
    else{
        Res *left_res = helper(root->left);
        Res *right_res = helper(root->right);
        
        Node *prev = left_res->rightmost;
        Node *next = right_res->leftmost;
        
        root->left = prev;
        if (prev){
            prev->right = root;
        }
        
        root->right = next;
        if (next){
            next->left = root;
        }
        
        Res *val = new Res();
        val->leftmost = left_res->leftmost;
        val->rightmost = right_res->rightmost;
        
        if (val->leftmost == NULL)
            val->leftmost = root;
        if (val->rightmost == NULL)
            val->rightmost = root;
            
        return val;
        
    }
}

//using inorder traversal
//in this we do the inorder traversal while maintaing the previous node or last visited node
//then we make right of the prev. node = to current node
// and left of current node = prev. node
// when we have prev node == NULL, i.e cur element is left most element and is also our head
//therefore we store it 
void inorder(Node *root, Node **head, Node **prev){
    if (root == NULL)
        return;

    inorder(root->left, head, prev);

    if (*prev == NULL){
        *head = root;
    }else
        (*prev)->right = root;
    
    root->left = *prev;
    *prev = root;
    inorder(root->right, head, prev);

}

//Function to convert binary tree to doubly linked list and return it.
Node * bToDLL(Node *root)
{
    // your code here
    if (root == NULL)
        return NULL;
        
    // Res *res = helper(root);
    // return res->leftmost;
    // root->left = 


    Node *prev = NULL;
    Node *head = NULL;

    inorder(root, &head, &prev);

    return head;
    
}



int main(){

    Node *node = new Node(1);

    node->left = new Node(3);
    node->right = new Node(2);


    Node * head = bToDLL(node);

    while(head){
        cout << head->data << " ";
        head = head->right;
    }

    cout << endl;

    return 0;
}