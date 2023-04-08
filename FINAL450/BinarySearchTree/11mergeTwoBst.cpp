#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }


    void inOrderPrint(Node *root){
        if (!root)
            return;
        inOrderPrint(root->left);
        cout << root->data << " ";
        inOrderPrint(root->right);
    }
};



//method 1
// do inorder traversal for first tree and store in arar1
// do inorder traversal for second tree and store in arr2
// merge the two arrs 
// then from the two arrays create a new balanced tree


void inOrder(Node *root, vector <int> &arr){
    if (root == NULL)
        return ;
    
    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

vector <int> mergeArr(vector <int> &arr1, vector <int> &arr2){

    vector <int> res;
    int i = 0, j = 0;

    while(i < arr1.size() && j < arr2.size()){
        if (arr1[i] < arr2[j]){
            res.push_back(arr1[i++]);
        }else
            res.push_back(arr2[j++]);
    }

    while(i<arr1.size())
        res.push_back(arr1[i++]);

    while(j<arr2.size())
        res.push_back(arr2[j++]);

    return res;
}

//creates a balanced bst from given sorted array
Node *buildBst(vector <int> &arr, int start, int end){
    if (start>end)
        return NULL;
    int mid = start + (end-start)/2;
    Node *root = new Node(arr[mid]);
    root->left = buildBst(arr, start, mid-1);
    root->right = buildBst(arr, mid+1, end);

    return root;
}

Node *mergeBsts(Node *root1, Node *root2){

    vector <int> in_order1;
    vector <int> in_order2;

    inOrder(root1, in_order1);
    inOrder(root2, in_order2);

    vector <int> res = mergeArr(in_order1, in_order2);

    return buildBst(res, 0, res.size()-1);

}


//This solution required extra space for arrays, also in merging algo we need extra array' 

//but there is anothr method in which we can merge two bsts in place,
//in this we use Doubly linked list

//we convert1 tree1 to list1
//convert tree2 to lsit2
//then merge these lists
//now convert list back to BST




//WRONGGGG SOLUTION :)))
Node *bstToDll(Node *root, Node *parent){
    if (root == NULL)
        return NULL;


    Node *successor = bstToDll(root->right, root);
    Node *predecessor = bstToDll(root->left, root);

    if (successor)
        successor->left = root;
    if (predecessor)
        predecessor->right = root;

    if (parent != NULL){
        if (root->data > parent->data){ //cur node is right child

            root->right = successor; //no problem is succesor is NULL

            if (predecessor == NULL){
                root->left = parent;
                return root;
            }else{
                root->left = predecessor;
                return predecessor;
            }
        }else{ //cur node is left child

            root->left = predecessor; //no problem if predecessor is null

            if (successor == NULL){
                root->right = parent;
                return root;
            }else{
                root->right = successor;
                return successor;
            }
        }
    }else{ //cur node is root node :)

        root->right = successor;
        root->left = predecessor;

        return root;

    }
}

Node *bstToList(Node *root){
    root = bstToDll(root, NULL);
    //current it is pointing at the root of the treee
    while(root->left)
        root = root->left;
    return root;
}

Node *mergeDLL(Node *head1, Node *head2){
    Node *dummy = new Node(0); //dummy head, lists starts from dummmy->right
    Node *prev = dummy;
    while(head1 && head2){

        if (head1->data < head2->data){
            prev->right = head1;
            head1->left = prev;
            head1 = head1->right; //incrementing head

            prev = prev->right; //incrementing prev
        }else{
            prev->right = head2;
            head2->left = prev;
            head2 = head2->right;

            prev = prev->right;
        }

    }

    while(head1){
        prev->right = head1;
        head1->left = prev;

        head1 = head1->right;
        prev = prev->right;
    }


    while(head2){
        prev->right = head2;
        head2->left = prev;

        head2 = head2->right;
        prev = prev->right;
    }
    if (dummy->right)
        dummy->right->left = NULL;
    return dummy->right;

}

Node *getMidOfList(Node *head){
    if (!head)
        return NULL;
    
    Node *slow = head;
    Node *fast = head;
    while(fast && fast->right){ //incase of singly linked list we do fast->right && fast->right->right, to understand this think about the case when we have just two nodes
        slow = slow->right;
        fast = fast->right->right;
    }
    return slow;
}

Node *dllToBst(Node *head){ //nlogn complexity
    if (head == NULL)
        return NULL;
    
    Node *root = getMidOfList(head); //O(n)
    cout << "got mid: " << root->data << endl;
    Node *next = root->right;
    Node *prev = root->left;

    if (prev){
        prev->right = NULL;
        root->left = dllToBst(head);
    }
    if (next){
        next->left = NULL;
        root->right = dllToBst(next);
    }
    return root;

}


Node *dllToBst2(Node *);

Node *mergeBsts2(Node *root1, Node *root2){ //nlogn or n depending how you convert dll to bst
    Node *head1 = bstToList(root1); //O(n)
    Node *head2 = bstToList(root2); //O(n)


    cout << "bstToDll done" << endl;
    Node *head3 = mergeDLL(root1, root2); //O(m+n)
    cout << "merge done" << endl;
    return dllToBst(head3); //nlogn
    return dllToBst2(head3); //n time

}

//time complexity of the above approach is nlogn, becauase dllToBst takesn nlogn time,
// there is another way to convert doubley linked list to bst in O(n) time.

// The method 1 constructs the tree from root to leaves. In this method, we construct from leaves to root.
// The idea is to insert nodes in BST in the same order as they appear in Doubly Linked List, so that the tree 
// can be constructed in O(n) time complexity. We first count the number of nodes in the given Linked List. 
// Let the count be n. After counting nodes, we take left n/2 nodes and recursively construct the left subtree.
//  After left subtree is constructed, we assign middle node to root and link the left subtree with root.
//  Finally, we recursively construct the right subtree and link it with root. 
// While constructing the BST, we also keep moving the list head pointer to next so that we have the 
// appropriate pointer in each recursive call. 

int countNodesInDll(Node *head){
    int n = 0;
    while(head){
        head = head->right;
        n++;
    }
    return n;
}

Node *dllToBstInOrderHelper(Node **head_ref, int num_nodes){
    if (num_nodes <= 0)
        return NULL;

    Node *left_node = dllToBstInOrderHelper(head_ref, num_nodes/2); //left subtree will have n/2 elements
    
    //by the time, head_ref would have been incremented n/2 times, and is pointing to the root
    Node *root = *head_ref;
    root->left = left_node;

    *head_ref = (*head_ref)->right;
    //num_nodes in right = num_nodes - num_nodes in left - 1(root)
    Node *right_node = dllToBstInOrderHelper(head_ref, num_nodes - num_nodes/2 -1);
    root->right = right_node;

    return root;

}

Node *dllToBst2(Node *root){
    int n = countNodesInDll(root);
    cout << n << endl;

    return dllToBstInOrderHelper(&root, n);

}

void printList(Node *head){

    while(head){
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

Node *sample(Node *parent){
    parent->left = new Node(1);
    parent->left->right = parent;
    return parent;
}

int main(){


    // Node *parent = new Node(10);

    // parent = sample(parent);
    // cout << parent->left->data << endl;
    // cout << parent->left->right->data << endl;

    vector <int> arr1{2,5,7,10,15};
    vector <int> arr2{0,6,9,13,20};
    Node *root1 = buildBst(arr1, 0, arr1.size()-1);
    Node *root2 = buildBst(arr2, 0, arr2.size()-1);

    // root1->inOrderPrint(root1); cout << endl;
    
    root1 = bstToList(root1);
    root2 = bstToList(root2);

    // Node *root =  dllToBst(root1);

    // root->inOrderPrint(root);
    // cout << endl;

    printList(root1);
    printList(root2);

    Node *root3 = mergeDLL(root1, root2);

    cout << "printList" << endl;
    printList(root3);

    root3 = dllToBst2(root3);

    root3->inOrderPrint(root3);

    // printList(root3);

    // root3 = dllToBst(root3);

    // root3->inOrderPrint(root3);
    // printList(root1);
    // printList(root2);

    // Node *root3 = mergeBsts(root1, root2);

    // root3->inOrderPrint(root3);

    // cout << "here" << endl;

    // Node *root4 = mergeBsts2(root1, root2);

    // root4->inOrderPrint(root4);
    return 0;
}