#include <bits/stdc++.h>
using namespace std;


int f(int i, vector <int> &arr){
    //base case pending
    if (i < 0)
        return 0;
    if (i == 0 )
        return arr[i];
    if (i == 1)
        return arr[0] + arr[1];


    return max({
        arr[i] + arr[i-1] + f(i-3, arr), //exluding i-2th
        arr[i] + f(i-2, arr), //excluding i-1th
        f(i-1, arr) //excluding ith
    });

}


int dpSol(vector <int> &arr){
    
    int n = arr.size();

    if (n  == 0)
        return 0;
    if (n == 1)
        return arr[0];
    if (n == 2)
        return arr[0] + arr[1];

    //n > 2
    int dp[n+1]; //index is one shifted

    //base case
    //i < 0
    dp[0] = 0;
    //i == 0
    dp[1] = arr[0];
    //i == 1
    dp[2] = arr[0] + arr[1];

    for (int i=3;i<=n;i++){

        dp[i] = max({
            arr[i-1] + arr[i-1-1] + dp[i-3],
            arr[i-1] + dp[i-2],
            dp[i-1]
        });
    }

    return dp[n];

}

int main(){
    vector <int> arr{100, 1000, 100, 1000, 1};
    cout << f(arr.size()-1, arr) << endl;
    cout << dpSol(arr) << endl;
    return 0;
}