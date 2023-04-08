#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};



Node *rotateInGroups(Node *head, int k){
    if (head == NULL)
        return NULL;

    Node *cur = head;
    Node *new_head = NULL;
    while(cur){
        Node *temp = cur;
        Node *cur_prev = cur->prev;

        Node *next;
        Node *prev;
        for (int i=0;i<k && temp!=NULL;i++){
            next = temp->next;
            swap(temp->next, temp->prev);
            prev = temp;
            temp = next;
        }
        if (new_head == NULL)
            new_head = prev;

        prev->prev = cur_prev; 
        if (cur_prev)
            cur_prev->next = prev;

        cur->next = temp;
        if (temp)
            temp->prev = cur;

        cur = temp;

    }

    return new_head;

}

Node *addToDLL(Node *node, int val){
    Node *new_node = new Node(val);
    new_node->next = node;
    node->prev = new_node;

    return new_node;
}

void printList(Node *node){
    Node *cur = node;
    while(cur!=NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main(){
    Node *head = new Node(1);

    head = addToDLL(head, 2);
    head = addToDLL(head, 3);
    head = addToDLL(head, 4);
    head = addToDLL(head, 5);
    head = addToDLL(head, 6);
    head = addToDLL(head, 7);

    printList(head);
    head = rotateInGroups(head, 3);
    printList(head);

    return 0;
}