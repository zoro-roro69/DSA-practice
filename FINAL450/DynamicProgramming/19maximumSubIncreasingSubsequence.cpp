#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector <int> &arr){
    //base case pending
    if (i < 0)
        return 0;

    int including = 0;
    int exlcuding = 0;
    if (arr[i] < arr[j]){
        including = arr[i] + f(i-1, i, arr);
    }
    exlcuding = f(i-1, j, arr);

    return max(including, exlcuding);

}

int dpSol(int arr[], int n){

    int dp[n+2][n+2]; 

    //base case
    for (int j=0;j<=n+1;j++)
        dp[0][j] = 0;

    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n+1;j++){
            int including = 0;
            int excluding = 0;
            if (j==n+1 || arr[i-1] < arr[j-1]){
                including = arr[i-1] + dp[i-1][i];
            }
            excluding = dp[i-1][j];
            dp[i][j] = max(including, excluding);
        }
    }

    return dp[n][n+1];


}

//space optimised solution

int dpSol2(int arr[], int n){

    int dp[n];

    // for (int i=0;i<n;i++)
    //     dp[i] = arr[i];

    int res = 0;
    for (int i=0;i<n;i++){
        int sum_  =0;
        for (int j=i-1;j>=0;j--){
            if (arr[i] > arr[j]){
                sum_ = max(sum_, dp[j]);
            }
        }
        dp[i] = arr[i] + sum_;
        res = max(res, dp[i]);
    }

    return res;

}


int main(){

    // vector <int> arr{1, 101, 2, 3 ,100};
    // vector <int> arr{1, 101, 2, 3 ,100};
    // arr.push_back(INT_MAX); //dummy element
    // int n = arr.size();
    // cout << f(n-2, n-1, arr) << endl;


    int arr[] = {1, 101, 2, 3 ,100};
    cout << dpSol(arr, 5) << endl;
    return 0;
}