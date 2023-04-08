#include <bits/stdc++.h>
using namespace std;

bool helper(int sum1, int sum2, int i, int arr[]){
    if (i<0)
        return sum1==sum2;
    
    return helper(sum1 + arr[i], sum2, i-1, arr) || 
            helper(sum1, sum2 + arr[i], i-1, arr);
}

//check take u forward dp playlist
int subsetSum(int n, int arr[]){
    return helper(0, 0, n-1, arr);
}

class Solution{

    bool recursive(int sum, int i, int arr[]){

        if (sum == 0)
            return true;
        if (i < 0)
            return false;

        return recursive(sum-arr[i], i-1, arr) //including
            || recursive(sum, i-1, arr); //excluding

    }

    bool subsetSum(int n, int arr[]){
        
        int total_sum = 0;
        for (int i=0;i<n;i++)
            total_sum += arr[i];
        if (total_sum%2) return false;
        // return recursive(total_sum/2, n-1, arr);

        //dp solution
        int sum = total_sum/2;
        bool dp[sum+1][n+1]; //adding 1 because using 1 based indexing

        //base case
        for (int i=0;i<=n;i++)
            dp[0][i] = true;
        //base case
        for (int i=1;i<=sum;i++){
            dp[i][0] = false;
        }

        for (int i=1;i<=sum;i++){
            for (int j=1;j<=n;j++){
                int item = j-1; 
                dp[i][j] = false;
                if (arr[item] <= i){ //including
                    dp[i][j] = dp[i-arr[item]][j-1];
                }
                dp[i][j] = dp[i][j] || dp[i][j-1]; //not including
            }
        }

        return dp[sum][n];
    }


    //space optimised since we need only previous row
    bool subsetSum2(int n, int arr[]){
        int total_sum = 0;
        for (int i=0;i<n;i++)
            total_sum += arr[i];
        if (total_sum%2) return false;

        int sum = total_sum/2;
        bool prev[sum+1]; //1 based indexing
        bool cur[sum+1];
        prev[0] = cur[0] = true;


        for (int i=1;i<=n;i++){ //i - items
            for (int j=1;j<=sum;j++) { //j - sums
                //exlcuding
                cur[j] = prev[j];
                int item = i-1;
                //including
                if (arr[item] <= j)
                    cur[j] = cur[j] || prev[j-arr[item]];

            }
            
            for (int j=0;j<=sum;j++)
                prev[j] = cur[j];
        }

        return cur[sum];
    }
};


class Solution2{

    bool recursive(int target, int i, int arr[]){
        if (target == 0)
            return true;
        if (i == 0)
            return target == arr[i];
        
        bool excluding = recursive(target, i-1, arr);
        bool including = false;
        if (target <= arr[i])
            including = recursive(target - arr[i], i-1, arr);

        return excluding || including;
    }

    bool subsetSum(int n, int arr[]){
        int total_sum = 0;
        for (int i=0;i<n;i++)
            total_sum += arr[i];
        if (total_sum%2) return false;

        int target = total_sum/2;

        int dp[n][target+1];

        //base case
        for (int i=0;i<n;i++){
            dp[i][0] = true;
        }

        //base case 2
        dp[0][arr[0]] = true;

        for (int i=1;i<n;i++){
            for (int j=1;j<=target;j++){
                bool excluding = dp[i-1][j];
                bool including = false;
                if (arr[i] <= j){
                    including = dp[i-1][j-arr[i]];
                }

                dp[i][j] = excluding || including;
            }
        }

        return dp[n-1][target];


    }

    bool spaceOptimised(int n, int arr[]){
        int total_sum = 0;
        for (int i=0;i<n;i++)
            total_sum += arr[i];
        if (total_sum%2) return false;

        int target = total_sum/2;

        vector <bool> prev(target+1, false);
        vector <bool> cur(target+1, false);
        //base case
        prev[0] = cur[0] = true;
        prev[arr[0]] = true;


        //replace dp[i-1] with prev
        //replace dp[i] with cur
        for (int i=1;i<n;i++){
            for (int j=1;j<=target;j++){
                
                bool excluding = prev[j];
                bool including = false;

                if (arr[i] <= j){
                    including = prev[j-arr[j]];
                }

                cur[j] = excluding || including;
            }
        }

        return prev[target];
    }

};

int main(){

    int arr[]  = {12,1,13,2};
    cout << subsetSum(3, arr) << endl;


    return 0;
}