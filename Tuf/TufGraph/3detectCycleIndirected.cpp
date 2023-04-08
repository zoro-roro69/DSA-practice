#include <bits/stdc++.h>
using namespace std;


//this is wrong
// bool cycleUsingBFS(int v, vector <int> adj[]){

//     if (v == 0)
//         return false;

//     queue <int> q;
//     vector <bool> visited(v, false);

//     for (int i=0;i<v;i++){
//         if (!visited[i]){
//             visited[i] = true;
//             q.push(i);

//             while(!q.empty()){
//                 int front = q.front(); q.pop();

//                 for (auto x:adj[front]){
//                     if (visited[x]){ //cycle found
//                         return true;
//                     }else{
//                         visited[x] = true;
//                         q.push(x);
//                     }
//                 }
//             }
//         }
//     }

//     return false;

// }

bool dfs(int v, vector <int> adj[], vector <int> &visited){
    if (visited[v] == 1)
        return true;
    if (visited[v] == 2)
        return false;

    visited[v] = 1; // being explored

    for (auto x:adj[v]){
        if (dfs(x, adj, visited))
            return true;
    }

    visited[v] = 2; //fully explored

    return false;

}


bool cycleUsingDFS(int v, vector <int> adj[]){

    if (v==0)
        return false;


    vector <int> visited(v, 0);
    //0 not visited
    //1 being explored
    //2 fully explored

    for (int i=0;i<v;i++){
        if (visited[i] == 0){
            if (dfs(i, adj, visited))
                return true;
        }
    }

    return false;
}

int main(){

    return 0;
}