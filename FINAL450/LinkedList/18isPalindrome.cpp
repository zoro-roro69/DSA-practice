#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int  d = 0, Node *n = NULL){
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

bool isPalindrome(Node *head){
    // 0 or 1 element
    if (head == NULL || head->next == NULL)
        return true;
    // 2 elements
    if (head->next->next == NULL){
        return head->data == head->next->data;
    }

    // more than 2 elements
    Node *slow = head;
    Node *fast  = head;
    string temp = "";
    while(fast->next && fast->next->next){
        temp += (slow->data + 'a');
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next !=NULL){//even elements
        temp += (slow->data + 'a');
    }
    fast = slow->next;
    //fast points to start of second half
    while(fast){
        if (temp.back() != (fast->data + 'a'))
            return false;
        temp.pop_back();
        fast = fast->next;
    }

    return true;
}


int main(){

    Node *head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(1);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);
    // head->next->next->next->next = new Node(0);

    cout << isPalindrome(head) << endl;
    return 0;
}