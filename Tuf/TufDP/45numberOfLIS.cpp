#include <bits/stdc++.h>
using namespace std;


//this jsut returns the lenght of the longest increasing subsequence
int f(int i, int prev, vector <int> &arr){
    //base case pending
    if (i>=arr.size())
        return 0;

    int including = 0;
    int excluding = 0;

    if (prev == -1 || arr[i] > arr[prev]){
        including = 1 + f(i+1, i, arr);
    }

    excluding = f(i+1, prev, arr);

    return max(including, excluding);
}


//this also gives the length of the LIS not the count
int lisDP(vector <int> &arr){

    int n = arr.size();
    if (n<=1)
        return n;

    int dp[n+1][n+1]; //second index is 1 shifted

    //base case i>=n: return 0;
    for (int j=0;j<=n;j++){
        dp[n][j] = 0;
    }


    for (int i=n-1;i>=0;i--){
        for (int j=i-1;j>=-1;j--){
            int including = 0;
            int excluding = 0;

            if (j == -1 || arr[i]>arr[j]){
                including = 1 + dp[i+1][i+1]; 
            }
            excluding = dp[i+1][j+1];

            dp[i][j+1] = max(including, excluding);
        }

    }

    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++)
            cout << dp[i][j] <<  " ";
        cout << endl;
    }

    //dp[0][0] contains the length of  LIS
    return dp[0][0];

}


int countLIS(vector <int> &arr){
    int n = arr.size();
    if (n <= 1)
        return n;

    int dp[n];
    int count[n];

    for (int i=0;i<n;i++){
        dp[i] = 1;
        count[i] = 1;
    }

    int longest = 1;
    for (int i=1;i<n;i++){
        for (int j=i-1;j>=0;j--){
            if (arr[i] > arr[j] ){
                if (dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    count[i] = count[j];
                }else if (dp[j]+1 == dp[i]){
                    count[i] += count[j];
                }
            }

        }
        longest = max(longest, dp[i]);
    }
    int res = 0;
    for (int i=0;i<n;i++){
        if (dp[i] == longest){
            res += count[i];
        }
    }
    cout << longest << endl;
    return res;
}





int main(){

    vector <int> arr{1,3,5,4,7};

    cout << lisDP(arr) << endl;
    cout << countLIS(arr) << endl;
    
    return 0;
}