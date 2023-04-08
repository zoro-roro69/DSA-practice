#include <bits/stdc++.h>
using namespace std;

int f(int i, int w, int wt[], int val[]){

    if (i<0 || w<=0)
        return 0;

    int including = 0;
    int excluding = 0;

    if (wt[i] <= w)
        including = val[i] + f(i, w-wt[i], wt, val);
    
    excluding = f(i-1, w, wt, val);

    return max(including, excluding);

}


int knapSack(int n, int w, int val[], int wt[]){
    int dp[n+1][w+1];

    //base case i<0 return 0;
    for (int j=0;j<=w;j++)
        dp[0][j] = 0;

    //base case w<=0 return 0;
    for (int i=0;i<=n;i++)
        dp[i][0] = 0;

    for (int i=1;i<=n;i++){
        for (int j=1;j<=w;j++){
            int including = 0;
            int excluding = 0;
            if (wt[i-1] <= j){
                including = val[i-1] + dp[i][j-wt[i-1]];
            }
            excluding = dp[i-1][j];

            dp[i][j] = max(including, excluding);
        }
    }

    return dp[n][w];

}


int main(){


    return 0;
}