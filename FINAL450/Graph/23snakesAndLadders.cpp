#include <bits/stdc++.h>
using namespace std;



int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();

    vector <bool> visited(n*n+1, false);
    queue <int> q;
    q.push(1);
    //visited[1] = true;


    int level = 0;
    while(!q.empty()){
        int size = q.size();

        while(size){
            int cur = q.front(); q.pop(); 
            size--;

            if (cur == n*n){
                return level;
            }
            if (visited[cur]){ //already visited
                continue; 
            }

            visited[cur] = true;

            for (int i=1;i<=6;i++){
                int next = min(cur + i, n*n);
                int r = (next-1)/n; r = n-r-1;
                int c = (next-1)%n;
                if ((n-r)%2){ //odd, towards right
                    //c is correct
                }else{ //even, towards left
                    c = n-c-1;
                }

                if (board[r][c] == -1){
                    if (!visited[next])
                        q.push(next);
                }else{
                    if (!visited[board[r][c]])
                        q.push(board[r][c]);

                    // visited[board[r][c]] = true;
                }

            }
        }

        level++;

    }

    return -1;
}

//better solution :)
int snakesAndLadders2(vector<vector<int>>& board) {
    int n = board.size();

    vector <bool> visited(n*n+1, false);
    queue <int> q;
    q.push(1);
    //visited[1] = true;


    int level = 0;
    while(!q.empty()){
        int size = q.size();

        while(size){
            int cur = q.front(); q.pop();
            size--;
            if (cur == n*n){
                return level;
            }

            for (int i=1;i<=6;i++){
                int next = min(cur + i, n*n);
                int r = (next-1)/n; r = n-r-1;
                int c = (next-1)%n;
                if ((n-r)%2){ //odd, towards right
                    //c is correct
                }else{ //even, towards left
                    c = n-c-1;
                }

                if (board[r][c] == -1){
                    if (!visited[next]){
                        visited[next] = true;
                        q.push(next);
                    }
                }else{
                    if (!visited[board[r][c]]){
                        q.push(board[r][c]);
                        visited[board[r][c]] = true;
                    }

                }

            }
        }

        level++;

    }

    return -1;
}


int main(){

    return 0;
}