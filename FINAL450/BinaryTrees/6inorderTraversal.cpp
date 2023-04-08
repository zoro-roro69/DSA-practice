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

//inorder -- left root right
void inOrderRecur(Node *root){
    if (root == NULL)
        return;
    inOrderRecur(root->left);
    cout << root->data << " ";
    inOrderRecur(root->right);
}




//inorder -- iter
struct node_exp{
    Node *node;
    bool visited;
    node_exp(Node *n, bool v){
        node = n;
        visited = v;
    }
};
// void inOrderIter(Node *root){
//     stack <node_exp * > st;

//     st.push(new node_exp(root, 0));
//     while(!st.empty()){
//         node_exp *top = st.top();

//         if (top->visited == false){
//             Node *cur = top->node->left;
//             while(cur){
//                 st.push(new node_exp(cur, 1));
//                 cur = cur->left;
//             }
//             top->visited = true;
//         }
//         top = st.top();
//         cout << top->node->data << " "; st.pop();

//         if (top->node->right)
//             st.push(new node_exp(top->node->right, 0));

//     }

//     cout << endl;
// }

void inOrderIter(Node *root){
    stack <Node *> st;
    Node *cur = root;

    while(cur!=NULL || !st.empty()){
        while(cur){
            st.push(cur);
            cur = cur->left;
        }

        if (!st.empty()){
            Node *top = st.top(); st.pop();
            cout << top->data << " ";
            // if (top->right) no need for this
                cur = top->right;
        }

    }
    cout << endl;

}

int main(){
    Node *root = new Node(1);
    root->left =  new Node(2);
    root->right =  new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    inOrderRecur(root); cout << endl;
    inOrderIter(root); cout << endl;
    // preOrderRecur(root); cout << endl;
    // postOrderRecur(root); cout << endl;
    return 0;
}