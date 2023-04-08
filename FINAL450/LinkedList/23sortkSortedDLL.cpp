#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};


void printList(Node *head){

    Node *cur = head;

    while (cur)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
    

}
//sorting k sorted array
//k sorted means element at positon maybe atmost k position away from
//its original position
void ksortedArray(vector <int> &v, int k){

    int n = v.size();
    vector <int> res;
    priority_queue<int, vector <int>, greater <int>> min_heap;

    if (k != n)
        k++; 

    //push k+1 elements in heap
    for (int i=0;i<k;i++){
        min_heap.push(v[i]);
    }

    int j = 0;
    for (int i=k; i<n;i++,j++){
        int top = min_heap.top(); min_heap.pop();
        v[j] = top;
        min_heap.push(v[i]);
    }

    while(!min_heap.empty()){
        v[j++] = min_heap.top(); min_heap.pop();
    }

}

void printVector (vector <int> v){

    for (auto x:v)
        cout << x << " ";
    cout << endl; 

}

struct comparator{
    bool operator()(Node *n1, Node *n2){
        return n1->data >= n2->data;
    }
};

Node * ksortedDLL(Node *head, int k){

    priority_queue<Node *, vector<Node *>, comparator> min_heap;   

    Node *cur = head;
    int i = 0;
    while(cur && i<=k){
        min_heap.push(cur);
        Node *temp = cur->next;
        cur->next = NULL;
        cur = temp;
        i++;
    }

    Node *new_head = NULL;
    Node *new_cur = NULL;

    while(cur){
        Node *top = min_heap.top(); min_heap.pop();
        if (new_head == NULL){
            top->prev = NULL;
            new_head = top;
            new_cur = top;
        }else{
            new_cur->next = top;
            top->prev = new_cur;
            new_cur = top;
        }
        min_heap.push(cur);
        Node *temp = cur->next;
        cur->next = NULL;
        cur = temp;
    }

    while(!min_heap.empty()){
        Node *top = min_heap.top(); min_heap.pop();
        new_cur->next = top;
        top->prev = new_cur;

        new_cur = new_cur->next;
    }

    return new_head;
}


Node *addToList(Node *head, int val){
    Node *new_node = new Node(val);
    new_node->next = head;
    
    head->prev = new_node;

    return new_node;

}

int main(){

    // vector <int> v{6,5,3,2,8,10,9};
    // printVector(v);
    // ksortedArray(v, 3);
    // printVector(v);

    Node *head = new Node (9);
    head = addToList(head, 10);
    head = addToList(head, 8);
    head = addToList(head, 2);
    head = addToList(head, 3);
    head = addToList(head, 5);
    head = addToList(head, 6);

    printList(head);
    head = ksortedDLL(head, 3);
    cout << "sorted" <<endl;
    printList(head);


    return 0;
}