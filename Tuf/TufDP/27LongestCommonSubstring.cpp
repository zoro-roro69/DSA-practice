#include <bits/stdc++.h>
using namespace std;

// Given two strings. The task is to find the length of the longest common substring.

struct res{
    int len;
    int max_len;

    res(){
        len = max_len = 0;
    }

    res(int m, int l){
        len = l;
        max_len = m;
    }

};


// we return two things here, first is the max length substring till now
// second we return lenghth of consecutive common sustring including current characters

res* f(int i, int j, string &s1, string &s2){
    if (i<0 || j<0)
        return new res(0,0);

    res *r1 = new res(0,0);
    res *r2 = new res(0,0);
    res *r3 = new res(0,0);

    if (s1[i] == s2[j]){
        r1 = f(i-1, j-1, s1, s2);
        r1->len +=1;
        r1->max_len = max(r1->max_len, r1->len);
    }

    r2 = f(i-1, j, s1, s2);
    r3 = f(i, j-1, s1, s2);

    return new res(max({r1->max_len, r2->max_len, r3->max_len}), r1->len);
}

//converting above to dp
int commonSubstringDP(string s1, string s2){
    int n = s1.size();
    int m = s2.size();

    res dp[n+1][m+1];

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            res r1;
            res r2;
            res r3;

            if (s1[i-1] == s2[j-1]){
                r1 = dp[i-1][j-1];
                r1.len += 1;
                r1.max_len = max(r1.len, r1.max_len);
            }

            r2 = dp[i-1][j];
            r3 = dp[i][j-1];

            dp[i][j].len = r1.len;
            dp[i][j].max_len = max({r1.max_len, r2.max_len, r3.max_len});

        }
    }

    return dp[n][m].max_len;
}


//a better solution we dont need to store two items at each state
//we only store the length of substring if two chars are equal at current state
// i.e we store 1 + dp[i-1][j-1]
// if they are not equal we simply do dp[i][j] = 0

int commonSubstringDp2(string s1, string s2){
    int n = s1.size();
    int m = s2.size();


    int ans = 0;
    int dp[n+1][m+1];

    //init
    for (int i = 0; i<n;i++){
        for (int j=0;j<m;j++){
            dp[i][j] = 0;
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }else
                dp[i][j] = 0;
        }
    }

    return ans;
}

int main(){

// S = “abacdfgdcaba”, S’ = “abacdgfdcaba”
    string s1 = "ABCDGH";
    string s2 = "ACDGHR";

    cout << f(s1.size()-1, s2.size()-1, s1, s2)->max_len << endl;
    cout << commonSubstringDP(s1, s2) << endl;

    return 0;
}

