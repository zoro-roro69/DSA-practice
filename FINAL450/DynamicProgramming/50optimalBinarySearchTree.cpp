#include <bits/stdc++.h>
using namespace std;

//MCM
int f(int i, int j, int level, vector <int> &freq){
    //base case pending
    if (i>j)
        return 0;

    int res = INT_MAX;
    for (int k=i;k<=j;k++){
        res = min(res, level*freq[k] + f(i,k-1,level+1, freq) + f(k+1, j, level+1, freq));
    }
    return res;
}


//eliminating the level state
int f2(int i, int j, vector <int> &freq){
    if (i>j)
        return 0;

    int freq_sum = 0;
    for (int k=i;k<=j;k++){
        freq_sum += freq[k];
    }


    int res = INT_MAX;

    for (int k=i;k<=j;k++){
        res = min(res, f2(i,k-1, freq) + f2(k+1,j,freq));
    }

    return res + freq_sum;

}


int dpSol(vector <int> freq, vector <int> bst){
    int n = freq.size();
    int dp[n+2][n+2];
    for (int i=0;i<=n+1;i++){
        for (int j=0;j<=n+1;j++)
            dp[i][j] = 0;
    }

    for (int i = n-1;i>=0;i--){
        for (int j=i;j<n;j++){
            int freq_sum = 0;
            for (int k=i;k<=j;k++)
                freq_sum += freq[k];

            dp[i +1][j +1] = INT_MAX;
            for (int k=i;k<=j;k++){
                dp[i +1][j +1] = min(dp[i +1][j +1], dp[i +1][k-1 +1] + dp[k+1 +1][j +1]);
            }

            dp[i +1][j +1] += freq_sum;
        }
    }

    return dp[0 +1][n];
}


int main(){

    vector <int> v{34};

    cout << f(0, v.size()-1,1, v) << endl;
    cout << f2(0, v.size()-1, v) << endl;
    cout << dpSol(v, {}) << endl;

    return 0;
}