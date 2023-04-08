#include <bits/stdc++.h>
using namespace std;

// Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
// The efficient way is the one that involves the least number of multiplications.

// The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) 
// where the ith matrix has the dimensions (arr[i-1] x arr[i]).

// Input: N = 5
// arr = {40, 20, 30, 10, 30}
// Output: 26000
// Explaination: There are 4 matrices of dimension 
// 40x20, 20x30, 30x10, 10x30. Say the matrices are 
// named as A, B, C, D. Out of all possible combinations,
// the most efficient way is (A*(B*C))*D. 
// The number of operations are -
// 20*30*10 + 40*20*10 + 40*10*30 = 26000.


int f(int i, int j, vector <int> &arr){

    if (i == j)
        return 0;

    int res = INT_MAX;
    for (int k=i;k<j;k++){
        int res1 = f(i, k, arr);
        int res2 = f(k+1, j, arr);
        int cost = arr[i-1]*arr[k]*arr[j];
        
        res = min(res, res1 + res2 + cost);
    }

    return res;
}


int mcmDP(vector <int> &arr){
    int n = arr.size(); //n=number of matrices
    if (n == 0)
        return 0;

    int dp[n+1][n+1];

    //base case i == j: return 0;
    for (int i =0; i<=n;i++){
        dp[i][i] = 0;
    }
    
    for (int i=n-1;i>=1;i--){
        for (int j=i+1;j<=n;j++){
            dp[i][j] = INT_MAX;
            for (int k=i;k<j;k++){
                int cost = arr[i-1]*arr[k]*arr[j];
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + cost);
            }
        }
    }

    return dp[1][n];
}

int main(){


    return 0;
}