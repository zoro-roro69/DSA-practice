#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/c/takeUforward/playlists

int editDistance(string &s1, string &s2, int i, int j){
    if (i>=s1.size() && j>=s2.size())
        return 0;
    else if (i>=s1.size()){
        return s2.size()-j;
    }else if(j>=s2.size()){
        return s1.size()-i;
    }else{ //i<s1.size() && j < s2.size()

        int exclude = 1 + editDistance(s1, s2, i+1, j);
        int keep_replace_add;

        if (s1[i]==s2[j]){ //we keep the current , if both are equal
            keep_replace_add = editDistance(s1, s2, i+1, j+1);
        }else{ //replace
            keep_replace_add = 1 + editDistance(s1, s2, i+1, j+1);
            //add
            keep_replace_add = min(keep_replace_add, 1 + editDistance(s1, s2, i, j+1));
        }

        return min(exclude, keep_replace_add);

    }
}   

int editDistanceDP(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();

    //1 based indexing
    vector <vector <int>> dp(n+1, vector <int>(m+1, 0));

    //base case when string 1 is empty or exhausted, no. of ops = no. of chars left in string 2
    for (int i=0;i<=m;i++)
        dp[0][i] = i;

    //base case when string 2 is empty or exhausted, no. of ops = no. of chars left in string 1
    for (int i=0;i<=n;i++)
        dp[i][0] = i;

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1]; //no op reqd since already chars are equal
            }else{
                dp[i][j] = min({dp[i][j-1] + 1, //exlcuding from string 2
                                dp[i-1][j] + 1, // excluding from strin 1
                                dp[i-1][j-1] + 1}); //replace op to make equal
            }
        }
    }

    return dp[n][m];
}

//cam be further space optimised since we are using only previous row

int main(){
    string s1 = "geek";
    string s2 = "gesek";
    cout << editDistance(s2, s1, 0, 0) << endl;
    return 0;
}