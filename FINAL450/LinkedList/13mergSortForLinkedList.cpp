#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int d = 0, Node *n = NULL){
        data = d;
        next = n;
    }
};

void printList(Node *head){

    Node *cur = head;
    while(cur){
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;

}

Node *merge2Lists(Node *head1, Node *head2){
    Node *res = new Node(0); //dummy node, actual list starts from res->next
    Node *cur = res;

    Node *cur1 = head1;
    Node *cur2 = head2;
    
    while(cur1 && cur2){
        if (cur1->data <= cur2->data){
            cur->next = cur1;
            cur1 = cur1->next;
        }else {
            cur->next = cur2;
            cur2 = cur2->next;
        }
        cur = cur->next;
    }

    while(cur1){
        cur->next = cur1;
        cur = cur->next;
        cur1 = cur1->next;
    }

    while(cur2){
        cur->next = cur2;
        cur = cur->next;
        cur2 = cur2->next;
    }

    return res->next;

}

Node *midOfList(Node *head){
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return head;

    Node *slow = head;
    Node *fast = head;

    while(slow && fast && fast->next){
        
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; //slow is now at mid of list
}

Node *mergeSortForList(Node *head){
    if (head == NULL || head->next == NULL)
        return head;
    else {
        Node *mid = midOfList(head);
        Node *head1 = mergeSortForList(mid->next);
        mid->next = NULL;
        Node *head2 = mergeSortForList(head);
        return merge2Lists(head1, head2);
        
    }

}

int main(){
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(6);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(4);

    printList(head);
    Node *res = mergeSortForList(head);
    printList(res);






    return 0;
}