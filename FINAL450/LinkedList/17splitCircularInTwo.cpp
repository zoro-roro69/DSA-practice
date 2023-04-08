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

void printList(Node *head){

    Node *cur = head;
    while(cur){
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;

}


Node *splitCircularInTwo(Node *head, Node **head1, Node **head2){

     if (head == NULL || head->next == head){
        *head1 = head;
        *head2 = head;
        return;
    }
    if (head->next->next == head){
        *head1 = head;
        *head2 = head->next;
        (*head2)->next = *head2;
        (*head1)->next = *head1;
        return;
    }

    //more than 2 elements

    Node *slow = head;
    Node *fast = head;

    while(fast->next!=head && fast->next->next!=head){
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast->next->next == head){
        fast = fast->next;
    }
    fast->next = slow->next;
    slow->next = head;
    
    *head1 = head;
    *head2 = fast->next;



}


int main(){


    return 0;
}