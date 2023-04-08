#include <bits/stdc++.h>
using namespace std;

// Minimum insertions to form a palindrome


//recursive
int f(int i, int j, string &s){
    if (i >= j)
        return 0;

    if (s[i] == s[j]){
        return f(i+1, j-1, s);
    }else{
        return 1 + min(f(i+1, j, s), f(i,j-1,s));
    }

}

// this can also be converted to longest palindromic subsequence
// to make string palindrome we need to retain the the longest existing palindromic subsequence in it 
// so the number of insertions would be = n - length of longest existing palindrome
// n = length of the string

int minToMakePalindrome(string s1){

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

    int l = dp[n][m];

    return n-l;

}


int main(){

    string s = "abcaa";
    cout << f (0, s.size()-1, s) << endl;

    return 0;
}