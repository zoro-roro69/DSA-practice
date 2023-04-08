#include <bits/stdc++.h>
using namespace std;

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

int f(int i, bool buy, vector <int> &prices){
    if (i>=prices.size())
        return 0;

    if (buy){ //we can buy here
        return max(
            f(i+1, 0, prices) - prices[i], //we buy here
            f(i+1, 1, prices) - 0 //we dont buy here
        );

    }else{ //we can sell here
        return max(
            f(i+2, 1, prices)  + prices[i], //we sell here
            f(i+1, 0, prices) + 0 //we dont sell here
        );
    }

}


//dp solution

int maxProfitdp(vector <int> prices){
    int n = prices.size();
    if (n == 0)
        return 0;

    int dp[n+1][2];

    //base case i>=n
    dp[n][0] = dp[n][1] = 0;

    for (int i=n-1;i>=0;i--){
        for (int j=0;j<=1;j++){
            if (j){//we can buy here
                dp[i][j] = max(
                    dp[i+1][0] - prices[i], //we buy here
                    dp[i+1][1] - 0 //we dont buy
                );
            }else{//we can sell here
                dp[i][j] = max(
                    dp[min(i+2,n)][1] + prices[i], //we sell here
                    dp[i+1][0] + 0 //we dont sell here
                );
            }
        }
    }

    return dp[0][1];
}

int main(){


    return 0;
}