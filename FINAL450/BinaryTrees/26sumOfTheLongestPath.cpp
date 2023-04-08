#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int sum_ = 0;
int max_ht = 0;

void sumOnLongestPath(Node *root, int &cur_sum, int &cur_ht){
    if (!root){
        if (cur_ht > max_ht){
            max_ht = cur_ht;
            sum_ = cur_sum;    
        }
    }

    cur_sum += root->data;
    cur_ht++;
    sumOnLongestPath(root->left, cur_sum, cur_ht);
    sumOnLongestPath(root->right, cur_sum, cur_ht);

    cur_ht--;
    cur_sum -= root->data;


}

int main(){
    return 0;
}