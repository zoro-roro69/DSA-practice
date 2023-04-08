#include <bits/stdc++.h>
using namespace std;

int f(int i, int prod_till_now, int k, vector <int> &arr){
    if (i<0)
        return 1;

    int include = 0;
    int exclude = 0;

    int prod = arr[i]*prod_till_now;
    if (prod < k)
        include += f(i-1, prod, k, arr);
    
    exclude = f(i-1, prod_till_now, k, arr);
    return include + exclude;
}


int dpSol(int k, vector <int> arr){

    int n = arr.size();
    if (n == 0)
        return 0;

    int dp[n+1][k]; //rows are 1 shifted

    //base case, i < 0
    for (int j=0;j<k;j++){
        dp[0][j] = 1;
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<k;j++){ //j is prod till now
            int include = 0;
            int exclude = 0;
            if (arr[i-1]<=j){
                include = dp[i-1][j/arr[i-1]];
            }
            exclude = dp[i-1][j];

            dp[i][j] = include + exclude;
        }
    }

    return dp[n][k-1]-1;

}

int main(){

    vector <int> arr{9,9,2,3,10,13,14};
    int k = 70 ;
    cout << f(arr.size()-1, 1, k, arr) - 1<< endl;

    cout << dpSol(k, arr) << endl;

    return 0;

}