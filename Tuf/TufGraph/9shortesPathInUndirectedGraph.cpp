#include <bits/stdc++.h>
using namespace std;


//in undirected graph bfs always gives the shortest path
vector <int> shortestPath(int source, int v, vector <int> adj[]){
    vector <int> dist(v, INT_MAX);
    dist[source] = 0;

    queue <int> q;
    q.push(source);


    while (!q.empty()){
        int front = q.front(); q.pop();

        for (int j:adj[front]){
            if (dist[j]== INT_MAX){ //if not visited
                dist[j] = 1 + dist[front];
                q.push(j);
            }

        }

    }

    return dist;
}



int main(){


    return 0;
}