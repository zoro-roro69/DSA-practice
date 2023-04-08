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


struct Pair{
    Node *node;
    int distance;

    Pair(Node *n = NULL, int d = 0){
        node = n;
        distance = d;
    }
    
};

    
vector <int> bottomView(Node *root) {
    // Your Code Here
    
    if (root == NULL) return {};
    
    map <int, int> mp;
    
    queue <Pair *> q;
    
    q.push(new Pair(root, 0));
    while(!q.empty()){
        Pair *front = q.front(); q.pop();
        
        mp[front->distance] = front->node->data;
        
        if (front->node->left){
            q.push(new Pair(front->node->left, front->distance-1));
        }
        
        if (front->node->right){
            q.push(new Pair(front->node->right, front->distance+1));
        }
        
    }
    vector <int> res;
    for (auto x:mp){
        res.push_back(x.second);
    }
    return res;
}