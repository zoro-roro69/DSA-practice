#include <bits/stdc++.h>
using namespace std;

// LCS Problem Statement: Given two sequences, find the length of longest subsequence 
// present in both of them. A subsequence is a sequence that appears in the same relative order,
// but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc 
// are subsequences of “abcdefg”.

// LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4. 

int f(int i, int j, string &s1, string &s2){
    if (i < 0 || j < 0)  
        return 0;
    else{
        int including = 0;
        int excluding = 0;
        if (s1[i] == s2[j])
            including = 1 + f(i-1, j-1, s1, s2);
        else
            excluding = max(f(i-1, j, s1, s2), f(i, j-1, s1, s2));

        return max(including, excluding);
    }
}

int LSCdp(string s1, string s2){
    int n = s1.size();
    int m = s2.size();

    if (n == 0 || m == 0)
        return 0;

    int dp[1+n][1+m]; //1 based indexing
    int direction[1+n][1+m]; //for printing the string itself, can also be printed without extra space

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
                direction[i][j] = 0; //0 means we included this and now we need to go i-1, j-1
            }
            else{ //exlcuding
                if (dp[i-1][j] >= dp[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                    direction[i][j] = 1; //move up i-1
                }else{
                    dp[i][j] = dp[i][j-1];
                    direction[i][j] = 2; //move left j-1
                }
            }
        }
    }

    string s=""; 
    int i=n, j = m;
    //constructct string
    while (i>0 && j>0){
        if (direction[i][j] == 0){
            //include cur char
            s += s1[i-1];
            i--;
            j--;
        }else if (direction[i][j] == 1){
            i--;
        }else{
            j--;
        }
    }
    reverse(s.begin(), s.end());
    cout << s << endl;

    return dp[n][m];
}

int main(){

// ABCDGH
// ACDGHR

// S = “abacdfgdcaba”, S’ = “abacdgfdcaba”
    string s1 = "ABCDGH";
    string s2 = "ACDGHR";

    cout << f(s1.size()-1, s2.size()-1, s1, s2) << endl;
    cout << LSCdp(s1, s2) << endl;

    return 0;
}