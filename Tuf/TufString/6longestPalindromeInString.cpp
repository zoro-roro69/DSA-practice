#include <bits/stdc++.h>
using namespace std;


int f(string &s, int i, int j){
    if (i>j)
        return 0;
    if (i == j) //single char
        return 1;
    int excluding_ij = 0;

    if (s[i] == s[j] && f(s,i+1, j-1) == (j-i+1) - 2){ //f(..) = len of string from i to j - 2
        excluding_ij = j-i+1;
        return excluding_ij;
    }

    int excluding_i = f(s, i+1, j);
    int excluding_j = f(s, i,j-1);

    return max(excluding_i, excluding_j);


}

//i -- 0 to n
// j -- n to 0
int f_iterative(string &s){
    int n = s.size();
    vector <vector <int>> dp(n, vector <int> (n, 0));

    //base case
    for (int i=0;i<n;i++)
        dp[i][i] = 1;

    string res = "";
    res.push_back(s[0]); //palindrome of length 1

    for (int i=n-1;i>=0;i--){
        for (int j=i+1;j<n;j++){
            if (s[i] == s[j] && dp[i+1][j-1] == (j-i+1)-2){
                dp[i][j] = j-i+1;
                if (dp[i][j] > res.size()){
                    res = s.substr(i, j-i+1);
                }
            }else{
                int excluding_i = dp[i+1][j];
                int exlcuding_j = dp[i][j-1];

                dp[i][j] = max(excluding_i, exlcuding_j);;
            }
        }
    }

    cout << res << endl;


    return dp[0][n-1];


}

int longestPalinSubstring(string s){

    return f(s, 0, s.size()-1);
}


int main(){

    string s = "abccbc";

    cout << longestPalinSubstring(s) << endl;
    cout << f_iterative(s) << endl;

    return 0;
}