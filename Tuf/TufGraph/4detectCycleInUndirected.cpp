#include <bits/stdc++.h>
using namespace std;


//cycle detection in undirected graph

bool cycleUsingBFS(int v, vector <int> adj[]){

    if (v == 0)
        return false;

    queue <int> q;
    vector <bool> visited(v, false);

    vector <int> par(v, -1); //for maintaining the immediate parent of the node
    //for handling the cases where graph is like this: 1---2 , 

    for (int i=0;i<v;i++){
        if (!visited[i]){
            visited[i] = true;
            q.push(i);

            while(!q.empty()){
                int front = q.front(); q.pop();

                for (auto x:adj[front]){
                    if (visited[x]){ //cycle found
                        if (par[front]!=x)
                            return true;
                        
                    }else{
                        par[x] = front;
                        visited[x] = true;
                        q.push(x);
                    }
                }
            }
        }
    }

    return false;
        

}

bool cycleUsingDFS(int v, vector <int> adj[]){
    if (v == 0)
        return false;

    stack <int> st;

    vector <bool> visited(v, false);
    vector <int> par(v, -1);

    for (int i=0;i<v;i++){
        if (!visited[i]){

            st.push(i);
            visited[i] = true;

            while(!st.empty()){
                int top = st.top(); st.pop();

                for (auto x:adj[top]){

                    if (visited[x]){
                        if (par[top]!=x)
                            return true;
                    }else{
                        visited[x] = true;
                        par[x] = top;
                        st.push(x);
                    }
                }

            }

        }
    }

    return false;



}

int main(){


    return 0;
}