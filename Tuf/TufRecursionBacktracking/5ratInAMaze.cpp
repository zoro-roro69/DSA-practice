#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


bool isValid(int x, int y, int n){
    if (x < 0 || x >=n)
        return false;
    if (y < 0 || y >=n)
        return false;

    return true;
}

void dfs(int x, int y, vector <vector <int>> &maze, int n, vector <int> &path, vector <vector <int>> &res){

    path.push_back(x*n+y);

    if (x == n-1 && y == n-1){
        res.push_back(path);
        path.pop_back();
        return;
    }
    maze[x][y] = 0; //blocking this cell (a way of marking it as visited)

    for (int i=0;i<4;i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (isValid(new_x, new_y, n) && maze[new_x][new_y] == 1){
            dfs(new_x, new_y, maze, n, path, res);
        }
    }
    //backtrack
    maze[x][y] = 1; 
    path.pop_back();
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    if (maze[0][0] == 0)
        return {};
    // Write your code here.
    vector <int> path;
    vector <vector <int>> res;


    dfs(0,0, maze, n, path, res);

    cout << "here" << endl;
    vector <vector <int>> formatted_res;

    for (auto v:res){
        vector <int> temp(n*n, 0);
        for (auto x:v){
            temp[x] = 1;
        }

        formatted_res.push_back(temp);
    }

    return formatted_res;
}


int main(){

    vector <vector <int>> maze{{1,0,1},{1,0,1},{1,1,1}};

    vector <vector <int>> res = ratInAMaze(maze, 3);

    for (auto v: res){
        for (auto x:v)
            cout << x << " ";
        cout << endl;
    }


    return 0;
}