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


int countTriplets(Node *head, int key){
    //assuming we have >=3 nodes in a list

    Node *cur = head;
    Node *last = head;

    while(last->next)
        last = last->next;

    int res = 0;

    while(cur && cur->next){

        int sum = key - cur->data;

        Node *l = cur->next;
        Node *r = last;
        while(l!=r && l->prev != r){
            if (l->data + r->data == sum){
                res++;
                l = l->next;
            }else if (l->data + r->data > sum){
                r = r->prev;
            }else{
                l = l->next;
            }
        }
        cur = cur->next;

    }

    return res;
}

Node *addToList(Node *head, int val){
    Node *new_node = new Node(val);
    new_node->next = head;
    
    head->prev = new_node;

    return new_node;

}

void printList(Node *head){

    Node *cur = head;

    while (cur)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
    

}

int main(){

    Node *head = new Node(9);
    head = addToList(head, 8);
    head = addToList(head, 6);
    head = addToList(head, 5);
    head = addToList(head, 4);
    head = addToList(head, 2);
    head = addToList(head, 1);

    printList(head);
    cout << countTriplets(head, 17) << endl;

    return 0;
}