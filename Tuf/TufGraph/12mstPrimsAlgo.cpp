#include <bits/stdc++.h>
using namespace std;


// A spanning tree is a sub-graph of an undirected connected graph, which includes all the 
// vertices of the graph with a minimum possible number of edges. If a vertex is missed, 
// then it is not a spanning tree.

// spanning tree always has n-1 edges, where n = number of vertices in the graph
// a graph can have more than one spanning trees


// +--+          +--+       +--+          +--+        +--+          +--+     +--+          +--+
// |1 +----------+2 |       |1 +----------+2 |        |1 +----------+2 |     |1 +----------+2 |
// ++-+          ++-+       ++-+          ++-+        ++-+          +--+     +--+          ++-+
//  |             |          |             |           |                                    |
//  |             |          |             |           |                                    |                            
//  |             |          |             |           |                                    |                            
//  |             |          |             |           |                                    |                            
// ++-+          ++-+       ++-+          ++-+        ++-+          +--+     +--+          ++-+                          
// |4 +----------+3 |       |4 |          |3 |        |4 +----------+3 |     |4 +----------+3 |                          
// +--+          +--+       +--+          +--+        +--+          +--+     +--+          +--+                          
//                                                                                                                       
//     graph 1                 spanning tree1           spanning tree2         spanning tree3                            


// a minimum spanning tree is the spanning tree in which the sum of weight of edges is minimum

// One such algo for finding minimum spanning tree is Prims algo

// It starts with an empty spanning tree. The idea is to maintain two sets of vertices. The first set contains
//  the vertices already included in the MST, the other set contains the vertices not yet included.
//  At every step, it considers all the edges that connect the two sets and picks the minimum weight edge
//  from these edges. After picking the edge, it moves the other endpoint of the edge to the set 
// containing MST. 

// A group of edges that connects two sets of vertices in a graph is called cut in graph theory.
//  So, at every step of Prim’s algorithm, find a cut (of two sets, one contains the vertices 
// already included in MST and the other contains the rest of the vertices), pick the minimum weight 
// edge from the cut, and include this vertex to MST Set (the set that contains already included vertices).

// How does Prim’s Algorithm Work? 
// The idea behind Prim’s algorithm is simple, a spanning tree means all vertices must be connected. 
// So the two disjoint subsets (discussed above) of vertices must be connected to make a Spanning Tree.
// And they must be connected with the minimum weight edge to make it a Minimum Spanning Tree.

// Follow the given steps to find MST using Prim’s Algorithm:
// 1. Create a set mstSet that keeps track of vertices already included in MST. 
// 
// 2. Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE. 
//    Assign the key value as 0 for the first vertex(you can start from any vertex) so that it is picked first. 

// 3. While mstSet doesn’t include all vertices 
//      Pick a vertex u which is not there in mstSet and has a minimum key value. 
//      Include u in the mstSet. 
//      Update the key value of all adjacent vertices of u. To update the key values, iterate through 
//      all adjacent vertices. For every adjacent vertex v, if the weight of edge u-v is less than 
//      the previous key value of v, update the key value as the weight of u-v



//Function to find sum of weights of edges of the Minimum Spanning Tree.
//brute, this approach hash complexity n^2, we can improve it 
int spanningTree(int v, vector<vector<int>> adj[]){

    vector <int> key(v, INT_MAX);
    vector <int> parent(v, -1);
    vector <int> included(v, false);

    //starting from vertexx 0
    key[0] = 0;

    int n = 0;
    while(n<v){
        int mini = -1;
        int minv = INT_MAX;
        for (int i=0;i<v;i++){
            if (included[i] == false && key[i] < minv){
                minv = key[i];
                mini = i;
            }
        }

        included[mini] = true;
        n++;

        for (auto j:adj[mini]){
            if (!included[j[0]] && j[1] < key[j[0]]){
                key[j[0]] = j[1];
                parent[j[0]] = mini;
            }

        }

    }

    int res = 0;
    for (int x:key)
        res += x;

    return res;

}

//the above approach has complexity n^2, we can improve it and make it nlogn
//by using priority_queue


//Time Complexity - O(V+E)*O(logV)
struct mycompare{
    bool operator()(pair<int,int> const &p1,  pair<int,int> const &p2){
        if (p1.first < p2.first)
            return false;
        else if (p1.first > p2.first)
            return true;
        else
            return p1.second < p2.second;
    }
};

int spanningTree2(int v, vector <vector <int>> adj[]){

    vector <int> key(v, INT_MAX);
    vector <bool> included(v, false);
    vector <int> parent(v, -1);

    priority_queue <pair <int,int> , vector<pair<int,int>>, mycompare> pq;
    pq.push({0,0}); //{weight, index}
    key[0] = 0;
    int n  = 0;


    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken. 
    // try the following case: 
    // Credits: Srejan Bera
    // 6 7 
    // 0 1 5 
    // 0 2 10 
    // 0 3 100 
    // 1 3 50 
    // 1 4 200
    // 3 4 250
    // 4 5 50 

    while(!pq.empty()){
        pair <int, int> p = pq.top(); pq.pop();
        included[p.second] = true;
        n++;

        for (auto j:adj[p.second]){
            if (included[j[0]] == false && j[1] < key[j[0]]){
                key[j[0]] = j[1];
                parent[j[0]] = p.second;
                pq.push({j[1], j[0]});
            }
        }

    }

    int res = 0;
    for (int x:key)
        res +=x;

    return res;

}

int main(){


    return 0;
}