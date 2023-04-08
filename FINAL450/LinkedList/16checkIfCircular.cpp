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

bool checkIfCircular(Node *head){
    if (head == NULL) 
        return false;
    Node *cur = head->next;
    while(cur){
        if (cur == head)
            return true;
        cur = cur->next; 
    }
    return false;
}

int main (){

    return 0;
}