#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node *arb;
    
    Node(int x){
        data = x;
        next = arb = NULL;
    }
};

Node *copyList(Node *head){
    if (!head)
        return NULL;


    // cout << "here0" << endl;
    Node *cur = head;

    while(cur){
        Node *temp = new Node(cur->data);
        temp->next = cur->next;
        cur->next = temp;
        cur = temp->next;
    }


    // cout << "here0" << endl;
    cur = head;

    while(cur){
        Node *clone = cur->next;
        if (cur->arb)
            clone->arb = cur->arb->next;
        else
            clone->arb = NULL;
        cur = clone->next;
    }

    cur = head;
    //resetting pointers
    Node *head2 = cur->next;

    Node *cur2 = head2;

    // cout << "here0" << endl;
    while(cur && cur2){
        cur->next = cur2->next;
        cur = cur->next;
        if (cur)
            cur2->next = cur->next;
        else
            cur2->next = NULL;
        cur2 = cur2->next;
    }

    // cout << "heefina" << endl;
    return head2;

}

void printList(Node *head){

    while(head){
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main(){

    Node *head = new Node(1);

    Node *head2 = copyList(head);

    printList(head2);


    return 0;
}