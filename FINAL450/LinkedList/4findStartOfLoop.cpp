#include <bits/stdc++.h>
using namespace std;

struct Node{

    int val;
    Node *next;

    Node(int v  = 0, Node *n = NULL){
        val = v;
        next = n;
    }

};


Node * startOfLoop(Node *head){
    if (head == NULL || head->next == NULL)
        return NULL; //NULL indicates no loop

    Node *slow = head->next; //remember this
    Node *fast = head->next->next;

    while(slow && (fast && fast->next)){
        if (slow == fast)
            break; //found loop

        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow != fast)
        return NULL;

    slow = head;

    cout << "here" << endl;

    while(slow != fast){

        slow = slow->next;
        fast = fast->next;

    }

    return slow;
}


int main(){

    Node* head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    Node *start = startOfLoop(head); 

    cout << "start: " << start->val << endl;

    return 0;
}