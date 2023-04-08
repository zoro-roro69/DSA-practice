#include <bits/stdc++.h>
using namespace std;
//Djkastra's algo

//also works for directed graph

// When edge weights are required to be nonnegative, Dijkstra's algorithm is often the algorithm of choice

// Dijkstra's algorithm finds a shortest path from a source vertex s to all other vertices.

// Everyone having a question regarding the need of Priority Queue. The fact is that 
// even without a Priority Queue, the algorithm will work absolutely fine, Priority 
// Queue is just an optimizing technique here, as it always returns the minimum distance, 
// hence we would have already figured the minimum distance of a node with least comparisons, 
// greatly reducing the time complexity. Otherwise, if we were to use a normal Queue, we might
//  find the shorter distance to a node in later checks. Hope you got the point!

//without priority queue
vector <int> shortestPath(int v, vector <vector <int>> adj[], int source){

    vector <int> dist(v, INT_MAX);
    dist[source] = 0;

    queue <int> q;
    q.push(source);

    while(!q.empty()){
        int front = q.front(); q.pop();
        for (auto j:adj[front]){
            if (dist[front] + j[1] < dist[j[0]]){
                dist[j[0]] = dist[front] + j[1];
                q.push(j[1]);
            }
        }
    }

    return dist;


}


int main(){


    return 0;
}