#include <bits/stdc++.h>
using namespace std;

//better solution

class Solution {
public:
    int i=0; //global index of string s
    TreeNode* solve(int d,string &s){ //d is the current depth
        if(i>=s.length())return NULL;
        string str="";
        int x=0; //x will store depth of this node
        int st=i; //storing previous posititon of i, if we need to reset i 
        while(s[i]=='-'){
            i++;
            x++;
        }
        if(x!=d){ //if current depth is not equal to depth of this node, so return NULL
            i=st; //reset i
            return NULL;
        }
        while(i<s.length()&&s[i]!='-'){ //extract the num at current node
            str+=s[i];
            i++;
        }
        
        int val=stoi(str);
        TreeNode* temp=new TreeNode(val);
        temp->left=solve(d+1,s);
        temp->right=solve(d+1,s);
        return temp;
    }
    TreeNode* recoverFromPreorder(string s) {
        return solve(0,s);
    }
};


//my solution, works but harder to understand
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* helper(int &i, string &traversal, int depth){
    if (i>=traversal.size())
        return NULL;

    string s_num = "";
    while(i<traversal.size() && traversal[i] != '-'){
        s_num += traversal[i++];
    }
    int num = stoi(s_num);
    TreeNode *cur_node = new TreeNode(num);
    if (i == traversal.size())
        return cur_node;

    int j = i;
    int next_depth = 0;
    while(traversal[i] == '-'){
        i++; next_depth++;
    }

    if (next_depth == 1 + depth){
        cur_node->left = helper(i, traversal, next_depth);
        //chek for the right child
        j = i;
        next_depth = 0;
        while(traversal[i] == '-'){
            i++; next_depth++;
        }
        if (next_depth == 1 + depth){
            cur_node->right = helper(i, traversal, next_depth);
        }else{
            //right child is NULL for cur node
            i = j;
        }

        return cur_node;
    }
    else{//sibling
        i = j;
        //left and right of cur are NULL
        return cur_node;
    }

}

TreeNode* recoverFromPreorder(string &traversal) {
    int i = 0;
    return helper(i, traversal, 0);   
}

void printPreOrder(TreeNode * node){
    if (node == NULL)
        return;
    else{
        cout << node->val << " ";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

int main(){

    string traversal ="1-401--349---90--88";
    TreeNode* root = recoverFromPreorder(traversal);
    
    printPreOrder(root); 

    return 0;
}