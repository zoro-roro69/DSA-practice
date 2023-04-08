#include <bits/stdc++.h>
using namespace std;

// given two strings s1, s2
// how many times s2 occurs as subsequence in s1
// ex s1 = "baggbag" s2 = "bag"


int f(int i, int j, string s1, string s2){
    //base case pending
    if (i<0 && j<0)
        return 1;
    else if (j<0)
        return 1;
    else if (i<0)
        return 0;
    //else
    int res = 0;
    if (s1[i] == s2[j])
        res += f(i-1, j-1, s1, s2);
    
    res += f(i-1, j, s1, s2);

    return res;
}

//on leetcode we are getting overflow error
//to overcome that use double matrix instead of type int
//and then cast the final answer back to int
int distinctSubsequenceDP(string s1, string s2){

    //no. of times s2 occurs in s1
    int n = s1.size();
    int m = s2.size();

    int dp[n+1][m+1];

    //init
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            dp[i][j] = 0;
        }
    }

    //base case
    for (int i=0;i<=n;i++){
        dp[i][0] = 1;
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            dp[i][j] = dp[i-1][j];

            if (s1[i-1] == s2[j-1]){
                dp[i][j] += dp[i-1][j-1];
            }
        }
    }

    return dp[n][m];

}


//even more space optimised
// can be further space optimised  by just using single array
int distinctSubsequenceDP2(string s1, string s2){

    //no. of times s2 occurs in s1
    int n = s1.size();
    int m = s2.size();

    int prev[m+1];
    int cur[m+1];
    //init 
    for (int i=0;i<=m;i++){
        prev[i] = 0;
        cur[i] = 0;
    }

    //base case
    cur[0] = prev[0] = 1;


    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cur[j]  = prev[j];

            if (s1[i-1] == s2[j-1]){
                cur[j] += prev[j-1];
            }
        }

        //set prev to cur
        for (int i=0;i<=m;i++){
            prev[i] = cur[i];
        }
    }

    return cur[m];
}



int distinctSubsequenceDP2(string s1, string s2){

    //no. of times s2 occurs in s1
    int n = s1.size();
    int m = s2.size();

    int prev[m+1];
    //init 
    for (int i=0;i<=m;i++){
        prev[i] = 0;
    }

    //base case
    prev[0] = 1;


    for (int i=1;i<=n;i++){
        for (int j=m;j>0;j--){ //note- we reversed here
            prev[j] = prev[j];

            if (s1[i-1] == s2[j-1]){
                prev[j] += prev[j-1];
            }
        }

    }

    return prev[m];
}

int main(){

    string s1 = "baggbag";
    string s2 = "bag";

    cout << distinctSubsequenceDP(s1, s2) << endl;

    return 0;
}