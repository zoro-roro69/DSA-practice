#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
};

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root){
    Node *head = new Node(0); //dummy node 
    head->bottom = root; //actual list starts from head->bottom

    Node *cur = root->next;
    while(cur){
        Node *temp = cur->next; 
        Node *prev = head;       
        //merge
        Node *cur1 = prev->bottom;
        Node *cur2 = cur;

        while(cur1 && cur2){
            if (cur1->data <= cur2->data){
                prev->bottom = cur1;
                prev = cur1;
                cur1 = cur1->bottom;
            }else{
                prev->bottom = cur2;
                prev = cur2;
                cur2 = cur2->bottom;
            }
        }
        if (cur1){
            prev->bottom = cur1;
        }
        if (cur2){
            prev->bottom = cur2;
        }
        cur = temp;
    }

    return head->bottom; //actual list starts from head->bottom;

}

int main(){

    return 0;
}