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


int lengthOfList(Node *head){
    int len  = 0;
    Node *cur = head;
    while(cur){
        cur = cur->next;
        len++;
    }
    return len;
}

void printList(Node *head){

    Node *cur = head;
    while(cur){
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;

}

Node *intersectionPoint(Node *head1, Node*head2){
    if (head1 == NULL || head2 == NULL)
        return NULL;
    int len1 = lengthOfList(head1);
    int len2 = lengthOfList(head2);

    if (len1 < len2){
        swap(head1, head2);
        swap(len1, len2);
    }

    Node *cur1 = head1;

    while(len1 != len2){
        cur1 = cur1->next;
        len1--;
    }

    Node *cur2 = head2;

    while((cur1 && cur2) && (cur1!=cur2)){
        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    return cur1;
}

int main(){

    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    Node *head2 = head1->next->next->next;

    Node *res = intersectionPoint(head1, head2);

    cout << "intersection: " << res->data << endl;
    return 0;
}