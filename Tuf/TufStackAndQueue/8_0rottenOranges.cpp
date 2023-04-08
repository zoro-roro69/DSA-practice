#include <bits/stdc++.h>
using namespace std;

// 0 - empty
// 1 - fresh
// 2 - rotten

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

inline bool isValid(int r, int c, int n, int m){
    return r >= 0 && r < n && c>=0 && c<m;
}

void bfs(vector <vector <int>> &grid, vector <vector <int>> &visited, int i, int j){
    //do bfs from i, j cell
    int n = grid.size();
    int m = grid[0].size();

    queue <pair <int, int>> q;
    q.push({i,j});
    visited[i][j] = 1;

    while(!q.empty()){
        auto front = q.front(); q.pop();
        int r = front.first; 
        int c = front.second;

        for (int k=0;k<4;k++){
            int new_r = r + dx[k];
            int new_c = c + dy[k];

            if (isValid(new_r, new_c, n, m)){ //&& visited[new_r][new_c] == 0){ //valid and not visited
                if (grid[new_r][new_c] == 0) //empty cell
                    continue;
                else if (grid[new_r][new_c] == 1){ //fresh orange
                    if (visited[new_r][new_c] == 0){
                        if (grid[r][c] == 1){ //r,c was previously fresh
                            visited[new_r][new_c] = visited[r][c] + 1;
                        }else{ //r,c was rotten from the begining
                            visited[new_r][new_c] = 1;
                        }

                        q.push({new_r, new_c});
                    }else { //already vsiited
                        if (grid[r][c] == 1 && (visited[r][c] + 1 < visited[new_r][new_c])){
                            visited[new_r][new_c] = visited[r][c] + 1;
                            q.push({new_r, new_c});
                        }
                        else if(grid[r][c] == 2 && (visited[new_r][new_c] > 1)){
                            visited[new_r][new_c] = 1;
                            q.push({new_r, new_c});
                        }
                    }
                }
                else if (grid[new_r][new_c] == 2 && visited[new_r][new_c] == 0){ //rotten orange
                    visited[new_r][new_c] = 1; 
                    q.push({new_r, new_c});
                }
            }
        }
    }

    return;

}

int minTimeToRot(vector<vector<int>>& grid, int n, int m){
    // Write your code here. 
    vector <vector <int>> visited(n, vector <int> (m,0));

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (grid[i][j] == 2 && visited[i][j] == 0) { //rotten and not visited
                //do bfs
                bfs(grid, visited, i, j);
            }

        }
    }

    int res = 0;
    bool flag = true;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (grid[i][j] == 1){
                if (visited[i][j]){
                    res = max(res, visited[i][j]);
                }else{
                    flag = false; //we still have a fresh orange 
                    break;
                }
            }
        }
    }
    if (flag)
        return res;

    return -1; //not all oranges were rotted
}

int main(){

    vector <vector <int>> grid{{2,1,0},
                               {0,1,1},
                               {1,0,1}};

    cout << minTimeToRot(grid, grid.size(), grid[0].size()) << endl;

    return 0;
}