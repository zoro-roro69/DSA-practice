#include <bits/stdc++.h>
using namespace std;


int f(int i, int j, int k, string &a, string &b, string &c){
    if (k == c.size()){
        return i == a.size()  && j == b.size();
    }

    bool using_a = i < a.size() && a[i] == c[k] ? f(i+1, j, k+1, a,b,c) : false;
    bool using_b = j < b.size() && b[j] == c[k] ? f(i, j+1, k+1, a,b,c) : false;

    return using_a || using_b;

}

int dpSol(string a, string b, string c){
    int dp[a.size()+1][b.size()+1][c.size()+1];

    for (int i=0;i<=a.size();i++){
        for (int j=0;j<=b.size();j++){
            for (int k=0;k<=c.size();k++){
                dp[i][j][k] = false;
            }
        }
    }
    //base case
    dp[a.size()][b.size()][c.size()] = 1;
    //base case
    // for (int i=0;i<a.size();i++){
    //     for (int j=0;j<b.size();j++){
    //         dp[i][j][c.size()] = false;
    //     }
    // }

    for (int i=a.size();i>=0;i--){
        for (int j=b.size();j>=0;j--){
            for (int k = c.size()-1; k>=0;k--){
                bool using_a = i < a.size() && a[i] == c[k] && dp[i+1][j][k+1];
                bool using_b = j < b.size() && b[j] == c[k] && dp[i][j+1][k+1];

                dp[i][j][k] = using_a || using_b;

            }
        }
    }

    return dp[0][0][0];

}

//reducing one state
//the third state i.e k can be calculated using k = i+j
// k = no. of characters matched till now in string a + no. of characters matched till now in string b;
int f2(int i, int j, string a, string b, string c){
    int k = i+j;

    if (k == c.size())
        return i == a.size() && j == b.size();

    bool using_a = false;
    bool using_b = false;

    using_a = i < a.size() && a[i] == c[k] ? f2(i+1, j, a,b,c) : false;
    using_b = j < b.size() && b[j] == c[k] ? f2(i, j+1, a,b,c) : false;

    return using_a || using_b;

}

int dpSol2(string a, string b, string c){

    int n = a.size();
    int m = b.size();
    int x = c.size();

    if (n+m != x)
        return false;

    bool dp[n+1][m+1];

    dp[n][m] = true;

    for (int i=n; i>=0; i--){
        for (int j=m; j>=0; j--){
            int k = i+j;
            if (k<x){
                bool using_a = false;
                bool using_b = false;

                using_a = i<n && a[i] == c[k] ? dp[i+1][j] : false;
                using_b = j<m && b[j] == c[k] ? dp[i][j+1] : false;

                dp[i][j] = using_a || using_b;
            }
        }
    }

    return dp[0][0];

}


bool isInterleave(string a, string b, string c){
    return dpSol2(a,b,c);
}

int main(){
    string a = "ab";
    string b = "ac";
    string c = "acab";

    cout << isInterleave(a, b, c) << endl;
    return 0;
}