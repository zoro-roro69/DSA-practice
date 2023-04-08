#include <bits/stdc++.h>
using namespace std;
//you can make maximum of two transactions

//this solution does not work :P
int maxProfit(int stocks[], int n){
    if (n == 0)
        return 0;
    
    int peak1 = 0;
    int peak2 = 0;

    int buy = stocks[0];

    int res = 0;
    for (int i=1;i<n;i++){
        if (stocks[i] <= buy){
            buy = stocks[i];
            //bottom
            if (peak1 == 0){
                peak1 = res;
            }else if (peak2 == 0){
                peak2 = res;
            }else {
                if (res > peak1){
                    peak2 = peak1;
                    peak1 = res;
                }else if (res > peak2){
                    peak2 = res;
                }

            }

            res = 0;
        }else{
            res += stocks[i] - buy;
            buy = stocks[i];
        }
    }

    return peak1+peak2;

}


//recursion
//cap = number of transactions
int f(int i, bool buy, int cap, int prices[], int n){
    if (i>=n)
        return 0;
    if (cap<=0)
        return 0;

    if (buy){ //we can buy here
        return max(
            f(i+1, 0, cap, prices, n) - prices[i], //we buy here
            f(i+1, 1, cap, prices, n) - 0 //we dont buy here
        );
    }else{ //we can sell here
        return max(
            f(i+1, 1, cap-1, prices, n) + prices[i], //we sell here, one transaction occured
            f(i+1, 0, cap, prices, n) + 0 //we dont sell here
        );
    }
}

//dp
int maxProfitWithLimitDP(int prices[], int n, int transaction_limit){
    if (n == 0)
        return 0;

    int dp[n+1][2][transaction_limit+1];

    //base case
    for (int l=0;l<=transaction_limit;l++){
        dp[n][0][l] = dp[n][1][l] = 0;
    }

    //base case
    for (int i=0;i<=n;i++){
        dp[i][0][0] = dp[i][1][0] = 0;
    }


    for (int i=n-1;i>=0;i--){
        for (int j=0;j<=1;j++){
            for (int k=1;k<=transaction_limit;k++){
                if (j){ //we can buy here
                    dp[i][j][k] = max(
                        dp[i+1][0][k] - prices[i], //we buy here
                        dp[i+1][1][k] - 0 //we dont buy here
                    );
                }else{//we can sell here
                    dp[i][j][k] = max(
                        dp[i+1][1][k-1] + prices[i], //we sell here
                        dp[i+1][0][k] + 0 //we dont sell here
                    );
                }
            }
        }
    }

    return dp[0][1][transaction_limit];
}

//even more space optimised
int maxProfitDp2(int prices[], int n, int transaction_limit){
    if (n == 0)
        return 0;

    int after[2][transaction_limit+1];
    int cur[2][transaction_limit+1];

    //base case, i == n
    for (int l=0;l<=transaction_limit;l++){
        after[0][l] = after[1][l] = 0;
    }

    //base case, cap == 0
    after[0][0] = cur[1][0] = 0;


    for (int i=n-1;i>=0;i--){
        for (int j=0;j<=1;j++){ //2
            for (int k=1;k<=transaction_limit;k++){ //3
                if (j){ //we can buy here
                    cur[j][k] = max(
                        after[0][k] - prices[i], //we buy here
                        after[1][k] - 0 //we dont buy here
                    );
                }else{//we can sell here
                    cur[j][k] = max(
                        after[1][k-1] + prices[i], //we sell here
                        after[0][k] + 0 //we dont sell here
                    );
                }
            }
        }

        //assgn ahead = cur
        for (int j=0;j<=1;j++){
            for (int k=1;k<=transaction_limit;k++){
                after[j][k] = cur[j][k];
            }
        }
    }

    return cur[1][transaction_limit];

    
}



int main(){
    return 0;
}