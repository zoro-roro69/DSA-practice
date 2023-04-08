#include <bits/stdc++.h>
using namespace std;


int f(int i, int j, vector <vector <int>> &mat){

    if (i < 0 || i>mat.size() || j<0 || j>mat[0].size())
        return 0;

    return mat[i][j] + max({f(i-1, j, mat),
                            f(i-1, j-1, mat),
                            f(i-1,j+1, mat)});

}

int dpSol(int n, vector <vector <int>> &mat){

    int dp[n][n];   

    int ans = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            int left = (i-1>=0 && j-1 >=0) ?  dp[i-1][j-1] : 0;
            int right = (i-1>=0 && j+1 < n) ? dp[i-1][j+1] : 0;
            int center = (i-1>=0 ) ? dp[i-1][j] : 0;

            dp[i][j] = mat[i][j] + max({left, center, right});
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

int main(){

    vector <vector <int>> mat{{348, 391},
          {618, 193}};

    cout << dpSol(2, mat) << endl;
    return 0;
}