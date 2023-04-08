#include <bits/stdc++.h>
using namespace std;

// Given a sequence, find the length of the longest palindromic subsequence in it.

int f(int i, int j, string &s1){
    if (i > j)
        return 0;
    if (i == j)
        return 1;

    if (s1[i] == s1[j]){
        return 2 + f(i+1, j-1, s1);
    }else
        return max(f(i+1, j, s1), f(i,j-1, s1));
}


//this can be converted to finding longest common subsequence. given two strings
//we just take the second string as reverse of the first
// i.e s1 = "aabaad"
//  then take s2 = "daabaa"
// then simpy do LCS(s1, s2)

int longestPalinSubseq(string s1) {
    //code here
    
    int n = s1.size();
    int m = s1.size();
    string s2 = s1;

    reverse(s2.begin(), s2.end());


    if (n == 0 || m == 0)
        return 0;

    int dp[1+n][1+m]; //1 based indexing
    // int direction[1+n][1+m]; //for printing the string itself, can also be printed without extra space

    //init
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++)
            dp[i][j] = 0;
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            //including
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                // direction[i][j] = 0; //0 means we included this and now we need to go i-1, j-1
            }
            else{ //exlcuding
                if (dp[i-1][j] >= dp[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                    // direction[i][j] = 1; //move up i-1
                }else{
                    dp[i][j] = dp[i][j-1];
                    // direction[i][j] = 2; //move left j-1
                }
            }
        }
    }

    return dp[n][m];
}

int main(){

    string s = "geeksforgeeks";

    cout << f(0, s.size()-1, s) << endl;

    return 0;
}