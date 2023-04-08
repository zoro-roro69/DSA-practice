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
Node * removeDuplicate(Node *head){

    Node *cur = head;

    while(cur && cur->next){
        if (cur->val == cur->next->val){
            cur->next = cur->next->next;
        }else{
            cur = cur->next;
        }
    }

    return head;
}   

int main (){

    Node *head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(2);

    printList(head);

    head = removeDuplicate(NULL);

    printList(head);

    return 0;

}