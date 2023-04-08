#include <bits/stdc++.h>
using namespace std;


int f(int i, bool buy, int t, vector <int> &stocks){
    if ( i == stocks.size() || t == 0)
        return 0;

    if (buy){
        //max of (buying here, not buying here)
        return max(f(i+1, buy, t, stocks), f(i+1, !buy, t, stocks) - stocks[i]);
    }else{
        int selling = 0;
        int not_selling = 0;
        if (t>0){ //number of transactions left > 0
            selling = f(i+1, !buy, t-1, stocks) + stocks[i];
        }
        not_selling = f(i+1, buy, t, stocks);

        return max(selling, not_selling);
    }
}

int dpSol(vector <int> &stocks, int t){
    int n = stocks.size();
    int dp[n+1][2][t+1];

    //base case, i == n
    for (int k=0;k<=t;k++){
        dp[n][0][k] = 0;
        dp[n][1][k] = 0;
    }

    //base case t == 0
    for (int i=0;i<=n;i++){
        dp[i][0][0] = 0;
        dp[i][1][0] = 0;
    }

    for (int i=n-1;i>=0;i--){
        for (int k=1;k<=t;k++){
            //max (buying, not buying)
            dp[i][0][k] = max(dp[i+1][1][k] - stocks[i], dp[i+1][0][k]);

            //max (selling, not selling)
            dp[i][1][k] = max(dp[i+1][0][k-1] + stocks[i], dp[i+1][1][k]);
            
        }
    }

    return dp[0][0][t];
}



int main(){
    vector <int> arr{2, 30, 15, 10, 8, 25, 80};

    cout << f(0, true, 2, arr) << endl;
    cout << dpSol(arr, 2) << endl;

    return 0;
}