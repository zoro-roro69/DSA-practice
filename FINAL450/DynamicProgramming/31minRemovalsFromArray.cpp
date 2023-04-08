#include  <bits/stdc++.h>
using namespace std;

// Given an array arr[] of size N and an integer K. The task is to find the minimum number 
// of elements that should be removed, such that Amax-Amin<=K. After the removal of 
// elements, Amax and Amin is considered among the remaining elements. 

int f(int i, int j, int &k, vector <int> &arr){

    //base case pending

    if (arr[j] - arr[i] <= k)
        return 0;

    int removing_front = f(i+1, j, k, arr);
    int removing_last = f(i, j-1, k, arr);

    return min(removing_front, removing_last);
}

int dpSol(int k, vector <int> &arr){
    int n = arr.size();
    int dp[n][n];

    //base case
    //if j<=i return 0
    for (int i = 0; i<n;i++){
        for (int j=i;j>=0;j--){
            dp[i][j] = 0;
        }
    }

    for (int i=n-2;i>=0;i--){
        for (int j=i+1;j<n;j++){
            if (arr[j]-arr[i] <= k)
                dp[i][j] = 0;
            else{
                int removing_front = dp[i+1][j];
                int removing_last = dp[i][j-1];

                dp[i][j] = 1 + min(removing_front, removing_last);
            }
        }
    }

    return dp[0][n-1];

}

int main(){


    return 0;
}