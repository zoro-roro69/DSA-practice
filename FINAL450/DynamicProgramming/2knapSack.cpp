#include <bits/stdc++.h>
using namespace std;


//recursive
//again including - exlcuding type solution
int knapsack(int W, int wt[], int val[], int n){
    if (n<0)
        return 0;

    int including_cur = 0;
    if (W >= wt[n])
        including_cur = val[n] + knapsack(W-wt[n], wt, val, n-1);

    int excluding_cur = knapsack(W, wt, val, n-1);

    return max(including_cur, excluding_cur);
}

//dp
//here space complexity can be improved, as at every step we are using 
// previous two rows only
int knapsack2(int W, int wt[], int val[], int n){


    int dp[n][W+1] = {0};

    for (int i=0;i<n;i++){
        for (int j=1;j<=W;j++){
            int excluding_cur = 0;
            int including_cur = 0;
            
            excluding_cur = i-1 >=0 ? dp[i-1][j] : 0;
            if (j>=wt[i]){
                including_cur = val[i];
                if (i-1>=0){
                    including_cur += dp[i-1][j-wt[i]];
                }
            }

            dp[i][j] = max(excluding_cur, including_cur);
        }
    }

    return dp[n-1][W];
}


//even more optimized space
int knapSack(int W, int wt[], int val[], int n)
{
    // making and initializing dp array
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i < n + 1; i++) {
        for (int w = W; w >= 0; w--) {
 
            if (wt[i - 1] <= w)
                // finding the maximum value
                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W]; // returning the maximum value of knapsack
}


int main(){


    return 0;
}