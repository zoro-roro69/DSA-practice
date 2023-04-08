#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, vector <int> &visited,int n, int m, bool graph[][101]){
    if (i == n)
        return true;
    //try to color the node
    for (int c=1;c<=m;c++){
        bool flag = true;
        for (int j=0;j<n;j++){
            if (graph[i][j] && visited[j] == c){
                flag = false;
                break;
            }
        }

        if (flag){
            visited[i] = c;
            if (dfs(i+1, visited, n , m, graph))
                return true;
            visited[i] = 0;
        }else{
            //try next color
        }

    }

    return false;

}

bool graphColoring(bool graph[101][101], int m, int n) {


    vector <int> visited(n, 0); //0 - not colored
    return dfs(0, visited,n, m, graph);

}

int main(){

    return 0;
}