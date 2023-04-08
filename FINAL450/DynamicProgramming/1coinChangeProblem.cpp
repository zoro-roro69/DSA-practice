#include <bits/stdc++.h>
using namespace std;

//recursive solution 

//S is array of coins
//m is current coin/index
//n is the sum or change to be formed
//at each coin we have two options whether to include it or exclude it from our soultion
// Let count(S[], m, n) be the function to count the number of solutions, then it can be written
//  as sum of count(S[], m-1, n) "not included" and count(S[], m, n-Sm) "included".
// Therefore, the problem has optimal substruc

int count(int S[], int m, int n){
    if (m <= 0)
        return 0;

    if (n < 0)
        return 0;
    else if(n == 0){ //sum is formed
        return 1;
    }else{

        return count(S, m-1, n) + count(S, m-1, n-S[m]);

    }

}

//Time - O(mn)
//Space - O(mn)
int count2(int S[], int m, int n){

    int dp[m][n+1];

    for (int i = 0; i<m;i++){
        dp[i][0] = 1; //only one way to form sum '0' i.e bu excluding current element
    }

    for (int i=0;i<m;i++){
        for (int j=1;j<=n;j++){
            int sum_without_including = 0;
            int sum_with_including = 0;
            if (i-1>=0)
                sum_without_including = dp[i-1][j];

            if (j - S[i] >= 0)
                sum_with_including = dp[i][j-S[i]];

            dp[i][j] = sum_with_including + sum_without_including;
        }
    }

    return dp[m-1][n];
}

//bettern solution space - O(n)
//as we notice aboce we are just using the previous row of the table and not before that
int count3(int S[], int m, int n){

    int dp[n+1] = {0};
    dp[0] = 1;

    for (int i=0;i<m;i++){
        for (int j=1;j<=n;j++){
            int sum_without_including = 0;
            int sum_with_including = 0;

            sum_without_including = dp[j];

            if (j - S[i] >= 0)
                sum_with_including = dp[j - S[i]];

            dp[j] = sum_without_including + sum_with_including;
        }
    }

    return dp[n];

}



/////coin change with no repition allowed 

//recurssive
int countNoReps(int S[], int m, int n){
    if (m < 0 || n < 0)
        return -1;
    if (n == 0)
        return 1;
    
    return countNoReps(S, m-1, n-S[m]) + countNoReps(S, m-1, n);

}

//bottom up

int countNoReps2(int S[], int m, int n){
    // n is the sum/change we need to make
    int dp[m][n+1];

    for (int i=0;i<m;i++)
        dp[i][0] = 1;

    
    for (int i=0;i<m;i++){
        for (int j=1;j<=n;j++){
            int sum_with_including = 0;
            int sum_without_including = 0;

            if (i-1 >=0 && j-S[i]>=0)
                sum_with_including = dp[i-1][j-S[i]];
            if (i-1>=0)
                sum_without_including = dp[i-1][j];

            dp[i][j] = sum_with_including + sum_without_including;
        }
    }

    return dp[m][n+1];

}

//coin change but we need to find the minimum number coins reqd to make the change
// repition allowed

class Solution {
public:
    int coinChangeRec(vector <int> &coins, int n, int amount){
        if (n<0 || amount < 0)
               return INT_MAX;
        if (amount == 0)
                return 0;
        
        int without_including = coinChangeRec(coins, n-1, amount);
        
        int with_including = coinChangeRec(coins, n, amount-coins[n]);
        
        if (with_including != INT_MAX)
            with_including += 1;
        
        return min(with_including, without_including);
        
    }
    
    int coinChangeDP(vector <int> &coins, int amount){
        int n = coins.size();
        int dp[n][amount+1];
        for (int i=0;i<n;i++){
            for (int j=0;j<=amount;j++)
                dp[i][j] = 0;
        }
        
        for (int i=0;i<coins.size();i++){
            for (int j=1;j<=amount;j++){
                int without_including = INT_MAX;
                int with_including = INT_MAX;
                
                if (i-1>=0)
                    without_including = dp[i-1][j];
                
                if (j - coins[i] >= 0)
                    with_including = dp[i][j-coins[i]];

                if (with_including != INT_MAX)
                    with_including +=1;
                
                dp[i][j] = min(with_including, without_including);
                
            }
        }
        if (dp[coins.size()-1][amount] == INT_MAX)
            return -1;
        return dp[coins.size()-1][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int res = coinChangeDP(coins, amount);
        
        if (res == INT_MAX)
               return -1;
        return res;
    }
};




int main (){


    return 0;
}