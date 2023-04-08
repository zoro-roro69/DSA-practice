#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Not a good approach this makes solution very complex
// Not complete
// TreeNode * findNode(TreeNode* root, TreeNode * &parent, int key){
//     if (root == NULL)
//         return NULL;
//     if (root->val == key)
//         return root;

//     parent = root;
//     if (key > root->val){
//         return findNode(root->right, parent, key);
//     }else{
//         return findNode(root->left, parent, key);
//     }
// }

// TreeNode *findLeftSuccesor(TreeNode *root, TreeNode * &parent){
//     if (root == NULL)
//         return NULL;
//     while(root->right){
//         root = root->right;
//     }
//     return root;
// }

// TreeNode *findRightSuccesor(TreeNode *root, TreeNode * &parent){
//     if (root == NULL)
//         return NULL;
//     while(root->left){
//         root = root->left;
//     }
//     return root;
// }

// TreeNode* deleteNode(TreeNode* root, int key) {
//     TreeNode *parent = NULL;

//     TreeNode *node = findNode(root, parent, key);
//     if (node == NULL)
//         return NULL; //key not found
//     if (parent == NULL){ //key is the root node
//         TreeNode *parent_of_succesor = root;
//         TreeNode* next_succesor = findRightSuccesor(root->right, parent_of_succesor);
//         if (next_succesor != NULL){
//             parent_of_succesor->left = next_succesor->right;
//             next_succesor->left = root->left;
//             next_succesor->right = root->right;

//         }else{
//             next_succesor = findLeftSuccesor(root->left, root);

//             if (next_succesor == NULL) //root was the only element in the tree
//                 return NULL;
//         }
    
//     }
// }


//Simple recursive solution :)

//i still dont know why this doesnt work
TreeNode *deleteNode(TreeNode *root, int key){

    if (root){
        if (key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else{ ///key == root->val
            if (root->left == NULL && root->right == NULL) //no children
                return NULL;

            if (root->left || root->right){ //one child
                return root->left ? root->left : root->right;
            }

            //two children
            TreeNode *right_succesor = root->right;
            cout << "sdfrs: " << right_succesor->val << endl;
            while(right_succesor->left){
                right_succesor = right_succesor->left;
            }
            right_succesor->right = deleteNode(root->right, right_succesor->val);
            right_succesor->left = root->left;

            //delete root
            root = right_succesor;

        }
        return root;
    }
    return NULL;
}


// TreeNode* deleteNode(TreeNode* root, int key) {
//     if(root) 
//         if(key < root->val) root->left = deleteNode(root->left, key);     //We frecursively call the function until we find the target node
//         else if(key > root->val) root->right = deleteNode(root->right, key);       
//         else{
//             if(!root->left && !root->right) return NULL;          //No child condition
//             if (!root->left || !root->right)
//                 return root->left ? root->left : root->right;    //One child contion -> replace the node with it's child
// 				                                                //Two child condition   
//             TreeNode* temp = root->left;                        //(or) TreeNode *temp = root->right;
//             while(temp->right != NULL) temp = temp->right;     //      while(temp->left != NULL) temp = temp->left;
//             root->val = temp->val;                            //       root->val = temp->val;
//             root->left = deleteNode(root->left, temp->val);  //        root->right = deleteNode(root->right, temp);		
//         }
//     return root;
// }  


int main(){


    return 0;
}