#include <bits/stdc++.h>
using namespace std;

// Given two strings str1 and str2, the task is to find the length of the shortest string that has
// both str1 and str2 as subsequences.

// to find the length of the shortest supersequence we need to first find the length of longest common subsequence
// the resultant supersequence will need to have all the characters of this LCS and all the characters which are
// not in LCS from both of strings 
// so the answer = length of shortest supersequence = lcs + (n-lcs) + (m-lcs)
// lcs = longest common subsequence
// n = size of str1
// m = size of str2

int shortestSuperseuence(string s1, string s2){
    int n = s1.size(); 
    int m = s2.size();

    int dp[n+1][m+1];

    //init
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            dp[i][j] = 0;
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int lcs = dp[n][m];
    int ans = lcs + (n-lcs) + (m-lcs);

    //print shortest supersequence

    int i = n, j = m;
    string res = "";
    while(i>0 && j>0){
        if (s1[i-1] == s2[j-1]){ //commom char include only once
            res.push_back(s1[i-1]);
            i--; j--;
        }else{
            if (dp[i][j] == dp[i-1][j]){
                res.push_back(s1[i-1]);
                i = i-1;
            }else{
                res.push_back(s2[j-1]);
                j = j-1;
            }
        }
    }

    while(i>0){
        res.push_back(s1[i-1]);
        i--;
    }

    while(j>0){
        res.push_back(s2[j-1]);
        j--;
    }

    reverse(res.begin(), res.end());
    cout << res << endl;

    return ans;
}

int main(){
// AVnQIELxFb TEpRbSvi
    string s1 = "geeks" ;
    string s2 = "eke";

    cout << shortestSuperseuence(s1, s2) << endl;
    return 0;
}