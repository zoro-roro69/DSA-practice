#include <bits/stdc++.h>
using namespace std;

//so basically what we do is, we try to do the topological sort using BFS(kahns algo)
//and if we are not able to do so, that means there is a cycle present
//since topological sort is only possible for dircected acyclic graph

// intution:
//in kahns algo what we do is we only process the node after its in_edges become 0
//but if there is a cycle in a graph there will be some node for which in_edge will never
//become 0

bool detectCycleBFS(int v, vector <int> adj[]){

    vector <int> in_edges(v, 0);

    for (int i=0;i<v;i++){
        for (int j:adj[i]){
            in_edges[j]++;
        }
    }

    queue <int> q;

    for (int i=0;i<v;i++){
        if (in_edges[i] == 0){
            q.push(i);
        }
    }

    int count = 0; 
    while(!q.empty()){
        int front = q.front(); q.pop();
        count++;

        for (int j:adj[front]){
            in_edges[j]--;
            if (in_edges[j] == 0)
                q.push(j);
        }

    }

    return count != v; //if count != v then ther is cycle
}

int main(){


    return 0;
}