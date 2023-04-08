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

Node * merge(Node *head1, Node *head2){

    Node *res = new Node(0); //dummy node
    Node *prev = res;

    Node *cur1 = head1;
    Node *cur2 = head2;

    while(cur1 && cur2){
        if (cur1->data <= cur2->data){
            prev->next = cur1;
            prev = cur1;
            cur1 = cur1->next;
        }else {
            prev->next = cur2;
            prev = cur2;
            cur2 = cur2->next;
        }
    }

    if (cur1){
        prev->next = cur1;
    }else{
        prev->next = cur2;
    }

    return res->next; //lists starts from res->next;
}

//Complexity: Time - O(N*k), space - O(1)
//Function to merge K sorted linked list.
Node * mergeKLists(Node *arr[], int k)
{
    if (k == 0)
        return NULL;
    Node * res = arr[0];
    for (int i=1;i<k;i++){
        res = merge(res, arr[i]);
    }

    return res;
}


//Using priority queue of size k
//complexity: Time - O(N*log(k)), space - O(k)
//we take a priority queue/min heap of size k and initially store the first or head element of all k lists
//then take the top element of heap, add it to the resultant list, and add the next element of top to the heap
//we do so until heap is empty
//so as we know that complexity of heap is log(k), and we traverse total elements in listss once (N)
// so total complexity = O(N*log(k))
struct compare{
    bool operator()(Node *&node1, Node *&node2){
        return node1->data >= node2->data;
    }
};

Node *meregeKList2(Node *arr[], int k){
    if (k == 0)
        return {};

    priority_queue <Node *, vector <Node *>, compare> min_heap;

    for (int i=0;i<k;i++){
        min_heap.push(arr[i]);
    }

    Node *res = new Node(0); //dummy node, list starts from res->next
    Node *prev = res;

    while(!min_heap.empty()){
        Node *top = min_heap.top(); min_heap.pop();
        prev->next = top;
        prev = top;

        if (top->next){
            min_heap.push(top->next);
            top->next = NULL;
        }

    }

    return res->next;

}
//Divide and conquer approach, Time- N*log(k)
//lets say arr = [1,2,3,4,5], here 1 means list 1, 2 -list 2, and so on .. 5 - list 5 
//we start from start and end, i = 0 and j = k-1 (k = len of array)
// merge(arr[i],  arr[j]) and store result in arr[i] 
//once i becomes <= j we set i = 0
// then repeat the merging process
//we do so until we have one list at arr[0]
//doing this the outer loop is O(log(k)), and inside it the merge is O(N)
//there total complexity is O(N*log(k))
Node *mergeKList3(Node *arr[], int k){
    if (k == 0)
        return NULL;

    int i = 0;
    int j = k-1;
    while(i<j){
        arr[i] = merge(arr[i], arr[j]);
        i++; j--;
        if (i<=j){
            i = 0;
        }
    }


    return arr[0];
}

int main(){

    return 0;
}