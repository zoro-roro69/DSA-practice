#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

void dfsCreateDummyNodes(Node *node, unordered_set <int> &visited){
    visited.insert(node->val);
    Node *dummy = new Node();
    dummy->val = node->val;
    dummy->neighbors = node->neighbors;

    for (auto nbr:node->neighbors){
        if (visited.find(nbr->val) == visited.end()){
            //not visited
            dfsCreateDummyNodes(nbr, visited);
        }
    }

    node->neighbors = {dummy};

}

Node* dfs(Node *node, unordered_set<int> &visited){
    visited.insert(node->val);
    Node *dummy = node->neighbors[0];

    
    vector <Node *> new_list;
    for (auto nbr:dummy->neighbors){
        new_list.push_back(nbr->neighbors[0]);
    }
    
    for (auto nbr:dummy->neighbors){
        if (visited.find(nbr->val) == visited.end()){
            dfs(nbr, visited);
        }
    }
    node->neighbors = dummy->neighbors;
    dummy->neighbors = new_list;
    return dummy;
}


void checkDFS(Node *node, unordered_set <int> &visited){
    visited.insert(node->val);
    cout << node->val << endl;
    Node *next = node->neighbors[0];
    if (next->val != node->val || node->neighbors.size()>1){
        cout << "error" << endl;
    }
    
    for (auto nbr:next->neighbors){
        if (visited.find(nbr->val) == visited.end()){
            checkDFS(nbr, visited);
        }
    }
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;
        unordered_set <int> visited;
        dfsCreateDummyNodes(node, visited);
        // visited.clear();
        // checkDFS(node, visited);
        // cout<<node->val <<endl;
        visited.clear();
        Node *res = node->neighbors[0];
        dfs(node, visited);
    // cout << res->val << endl;
        return res;
    
    }
};



int main(){

    return 0;
}