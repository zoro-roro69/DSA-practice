#include <bits/stdc++.h>
using namespace std;

//st -- service time
//tt -- transfer time
vector<int> entry_time= {0,0};
vector <int> exit_time= {0,0};
int f(int i, int j, vector <vector <int>> &st, vector <vector <int>> &tt){
    //base case pending
    if (j==0){
        return entry_time[i] + st[i][j];
    }
    return st[i][j] + min(f(i,j-1, st, tt), f(!i, j-1, st, tt) + tt[!i][j]);
}

int dpSol(vector <int> &enrty_time, vector <int> &exit_time, vector <vector <int>> &st,
    vector <vector <int>> &tt, int n)
{
    vector <vector <int>> dp(2, vector <int> (n, 0));
    //base case j == 0
    dp[0][0] = st[0][0] + enrty_time[0];
    dp[1][0] = st[1][0] + enrty_time[1];

    for (int j=1;j<n;j++){
        for (int i=0;i<2;i++){
            dp[i][j] = st[i][j] + min(dp[i][j-1], dp[!i][j-1] + tt[!i][j]);
        }
    }

    dp[0][n-1] += exit_time[0];
    dp[1][n-1] += exit_time[1];

    return min(dp[0][n-1], dp[1][n-1]);
}

int main(){
    vector <vector <int>> st = {{4, 5, 3, 2}, 
                            {2, 10, 1, 4}}; 
    vector <vector <int>> tt = {{0, 7, 4, 5}, 
                            {0, 9, 2, 8}}; 

    // vector <vector <int>> st = {{4}, 
    //                         {2}}; 
    // vector <vector <int>> tt = {{0}, 
    //                         {0}}; 
    entry_time[0] = 10;
    entry_time[1] = 12;

    exit_time[0] = 18;
    exit_time[1] = 7;

    int n = 4;

    int res = INT_MAX;
    res = min(f(0,n-1, st, tt)+exit_time[0], f(1, n-1, st, tt) + exit_time[1]);
    cout << res << endl;

    cout << "dp" << endl;

    cout << dpSol(entry_time, exit_time, st, tt, n) << endl;
    return 0;
}