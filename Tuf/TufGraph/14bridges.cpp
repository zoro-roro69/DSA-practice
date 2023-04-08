#include <bits/stdc++.h>
using namespace std;


//bridges are basically those edges in graph, whose removal
// will make the graph disconnected or will increase the number of connected
// components in the graph
//example:--
// ┌───┐                  ┌───┐            ┌───┐
// │ 1 ├──────────────────┤ 2 ├────────────┤ 3 │
// └─┬─┘                  └──┬┘            └───┘
//   │                       │
//   │                       │
//   │                       │
//   │                       │
//   │                       │
// ┌─┴─┐                   ┌─┴─┐
// │ 4 ├───────────────────┤ 5 │
// └───┘                   └─┬─┘
//                           │
//                           │
//                           │
//                           │
//                         ┌─┴─┐
//                         │ 6 │
//                         └───┘
// in this graph if we remove the edge (2,3), node 3 will be disconnected
// therefore edge (2,3) is a bridge
// similarly if we remove the edge (5,6), node 6 will be disconnected
// therefor edge (5,6) is a bridge
// but if we remove the edge (2,5), we can see that it will not break the graph into more components
// since 5 is reachable from node 4 aswell, thus edge (2,5) is not a bridge

void dfs(int node, int &timer, int parent,vector <int> &disc, vector <int> &low,
         vector <bool> &visited, vector <int> adj[], vector <vector <int>> &res){
    
    visited[node] = true;
    disc[node] = timer;
    low[node] = timer;
    timer++;

    for (int nbr:adj[node]){
        if (nbr == parent)
            continue;
        else if (!visited[nbr]){
            dfs(nbr,timer, node, disc, low, visited, adj, res);
            low[node] = min(low[node], low[nbr]); //updating node's low, if low of nbr is updated

            if (low[nbr] > disc[node]){ 
                // CONDITON FOR BRIDGE,  low[nbr] > disc[node] means that, that this is the only edge 
                // connecting 'node' and 'nbr',
                // if it is false then it means that nbr is connected to a vertext which comes before the current node in dfs traversal 
                res.push_back({node, nbr});
            }
        }else{
             //ndr is visited i.e, back edge or cycle
            low[node] = min(low[node], disc[nbr]);
        }

    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    vector <int> adj[v];

    for (auto edge:edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector <int> disc(v,-1); //discovery time during DFS
    vector <int> low(v,-1); //lowest discovery time
    vector <bool> visited(v,false);

    int timer = 0;
    int parent = -1;

    vector <vector <int>> res;

    for (int i=0;i<v;i++){
        if (!visited[i]){
            dfs(i, timer, parent, disc, low, visited, adj, res);
        }
    }

    return res;

}


int main(){

    return 0;
}