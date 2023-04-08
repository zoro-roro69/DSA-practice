#include <bits/stdc++.h>
using namespace std;

void dfsHelper(int v, vector <int> adj[], vector <bool> &visited, vector <int> &res){
    visited[v] = true;

    for (int j:adj[v]){
        if (!visited[j])
            dfsHelper(j, adj, visited, res);
    }

    res.push_back(v);

}

vector <int> topologicalSort(int v, vector <int> adj[]){

    vector <int> res;
    vector <bool> visited(v, false);

    for (int i=0;i<v;i++){
        if (!visited[i])
            dfsHelper(i, adj, visited, res);
    }

    reverse(res.begin(), res.end());

    return res;
}

void dfsTopo(int i, vector <bool> &visited, vector <int> adj[], vector <int> &res){

    visited[i] = true;

    for (int j:adj[i]){
        if (!visited[j])
            dfsTopo(j, visited, adj, res);
    }
    res.push_back(i);

}

vector <int> getTopoSort(int n,vector <int> adj[]){

    vector <int> res;
    vector <bool> visited(n, false);

    for (int i=0;i<n;i++){
        if (!visited[i]){
            dfsTopo(i, visited, adj, res);
        }
    }

    reverse(res.begin(), res.end());
    return res;

}

void dfs(int i, vector <int> adj[], vector <int> &min_time){

    min_time[i]++;

    for (int j:adj[i]){
        if (min_time[j] <= min_time[i]){ //not visited 
            min_time[j] = min_time[i];
            dfs(j, adj, min_time);
        }
    }
}
vector <int> minimumTimeTakenByJobs(int n, vector <int> adj[]){

    vector <int> topo_order = topologicalSort(n, adj);

    for (int i:topo_order)
        cout << i << " ";
    cout << endl;

    vector <int> min_time(n,0);

    for (int i:topo_order){
        if (min_time[i] == 0){
            dfs(i, adj, min_time);
        }
    }

    return min_time;
}

//min time taken by each job, using kahns algo for topo sort
vector <int> minimumTimeTakenByJobs2(int n, vector <int> adj[]){

    vector <int> in_edges(n, 0);

    for (int i=0;i<n;i++){
        for (int j:adj[i]){
            in_edges[j]++;
        }
    }

    queue <int> q;
    vector <int> min_time(n, 0);

    for (int i=0;i<n;i++){
        if (in_edges[i] == 0){
            q.push(i);
            min_time[i] = 1;
        }
    }

    while (!q.empty()){
        int top = q.front(); q.pop();

        for (int j:adj[top]){
            in_edges[j]--;
            if (in_edges[j] == 0){
                min_time[j] = min_time[top] + 1;
                q.push(j);
            }
        }
    }

    return min_time;
    
}


int main(){
    int n= 10;
    vector <int> adj[n];

    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[0].push_back(4);

    adj[1].push_back(8);
    adj[1].push_back(7);

    adj[2].push_back(5);

    adj[3].push_back(5);

    adj[5].push_back(6);

    adj[6].push_back(7);

    adj[7].push_back(9);

    adj[1].push_back(8);

    vector <int>res = minimumTimeTakenByJobs(n, adj);

    for (auto x:res)
        cout << x << " ";
    cout << endl;

    res = minimumTimeTakenByJobs2(n, adj);

    for (auto x:res)
        cout << x << " ";
    cout << endl;

    return 0;
}