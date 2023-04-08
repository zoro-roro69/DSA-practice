#include <bits/stdc++.h>
using namespace std;

//similar to previous two problems



// given an array of integers and a target value we need to find number of subsets 
// that sum to that target value
//this wont work if array contains 0 values
int recursive(int i, int target, vector <int> v){
    if (target == 0)
        return 1;
    if (i == 0)
        return v[0] == target;
    
    int excluding = recursive(i-1, target, v);
    int including = 0;
    if (v[i] <= target)
        including = recursive(i-1, target-v[i], v);

    return including + excluding;
}

//if array contains 0 values
int f(int i, int target, vector <int> v){

    if (i == 0){
        if (target == 0 && v[i] == 0)  return 2;
        if (target == 0 || v[i] == target) return 1;

        return 0;
    }

    int excluding = recursive(i-1, target, v);
    int including = 0;
    if (v[i] <= target)
        including = recursive(i-1, target-v[i], v);

    return including + excluding;
}

// NOTE- this solution works only for positive integers,
// in case we have -ve integers then dont use matrix use map/unordered map :)

// also this wont work when we have 0's in array like - {0,0,1} target = 1, result should be 4 but this gives 1
//dp solution can be space optimised
int countSubsets(vector <int> arr, int k){
    int n = arr.size();
    if (n == 0)
        return 0;

    int dp[n][k+1];

    for (int i=0;i<n;i++){
        for (int j=0;j<=k;j++)
            dp[i][j] = 0;
    }
    //base case, when target == 0
    for (int i=0;i<n;i++)
        dp[i][0] = 1;
    
    //base case
    if (arr[0] <= k)
        dp[0][arr[0]] = 1;

    for (int i=1;i<n;i++){
        for (int j=1;j<=k;j++){
            //excluding
            dp[i][j] = dp[i-1][j];

            //including
            if (arr[i] <= j){
                dp[i][j] += dp[i-1][j-arr[i]];
            }
        }
    }
    return dp[n-1][k];
}


int main(){
    vector <int>  arr{0,0,1};

    // cout << recursive(3, 6, arr) << endl;
    cout << countSubsets(arr, 1) << endl;

    return 0;
}