#include <bits/stdc++.h>
using namespace std;

struct Node{
    
    int val;
    Node *next;

    Node(int v = 0, Node *n = NULL){
        val = v;
        next = n;
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

Node *reverseList(Node *prev, Node *cur){
    if (cur == NULL)
        return NULL;

    Node *next = cur->next;
    cur->next = prev;
    if (next == NULL)
        return cur;
    return  reverseList(cur, next);
}

Node *reverseListIterative(Node *head){

    Node *prev = NULL;
    Node *cur = head;
    while(cur){
        Node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}


int main(){

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    printList(head);
    head = reverseListIterative(head);
    printList(head);

    return 0;
}