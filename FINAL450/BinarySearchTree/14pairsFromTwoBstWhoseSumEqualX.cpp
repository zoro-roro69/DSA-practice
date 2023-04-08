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


};

//this solution counts duplicates
// int countPairs(Node* root1, Node* root2, int x){
//     if (root1 == NULL || root2 == NULL)
//         return 0;

//     if (root1->data + root2->data > x){
//         return countPairs(root1->left, root2, x) + countPairs(root1, root2->left, x);
//     }
//     else if(root1->data + root2->data < x){
//         return countPairs(root1->right, root2, x) + countPairs(root1, root2->right, x);
//     }else{
//         return 1 + countPairs(root1->right, root2->left, x) + countPairs(root1->left, root2->right, x);
//     }

// }

void inOrder(Node *root, vector <int> &arr){
    if (root == NULL)
        return ;
    else{
        inOrder(root->left, arr);
        arr.push_back(root->data);
        inOrder(root->right, arr);
    }
}


int countPairs2(Node *root1, Node *root2, int x){
    vector <int> arr1;
    vector <int> arr2;
    inOrder(root1, arr1);
    inOrder(root2, arr2);

    int count = 0;
    int i = 0 , j = arr2.size()-1;

    while(i < arr1.size() && j>=0){
        int sum_ = arr1[i] + arr2[j];
        if (sum_ > x)
            j--;
        else if (sum_ < x)
            i++;
        else{
            count++;
            i++;
            j--;
        }
    }

    return count;
}

//another soultion is that for each element in bst 1 try to find x - bst1[i] in bst2 

int main(){


    return 0;
}