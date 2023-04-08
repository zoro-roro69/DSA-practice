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

//original solution, working but not good
//earlier i was just using the helper function alone
//but that did not work because
// lets say we have list like this 8-6-9
//so when my cur. is at 6, which is less than the next i,e 9, so we remove 6
//now we are left with 8-9
//now i increment my cur and prev, so my cur is at 9 and prev is still at 8
//since cur->next == NULL we exit out of loop. so our final answer is the list 8-9
//which we can see is not the correct answer , sice we can see 9 is greeater than 8 and we need to remove 8
//so the correct answer should be list [9]
//so temporary fix was that i was calling helper function in while loop until it sets the flag = false
//which means there are no elements on the right which are greater than the previous ones.

class Solution
{
    public:
    
    Node *helper(Node *head, bool &flag){
        Node *res = new Node(0); //dummy node
        res->next = head;
        Node *prev = res;
        flag = false;
        Node *cur = head;
        while(cur && cur->next){
            if (cur->data < cur->next->data){
                prev->next = cur->next;
                flag = true;
            }else{
                prev = cur;
            }
            cur = cur->next;
        }
        
        return res->next;
        
    }
    
    Node *compute(Node *head)
    {
        // your code goes here
        
        bool flag = true;
        while(flag){
            head = helper(head, flag);
        }
        
        return head;
        

    }
    
};

//better soultion, but not the best
// here what we do is we first reverse the list
// now the problem becomes : if current element is greater than the next element remove the next element
// now this is easier to do
// example lets say we have list = 8 6 9
// reverse it we have 9 6 8
// our cur. 9 is greater than 6 therefore we remove 6 , now the list is 9 - 8
// cur is still at 9
// 9 is greate than 8 so we remove 8
// now we again need to reverse the list to get the original order
// our final answer is == [9]

class Solution1{

    Node *reverse(Node *head){
        if (head == NULL || head->next == NULL)
            return head;

        
        Node *prev = head;
        Node *cur = head->next;
        head->next = NULL;

        while(cur){
            Node *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
        
    }


    Node *compute(Node *head)
    {
        // your code goes here
        head = this->reverse(head);
        Node *cur = head;
        while(cur && cur->next){
            if (cur->data > cur->next->data){
                cur->next = cur->next->next;
            }else{
                cur = cur->next;
            }
        }

        head  = this->reverse(head);
        return head;
    }
};


//best solution
// this is a revucrsive soultion, this function returns the greatest element/node on the right
// then we compare the returned element with the current
//if current is smaller then we return "returned"
// else we make next of current = "returned", and return current element;

class Solution3{

    Node *compute(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        
        Node *res =compute(head->next);
        if (head->data < res->data){
            return res;
        }else{
            head->next = res;
            return head;
        }
    }


};
   

int main(){

    return 0;
}