#include <bits/stdc++.h>
using namespace std;

// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an 
// integer fee representing a transaction fee.
// Find the maximum profit you can achieve. You may complete as many transactions as you like, 
// but you need to pay the transaction fee for each transaction.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before 
// you buy again).

// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8

int f(int i, int buy, vector <int> &prices, int fee){
    if (i>=prices.size())
        return 0;
    
    if (buy){ //we can buy here

        return max(
            f(i+1, 0, prices, fee) - prices[i], //we buy here
            f(i+1, 1, prices, fee) - 0 //we dont buy here
        );

    }else{ //we sell here


        return max(
            f(i+1, 1, prices, fee) + prices[i] - fee, //we sold here, so add prices[i]
            f(i+1, buy, prices, fee) //we did not sell here
        );
    }
}

//dp solution
int maxProfit(vector <int> prices, int fee){
    int n = prices.size();

    if (n == 0)
        return 0;

    int dp[n+1][2];

    //base case i>=n
    dp[n][0] = dp[n][1] = 0;

    for (int i=n-1;i>=0;i--){
        //we can buy here
        dp[i][1] = max(
            dp[i+1][0] - prices[i], //we buy here
            dp[i+1][1] - 0 //we dont buy
        );

        dp[i][0] = max(
            dp[i+1][1] + prices[i] - fee, //we sell here
            dp[i+1][0] + 0 //we dont sell here
        );
    }

    return dp[0][1];
}


int main(){
    return 0;
}