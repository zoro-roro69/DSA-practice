#include <bits/stdc++.h>
using namespace std;


// n^2 solution
int dpSol1(int nums[], int n){
    // int n = nums.size();
    if (n<=1)
        return 0;
    
    if (nums[0] == 0)
        return -1; // not possible to reach end


    int dp[n];

    dp[n-1] = 0; //if you are already at end
    
    for (int i=n-2;i>=0;i--){
        if (i + nums[i] >= n-1)
            dp[i] = 1;
        else{
            
            dp[i] = n; //max
            for (int offset=1; offset<=nums[i]; offset++){
                dp[i] = min(dp[i], 1 + dp[i + offset]);
            }
        }
    }
    
    // for (int i=0;i<n;i++)
    //     cout << dp[i] << " ";
    
    // cout << endl;
    if (dp[0] == n) //not possible to each end
        return -1;

    return dp[0];
}


// O(n) solution   

int minJumps(int nums[], int n){
    if (n <= 1)
        return 0;

    if (nums[0] == 0)
        return -1;

    int steps = nums[0];
    int max_reach = nums[0];
    int jumps = 1;

    for (int i=1;i<n-1;i++){

        max_reach = max(max_reach, i + nums[i]);
        steps--;

        if (steps == 0){
            if (max_reach <= i){ //not reachable
                jumps = -1;
                break;
            }
            jumps++;
            steps = max_reach - i;
        }
    }

    return jumps;
}


int main(){

    int nums[] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    int n = 10;

    cout << dpSol1(nums, n) << endl;

    return 0;
}