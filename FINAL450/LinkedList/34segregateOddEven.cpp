#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution{
public:
    Node* divide(int N, Node *head){
        // code here

        Node *odd = NULL;
        Node *odd_head = NULL;
        Node *even = NULL;
        Node *even_head = NULL;
        Node *cur = head;
        
        while(cur){
            if (cur->data%2 == 0){ //even
                if (even == NULL){
                    even = cur;
                    even_head = cur;
                }else{
                    even->next = cur;
                    even = cur;
                }
            }else{//even
               
                if (odd == NULL){
                    odd = cur;
                    odd_head = cur;
                }else{
                    odd->next = cur;
                    odd = cur;
                }
                
            }
            
            cur = cur->next;
        }
        if (odd)
            odd->next = NULL;
        
        if (even_head){
            even->next = odd_head;
            return even_head;
        }else{
            return odd_head;
        }
    }
};