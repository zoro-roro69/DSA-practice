#include <bits/stdc++.h>
using namespace std;

// Given three numbers N, X, and Y. Geek and his friend playing a coin game. 
// In the beginning, there are N coins. In each move, a player can pick X, Y, 
// or 1 coin. Geek always starts the game. The player who picks the last coin 
// wins the game. The task is to check whether Geek will win the game or not if both are playing optimally.



int f(int n, bool turn, int x, int y){
    //base case pending
    if (n == 0){
        if (turn){ // n == 0 and turn is true, i,e its now player 'a' turns, that means a has lost
            return false;
        }
        return true; // n== 1 and turn == 0, player b turn, a has won
    }
    bool res;
    if (turn){ //player a turn
        res = f(n-1, !turn, x, y);

        if (x <= n)
            res =  res || f(n-x, !turn, x, y);
        if (y <= n)
            res = res || f(n-y, !turn, x, y);
        
        return res;
    }else{ 
        //player b turn

        res = f(n-1, !turn, x, y);

        if (x <= n)
            res = res && f(n-x, !turn, x, y);
        if (y <= n)
            res = res && f(n-y, !turn, x, y);
        
        return res;
    }
}

int dpSol(int n, int x, int y){

    int dp[n+1][2];

    //base case
    dp[0][0] = true; //true when its n== 0 and its b turn
    dp[0][1] = false; //fasle when its n == 0 and its a turn

    for (int i=1;i<=n;i++){
        //A's turn

        dp[i][1] = dp[i-1][0];
        if (x<=i)
            dp[i][1] = dp[i][1] || dp[i-x][0];
        if (y<=i)
            dp[i][1] = dp[i][1] || dp[i-y][0];


        //B's turn

        // take_1 = dp[i-1][1];
        dp[i][0] = dp[i-1][1];
        if (x <= i){
            dp[i][0]  = dp[i][0] && dp[i-x][1];
        }
        if (y <= i)
            dp[i][0] = dp[i][0] && dp[i-y][1];
        
    }

    return dp[n][1];

}

//even better solution

int dpSol2(int n, int x, int y){

    //basically in this we eliminate the turn variable, 
    // dp[n] = true or false means thats whosever ever turn it is at n coint will win or lose the game respectively
    //here we take advantage of the fact that its player a's turn first
    bool dp[n+1];
    //base case
    dp[0] = false;
    dp[1] = true;

    for (int i=2;i<=n;i++){
        //after picking 'c' coins it will be 'b' turns
        //so if in any of i-c b losses then a wins 
        dp[i] = (dp[i-1] == 0); //pick one coin
        if (x <= i)
            dp[i] = dp[i-x] == 0;
        if (y <= i)
            dp[i] = dp[i-y] == 0;
    }
    return dp[n];

}

int main(){

    cout << f(5, true, 4, 3) << endl;
    cout << dpSol(5, 4, 3) << endl;
    cout << dpSol2(5, 4, 3) << endl;
    return 0;
}