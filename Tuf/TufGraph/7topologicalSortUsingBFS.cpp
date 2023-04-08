#include <bits/stdc++.h>
using namespace std;


//also known as kahns algorithm
vector <int> topologicalSortBFS(int v, vector <int> adj[]){

    vector <int> res;

    vector <int> in_edges(v, 0);

    for (int i=0;i<v;i++){
        for (int j:adj[i]){
            in_edges[j]++;
        }
    }
    queue <int> q;
    for (int i=0;i<v;i++){
        if (in_edges[i] == 0)
            q.push(i);
    }

    while(!q.empty()){

        int front = q.front(); q.pop();
        res.push_back(front);

        for (int j:adj[front]){
            in_edges[j]--;
            if (in_edges[j] == 0)
                q.push(j);
        }
    }

    return res;
}


int main(){

    return 0;
}