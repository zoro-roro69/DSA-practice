#include <bits/stdc++.h>
using namespace std;


#include <bits/stdc++.h> 
bool helper(int i,int n, int m, vector <vector<int>> &mat, vector <int> &visited){
    if (i >=n)
        return true;
    
    vector <bool> colors(m, true);

    for (int nbr=0;nbr<n;nbr++){
        if (mat[i][nbr] && visited[nbr]!=-1){
            colors[visited[nbr]] = false;
        }
    }

    
    for (int j=0;j<m;j++){
        if (colors[j]){
            visited[i] = j;
            if (helper(i + 1, n, m, mat, visited)) {
                return true;
            }
            //backtrack
            visited[i] = -1;
        }
    }

    return false;

    // if (c == -1)
    //     return false;
    
    // visited[i] = c;
    // return helper(i+1, n, m, mat, visited);

}


string graphColoring(vector<vector<int>> &mat, int m) {
    //mat  = adjacency matrix
    // m = colors
    int n =  mat.size();
    vector <int> visited(n, -1);

    if  (helper(0, n, m, mat, visited))
        return "YES";
    
    return "NO";

}



int main(){
    vector <vector <int>> adj{{0,1},
                              {1,0}};

    cout << graphColoring(adj, 1) << endl;
    return 0;
}