#include <bits/stdc++.h>
using namespace std;


// strongly connected component in a directed graph is a component, in which
// every node is reachable from every other node in that component

// ┌────────┐                     ┌─────────┐
// │        │                     │         │
// │   1    │                     │         │
// │        ├──────────────────►  │    2    │                          ┌─────────┐
// │        │                     │         │                          │         │
// └────────┘                     └───┬─────┘                          │   5     │
//                                    │                                │         │
//     ▲                              │                                │         │
//     │                              │                                └─────────┘
//     │                              │                                    ▲
//     │                              │                                    │
//     │                              │                                    │
//     │                              │                                    │
//     │                              ▼                                    │
//     │                                                                   │
//     │                                                                   │
//     │                          ┌──────────┐                             │
//  ┌──┴─────┐                    │          │                             │
//  │        │                    │   4      │                         ┌───┴────┐
//  │        │◄───────────────────┤          ├───────────────────►     │        │
//  │    3   │                    │          │                         │        │
//  │        │                    └──────────┘                         │   6    │
//  └────────┘                                                         └────────┘



// in the above graph we have 3 SCC's:
//  {1,2,4,3}
//  {5}
//  {6}

//kosaraju's algorithm is used to find all the scc's in the graph
// it involves 3 steps
// 1. get toposort 
// 2. transpose the graph i.e reverse the current edges
// 3. apply dfs in order of toposort

// lets understand the algo using above example graph
// 1. so first we get the topo sort - {1, 2, 3, 4, 5, 6}
// 2. get transpose of the graph

// the transpose looke like this:
// +-----+             +------+                 +-----+
// | 1   | <-----------+ 2    |                 | 6   |
// +-+---+             +--+---+                 +--+--+
//   |                    ^                        |
//   |                    |                        |
//   |                    |                        |
//   v                    |                        v
// +-+---+             +--+---+                 +--+--+
// |  4  +------------>+  3   | <---------------+  5  |
// +-----+             +------+                 +-----+


// now see the advantage of doing the transpose was that, the only edge(bridge) connecting from 3 to 5 
// is reversed. so now when we do dfs in transpose graph, starting from toposort order of the original graph
// i.e when we do dfs from 1 , 5 is now not reachable
// so when we do dfs in this tranpose from 1 we get one strongly connected component - {1, 4, 3, 2}
// then we do dfs from 5 we get - {5}
// then we do dfs from 6 and get - {6}

//so the graph has total of 3 strongly connected components 
// i.e - {1, 4, 3, 2} , {5}, {6}

// Note- Doing DFS in topoorder of the original graph matters 
// lets say in the above graph if instead of starting dfs from 1 we start dfs from 6
// then doing dfs from 6 we would get the result = {6, 5, 3 ,4, 2, 1}
// according to this result whole graph is strongly connnected
// which is WRONG



void topoDFS(int i, vector <bool> &visited, vector <int> adj[], vector <int> &res){
    visited[i] = true;

    for (int j:adj[i]){
        if (!visited[j]){
            topoDFS(j, visited, adj, res);
        }
    }
    res.push_back(i);
}
vector <int> getToposort(int v, vector <int> adj[]){

    vector <bool> visited(v, false);
    vector <int> res;

    for (int i=0;i<v;i++){
        if (!visited[i]){
            topoDFS(i, visited, adj, res);
        }
    }

    reverse(res.begin(), res.end());

    return res;

}

void kosarajuDFS(int i, vector <bool> &visited, vector <int> adj[], vector <int> &scc){
    visited[i] = true;
    scc.push_back(i);

    for (int j:adj[i]){
        if (!visited[j]){
            kosarajuDFS(j, visited, adj, scc);
        }
    }

}

vector <vector <int>> kosarajusAlgo(int v, vector <int> adj[]){

    //1. get topo sort
    vector <int> topo = getToposort(v, adj);
    vector <int> transpose[v];

    //2. transpose of graph
    for (int i=0;i<v;i++){
        for (int j:adj[i]){
            transpose[j].push_back(i);
        }
    }

    vector <bool> visited(v, false);
    vector <vector <int>> res;
    //3. dfs in topo order
    for (int i:topo){
        vector <int> scc;
        if (!visited[i]){
            kosarajuDFS(i, visited, transpose, scc);
            res.push_back(scc);
        }
    }

    return res;


}



int main(){

    return 0;
}