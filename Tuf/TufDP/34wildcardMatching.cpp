#include <bits/stdc++.h>
using namespace std;

// Given a text and a wildcard pattern, implement wildcard pattern matching algorithm that finds 
// if wildcard pattern is matched with text. The matching should cover the entire text (not 
// partial text). The wildcard pattern can include the characters ‘?’ and ‘*’ 

// ‘?’ – matches any single character 
// ‘*’ – Matches any sequence of characters (including the empty sequence)

int f(int i, int j, string &pattern, string &s){
    if(i < 0 && j < 0)
        return true; 
    else if (i<0)
        return false;
    else if (j<0){
        while(i>=0 && pattern[i]=='*'){ //if *(s) are at begining
            i--;
        }
        return i<0;
    }

    if (pattern[i] == s[j] || pattern[i] == '?')
        return f(i-1, j-1, pattern, s);
    else if (pattern[i] == '*')
        return f(i-1, j-1, pattern, s) || //used * to match just current char
               f(i-1, j, pattern, s) || //used * as empty string, didnt match with other char
               f(i, j-1, pattern, s); //used * to match current char, and also many more
    else
        return false;

}

int wildcardDP(string pattern, string s){
    int n = pattern.size();
    int m = s.size();

    int dp[n+1][m+1];
    //init
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            dp[i][j] = 0;
        }
    }

    //base case
    dp[0][0] = 1;

    //base case, no need for this loop we have already intitalised with 0's above
    for (int j=1;j<=m;j++){
        dp[0][j] = 0;
    }

    //base case, when *  are at start of the pattern
    for (int i=1;pattern[i-1] == '*';i++){
        dp[i][0] = true;
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (pattern[i-1] == s[j-1] || pattern[i-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }else if(pattern[i-1] == '*'){
                dp[i][j] = dp[i-1][j-1] || //used * to match cur char only
                           dp[i-1][j] || //used * as empty string, or ddint match with cur char
                           dp[i][j-1]; //used * to match cur char and many more
            }
        }
    }

    // for (int i=0;i<=n;i++){
    //     for (int j=0;j<=m;j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    return dp[n][m];
}


int main(){

    string s1 = "*****ba*****ab";
    string s2 = "baaabab";

    cout << f(s1.size()-1, s2.size()-1, s1, s2) << endl;

    cout << wildcardDP(s1, s2) << endl;


}