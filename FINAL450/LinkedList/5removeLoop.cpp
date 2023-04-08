#include <bits/stdc++.h>
using namespace std;


struct Node{

    int val;
    Node *next;

    Node(int v = 0, Node *n = NULL){
        val = v;
        next = n;
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
Node *removeLoop(Node *head){
    if (head == NULL || head->next == NULL)
        return head;
    
    Node *slow = head->next;
    Node *fast = head->next->next;


    while ( slow && fast && fast->next ) {
        if (slow == fast)
            break;

        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow != fast)
        return head; //no loop

    slow = head;

    if (slow == fast){ //head is starting point
        while(fast->next!=slow)
            fast = fast->next;
        
    }else {

        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = NULL;

    return head;

}


int main(){

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head->next->next->next->next = head;

    cout << head->val <<endl;

    head = removeLoop(head);

    printList(head);

    return 0;
}