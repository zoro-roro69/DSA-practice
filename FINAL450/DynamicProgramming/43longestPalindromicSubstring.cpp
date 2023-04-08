#include <bits/stdc++.h>
using namespace std;

//this solution wont work :)
// try this test case : "aacabdkacaa"
int longestPalindromicSubstring(string s){

    int n = s.size();
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int dp[n+1][n+1];

    //base case i<0 || j< 0 reutnr 0;
    for (int j=0 ;j<n;j++){
        dp[0][j]  =0;
        dp[j][0] = 0;
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (s[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }else{
                dp[i][j]  =0;
            }
        }
    }

    return ans;

}


int f(int i, int j, string s){
    if (i>j)
        return 0;
    if (i == j)
        return 1;

    int res = 0;
    if (s[i] == s[j]){
        
        res = f(i+1,j-1,s);
        if (res+2 == (j-i+1)){
            res += 2;
        }
    }
    
    
    return max({res, f(i+1, j, s), f(i, j-1 ,s)});
}


//dp
string dpSol(string s){
    //find longest palndromic substring

    int n = s.size();

    int dp[n][n];

    //base case i>j return 0
    for (int i=0;i<n;i++){
        for (int j=i-1;j>=0;j--)
            dp[i][j] = 0;
    }

    //base case i ==j return 1
    for (int i=0;i<n;i++){
        dp[i][i] = 1;
    }

    for (int i=n-1;i>=0;i--){
        for (int j=i+1;j<n;j++){
            int res = 0;
            if (s[i] == s[j]){
                res = dp[i+1][j-1];
                if (res+2 == j-i+1){
                    res += 2;
                }
            }
            dp[i][j] = max({res, dp[i+1][j], dp[i][j-1]});
        }
    }

    string res = "";
    int i = 0; int j = n-1;
    while(i>0 && j > 0){
        if (dp[i][j] == j-i+1){
            res = s.substr(i, j-i+1);
            break;
        }else{
            if (dp[i][j] == dp[i+1][j])
                i++;
            else if (dp[i][j] == dp[i][j-1])
                j--;
            else if(dp[i][j] == dp[i+1][j-1]){
                i++;
                j--;
            }
        }
    }

    return res;

}


int main(){



    return 0;
}