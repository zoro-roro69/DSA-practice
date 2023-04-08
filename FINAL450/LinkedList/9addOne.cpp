#include <bits/stdc++.h>
using namespace std;

struct Node {

    int val;
    Node *next;

    Node(int v = 0, Node * n= NULL){
        val = v;
        next = NULL;
    }

};

void printList(Node *head){

    Node *cur = head;
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

}


int helper(Node *head){
    if (head == NULL)
        return 1;

    int c = helper(head->next);
    int sum = c + head->val;
    head->val = sum%10;
    return sum/10;

}

Node *addOne(Node *head){
    if (head == NULL)
        return head;
    int c = helper(head);
    Node *new_node = head;

    if (c){
        new_node = new Node(1);
        new_node->next = head;
    }

    return new_node;
}

int main(){

    Node *head = new Node(2);
    head->next = new Node(9);
    // head->next->next = new Node(9);

    printList(head);
    head = addOne(head);
    printList(head);

    


    return 0;
}