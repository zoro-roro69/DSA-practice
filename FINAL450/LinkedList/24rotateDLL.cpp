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


void printList(Node *head){

    Node *cur = head;

    while (cur)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
    

}

//rotate DLL counter clockwise by N nodes, 
// N is always less than number of nodes in list
Node *rotateDLL(Node *head, int n){

    Node *last = head;
    Node *nth_node = NULL;
    int count = 1;
    while(last->next){
        if (count == n)
            nth_node = last;
        last = last->next;
        count++;
    }

    Node *new_head = nth_node->next;
    nth_node->next = NULL;
    new_head->prev = NULL;
    last->next = head;
    head->prev = last;

    return new_head;
}

Node *addToList(Node *head, int val){
    Node *new_node = new Node(val);
    new_node->next = head;
    
    head->prev = new_node;

    return new_node;

}

int main(){

    Node *head = new Node(5);
    head = addToList(head, 4);   
    head = addToList(head, 3);   
    head = addToList(head, 2);   
    head = addToList(head, 1);   

    printList(head);
    head = rotateDLL(head, 4);
    printList(head);    


    return 0;
}