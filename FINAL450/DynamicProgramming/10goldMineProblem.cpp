#include <bits/stdc++.h>
using namespace std;


int f(int i, int j, vector <vector <int>> &arr){
    if (i < 0 || j < 0 || i >= arr.size())
        return 0;
    return arr[i][j] + max({f(i, j-1, arr), f(i-1, j-1, arr), f(i+1, j-1, arr)});
}

int maxGold(int n, int m, vector <vector <int>> dp){
    

    // int final_res = 0;

    // for (int i=0;i<n;i++){
    //     final_res = max(final_res, f(i,m-1,dp));
        
    // }
    // return final_res;

    int final_res =0;
    if (m == 1){ //nly one col
        for (int i=0;i<n;i++){
            final_res = max(final_res, dp[i][0]);
        }
        return final_res;
    }
    for (int j=1;j<m;j++){
        for (int i=0;i<n;i++){
            int res = 0;
            res = max (res, dp[i][j-1]);
            res = max (res, (i-1)>=0 ? dp[i-1][j-1]: 0);
            res = max (res, (i+1) < n ? dp[i+1][j-1]: 0);
            res += dp[i][j];
            dp[i][j] = res;
            final_res = max(final_res, res);
        }
    }

    return final_res;

}

int main(){
    vector <vector <int>> v{{1, 3, 3}, {2,1,4},{0, 6,4}};
    cout << maxGold(3,3,v) <<endl;
    return 0;
}