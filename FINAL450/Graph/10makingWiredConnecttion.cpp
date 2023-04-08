#include <bits/stdc++.h>
using namespace std;


//approach one
//in this basically we can see that we hane N number of components on the graph
//then we need N-1 edges to connect the graph
//example :
// +-------+                    +--------+                      +----------+
// |       |                    |        |                      |          |
// |   1   |                    |    2   |                      |   3      |
// |       |                    |        |                      |          |
// +-------+                    +--------+                      +----------+

// in this graph we have 3 components
//and to make this connected we need 3-1 = 2 edges, like shown below

// +-------+                    +--------+                      +----------+
// |       |                    |        |                      |          |
// |   1   +------------------+ |    2   | +------------------+ |   3      |
// |       |                    |        |                      |          |
// +-------+                    +--------+                      +----------+

// so the idea is to count the number of cycles in the graph, as from each cycle
// we can take one edge and use it to connect to another disconnected component
// so if (num_cycles >= num_components-1)
// return num_components-1;
//else return -1;

// +------+                +------+
// |  1   |                |  2   |
// |      +----------------+      |
// +--+---+                +-+----+
//    |                      |
//    |                      |
//    |                      |  ----- use this edge, from the cycle
//    |                      |
//    |     +----------------+
// +--+----+
// |       |                          +--------+
// |  3    |                          |        |
// |       |                          |  4     |
// +-------+                          |        |
//                                    +--------+
// in above example num_cycles = 1
// num_components-1 = 2-1 = 1
// therefore return 1 as ans

// +------+                +------+
// |  1   |                |  2   |
// |      +----------------+      +--------+
// +--+---+                +------+        |
//    |                                    |
//    |                                    |
//    |                                    |
//    |                                    |
//    |                                    |
// +--+----+                               |
// |       |                          +----+---+
// |  3    |                          |        |
// |       |                          |  4     |
// +-------+                          |        |
//                                    +--------+




bool dfs(int i, int par, vector <int> &visited, vector <int> adj[], int &num_cycles){
    if (visited[i] == 2)
        return;

    if (visited[i] == 1){
        num_cycles++;
        return;
    }

    for (int j:adj[i]){
        if (par == j)
            continue;
        dfs(j, i, visited, adj, num_cycles);
    }
    visited[i] = 2;
}

int makeConnected(int n, vector<vector<int>>& connections) {
    
    vector <int> adj[n];

    for (auto c:connections){
        adj[c[0]].push_back(c[1]);
        adj[c[1]].push_back(c[0]);
    }

    int num_cycles = 0;
    int num_components = 0;

    vector <int> visited(n, 0);// 0- not visited, 1-partialvly visted, 2-fully visited

    for (int i=0;i<n;i++){
        if (visited[i] == 0){
            num_components++;
            dfs(i, -1, visited, adj, num_cycles);
        }
    }

    if (num_cycles >= num_components-1){
        return num_components-1;
    }else
        return -1;
}

//second approach: much better approach
// as we know that for graph with n vertices, we need minium n-1 edges to make them connected (Minimum spanning tree)
// so if we have edges less than n-1 we return -1
// if we have num edges >= n-1
// then we return number of components in graph - 1;
// so basically in this we just need to count the number of connected components in the graph

// class Solution {
// public:
//     void solve(vector<vector<int>> &adj,vector<bool> &visited,int u){
//         visited[u]=true;
//         for(auto i:adj[u]){
//     if(!visited[i]){
//         solve(adj,visited,i);
//     }
//         }
//     }
//     int makeConnected(int n, vector<vector<int>>& connections) {
        
//    int noOfEdges=connections.size();
//         if(noOfEdges<n-1){
//             return -1;
//         }
//         vector<vector<int>> adj(n);
//         for(int i=0;i<noOfEdges;i++){
//             int src=connections[i][0];
//             int dest=connections[i][1];
//             adj[src].push_back(dest);
//             adj[dest].push_back(src);
//         }
//         vector<bool> visited(n,false);
//         int count=-1;
//         for(int i=0;i<n;i++){
// if(!visited[i]){
//     count++;
//     solve(adj,visited,i);
// }
//         }
//             return count;
        
//     }
// };

int main(){

    return 0;
}
