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


bool findPair(Node *head, int key){
    if (head == NULL || head->next == NULL)
        return false;

    Node *start = head;
    Node *last = head;
    while(last->next)
        last = last->next;

    while( start != last && start->prev != last){
        int sum = start->data + last->data;
        if (sum == key)
            return true;
        else if (sum > key){
            last = last->prev;
        }else{
            start = start->next;
        }

    }

    return false;

}


int main(){


    return 0;
}