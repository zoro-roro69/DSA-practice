#include <bits/stdc++.h>
using namespace std;


void dfs(int i, int j,int n, vector <vector <int>> &m ,vector <vector <int>> &visited, vector <string> &res, string &cur_path) {
    if (i>=n || i < 0 || j>=n || j <0 || m[i][j]==0) //invalid cell
        return;
    if (i == n-1 && j == n-1){ //destination reached
        res.push_back(cur_path);
        return;
    }

    if (visited[i][j])
        return;

    visited[i][j] = true;

    //down
    cur_path.push_back('D');
    dfs(i+1, j, n, m,visited, res, cur_path);
    cur_path.pop_back();

    //up
    cur_path.push_back('U');
    dfs(i-1, j, n, m,visited, res, cur_path);
    cur_path.pop_back();

    //right
    cur_path.push_back('R');
    dfs(i, j+1, n, m,visited, res, cur_path);
    cur_path.pop_back();

    //left
    cur_path.push_back('L');
    dfs(i, j-1, n, m,visited, res, cur_path);
    cur_path.pop_back();

    // cur_path.pop_back();
    visited[i][j] = false;

    return;

}

vector<string> findPath(vector<vector<int>> &m, int n) {
    // Your code goes here
    
    vector <string> res = {};
    if (n <= 1)
        return res;

    vector <vector <int>> visited(n, vector <int> (n,0));

    string cur_path = "";
    dfs(0, 0, n, m, visited, res, cur_path);

    
    return res;
}



int main(){


    return 0;
}