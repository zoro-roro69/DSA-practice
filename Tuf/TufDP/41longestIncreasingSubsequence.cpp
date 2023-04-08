#include <bits/stdc++.h>
using namespace std;

//can be done in nlogn using binary search



// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// A subsequence is a sequence that can be derived from an array by deleting some or no elements without
//  changing the order of the remaining elements. For example, [3,6,2,7] is a 
// subsequence of the array [0,3,1,6,2,2,7].

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.


//we can apply memoization here
int f(int i, int prev, vector <int> &arr){
    if (i>=arr.size())
        return 0;

    int including = 0;
    int excluding = 0;

    if (prev == -1 || arr[i] > arr[prev])
        including = 1 + f(i+1, i, arr);

    excluding = f(i+1, prev, arr);

    return max(including, excluding);

}


//this can be space optimised as we just need next rwo
int lisDP(vector <int> &arr){
    int n = arr.size();
    if (n == 0)
        return 0;

    int dp[n+1][n+1]; //second parameter is in +1 state (coordinate shift)
    
    // for (int i=0;i<=n;i++){
    //     for (int j=0;j<=n;j++)
    //         dp[i][j] = 0;
    // }

    //base case
    for (int j=0;j<=n;j++)
        dp[n][j] = 0;

    for (int i=n-1;i>=0;i--){
        for (int j=i-1;j>=-1;j--){

            int including = 0;
            int excluding = 0;

            if (j == -1 || arr[i] > arr[j])
                including = 1 + dp[i+1][i+1];

            excluding = dp[i+1][j+1];
            dp[i][j+1] = max(including, excluding);
            
        }
    }

    return dp[0][0];

}

int lisDp2(vector <int> arr){


    int n = arr.size();
    if (n == 0)
        return 0;

    vector <int> cur(n+1, 0);
    vector <int> ahead(n+1, 0);


    for (int i=n-1;i>=0;i--){
        for (int j=i-1;j>=-1;j--){

            int including = 0;
            int excluding = 0;

            if (j == -1 || arr[i] > arr[j])
                including = 1 + ahead[i+1];

            excluding = ahead[j+1];
            cur[j+1] = max(including, excluding);
            
        }
        //ahead to cur
        for (int j=0;j<=n;j++){
            ahead[j] = cur[j];
        }
    }

    return cur[0];


}

//a better dp solution

int lisDp3(vector <int> arr){
    int n = arr.size();
    if (n == 0)
        return 0;

    int dp[n];
    for (int i=0;i<n;i++)
        dp[i] = 1;
    
    int res = 1;
    for (int i=1;i<n;i++){
        
        for (int j=i-1;j>=0 && j+1>=dp[i];j--){
            if (arr[i] > arr[j])
                dp[i] = max(1 + dp[j], dp[i]);
                
            
        }
        res = max(res, dp[i]);
    }

    return res;
}

int main(){


    return 0;
}