// DAG -- directed acyclic graph
//Topological sort in directed graph(with no cycle) is basically ordering of vertices
// such that v1, v2, v3 ... vn;
// there if there is an edge  u --> v, then u comes befor v in the above list

#include <bits/stdc++.h>
using namespace std;

//topological sort using dfs
//in this method we only print or store the elment, after all of its children are visited

void dfsHelper(int v, vector <int> adj[], vector <bool> &visited, vector <int> &res){

    visited[v] = true;

    for (int j:adj[v]){
        if (!visited[j])
            dfsHelper(j, adj, visited, res);
    }

    res.push_back(v);


}

vector <int> topologicalSort(int v, vector <int> adj[]){

    vector <int> res;
    vector <bool> visited(v, false);

    for (int i=0;i<v;i++){
        if (!visited[i])
            dfsHelper(i, adj, visited, res);
    }

    reverse(res.begin(), res.end());

    return res;
}

int main(){

    int v = 6;
    vector <int> adj[v];

    adj[5] = {0, 2};
    adj[2] = {3};
    adj[3] = {};
    adj[1] = {3};
    adj[4] = {1,0};
    adj[0] = {};

    vector <int> res = topologicalSort(v, adj);

    for (auto x:res)
        cout << x << " ";
    cout << endl;

    return 0;
}