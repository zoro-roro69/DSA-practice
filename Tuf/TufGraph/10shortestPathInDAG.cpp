#include <bits/stdc++.h>
using namespace std;

//shortest path in Directed Acyclic graph


// If you are still confused with intution behind the topological sort....
// Topological sort ensures that we are picking up nodes that come first while
//  travelling from the source, this, in turn, will ensure that every node will 
// have at least one condition that it can be reached from the source.
// As we are setting dist[src] = 0, it will start from there, the condition 
// dis[node] != infinity will not let any  node other than src enter that condition first.
//  Because of topological sort nodes coming before src will be discarded.

vector <int> topologicalSort(int v, vector <vector <int>> adj[]){
    vector <int> res;
    vector <int> in_edges(v, 0);

    for (int i=0;i<v;i++){
        for (int j=0;j<adj[i].size();j++){
            in_edges[adj[i][j][0]]++;
        }
    }

    queue <int> q;
    for (int i=0;i<v;i++){
        if (in_edges[i] == 0)
            q.push(0);
    }

    while(!q.empty()){
        int front = q.front(); q.pop();
        res.push_back(front);

        for (auto j:adj[front]){
            in_edges[j[0]]--;
            if (in_edges[j[0]] == 0){
                q.push(j[0]);
            }
        }
    }

    return res;
}

vector <int> shortestPathInDAG(int v, vector <vector <int>> adj[], int source){

    vector <int> topo_sorted = topologicalSort(v, adj);

    vector <int> dist(v, INT_MAX);

    dist[source] = 0;

    for (int x:topo_sorted){
        if (dist[x]!=INT_MAX){
            for (auto j:adj[x]){
                if (dist[x] + j[1] < dist[j[0]]){
                    dist[j[0]] = dist[x] + j[1];
                }
            }
        }else{
            //dist[x] == INT_MAX
            //means that x is not reachable from source
        }
    }

    return dist;


}



int main(){


    return 0;
}