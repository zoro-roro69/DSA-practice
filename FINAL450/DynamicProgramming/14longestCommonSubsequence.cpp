#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, string &s1, string &s2){
    //base case pending
    if (i < 0 || j < 0)
        return 0;

    if (s1[i] == s2[j])
        return 1 + f(s1[i], s2[j], s1, s2);
    else    
        return max(f(i, j-1, s1, s2), f(i-1, j, s1, s2) );
}

int LCSdp(string s1, string s2){

    int n = s1.size();
    int m = s2.size();

    vector <vector <int>> dp(n+1, vector <int> (m+1, 0)); //1 shifted indexes

    //base case i<0
    for (int j=0;j<=m;j++)
        dp[0][j] = 0;

    //base case j<0
    for (int i=0;i<=n;i++)
        dp[i][0] = 0;

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    return dp[n][m];
}


int main(){

    return 0;
}