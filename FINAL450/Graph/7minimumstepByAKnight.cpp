#include <bits/stdc++.h>
using namespace std;

//Function to find out minimum steps Knight needs to reach target position.
int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){

    vector <vector <int>> neighbors{{-1,2}, {1,2}, {-1,-2}, {1,-2}, {2,1}, {2,-1}, {-2,1}, {-2,-1}};

    queue <pair <int,int>> q;
    vector <vector <int>> visited(N+1, vector <int> (N+1, false));

    q.push({KnightPos[0], KnightPos[1]});

    visited[KnightPos[0]][KnightPos[1]] = true;

    int level = 0;
    while(!q.empty()){
        
        int cur_size = q.size();
        for (int i=0;i<cur_size;i++){

            pair<int,int> front = q.front(); q.pop();

            if (front.first == TargetPos[0] && front.second == TargetPos[1])
                return level;
            
            for (auto nbr:neighbors){
                int x = front.first + nbr[0];
                int y = front.second + nbr[1];
                
                if (x>=1 && x<=N && y>=1 && y<=N && !visited[x][y]){
                    q.push({x,y});
                    visited[x][y] = true;
                }

            }
        
        }
        level++;
    }

}

int main(){

    return 0;
}