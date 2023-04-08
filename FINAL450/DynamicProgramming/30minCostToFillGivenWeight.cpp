#include <bits/stdc++.h>
using namespace std;

// Given an array cost[] of positive integers of size N and an integer W, cost[i] represents the cost of ‘i’ kg packet of oranges, the task is to find the minimum cost to buy W kgs of oranges. If it is not possible to buy exactly W kg oranges then the output will be -1
// Note:
// 1. cost[i] = -1 means that ‘i’ kg packet of orange is unavailable
// 2. It may be assumed that there is infinite supply of all available packet types.


int f(int i, int w, int cost[]){
    if (w==0)
        return 0;
    if (i<0){ //w is not 0
    //  cout << "here" <<endl;
        return INT_MAX;
    }

    int including = INT_MAX;
    int exlcuding = INT_MAX;

    if (cost[i]!=-1 && i+1 <= w){
        int res = f(i,w-(i+1), cost);
        if (res != INT_MAX)
            including = cost[i] + f(i, w - (i+1), cost);
        
    }

    exlcuding = f(i-1, w, cost);

    return min(including, exlcuding);
}

int dpSol(int cost[], int n, int w){

    int dp[n+1][w+1];

    //base case, w == 0, return 0
    for (int i=0;i<=n;i++){
        dp[i][0] = 0;
    }

    //base case, i < 0 && w!= 0
    for (int j=1;j<=w;j++){
        dp[0][j] = INT_MAX;
    }


    for (int i=1;i<=n;i++){
        for (int j=1;j<=w;j++){
            int including = INT_MAX;
            int excluding = INT_MAX;

            if (cost[i-1] != -1 && i <= j){
                if (dp[i][j-i]!=INT_MAX){
                    including = cost[i-1] + dp[i][j-i];
                }
            }
            excluding = dp[i-1][j];
            dp[i][j] = min(including, excluding);
        }
    }

    return dp[n][w];
}



int main(){


    return 0;
}