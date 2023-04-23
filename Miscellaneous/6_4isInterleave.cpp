#include <bits/stdc++.h>
using namespace std;

bool f(string &s1, string &s2, string &s3, int i, int j){
    int ind = i+j;
    if (i >= s1.size() && j>= s2.size() && ind >=s3.size()){
        return true;
    }

    if (i >= s1.size()){
        if (s3[ind] != s2[j])
            return false;
        else
            return f(s1, s2, s3, i, j+1);
    }

    if (j >= s2.size()){
        if (s3[ind] != s1[i])
            return false;
        else
            return f(s1, s2, s3, i+1, j);
    }

    bool including_i = false;
    bool including_j = false;
    
    if (s3[ind] == s1[i])
        including_i = f(s1, s2, s3, i+1, j);
    if (s3[ind] == s2[j])
        including_j = f(s1, s2, s3, i, j+1);

    return including_i || including_j;

}

bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size())
        return false;
    return f(s1, s2, s3, 0, 0); 
}


bool isInterleaveDp(string s1, string s2, string s3){
    int n = s1.size();
    int m = s2.size();
    int p = s3.size();

    if (n + m != p)
        return false;
    
    vector <vector <bool>> dp(n+1, vector <bool> (m+1, 0));

    //base case
    dp[n][m] = true;

    //base case i>= n
    for (int j=m-1;j>=0;j--){
        //i >= n; 
        int ind = n+j;
        if (s3[ind] != s2[j])
            dp[n][j] = false;
        else
            dp[n][j] = dp[n][j+1];  

    }
    //base case j >= m
    for (int i=n-1;i>=0;i--){
        int ind = i+m;
        if (s3[ind] != s1[i])
            dp[i][m] = false;
        else
            dp[i][m] = dp[i+1][m];
    }

    for (int i=n-1;i>=0; i--){
        for (int j=m-1;j>=0;j--){
            bool including_i = false;
            bool including_j = false;
            int ind = i+j;
            if (s3[ind] == s1[i]){
                including_i = dp[i+1][j];
            }

            if (s3[ind] == s2[j]){
                including_j = dp[i][j+1];
            }

            dp[i][j] = including_i || including_j;
        }
    }

    return dp[0][0];
    
}

int main(){

    return 0;
}