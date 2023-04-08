#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


vector<int> reverseLevelOrder(Node *root)
{
    queue <Node*> q;
    q.push(root);

    stack <vector <int>> st;
    while(!q.empty()){
        int cur_size = q.size();

        vector <int> cur_lvl;
        while(cur_size){

            Node *front = q.front(); q.pop();
            cur_lvl.push_back(front->data);

            if (front->left)
                q.push(front->left);

            if (front->right)
                q.push(front->right);

            cur_size--;
        }
        st.push(cur_lvl);
    }
    vector <int> res;
    while(!st.empty()){
        
        vector <int> v = st.top(); st.pop();
        for (int x:v)
            res.push_back(x);

    }
    return res;
}

//better version, using queue and stack



vector<int> reverseLevelOrder2(Node *root){

    queue <Node *> q;
    stack <Node *> st;
    vector <int> res;

    q.push(root);
    while(!q.empty()){
        Node *front = q.front(); q.pop();
        st.push(front);

        //push right child first in the queue
        if (front->right)
            q.push(front->right);
        if (front->left)
            q.push(front->left);

    }

    //empty the stack
    while(!st.empty()){
        Node *top = st.top(); st.pop();
        res.push_back(top->data);
    }


    return res;

}

int main(){

    return 0;

}