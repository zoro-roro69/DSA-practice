#include <bits/stdc++.h>
using namespace std;

// Given an array A[] of size N, find the longest subsequence such that difference between adjacent elements is one.


int longestSubsequenceWithDiffOne(int n, int arr[]){
    if (n<=1)
        return n;

    int dp[n];
    for (int i=0;i<n;i++){
        dp[i] = 1;
    }

    int res = 1;
    for (int i=1;i<n;i++) {
        for (int j=0;j<i;j++){
            if (abs(arr[i]-arr[j]) == 1 && dp[j]+1 > dp[i]){
                dp[i] = dp[j]+1;
            }
        }
        res = max(res, dp[i]);
    }

    return res;
}


int main(){


    return 0;
}