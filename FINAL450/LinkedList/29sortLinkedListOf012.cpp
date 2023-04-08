#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};



Node* segregate(Node *head) {
    //dummy nodes
    Node *zero = new Node(0);
    Node *one = new Node(1);
    Node *two = new Node(2);

    Node *cur_zero = zero;
    Node *cur_one = one;
    Node *cur_two = two;

    Node *cur = head;
    while(cur){
        if (cur->data == 0){
            cur_zero->next = cur;
            cur_zero = cur;
        }else if(cur->data == 1){
            cur_one->next = cur;
            cur_one = cur;
        }else{
            cur_two->next = cur;
            cur_two = cur;
        }
        cur = cur->next;
    }

    if (one->next)
        cur_zero->next = one->next;
    else
        cur_zero->next = two->next;
    cur_one->next = two->next;
    cur_two->next = NULL;

    return zero->next;
}

int main(){

    return 0;
}