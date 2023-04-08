#include <bits/stdc++.h>
using namespace std;

// void topoDfs(int i, vector <bool> &visited, vector <int> adj[], vector <int> &res){
//     visited[i] = true;
    
//     for (int j:adj[i]){
//         if (!visited[j])
//             topoDfs(j, visited, adj, res);
//     }

//     res.push_back(i);
// }

// vector <int> topoSort(int n, vector <int> adj[]){

//     vector <bool> visited(n, false);

//     vector <int> res;
//     for (int i=0;i<n;i++){
//         if (!visited[i]){
//             topoDfs(i, visited, adj, res);
//         }
//     }

//     reverse(res.begin(), res.end());

//     return res;

// }

// void dfs(int i, vector <bool> &visited, vector <int> adj[], vector <int> &res, vector <int> &cur_path){
//     visited[i] = true;
//     cur_path.push_back(i);

//     for (int j:adj[i]){
//         if (!visited[j]){
//             dfs(j, visited, adj, res, cur_path);
//         }
//     }
//     if (res.size() < cur_path.size()){
//         res = cur_path;
//     }
//     cur_path.pop_back();
//     return;
// }

// //for unweighted graph
// vector <int> longestPathInDAG(int n, vector <int> adj[]){

//     vector <int> topoorder = topoSort(n, adj);
//     vector <bool> visited(n, false);

//     vector <int> res;
//     vector <int> cur_path;

//     for (int i=0;i<n;i++){
//         if (!visited[toporder[i]]){
//             dfs(topoorder[i], visited, adj, res, cur_path);
//         }
//     }

//     return res;

// }



// The longest path problem for a general graph is not as easy as the shortest path problem because
// the longest path problem doesn’t have optimal substructure property

// In fact, the Longest Path problem is NP-Hard for a general graph.
// However, the longest path problem has a linear time solution for directed acyclic graphs. 
// The idea is similar to linear time solution for shortest path in a directed acyclic graph., we use Topological Sorting.

// We initialize distances to all vertices as minus infinite and distance to source as 0, 
// then we find a topological sorting of the graph. Topological Sorting of a graph represents 
// a linear ordering of the graph

// Once we have topological order (or linear representation), we one by one process all vertices in 
// topological order. For every vertex being processed, we update distances of its adjacent using 
// distance of current vertex.

void topoDfs(int i, vector <bool> &visited, vector <pair <int,int>> adj[], vector <int> &res){
    visited[i] = true;
    
    for (auto p:adj[i]){
        if (!visited[p.first])
            topoDfs(p.first, visited, adj, res);
    }

    res.push_back(i);
}

vector <int> topoSort(int n, vector <pair <int,int>> adj[]){

    vector <bool> visited(n, false);

    vector <int> res;
    for (int i=0;i<n;i++){
        if (!visited[i]){
            topoDfs(i, visited, adj, res);
        }
    }

    reverse(res.begin(), res.end());

    return res;

}
//for weighted graph
int longestPathInWeightedDAG(int n, vector <pair <int,int>> adj[], int source){

    vector <int> toporder = topoSort(n, adj);
    vector <int> dist(n, INT_MIN);

    dist[source] = 0;

    int res = 0;
    for (int i:toporder){
        for (auto p:adj[i]){
            int j = p.first;
            int wt = p.second;

            if (dist[i]!= INT_MIN && dist[i] + wt > dist[j]){
                dist[j] = dist[i] + wt;
                res = max(res, dist[j]);
            }
    
        }
    }

    //dist contains length of longest distances from the source to all other vertices
    for (int j:dist)
        cout << j << " ";
    cout << endl;

    return res; //res contains max of dist i.e longest distance
}

int main(){



    return 0;
}