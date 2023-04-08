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

Node *findMid(Node *head){

    Node *slow = head;
    Node *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main(){

    return 0;
}