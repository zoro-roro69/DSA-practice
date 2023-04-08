#include <bits/stdc++.h>
using namespace std;


struct Node {

    int val;
    Node *next;

    Node(int v = 0, Node * n= NULL){
        val = v;
        next = NULL;
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

Node *removeDuplicates(Node *head){
    if (head == NULL)
        return head;
    unordered_set <int> visited;

    visited.insert(head->val);
    Node *prev = head;
    Node *cur = head->next;

    while(cur){
        if (visited.find(cur->val) != visited.end()){
            prev->next = cur->next;
        }else{
            prev = cur;
            visited.insert(cur->val);
        }
        cur = cur->next;
    }

    return head;
}

int main(){

    Node *head = new Node(3);
    head->next = new Node(2);

    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(5);

    printList(head);

    head = removeDuplicates(head);

    printList(head);    

    return 0;
}