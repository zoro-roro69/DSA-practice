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


//recurrsive solution
//works for small lists
//will get segmentation fault/heap stack overflow for large llists

class Solution1{

    Node *helper(Node *root, int &count, int n){
        if (root == NULL)
            return NULL;
            
        Node *res = helper(root->next, count, n);
        if (res)
            return res;
            
        if (count == n){
            return root;
        }
        
        count++;
        
        return NULL;
    }

    int getNthFromLast(struct Node *head, int n)
    {   
        int count = 1;
        Node *res = helper(head, count, n);
        if (res)
            return res->data;
        return -1;
    }
};


class Solution2{

    int getNthFromLast(struct Node *head, int n)
    {

        int len = 0;   

        Node *cur = head;
        while(cur){
            cur = cur->next;
            len++;
        }

        if (len < n)
            return -1;

        int i = 0;
        cur = head;
        while(i < len-n){
            cur = cur->next;
            i++;
        }
        return cur->data;
        
    }


};