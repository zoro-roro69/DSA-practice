#include <bits/stdc++.h>
using namespace std;


int f(int i, int j, bool turn, vector <int> &arr){
    if (i>j)
        return 0;

    if (turn){ 
        //player a turn
        return max(arr[i] + f(i+1, j, !turn, arr), arr[j] + f(i,j-1, !turn, arr));
    }else{
        //player b turn
        return min(f(i+1, j, !turn, arr), f(i, j-1, !turn, arr));
    }

}


int dpSol(int n, vector <int> arr){

    int dp[n][n][2];
    //base case
    // i>j
    for (int i=0;i<n;i++){
        for (int j= 0;j<n;j++){
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
    }

    for (int i=n-1;i>=0;i--){
        for (int j=i+1;j<n;j++){
            //player a turn
            dp[i][j][1] = max(arr[i] + dp[i+1][j][0], arr[j] + dp[i][j-1][0]);
            //player b turn
            dp[i][j][0] = min(dp[i+1][j][1], dp[i][j-1][1]);
        }
    }

    return dp[0][n-1][1];

}

//recursive solution can also be written as
// Following is the recursive solution that is based on the above two choices. We take a maximum of two choices. 

// F(i, j) represents the maximum value the user
// can collect from i'th coin to j'th coin.

// F(i, j) = Max(Vi + min(F(i+2, j), F(i+1, j-1) ), 
//               Vj + min(F(i+1, j-1), F(i, j-2) ))
// As user wants to maximise the number of coins. 

// Base Cases
//     F(i, j) = Vi           If j == i
//     F(i, j) = max(Vi, Vj)  If j == i + 1


int main(){
    vector <int> arr{8,15,3,7};
 
    cout << f(0, arr.size()-1, true,arr) << endl;
    cout << dpSol(arr.size(), arr) << endl;

    return 0;
}
