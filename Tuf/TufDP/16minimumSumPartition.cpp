#include <bits/stdc++.h>
using namespace std;

//very similar to previous one 
//the minimum difference will be when we are able to paartition the array such that 
//both subsets have equal or almost equal sum
//so also in this we try to check if we can form total_sum/2 or not
// if not then we check for total_sum/2 -1, and similarly keep going down until we found the one which can be formed
// then we just return the difference 
int minPartition(int n, int arr[]){

    int total_sum = 0;
    for (int i=0;i<n;i++){
        total_sum += arr[i];
    }

    int target = total_sum/2;

    bool dp[n][target+1]; 
    //base case
    for (int i=0;i<n;i++){
        dp[i][0] = true;
    }

    //base case 
    dp[0][arr[0]] = true;

    for (int i=1;i<n;i++){
        for (int j=1;j<=target;j++){
            //excluding
            bool excluding = dp[i-1][j];
            //including
            bool including = false;
            if (j <= arr[i]){
                including = dp[i-1][j-arr[i]];
            }

            dp[i][j] = excluding || including;
        }
    }

    int res = 0;
    for (int j=target;j>=0;j--){
        if (dp[n-1][j]){ //we can form j
            int remaining_sum = total_sum - j;
            res = remaining_sum - j;
            break;
        }
    }

    return res;

}

int main(){


    return 0;
}