#include <bits/stdc++.h>
using namespace std;

//only for squares
int res  = 0;
bool f(int i, int j, int size, vector <vector <int>> &mat){
    //base case pending
    if (size == 1)
        return mat[i][j];

    bool flag1 = f(i,j, size-1, mat);
    bool flag2 = f(i+1, j, size-1, mat);
    bool flag3 = f(i, j+1, size - 1, mat);
    bool flag4 = f(i+1, j+1, size - 1, mat);

    bool flag = flag1 && flag2 && flag3 && flag4;

    if (flag){
        res = max(res, size);
    }


    return flag;

}

int fmain(int n, int m, vector <vector <int>> &mat){

    int ans = 0;
    int size = min(n, m);
    if (n<=m){
        for (int j=0;j+size-1 < m;j++){
            res = 0;
            f(0, j, size, mat);
            ans = max(res, ans);
        }

    }else{
        for (int i=0;i+size-1<n;i++){
            res = 0;
            f(i,0, size, mat);
            ans = max(res, ans);
        }
    }

    return res;
}

//for squares only
int dpSol1(int n, vector <vector <int>> &mat) {

    int dp[n][n][n+1];
    //size == 1
    int res = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            dp[i][j][1] = mat[i][j];
            res = max(res, mat[i][j]);
        }
    }

    for (int s = 2;s<=n;s++){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                dp[i][j][s] = dp[i][j][s-1] && dp[i+1][j][s-1] && dp[i][j+1][s-1] && dp[i+1][j+1][s-1];
                if (dp[i][j][s]){
                    res = max(s, res);
                }
            }
        }
    }
    return res;
}

int dpSol2(int si, int sj, int n, vector <vector <int>> &mat) {

    int dp[n][n][n+1];
    //size == 1
    int res = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            dp[i][j][1] = mat[si + i][sj + j];
            res = max(res, mat[si + i][sj + j]);
        }
    }

    for (int s = 2;s<=n;s++){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                dp[i][j][s] = dp[i][j][s-1] && dp[i+1][j][s-1] && dp[i][j+1][s-1] && dp[i+1][j+1][s-1];
                if (dp[i][j][s]){
                    res = max(s, res);
                }
            }
        }
    }
    return res;
}

int dpmain(int n, int m, vector <vector <int>> &mat){

    int res = 0;
    int size = min(n, m);
    
    if (n <= m){
        for (int j=0;j+size-1<m;j++){
            res = max(res, dpSol2(0, j, size, mat));
        }
    }else{

        for (int i=0;i+size-1<n;i++){
            res = max(res, dpSol2(i, 0, size, mat));
        }
    }

    return res;

}

//////////////////// better dp solution
// in this solution we basically start with at 0,0 and check if it is 1 then we try to extend it
// example 
// [1, 1]
// [1, 1]
// at (0,0) we have 1 so we check for elements at (i+1, j) (i, j+1) and (i+1, j+1)
// basically we try to stretch it from the right bottom corner


int solve(int i, int j, vector <vector <int>> &mat, int &res){
    if (i >= mat.size() || j >= mat[0].size())
        return 0;

    int right = solve(i, j+1, mat, res);
    int diagonal = solve(i+1, j+1, mat, res);
    int down = solve(i+1, j, mat, res);

    if (mat[i][j] == 1){
        int ans = 1 + min({right, diagonal, down});
        res = max(ans, res);
        return ans;
    }else{
        return 0;
    }
}


//can be further space optimised sice we are just using one row
int dpsolve(int n, int m, vector <vector <int>> &mat){

    int dp[n+1][m+1];

    //base case
    for (int i=0;i<=n;i++)
        dp[i][m] = 0;
    //base case
    for (int i=0;i<=m;i++)
        dp[n][i] = 0;

    int res = 0;
    for (int i=n-1;i>=0;i--){
        for (int j=m-1;j>=0;j--){
            if (mat[i][j] == 1){
                int ans = 1 + min({dp[i+1][j+1], dp[i+1][j], dp[i][j+1]});
                dp[i][j] = ans;
                res = max(res, ans);
            }else
                dp[i][j] = 0; 
        }
    }
    return res;
}

int main(){
    // vector <vector <int >> mat{{0, 1,1,1}, {0,1,1,1},{0,1,1,1},{1,1,1,1}};
    vector <vector <int >> mat{{0, 1}, {1,0}};
    // cout << f(0, 0, 4, mat) << endl;
    // cout << fmain(4,4, mat) << endl;
    int ans = 0;
    solve(0,0,mat, ans);
    cout << ans << endl;
    return 0;
}