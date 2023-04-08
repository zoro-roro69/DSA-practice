#include <bits/stdc++.h>
using namespace std;


//in this we are only allowed to color the vertices using two colors only
// if a graph is two colorable then it is laso known as bipartite graph

bool isBipartite(vector<vector<int>> &mat){
    int n = mat.size();
    vector <int> visited(n, 0);
    queue <int> q;

    //assumign graph is connected, if not then we need to loop throught do bfs from all nodes which were not visi
    // -ited earlier

    q.push(0);
    visited[0] = 1; //coloring with firs color
    while(!q.empty()){
        int front = q.front(); q.pop();

        // for (int i=0;i<n;i++){ //for adjaceny matrix
        for (int i: mat[front]){ //for adjaceny list
            // if (front !=i && mat[front][i]){
                if (visited[i] == 0){
                    visited[i] = (visited[front] == 1) ? 2 : 1;
                    q.push(front);
                }
                else if(visited[i] == visited[front]){
                    //not colorable
                    return false;
                }else{
                    //continue
                }
            
        }
    }

    return true; //grqaph is bipartite
}



//DFS solution

// class Solution {
// public:
//     bool check(vector<vector<int>> &graph, int col , vector<int> &colour , int node){
//         colour[node] = col;
//         for(auto it:graph[node]){
//             if(colour[it] == -1){
//                 if(check(graph ,!col , colour , it) == false) return false;
//             }
//             else{
//                 if(col == colour[it]) return false;
//             }
//         }
//         return true;
//     }


//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> colour(n, -1);
//         for(int i =0;i<n;++i){
//             if(colour[i] == -1){
//                 if(check(graph , 1 , colour , i) == false) return false;
//             }
//         }
//         return true;
//     }
// };

int main(){


    // vector <vector <int>> mat

    return 0;
}