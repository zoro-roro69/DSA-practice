#include <bits/stdc++.h>
using namespace std;

#define V vector
#define P pair

bool dfs(int i, int &cur_dist, V <bool> &visited,  V <V <P <int, int>>> &adj, V <int> &res, int k){
    visited[i] = true;
    res.push_back(i);
    if (cur_dist >= k){
        return true;
    }


    for (P <int, int> p: adj[i]){
        if (!visited[p.first]){
            cur_dist += p.second;
            if (dfs(p.first, cur_dist, visited, adj, res, k)){
                return true;
            }else{
                cur_dist -= p.second;
            }
        }
    }

    res.pop_back();
    visited[i] = false;
    return false;

}

V <int> pathMoreThanKOfLength(int source, int n, int k, V <V <P<int, int>>> &adj){

    V <bool> visited(n, false);

    int cur_dist = 0;

    V <int> res;

    dfs(source, cur_dist, visited, adj, res, k);


    return res;
} 

int main(){
    V < V < P <int, int>>> adj(9);

    adj[0].push_back({1,4});
    adj[0].push_back({7,8});


    adj[1].push_back({7,11});
    adj[1].push_back({0,4});
    adj[1].push_back({2,8});

    adj[2].push_back({1,8});
    adj[2].push_back({8,2});
    adj[2].push_back({3,7});
    adj[2].push_back({5,4});


    adj[3].push_back({2,7});
    adj[3].push_back({5,14});
    adj[3].push_back({4,9});


    adj[4].push_back({3,9});
    adj[4].push_back({5,10});


    adj[5].push_back({4,10});
    adj[5].push_back({3,14});
    adj[5].push_back({2,4});
    adj[5].push_back({6,2});

    adj[6].push_back({7,1});
    adj[6].push_back({8,6});
    adj[6].push_back({5,2});


    adj[7].push_back({0,8});
    adj[7].push_back({1,11});
    adj[7].push_back({8,7});
    adj[7].push_back({6,1});


    adj[8].push_back({6,6});
    adj[8].push_back({7,7});
    adj[8].push_back({2,2});

    V <int> res = pathMoreThanKOfLength(0, 9, 61, adj);

    for (int x: res)
        cout << x << " ";
    cout << endl;
    
 
    // V <int> res = pathMoreThanKOfLength()

    return 0;
}