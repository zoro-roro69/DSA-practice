#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int d = 0, Node *n = NULL){
        data = d;
        next = n;
    }
};

Node* findIntersection(Node* head1, Node* head2)
{
    Node *res = new Node(-1); //dummy node, lists starts from res->next
    Node *cur = res;

    Node *cur1 = head1;
    Node *cur2 = head2;

    while(cur1 && cur2){
        
        if (cur1->data == cur2->data && cur->data != cur1->data){
            cur->next = new Node(cur1->data);
            cur  = cur->next;
        }else if(cur1->data < cur2->data){
            cur1 = cur1->next;
            
        }else if (cur1->data > cur2->data){
            cur2 = cur2->next;

        }else{
        
            cur1 = cur1->next;
            cur2 = cur2->next;
            
        }
    }

    return res->next;
}