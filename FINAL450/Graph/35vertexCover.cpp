#include <bits/stdc++.h>
using namespace std;

// A vertex cover of an undirected graph is a subset of its vertices such that for every edge (u, v) 
// of the graph, either ‘u’ or ‘v’ is in the vertex cover. Although the name is Vertex Cover, the 
// set covers all edges of the given graph

// +------+          +-------+                    +-------+
// |  0   |          |    1  |                    |   2   |
// |      +----------+       +--------------------+       |
// +------+          +-------+                    +---+---+
//                                                |   |
//                                      +---------+   |
//                                      |             |
//                             +--------+             |
//                             |                      |
//                    +-------++                  +---+----+
//                    |   4   |                   |    3   |
//                    |       |                   |        |
//                    +-------+                   +--------+

//so the vertext cover of the above graph is {2,0} or {2,1}

//the problem to find the minimum size vertext cover is NP HARD
//one naive solution is to check through all possible subsets of vertices and among them select the one which has minimum
//size and satisfies the criteria

//although for bipartite graph, and trees there exists polynomial time solution

//for other graphs there exists approximate algorithm for vertex cover which runs in polynomial time
// which goes as follows:
// 1) Initialize the result as {}
// 2) Consider a set of all edges in given graph.  Let the set be E.
// 3) Do following while E is not empty
// ...a) Pick an arbitrary edge (u, v) from set E and add 'u' and 'v' to result
// ...b) Remove all edges from E which are either incident on u or v.
// 4) Return result 

// It can be proved that the above approximate algorithm never finds a vertex cover whose size is more 
// than twice the size of the minimum possible vertex cover


pair <int , int> getEdge(vector <unordered_set <int>> &adj){
    for (int i=0;i<adj.size();i++){
        for (int j: adj[i] ){
            adj[i].erase(j);
            adj[j].erase(i);
            return {i,j};
        }
    }

    return {};
}

vector <int> findMinimumVertexCover(int n, vector <unordered_set <int>> &adj){

    vector <int> res;
    int num_edges = 0;
    for (int i=0;i<n;i++){
        for (int j:adj[i]){
            if (j > i){
               num_edges++;
            }
        }
    }

    if (num_edges == 0)
        return {};
    


    while (num_edges){
        pair <int,int> edge = getEdge(adj);
        res.push_back(edge.first);
        res.push_back(edge.second);
        num_edges--;

        //adjacent to edge.first
        for (int j:adj[edge.first]){
            adj[j].erase(edge.first);
        }
        num_edges -= adj[edge.first].size();
        adj[edge.first].clear();

        //adjacent to edge.second
        for (int j:adj[edge.second]){
            adj[j].erase(edge.second);
        }
        num_edges -= adj[edge.second].size();
        adj[edge.second].clear();
        
    }

    return res;

}

int main(){
    // int n = 4;
    // vector <unordered_set<int>> adj(n);

    // adj[0].insert(3);

    // adj[1].insert(3);

    // adj[2].insert(3);

    // adj[3].insert(1);
    // adj[3].insert(0);
    // adj[3].insert(2);

    int n = 7;
    vector <unordered_set<int>> adj(n);

    adj[0].insert(2);
    adj[0].insert(1);

    adj[1].insert(0);
    adj[1].insert(3);

    adj[2].insert(0);

    adj[3].insert(4);
    adj[3].insert(1);


    adj[4].insert(5);
    adj[4].insert(3);

    adj[5].insert(4);
    adj[5].insert(6);

    adj[6].insert(5);

    vector <int> res = findMinimumVertexCover(n, adj);

    for (auto x:res)
        cout << x << " ";

    cout << endl;


    return 0;
}