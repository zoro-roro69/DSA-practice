#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

//result node to store height and diameter
struct result{
    int ht;
    int dm;
    
    result(int h = 0, int d = 0){
        ht = h;
        dm = d;
    }
};

result* findDiameter(Node *root){
    if (root == NULL)
        return new result();
    
    result* left_res = findDiameter(root->left);
    result* right_res = findDiameter(root->right);
    
    result *res  = new result();
    res->ht = 1 + max(left_res->ht, right_res->ht);
    res->dm = max(1 + left_res->ht + right_res->ht, max(left_res->dm, right_res->dm));
    
    return res;
}  

int diameter(Node* root) {
        result *res = findDiameter(root);
        return res->dm;
}


// int diameterOpt(struct node* root, int* height)
// {
//     // lh --> Height of left subtree
//     // rh --> Height of right subtree
//     int lh = 0, rh = 0;
  
//     // ldiameter  --> diameter of left subtree
//     // rdiameter  --> Diameter of right subtree
//     int ldiameter = 0, rdiameter = 0;
  
//     if (root == NULL) {
//         *height = 0;
//         return 0; // diameter is also 0
//     }
  
//     // Get the heights of left and right subtrees in lh and
//     // rh And store the returned values in ldiameter and
//     // ldiameter
//     ldiameter = diameterOpt(root->left, &lh);
//     rdiameter = diameterOpt(root->right, &rh);
  
//     // Height of current node is max of heights of left and
//     // right subtrees plus 1
//     *height = max(lh, rh) + 1;
  
//     return max(lh + rh + 1, max(ldiameter, rdiameter));
// }
 

int main(){


    return 0;
}