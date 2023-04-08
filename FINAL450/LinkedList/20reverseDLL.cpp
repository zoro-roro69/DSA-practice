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


Node* reverseDLL(Node * head)
{
    //Your code here
    if (head == NULL)
        return NULL;

    Node *cur = head;
    Node *temp = NULL;
    while(cur){
        temp = cur->prev;
        // swap(cur->next, cur->prev);
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev; //prev now points to next
    }
    if (temp)
        head = temp->prev; //new head is the last element
    return head;
}

int main(){


    return 0;
}