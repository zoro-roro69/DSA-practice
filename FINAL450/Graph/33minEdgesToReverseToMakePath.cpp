#include <bits/stdc++.h>
using namespace std;
#define V vector
#define P pair


int minEdgesToReverse(int source, int dest, int n, V <int> adj[]){

    V < V < P <int, int >>> graph(n);
    for (int i=0;i<n;i++){
        for (int j:adj[i]){
            graph[i].push_back({j, 0}); //normal edge with 0 wt
            graph[j].push_back({i, 1}); //reverse edge with 1 wt
        }
    }

    vector <int> dist(n, INT_MAX);
    dist[source] = 0;
    queue <int> q;
    q.push(source);

    while(!q.empty()){
        int front = q.front(); q.pop();

        for (auto p: graph[front]){
            if (dist[p.first] > dist[front] + p.second){
                dist[p.first] = dist[front] + p.second;
                q.push(p.first);
            }
        }
    }

    return dist[dest];

}

int main(){

    vector <int> v[7];

    v[0].push_back(1);

    v[2].push_back(1);
    v[5].push_back(1);

    v[2].push_back(3);
    v[6].push_back(3);
    v[6].push_back(4);
    v[4].push_back(5);

    cout << minEdgesToReverse(0, 6, 7, v) << "\n";


    return 0;
}