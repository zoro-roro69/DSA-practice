#include <bits/stdc++.h>
using namespace std;

struct Node {

    int val;
    Node *next;

    Node(int v = 0, Node * n= NULL){
        val = v;
        next = NULL;
    }

};

int lengthOfList(Node *head){
    int len  = 0;
    Node *cur = head;
    while(cur){
        cur = cur->next;
        len++;
    }
    return len;
}

void printList(Node *head){

    Node *cur = head;
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

}

Node *reverseList(Node *head){
    if (head == NULL || head->next == NULL)
        return head;

    Node *prev = NULL;
    Node *cur = head;

    while(cur){
        Node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

//when we are allowed to modify the list
Node *addTwoLists(Node *head1, Node *head2){
    head1 = reverseList(head1);
    head2 = reverseList(head2);

    Node *cur1 = head1;
    Node *cur2 = head2;

    Node *res = new Node(0); //dummy head, list starts from res->next
    Node *prev = res;
    int sum = 0;

    while(cur1 || cur2){
        if (cur1){
            sum += cur1->val;
            cur1 = cur1->next;    
        }
        if (cur2){
            sum += cur2->val; 
            cur2 = cur2->next;
        }

        prev->next = new Node(sum%10);
        prev = prev->next;
        sum = sum/10; //carry

    }

    if (sum){
        prev->next = new Node(sum);
    }

    res = res->next;

    res = reverseList(res);

    return res;
}


//when we are not allowed to modify the list
Node *addTwoListSameSize(Node *head1, Node *head2, int &carry){
    if (head1 == NULL){
        carry = 0;
        return NULL;
    }

    Node *res = addTwoListSameSize(head1->next, head2->next, carry);

    int sum = head1->val + head2->val + carry;
    Node *new_node = new Node(sum%10);
    new_node->next = res;
    carry = sum/10;

    return new_node;
}

Node *addCarryToRemaining(Node *head1, Node *cur, int &carry,Node *res){
    if (head1 == cur){
        return res;
    }
    
    Node *ret = addCarryToRemaining(head1->next, cur, carry, res);
    int sum  = head1->val + carry;
    Node *new_node = new Node(sum%10);
    new_node->next = ret;

    carry = sum/10;
    return new_node;
}

Node *addTwoLists2(Node *head1, Node *head2){
    Node *res; 
    if (head1 == NULL){
        res = head2;
        return res;
    }

    if (head2 == NULL){
        res = head1;
        return res;
    }

    int len1 = lengthOfList(head1);
    int len2 = lengthOfList(head2);

    if (len1<len2){
        swap(head1, head2);
        swap(len1, len2);
    }

    Node *cur = head1;
    while(len1!=len2){
        cur = cur->next;
        len1--;
    }

    int carry;
    res = addTwoListSameSize(cur, head2, carry); //returns carry
    
    //add carry to remaining list1
    Node *res_head = addCarryToRemaining(head1, cur, carry, res);
    if (carry){
        Node *new_node = new Node(1);
        new_node->next = res_head;
        res_head = new_node;
    }

    return res_head;


}

int main(){

    Node *head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);


    Node *head2 = new Node(1);
    // head2->next = new Node(1);

    printList(head);
    printList(head2);

    Node *res = addTwoLists2(head, head2);

    cout << "------------" << endl;
    printList(res);

    return 0;
}