#include <bits/stdc++.h>
using namespace std;

// Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.
// The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B

int f(int i, int j, string s){
    //base case pending
    if (i < 0 || j < 0)
        return 0;

    if (i!=j && s[i] == s[j])
        return 1 + f(i-1,j-1, s);
    else    
        return max(f(i,j-1,s), f(i-1, j, s));

}

int dpLongestRepeatingSubsequence(string s){

    int n = s.size();
    int dp[n+1][n+1]; //one shifted index

    //base case i < 0
    for (int j=0;j<=n;j++)
        dp[0][j] = 0;

    //base case j < 0
    for (int i=0;i<=n;i++)
        dp[i][0] = 0;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i!=j && s[i] == s[j]){
                dp[i+1][j+1] = 1 + dp[i-1+1][j-1+1];
            }else
                dp[i+1][j+1] = max(dp[i-1+1][j+1], dp[i+1][j+1-1]);
        }
    }
    return dp[n][n];
}

int main(){



    return 0;
}