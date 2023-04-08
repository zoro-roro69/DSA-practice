#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

struct Node{
    int data;
    Node *next;

    Node(int d = 0, Node *n = NULL){
        data = d;
        next = n;
    }
};


long long multiplyByDigit(Node *node, int mul, long long prod_till_now){
    if (node == NULL)
        return prod_till_now;

    long long prod = ((prod_till_now*10)%MOD + (node->data)*mul)%MOD;

    return multiplyByDigit(node->next, mul, prod);

}

/*You are required to complete this method*/
long long  multiplyTwoLists (Node* l1, Node* l2)
{

    Node *cur = l1;
    long long res = 0;
    while(cur){
        long long temp = multiplyByDigit(l2, cur->data, 0);
        res = ((res*10)%MOD + temp)%MOD;
        cur = cur->next;
    }

    return res;
}

int main(){
    Node *node = new Node(9);
    node->next = new Node(8);
    node->next->next = new Node(9);
    node->next->next->next = new Node(9);


    Node *node1 = new Node(9);
    node1->next = new Node(8);
    node1->next->next = new Node(9);
    node1->next->next->next = new Node(9);

    long long res = multiplyTwoLists(node, node1);

    cout << res << endl;


    return 0;
}