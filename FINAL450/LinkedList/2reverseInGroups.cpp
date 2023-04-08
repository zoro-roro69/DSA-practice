#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;

    Node(int v = 0, Node* n = NULL){
        val = v;
        next = n;
    }
};

Node* add(int val, Node *head){
    Node *new_node = new Node(val);
    new_node->next = head;
    return new_node;
}

void printList(Node *head){

    Node *cur = head;
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

}

Node* reverseInGroup(Node *head, int k){
    
    Node *new_head = NULL;
    Node *cur = head;
    Node *prev = NULL;
    while(cur!=NULL){
        int count = 0;
        Node *temp_prev = prev;
        Node *first  = cur;
        while(count < k && cur!=NULL){
            Node *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            count++;
        }
        if (temp_prev)
            temp_prev->next = prev;
        else{   
            head = prev; //not required
            new_head = prev;
        }
        first->next = cur;
        prev = first;
    }

    return new_head;
}

int main(){

    Node *head = new Node(1);
    // head = add(2, head);
    // head = add(3, head);
    // head = add(4, head);
    // head = add(5, head);
    // head = add(6, head);

    printList(head);

    head = reverseInGroup(head, 2);
    
    printList(head);

    return 0;
}