#include <bits/stdc++.h>
using namespace std;

// Articulation points in a graph are those vertices, on whose removal
// the graph becomes disconnected or number of connected component increases


// ┌─────┐                                                                                                             ┌─────┐
// │     │                         ┌─────┐                                                                             │     │                         ┌─────┐
// │  1  ├─────────────────────────┤  2  │                                                                             │  1  ├─────────────────────────┤  2  │
// │     │                         │     │                                                                             │     │                         │     │
// └───┬─┘                         └────┬┘                                                                             └───┬─┘                         └─────┘
//     │                                │                                                                                  │
//     │                                │                                                                                  │
//     │                                │                                                                                  │
//     │                                │                                                                                  │
//     │                                │                                                                                  │
//     │                                │                                                                                  │
//     │                                │                                                                                  │
//     │                                │                                                                                  │
//     │                                │                                                                                  │
//     │                                │                                                                                  │
//     │                                │                                                                                  │
//  ┌──┴──┐                             │                                                                               ┌──┴──┐
//  │     │                         ┌───┴──┐                   ┌──────┐                                                 │     │                                                    ┌──────┐
//  │     │                         │      │                   │      │                                                 │     │                                                    │      │
//  │  3  ├─────────────────────────┤      ├───────────────────┤      │                                                 │  3  │                                                    │      │
//  │     │                         │  4   │                   │   5  ├────────────────────┐                            │     │                                                    │   5  ├────────────────────┐
//  └─────┘                         │      │                   │      │                    │                            └─────┘                                                    │      │                    │
//                                  └──────┘           ┌───────┴──────┘                    │                                                                               ┌───────┴──────┘                    │
//                                                     │                                   │                                                                               │                                   │
//                                                     │                                   │                                                                               │                                   │
//                                                     │                                   │                                                                               │                                   │
//                                                     │                                   │                                                                               │                                   │
//                                                     │                                   │                                                                               │                                   │
//                                                     │                                   │                                                                               │                                   │
//                                                     │                                   │                                                                               │                                   │
//                                                 ┌───┴───┐                          ┌────┴────┐                                                                      ┌───┴───┐                          ┌────┴────┐
//                                                 │       │                          │         │                                                                      │       │                          │         │
//                                                 │   6   ├──────────────────────────┤         │                                                                      │   6   ├──────────────────────────┤         │
//                                                 │       │                          │    7    │                                                                      │       │                          │    7    │
//                                                 └───────┘                          │         │                                                                      └───────┘                          │         │
//                                                                                    └─────────┘                                                                                                         └─────────┘


// The idea is to use DFS (Depth First Search). In DFS, follow vertices in a tree form called the DFS tree.
//  In the DFS tree, a vertex u is the parent of another vertex v, if v is discovered by u. 

// In DFS tree, a vertex u is an articulation point if one of the following two conditions is true. 

// u is the root of the DFS tree and it has at least two children. 
// u is not the root of the DFS tree and it has a child v such that no vertex in the subtree rooted 
// with v has a back edge to one of the ancestors in DFS tree of u.


// Do DFS traversal of the given graph 
// In DFS traversal, maintain a parent[] array where parent[u] stores the parent of vertex u.
// To check if u is the root of the DFS tree and it has at least two children. For every vertex, 
// count children. 
// 
// If the currently visited vertex u is root (parent[u] is NULL) and has more than two children, print it. 
// 
// To handle a second case where u is not the root of the DFS tree and it has a child v such that no vertex in
//  the subtree rooted with v has a back edge to one of the ancestors in DFS tree of u maintain an array disc[]
//  to store the discovery time of vertices.
// 
// For every node u, find out the earliest visited vertex (the vertex with minimum discovery time) that can be
//  reached from the subtree rooted with u. So we maintain an additional array low[] such that: 
// low[u] = min(disc[u], disc[w]) , Here w is an ancestor of u and there is a back edge from some 
// descendant of u to w.



void dfs(int i, int parent, int &timer, vector <int> &disc,
         vector <int> &low, vector <bool> &visited, vector <int> adj[], vector <int> &res)
{

    visited[i] = true;
    disc[i] = timer;
    low[i] = timer;
    timer++;

    int child = 0;
    bool flag = false;
    for (int nbr:adj[i]){
        if (nbr == parent)
            continue;
        if (!visited[nbr]){
            child++;
            dfs(nbr, i, timer, disc, low, visited, adj, res);
            low[i] = min(low[i], low[nbr]);

            if (low[nbr] >= disc[i] && parent!=-1){ //articulation point
                //i is ap
                if (!flag){ //just to check if i is already included
                    res.push_back(i);
                    flag = true;
                }
            }
        }else{
            //nbr is visited, i.e back edge is there
            low[i] = min(low[i], disc[nbr]);
        }
    }

    if (parent == -1 && child > 1){
        res.push_back(i);
    }

}
// to understand why we need to handle for the root node seperately, try these two examples
//                                   +
//                                   |
//                                   |
// in this root node '1' is not AP   |              in this root node '1' is AP
//                                   |
//                                   |
//                                   |
//      +---+             +--+       |                  +---+
//      | 1 +-------------+2 |       |             +--+ | 1 +----------+
//      +-+-+             +--+       |             |    +---+          |
//        |               |          |             |        |          |
//        |               |          |             |        |          |
//        |               |          |             |        |          |
//        |               |          |             |        |          |
//      +-+-+            ++--+       |           +-+-+      +---+    +-+-+
//      |3  +------------+ 4 |       |           | 2 |      | 3 |    | 4 |
//      +---+            +---+       |           +---+      +---+    +---+
//                                   |
//                                   |
//          graph 1                  |                  graph 2
//                                   |
//                                   |
//                                   |
//                                   |
//                                   +



vector <int> articulationPoints(int v, vector <int> adj[]){

    vector <int> disc(v,-1);
    vector <int> low(v, -1);
    vector <bool> visited(v, false);

    vector <int> res;

    int timer = 0;

    for (int i=0;i<v;i++){
        if (!visited[i])
            dfs(i, -1, timer, disc, low, visited, adj, res);
    }

    return res;
}

int main(){

    return 0;
}