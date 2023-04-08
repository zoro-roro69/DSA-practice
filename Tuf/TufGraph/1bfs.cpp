#include <bits/stdc++.h>
using namespace std;

//NOTE - this code works if the graph is connected (connected means that all nodes are reachable from the give node)
//but if graph is disconnected i.e has components, then we need to try to start bfs from every node if it is not visi
//ted in previous traversale

// TC - O(N )
// SC - O(N)

// Function to return Breadth First Traversal of given graph.
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector <int> res;
    if (V == 0)
        return res;

    queue <int> q;
    vector <bool> visited(V, false);

    q.push(0);
    visited[0] = true;
    while(!q.empty()){

        ///dont need to do this level stuff in normal bfs just keep on taking the first from the queue 
        // check below function bfs2
        int cur_lvl_size = q.size();

        while (cur_lvl_size){

            int front = q.front(); q.pop();
            res.push_back(front);

            for (auto x:adj[front]){
                if (!visited[x]){
                    visited[x] = true;
                    q.push(x);
                }
            }

            cur_lvl_size--;
        }
    }

    return res;

}


vector<int> bfsOfGraph2(int V, vector<int> adj[]) {
    // Code here
    vector <int> res;
    if (V == 0)
        return res;

    queue <int> q;
    vector <bool> visited(V, false);

    for (int i=0;i<V;i++){
        if (!visited[i]){
            //do bfs starting from ith node
            q.push(i);
            visited[i] = true;
            
            while(!q.empty()){
                int front = q.front(); q.pop();
                res.push_back(front);

                for (auto x:adj[front]){
                    if (!visited[x]){
                        q.push(x);
                        visited[x] = true;
                    }
                }

            }

        }
    }

    return res;

}







int main (){


    return 0;
}