#include <bits/stdc++.h>
using namespace std;


void dfs(int i, vector <bool> &visited, vector <vector<int>> &adj, int &count){
    visited[i] = true;
    count++;

    for (int j:adj[i]){
        if (!visited[j]){
            dfs(j, visited, adj, count);
        }
    }

}

long long journeyToTheMoon(int n, vector <vector <int>> &adj){

    vector <bool> visited(n, false);

    vector <int> components; 

    for (int i=0;i<n;i++){
        int count = 0;
        if (!visited[i]){
            dfs(i, visited, adj, count);
            components.push_back(count);
        }
    }

    long long res = 0;
    int sum_till_now = 0;
    for (int x:components){
        res += (long long)x* (long long)(n-x-sum_till_now);
        sum_till_now += x;
    }

    cout << sum_till_now << endl;
    return res;    

}


int main(){

    freopen("input.txt", "r", stdin);

    int n; int p;
    cin>>n>>p;

    vector <vector<int>> adj(n);

    for (int i=0;i<p;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << journeyToTheMoon(n, adj) << endl;
    return 0;
}