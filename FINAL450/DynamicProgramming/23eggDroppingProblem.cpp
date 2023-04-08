#include <bits/stdc++.h>
using namespace std;


int f(int i, int j, int n){
    //base case pending
    if (j < i)
        return 0;

    if (n == 1)
        return j - i + 1;
    
    if (i == j)
        return 1;

    int res = INT_MAX;

    for (int k=i+1;k<j;k++){
        int egg_breaks = f(i, k-1, n-1);
        int egg_doesnt_break = f(k+1, j, n);

        int ans = 1 + max(egg_breaks, egg_doesnt_break);
        res = min(res, ans);
    }

    return res;
}


int f2(int n, int k){
    //base case pending
    if (k <= 0)
        return 0;
    if (k == 1)
        return 1;
    if (n == 1)
        return k;

    int res = INT_MAX;
    for (int i=0;i<k;i++){
        int egg_breaks = f2(n-1, i-1+1);
        int egg_doesnt_break = f2(n, k-i-1);
        int ans = 1 + max(egg_breaks, egg_doesnt_break);

        res = min(ans, res);
    }

    return res;
}


int dp(int n, int K){
    int dp[n+1][K+1];

    //for k<=0
    for (int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    ///k == 1
    for (int i=0;i<=n;i++){
        dp[i][1] = 1;
    }
    // n == 1
    for (int j=0;j<=K;j++){
        dp[1][j] = j; 
    }


    for (int i=2;i<=n;i++){
        for (int j=2;j<=K;j++){
            dp[i][j] = INT_MAX;

            for (int k=2;k<=j;k++){
                int egg_breaks = dp[i-1][k-1];
                int egg_doesnt_break = dp[i][j-k];
                int ans = 1 + max(egg_breaks, egg_doesnt_break);

                dp[i][j] = min(dp[i][j], ans); 
            }
        }
    }


    return dp[n][K];
}

int main(){

    return 0;
}