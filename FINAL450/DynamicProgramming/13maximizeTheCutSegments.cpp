#include <bits/stdc++.h>
using namespace std;

int f(int i, int x, int y, int z){
    if (i == 0)
        return 0;
    else if (i < 0)
        return -1; //invalid

    int xval = f(i-x, x, y, z);
    int yval = f(i-y, x, y, z);
    int zval = f(i-z, x, y, z);

    int res = max({xval, yval, zval});
    if (res>=0)
        res += 1;

    return res;
}

int dpMaximizeCuts(int n, int x, int y, int z){
    if (x == 1 || y == 1 || z == 1)
        return n;

    vector <int> dp(n+1, 0);
    dp[0] = 0;

    for (int i=1;i<=n;i++){
        int xval = -1;
        int yval = -1;
        int zval = -1;
        if (i>=x)
            xval = dp[i-x];
        if (i>=y)
            yval = dp[i-y];
        if (i>=z)
            zval = dp[i-z];

        int max_ = max({xval, yval, zval});
        if (max_ >= 0)
            max_ += 1;
        dp[i] = max_;
    }
    return dp[n];
}

//one shifted
int dp2(int n, int x, int y, int z){
    if (x == 1 || y == 1 || z == 1)
        return n;

    vector <int> dp(n+2, 0); //one shifted indexes
    dp[0] = -1;
    dp[1] = 0;

    for (int i=1;i<=n;i++){
        int xval = -1;
        int yval = -1;
        int zval = -1;

        if (i >= x)
            xval = dp[i-x+1];
        if (i >= y)
            yval = dp[i-y+1];
        if (i >= z)
            zval = dp[i-z+1];
        int max_ = max({xval, yval, zval});
        if (max_ >= 0)
            max_ += 1;
        
        dp[i+1] = max_;
    }
    return dp[n+1];
}


int main(){

    cout << f (7, 5, 5, 2) << endl;
    cout << dpMaximizeCuts(7, 5, 5, 2) << endl;

    return 0;
}