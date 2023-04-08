#include <bits/stdc++.h>
using namespace std;
//Given a rod of length N inches and an array of prices, price[] that contains prices 
// of all pieces of size smaller than N. Determine the maximum value obtainable by cutting 
// up the rod and selling the pieces.


//similar to previous problems
// we can treat as find subsetsum problem where given the array and sum we need to find the subset which sums 
// to that sum
// in this case our array will be array of lengths {1,2,3...n} and our target will be n itself
// so from the array we need such pieces that sum n .
// also we need to find such a subset which has maximum value/prices
// so we return max(including, excluding)

int f(int i, int target, vector <int> &prices){
    if (target == 0)
        return 0;
    if (i == 0){
        if (i+1 <= target)
            return prices[i] + f(i, target-(i+1), prices);
        return 0;
    }

    int excluding = f(i-1, target, prices);
    int including = 0;
    if (i+1 <= target)
        including = prices[i] + f(i, target-(i+1), prices); //staying at same index, because we can take same piece again

    return max(including, excluding);
}


int rodCuttingDp(int price[], int n){
    if (n == 0)
        return 0;

    int dp[n][n+1];

    for (int i=0;i<n;i++){
        for (int j=0; j<=n; j++){
            dp[i][j] = 0;
        }
    }

    //base case
    for (int i=1;i<=n;i++){
        dp[0][i] = dp[0][i-1] + price[0];
    }


    for (int i=1; i<n;i++){
        for (int j=1;j<=n;j++){
            int excluding = dp[i-1][j];
            int including = 0;

            if (i+1 <= j){
                including = dp[i][j - (i+1)] + price[i];
            }
            dp[i][j] = max(including, excluding);
        }
    }

    return dp[n-1][n];
}

int main(){
    vector <int> arr {3, 5, 8, 9, 10, 17, 17, 20};
    int price[] = {3, 5, 8, 9, 10, 17, 17, 20};
    // cout << f(arr.size()-1, arr.size(), arr) << endl;
    cout << rodCuttingDp(price, 8) << endl;

    return 0;
}