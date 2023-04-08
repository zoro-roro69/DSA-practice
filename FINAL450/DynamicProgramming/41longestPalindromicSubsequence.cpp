#include <bits/stdc++.h>
using namespace std;


int longestPalindromicSubsequence(string s){
    int n = s.size();
    string s2 = s;
    reverse(s2.begin(), s2.end());

    int dp[n+1][n+1];
    //base case i<0 return 0;
    for (int j=0;j<=n;j++){
        dp[0][j] = 0;
    }
    //base case j<0 return 0;
    for (int i=0;i<=n;i++){
        dp[i][0] = 0;
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (s[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][n];


}

int f(int i, int j, string &s){
    if (i == j)
        return 1;
    if (i>j)
        return 0;
    
    if (s[i] == s[j])
        return 2 + f(i+1, j-1, s);
    
    return max(f(i+1, j, s), f(i, j-1, s));
    
}

int f2(string s){
    int n = s.size();

    int dp[n][n];

    //base case i==j return 1;
    for (int i=0;i<n;i++)
        dp[i][i] = 1;

    //base case i>j return 0;
    for (int i=0;i<n;i++){
        for (int j=i-1;j>=0;j--){
            dp[i][j] = 0;
        }
    }
    int res = 1;

    for (int i= n-1;i>=0;i--){
        for (int j = i+1;j<n;j++){
                int len = j-i+1;
                dp[i][j] = 0;
                if (s[i] == s[j]){
                    if (len > 2 )
                        dp[i][j] = 2 + dp[i+1][j-1];
                    else if (len<=2){
                        dp[i][j] = len;
                    }
                }

                if (i+1 < n)
                    dp[i][j] = max(dp[i][j], dp[i+1][j]);
                if (j-1 >= 0)
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }

    return max(res, dp[0][n-1]);
}

int main(){


    return 0;
}