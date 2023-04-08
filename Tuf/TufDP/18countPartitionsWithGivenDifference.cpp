#include <bits/stdc++.h>
using namespace std;

// We are given an array ‘ARR’ with N positive integers and an integer D.
// We need to count the number of ways we can partition the given array into two subsets,
//  S1 and S2 such that S1 – S2 = D and S1 is always greater than or equal to S2.


//so basically we can transform this question into previous one i.r finding all subsets that sum to given
//target
// lets say the sum of two partitions are X and Y
// so what we need to satisy is this :
// X - Y = D (D == reqd difference) --- let this be eq1
// we also know 
// X + Y = S (s == total sum of array) -- let this be eq2
// add eq1 and eq 2
// 2X = S+D
// X = (S+D)/2;

// so now basically we need to find all the subsets that sum to (S+D)/2

int f(int i, int target, vector <int> &v){
    if (i == 0){
        if (target == 0 && v[i] == 0) return 2; //two ways since including or excluding v[i] wont make any difference
        if (target == 0 || v[i] == target) return 1; //one for each

        return 0;
    }

    int excluding = f(i-1, target, v);
    int including = 0;
    if (v[i] <= target){
        including = f(i-1, target-v[i], v);
    }

    return including + excluding;

}

//can be space optimised firther 
int countPartitionsWithGivenDiff(vector <int> arr, int D){
    int n = arr.size();
    if (n == 0) return 0;

    int S = 0;
    for (auto x:arr)
        S += x;
    
    if (D>S) return 0; //difference cannot be greater than total sum

    if ((S+D)%2) return 0;

    int target = (S+D)/2;
    
    // return f(n-1, target, arr);
    int dp[n][target+1];
    dp[0][0] = 1;
    if (arr[0] <= target){
        dp[0][arr[0]] = 1;
        if (arr[0] == 0)
            dp[0][0] = 2;
    }

    for (int i=1;i<n;i++){
        for (int j=1;j<=target;j++){
            int excluding = dp[i-1][j];
            int including = 0;
            if (arr[i] <= j)
                including = dp[i-1][j-arr[i]];
            dp[i][j] = including + excluding;
        }

    }

    return dp[n-1][target];

}


