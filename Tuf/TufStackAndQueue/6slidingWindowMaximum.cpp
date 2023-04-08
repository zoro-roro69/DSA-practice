#include <bits/stdc++.h>
using namespace std;

//  Qi of capacity K, that stores only useful elements of current window of K elements. 


// . An element is useful if it is in current window and is greater than all other elements on right side of it in current window. 


// Process all array elements one by one and maintain Qi to contain useful elements of current window and these useful elements are maintained in sorted order. 


// The element at front of the Qi is the largest and element at rear/back of Qi is the smallest of current window.

// run a loop and insert the first K elements in the deque. 
// Before inserting the element, check if the element at the back of the queue is smaller than the current element,

//  if it is so remove the element from the back of the deque until all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque.

// Now, run a loop from K to the end of the array

// Print the front element of the deque

// Remove the element from the front of the queue if they are out of the current window.



struct Node{
    int val;
    Node *next;
    Node *prev;

    Node(int v = 0){
        val = v;
        next = prev = NULL;
    }
};

class Dll{
    public:
    
        Node* head;
        int size = 0;

        Dll(){
            head = new Node(); //first  node is dummy node
            head->next = head->prev = head; //circular
            size = 0;
        }

        void insertAtEnd(int val){
            Node *new_node = new Node(val);
            head->prev->next = new_node;
            new_node->prev = head->prev;
            new_node->next = head;
            head->prev = new_node;
            size++;
        }

        void removeAtFront(){
            head->next = head->next->next;
            head->next->prev = head;
            size--;
        }

        void removeAtEnd(){
            head->prev = head->prev->prev;
            head->prev->next = head;
            size--;
        }

        Node *getTail(){
            if (head->prev == head) //list empty
                return NULL;
            return head->prev;
        }


};


vector<int> slidingWindowMaximum(vector<int> &nums, int &k){

    Dll dll;

    int i=0;
    for (i=0;i<k;i++){
        while (dll.size){
            Node *tail = dll.getTail();
            if (nums[tail->val] < nums[i]){
                dll.removeAtEnd();
            }else
                break;
        }
        dll.insertAtEnd(i);
    }

    vector <int> res;

    for (;i<nums.size(); i++){
        //i is k+1th elment before adding i we get the maximum of the prev window
        res.push_back(nums[dll.head->next->val]);

        //remove first element if it does not lies in current windwo
        if (dll.head->next->val == i-k){
            dll.removeAtFront();
        }

        while (dll.size){
            Node *tail = dll.getTail();
            if (nums[tail->val] < nums[i]){
                dll.removeAtEnd();
            }else
                break;
        }
        dll.insertAtEnd(i);
    }

    res.push_back(nums[dll.head->next->val]);
    return res;

}

int main(){

    return 0;
}