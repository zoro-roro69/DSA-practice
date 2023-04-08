#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *random;

    Node(int d){
        data = d;
        next = NULL;
        random = NULL;
    }
};

Node *cloneList(Node *head){

    Node *cur = head;

    while(cur){
        Node *new_node = new Node(cur->data);
        new_node->next = cur->next;
        cur->next = new_node;
        cur = new_node->next;
    }

    cur = head;
    while(cur){
        Node *clone = cur->next;
        if (cur->random)
            clone->random = cur->random->next;
        cur = cur->next->next;
    }
    Node *org = head;
    Node *clone = org->next;

    Node *res = clone;

    while(org && clone){
        org->next = clone->next;
        if (clone->next)
            clone->next = clone->next->next;

        org = org->next;
        clone = clone->next;
    }

    return res;
}


int main(){


    return 0;
}