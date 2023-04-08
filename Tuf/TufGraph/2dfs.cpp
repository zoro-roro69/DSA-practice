#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector <int> adj[], vector <bool> &visited, vector <int> &res){

    if (visited[i])
        return;
    
    visited[i] = true;
    res.push_back(i);

    for (auto x:adj[i]){
        dfs(x, adj, visited, res);
    }


}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {

    vector <int> res;
    if (!V)
        return res;

    vector <bool> visited(V, false);

    //in the given question we need to do dfs from vertex 0 only
    dfs(0, adj, visited, res);

    return res;
}


vector <int> dfs2(int V, vector <int> adj[]){
    vector <int> res;
    if (!V)
        return res;

    stack <int> st;
    vector <int> visited(V, 0);

    //0 - not visited
    //1 - in the stack 
    //2 - fully explored

    st.push(0);
    visited[0] = 1;

    while(!st.empty()){
        int top = st.top(); st.pop();
        if (visited[top]!=2){

            visited[top] = 2;
            res.push_back(top);

            for (int i=adj[top].size()-1;i>=0;i--){
                int x = adj[top][i];

                if (visited[x] == 0){
                    st.push(x);
                    visited[x] = 1;
                }else if(visited[x] == 1){
                    st.push(x);
                }
            }

        }
    }

    return res;

}

int main(){

    return 0;
}