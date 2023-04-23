#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


int countNodes(ListNode * node){
    int count = 0;
    while(node){
        node = node->next;
        count++;
    }

    return count;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int size_a = countNodes(headA);
    int size_b = countNodes(headB);

    if (size_b < size_a){ //making a the smaller list
        swap(size_a, size_b);
        swap(headA, headB);
    }

    int diff = size_b - size_a;
    //giving head start to larger list
    while(diff){
        headB = headB->next;
        diff--;
    }

    while(headA && headB){
        if (headA == headB) //found intersection
            return headA;

        headA = headA->next;
        headB = headB->next;
    }

    return NULL; //no intersection
}

//why do we need difference in the length ? so that they can start from same distance
//without counting the difference in length, how do we make sure that they start from the distance ?

// We can use two iterations to do that. In the first iteration, we will reset the pointer 
// of one linkedlist to the head of another linkedlist after it reaches the tail node. 
// In the second iteration, we will move two pointers until they points to the same node. 
// Our operations in first iteration will help us counteract the difference. So if two linkedlist 
// intersects, the meeting point in second iteration must be the intersection point. If the two 
// linked lists have no intersection at all, then the meeting pointer in second iteration must 
// be the tail node of both lists, which is null

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    ListNode *a = headA;
    ListNode *b = headB;
    while (a != b){
        //whenever one of theem becomes NULL, we make them point to head of the other list
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;

    }
    //a and b will be equal if they point to intersection, if no intersection then they both will be NULL

    return a; 
}


int main(){

    return 0;
}