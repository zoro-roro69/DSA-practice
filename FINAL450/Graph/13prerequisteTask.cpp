#include <bits/stdc++.h>
using namespace std;


bool dfs(int i, vector <int> &visited, vector <int> adj[]){

    visited[i] = 1;

    for (int j:adj[i]){
        if (visited[j] == 0){
            if (dfs(j, visited, adj))
                return true;
        }
        else if (visited[j] == 1){
            return true; //cycle
        }
    }

    visited[i] = 2;

    return false;

}


bool isPossible(int n, vector<pair<int,int>> &prerequisites) {

    vector <int> adj[n];

    for (auto p: prerequisites){
        adj[p.second].push_back(p.first);
    }

    //check for cycle in directed graph

    vector <int> visited(n, 0); //0 - not visited, 1 - partial visited, 2 - fully visited

    for (int i=0;i<n;i++){
        if (visited[i]==0){
            if (dfs(i, visited, adj)){
                
                return false;
            }
        }
    }

    return true;
}

int main(){


}