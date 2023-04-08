#include <bits/stdc++.h>
using namespace std;

// Given an array arr[] of size N, check if it can be partitioned into two parts such that the 
// sum of elements in both parts is the same

bool f(int i, int sum_, int arr[]){
    if (sum_ == 0)  //reqd sum achieved
        return true;
    if (i < 0)
        return false;

    bool including = false;
    bool excluding = false;
    if (arr[i] <= sum_)
        including = f(i-1, sum_ - arr[i], arr);

    excluding = f(i-1, sum_, arr);

    return including || excluding;

}


int dpSol(int n, int arr[]){
    int sum_ = 0;
    for (int i=0;i<n;i++)
        sum_ += arr[i];

    cout << sum_ << endl;

    if (sum_ % 2) //sum is odd 
        return false;
    
    sum_ /= 2; //this is the sum we need to achieve

    bool dp[n+1][sum_+1];
    //base case
    // sum_== 0 return true
    for (int i=0;i<=n;i++)
        dp[i][0] = true;

    //base case i<0 return false
    for (int j=1;j<=sum_;j++)
        dp[0][j] = false;

    for (int i=1;i<=n;i++){
        for (int j=1;j<=sum_;j++){
            bool including = false;
            bool excluding = false;

            if (arr[i-1] <= j)
                including = dp[i-1][j-arr[i-1]];
            excluding = dp[i-1][j];

            dp[i][j] = including || excluding;
        }
    }

    return dp[n][sum_];


}


int main(){
    int n = 11;
    int arr[] = {899, 74, 789, 978, 133, 957, 690, 114, 9, 942, 791};

    cout << dpSol(n, arr) << endl;
    return 0;
}