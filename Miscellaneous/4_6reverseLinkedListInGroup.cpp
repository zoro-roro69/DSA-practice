#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;

    node(int x){
        data = x;
        next = NULL;
    }
};

pair <node*, node*> reverseTillK(node *head, int k){

    node *prev = NULL;
    node *cur = head;
    int count = 0;

    while(cur && count < k){
        node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        count++;
    }

    return {prev, cur};
}

node *reverseInGroup(node *head, int k){
    node *prev_end = NULL; //ending of previous group
    node *cur = head;

    while(cur){
        auto p  = reverseTillK(cur, k);
        //p.first = head
        //p.second = start of next group
        if (prev_end == NULL){
            head = p.first;
        }else{
            prev_end->next = p.first;
        }
        prev_end = cur; //cur which was head of this group is now at the end
        cur = p.second; //moving cur to start of next group
    }

    return head;
}



void printList(node *head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    node *head= new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    printList(head) ;
    auto p = reverseTillK(head, 5);
    printList(p.first);

    return 0;
}