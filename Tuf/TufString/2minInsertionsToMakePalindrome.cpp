#include <bits/stdc++.h>
using namespace std;


// Note in this we are allowed to insert anywhere in the string
//can also be done from LPS, longest palndromic Subsequence :)
// ans = n - LPS(s)


//here is another approach
int f(string &s, int i, int j){
    if (i>=j)
        return 0;
    else{
        if (s[i] == s[j])
            return f(s, i+1, j-1);
        else{
            return 1 + min(f(s, i+1,j), f(s,i,j-1));
        }
    }
}

//i = 0 to n
// j = n to 0
int minInsertionsToMakePalindrome(string s){
    int n = s.size();
    vector <vector <int>> dp(n, vector <int> (n, 0));

    for (int i = n-1;i>=0;i--){
        for (int j = i+1; j<n;j++){
            if (s[i] == s[j] ){
                if (i+1<n && j-1 >=0)
                dp[i][j] = dp[i+1][j-1];
            }else{
                if (i+1<n && j-1 >=0)
                dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}

//space optimised
int minInsertions2(string s){
    int n = s.size();
    vector <int> prev(n, 0);
    vector <int> cur(n, 0);

    for (int i = n-1;i>=0;i--){
        for (int j = i+1; j<n;j++){
            if (s[i] == s[j] ){
                if (i+1<n && j-1 >=0)
                cur[j] = prev[j-1];
            }else{
                if (i+1<n && j-1 >=0)
                cur[j] = 1 + min(prev[j], prev[j-1]);
            }
        }
        prev = cur; //
    }

    return cur[n-1];

}



int main(){

    string s = "abcab";

    cout << f(s, 0, s.size()-1) << endl;

    cout << minInsertionsToMakePalindrome(s) << endl;

    return 0;
}