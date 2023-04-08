#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int  d = 0, Node *n = NULL){
        data = d;
        next = n;
    }
};

void printList(Node *head){

    if (head == NULL) return;

    Node *cur = head->next;
    cout << head->data << " ";
    while(cur!=head){
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;

}

//remember the case when element to be deleted is not found
Node *deleteFromCircular(Node *head, int key){
    if (head->next == head){ //single element
        if (head->data == key)
            return NULL;
        return head;
    }

    if (head->data == key){
        //element to be deleted is head
        Node *last = head;
        while(last->next!=head)
            last = last->next;

        last->next = last->next->next;
        head = head->next;
        return head;
    }

    //node to be deleted is not found or is found
    Node *cur = head;
    while(cur->next != head && cur->next->data != key){
        cur = cur->next;
    }
    // if (cur->next == head){
    //     head = cur->next->next;
    // }
    if (cur->next->data == key) //found
    cur->next = cur->next->next;

    return head;
}

int main(){

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;

    printList(head);
    head = deleteFromCircular(head, 6);
    printList(head);

    return 0;

}