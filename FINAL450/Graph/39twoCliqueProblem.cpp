#include <bits/stdc++.h>
using namespace std;
// Clique
// A Clique is a subgraph of graph such that all vertices in subgraph are completely connected with each other. 
// +----+                                +------+
// | 1  |                                |  4   |
// +-+--+------------+-----+             |      |
//   |               |  3  +-------------+------+
//   |               |     |
//   |               +-+---+
//   |                 |
// +-+--+              |
// | 2  +--------------+
// +----+

//in the above graph, the subgraph {1,2,3} is clique as it is fully connected (every vertex has edge 
// to every other vertex)

//Now in two clique problem we are given a graph and we need to return whether this graph, can be divided
// in two cliques or not

//         +----+                            +----+
//    +----+ 1  +-----+                      |  4 |
//    |    +----+     |              +-------+----+
//    |               |              |            |
//    |               |     +--------+            |      +----+
//    |               |     |                     +------+ 5  |
// +--+--+          +-+--+--+                            +----+
// |  2  +----------+ 3  |
// +-----+          +----+

//for example in this graph we have two cliques: {1,2,3} and {4, 5}

// Solution: a graph can be divided in two cliques if
// the complement of a graph is bipartite.
// complement of a graph is a graph in which all orginal edges are removed and en edge is 
// introduced between the vertices which didnt have any edge in the original graph

// so lets continue the above example, its complement is : 
// +----+
// | 1  +----------+
// +----+          |
//                 |  +-----+
//                 +--+  4  |
// +----+          |  +-----+
// | 3  +----------------+
// +----+          |
//                 |
//                 |  +-----+
// +----+          +--+  5  |
// | 2  +----------+  +-----+
// +----+

// If complement is Bipartite, then graph can be divided into two sets U and V 
// such that there is no edge connecting to vertices of same set.

// This means in original graph, these sets U and V are completely connected. Hence 
// original graph could be divided in two Cliques (U and V).


bool ifBipartite(int n, vector <int> adj[]){
    //assuming we have connected graph as input
    vector <int> visited(n, 0);
    queue <int> q;

    q.push(0); visited[0] = 1;

    while(!q.empty()){
        int front =  q.front(); q.pop();

        for (int j:adj[front]){
            if (visited[j] == 0){
                visited[j] = 1;
                q.push(j);
            }else if(visited[j] == visited[front]){
                return false;
            }else{
                //coloring with opposite color
                visited[j] = (visited[front] == 1) ? 2:1;
                q.push(j);
            }
        }
    }

    return true;
}

bool checkIfTwoCliques(int n, vector <int> adj[]){
    vector <int> complement_adj[n];

    for (int i=0;i<n;i++){
        unordered_set <int> s;
        for (auto j:adj[i])
            s.insert(j);
        for (int j=0;j<n;j++){
            if (j!=i && s.find(j) == s.end()){
                complement_adj[i].push_back(j);
                complement_adj[j].push_back(i);
            }
        }
    }

    return ifBipartite(n, complement_adj);
}



int main(){

    return 0;
}