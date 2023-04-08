#include <bits/stdc++.h>
using namespace std;
// Given a height h, count the maximum number of balanced binary trees possible with height h. 
// Print the result modulo 109 + 7.
int f(int n){
    if (n <= 1)
        return 1;

    return f(n-1)*f(n-1) + 2*(f(n-1)*f(n-2));

}

const int MOD = 1000000007;

long long countBalancedBinaryTrees(int n){

    long long dp[n+1];
    dp[0] = dp[1] = 1;

    for (int i=2;i<=n;i++){
        dp[i] = ((dp[i-1]*dp[i-1])%MOD + (2*(dp[i-1]*dp[i-2])%MOD)%MOD)%MOD;
    }

    return dp[n];

}
   

int main(){


    return 0;
}