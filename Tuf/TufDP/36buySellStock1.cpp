#include <bits/stdc++.h>
using namespace std;

// The cost of a stock on each day is given in an array, find the max profit that you can make
//  by buying and selling in those days. For example, if the given array is 
// {100, 180, 260, 310, 40, 535, 695}, the maximum profit can earn by buying on day 0, selling on day 3.
//  Again, buy on day 4 and sell on day 6. If the given array of prices is sorted in decreasing order, 
// then profit cannot be earned at all.

int maxProfit(int stocks[], int n){
    if (n == 0)
        return 0;
    int res = 0;

    int buy = stocks[0];

    for (int i=1;i<n;i++){
        if (stocks[i] <= buy){
            buy = stocks[i];
        }else{
            res += stocks[i] - buy;
            buy = stocks[i];
        }
    }

    return res;

}

//recursive solution
int f(int i, bool buy, int prices[], int n){
    if (i >= n){
        return 0;
        
    }
    
    if (buy){ //we can buy here
        return max(
            f(i+1, 0, prices, n) - prices[i], //we bought here, so subtract prices[i]
            f(i+1, 1, prices, n) //we did not buy here
        );
    }else{ //we can sell here
        return max(
            f(i+1, 1, prices, n) + prices[i], //we sold here, so add prices[i]
            f(i+1, buy, prices, n) //we did not sell here
        );
    }

}


//dp solution
// this can be space optimised using cur and prev arrays
int maxProfitDp(int prices[], int n){
    if (n == 0)
        return 0;

    int dp[n+1][2];


    //base case
    dp[n][0] = dp[n][1] = 0;

    for (int i=n-1;i>=0;i--){
        int profit = 0;
        //buy == 1, you can buy here
        profit = max(
            dp[i+1][0] - prices[i], // we buy here
            dp[i+1][1] - 0 //we dont buy here
        );

        dp[i][1] = profit;

        //buy == 0, we can sell here
        profit = max(
            dp[i+1][1] + prices[i], //we sell here
            dp[i+1][0] + 0 //we dont sell here
        );

        dp[i][0] = profit;

    }

    return dp[0][1];


}

int main(){
    int arr[] = {100, 180, 260, 310, 40, 535, 695};

    cout << maxProfit(arr, 7) << endl;

    return 0;
}