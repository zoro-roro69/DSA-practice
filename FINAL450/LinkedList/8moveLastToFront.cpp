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

Node *moveLastToFront(Node *head){

    if (head == NULL || head->next == NULL)
        return head;

    Node *cur = head;

    while(cur->next->next){
        cur = cur->next;
    }

    cur->next->next = head;
    head = cur->next;
    cur->next = NULL;

    return head;
}

int main(){

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    // head->next->next->next = new Node(4);


    printList(head);
    head = moveLastToFront(head);
    printList(head);
    
    return 0;
}