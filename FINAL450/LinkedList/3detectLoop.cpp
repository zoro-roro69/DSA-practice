#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;

    Node(int v = 0, Node * n = NULL){
        val  = v;
        next = n;
    }

};

bool detectLoop(Node *head){

    if (head == NULL || head->next == NULL)
        return false;
    
    Node *slow = head;
    Node *fast = head->next->next;
    

    while(slow && (fast && fast->next)){
        if (slow == fast)
            return true;
        
        slow = slow->next;
        fast = fast->next->next;
    }

    return false;
}

int main(){

    return 0;
}