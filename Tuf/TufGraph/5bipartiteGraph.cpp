#include <bits/stdc++.h>
using namespace std;

// Bipartitie graph
// graph that can be colored using 2 colors such that no two adjacent nodes
// have same color
// Nore -- 
// if a graph has odd length cycle, then it cannot be bipartite
// if it doesnt have have odd length cycle then it is bipartite

//official definition of bipartite graph
// A Bipartite Graph is a graph whose vertices can be divided 
// into two independent sets, U and V such that every edge (u, v)
//  either connects a vertex from U to V or a vertex from V to U.
//  In other words, for every edge (u, v), either u belongs to U 
// and v to V, or u belongs to V and v to U. We can also say that
//  there is no edge that connects vertices of same set.

// A bipartite graph is possible if the graph coloring is possible 
// using two colors such that vertices in a set are colored with the same color.


//using bfs
bool isBipartite(int v, vector<int>adj[]){
    // Code here
    if (v <=2)
        return true;
    queue <int> q;   

    vector <int> visited(v , 0);
    // 0 - not colored
    // 1 - color1
    // 2 - color2

    for (int i=0;i<v;i++){
        if (visited[i] == 0){
            
        
            q.push(i);
            visited[i] = 1;

            while(!q.empty()){
                int front = q.front(); q.pop();

                for (auto x:adj[front]){
                    if (visited[x] == 0){
                        if (visited[front] == 1){
                            visited[x] = 2;
                        }else if (visited[front] == 2)
                            visited[x] = 1;

                        q.push(x);
                    }else if (visited[x] == visited[front])
                        return false;
                    else{
                        //no need to color as already colored with opposite color
                    }
                }
            }
            
        }
    }

    return true;
}

//using dfs
bool isBipartiteUsingDFS(int v, vector<int>adj[]){

    if (v<=2)
        return true;

    stack <int> st;
    vector <int> visited(v, 0);

    for (int i=0;i<v;i++){
        if (visited[i] == 0){

            st.push(i);
            visited[i] = 1;

            while(!st.empty()){
                int top = st.top(); st.pop();

                for (auto x:adj[top]){

                    if (visited[x] == 0){
                        if (visited[top] == 1){
                            visited[x] = 2;
                        }else if (visited[top] == 2)
                            visited[x] = 1;

                        st.push(x);
                    }else if (visited[x] == visited[top])
                        return false;
                    else{
                        //no need to color as already colored
                    }
                }

            }
        }

    }


    return true;

}



int main(){

    return 0;
}