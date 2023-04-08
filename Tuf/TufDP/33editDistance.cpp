#include <bits/stdc++.h>
using namespace std;

// Given two strings str1 and str2 and below operations that can be performed on str1.
// Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  
// Insert
// Remove
// Replace
// All of the above operations are of equal cost

int f(int i, int j, string &s1, string &s2){
    //base case pending
    if (i < 0 && j < 0)
        return 0;
    else if (i<0)
        return j+1;
    else if (j<0)
        return i+1;
    else{
        if (s1[i] == s2[j]){
            return f(i-1,j-1, s1, s2);
        }else{
            return 1 + min({
                f(i, j-1, s1, s2), //insertion in s1
                f(i-1, j, s1, s2), //deletion in s1
                f(i-1, j-1, s1, s2) //replace in s1
            });
        }
    }
}


//can be further space optimised
int editDistanceDp(string s1, string s2){
    int n = s1.size();
    int m = s2.size();

    int dp[n+1][m+1];

    //init
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            dp[i][j] = 0;
        }
    }

    //base case
    for (int i=1;i<=n;i++){
        dp[i][0] = i;
    }
    //base case
    for (int i=1;i<=n;i++){
        dp[0][i] = i;
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = 1 + min({
                    dp[i][j-1], //insertion in s1
                    dp[i-1][j], //deletion in s1
                    dp[i-1][j-1] //replace in s1
                });
            }
        }
    }


    return dp[n][m];


}
