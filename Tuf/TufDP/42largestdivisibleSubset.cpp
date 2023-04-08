#include <bits/stdc++.h>
using namespace std;

bool divisible(vector <int> &arr, int element){
    for (auto x:arr){
        if (x%element && element%x)
            return false;
    }
    return true;
}

void f(int i, vector <int> &arr, vector <int> &cur, vector <int> &res){

    if (i>=arr.size()){
        if (cur.size() > res.size())
            res = cur;
        return;
    }

    //including cur
    // if (cur.empty() == true || divisible(cur, arr[i])){
    //if arr is already sorted
    if (cur.empty() == true || arr[i]%cur.back() == 0){
        cur.push_back(arr[i]);
        f(i+1, arr, cur, res);    
        cur.pop_back();
    }

    //not including cur
    f(i+1, arr, cur, res);
}
//this returns the length of largest divisible array
int f2(int i, int prev, vector <int> &arr){
    if (i>=arr.size())
        return 0;

    int including = 0;
    int excluding = 0;

    if (prev == -1 || arr[i]%arr[prev] == 0){
        including = 1 + f2(i+1, i, arr);
    }else{
        excluding = f2(i+1, prev, arr);
    }

    return max(including, excluding);

}

vector <int> largestDivisibleDp(vector <int> &nums){
    int n = nums.size();
    if (n <=1)
        return nums;

    sort(nums.begin(), nums.end());

    int dp[n+1][n+1]; //second index is one shifted

    // for (int i=0;i<=n;i++){
    //     for (int j=0;j<=n;j++)
    //         dp[i][j] =-1;
    // }

    //base case, i == n
    for (int i=0;i<=n;i++){
        dp[n][i] = 0;
    }

    for (int i=n-1;i>=0;i--){
        for (int j=i-1;j>=-1;j--){
            int including = 0;
            int excluding = 0;
            if (j == -1 || nums[i]%nums[j] == 0){
                including = 1 + dp[i+1][i+1];
            }

            excluding = dp[i+1][j+1];
            dp[i][j+1] = max(including, excluding);
        }
    }

    // cout << "dp matrix" <<endl;
    // for (int i=0;i<=n;i++){
    //     for (int j=0;j<=n;j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    vector <int> res;
    int i = 0, j =0;
    while (i < n && j < n) {
        if (dp[i][j] == dp[i+1][j]){ //not includded
            i = i+1;
        }else if(dp[i][j] == dp[i+1][i+1]+1){
            //included
            res.push_back(nums[i]);
            i = i+1;
            j = i+1;

        }
    }


    // cout << "res:::::" << endl;
    // cout << dp[0][0] <<endl;


    return res;
}

//even better dp solution
vector <int> largestDivisibleDp(vector <int> &nums){
    int n  = nums.size();
    if (n <= 0)
        return nums;

    sort(nums.begin(), nums.end());

    int dp[n];
    int par[n]; //to store parent
    
    for (int i=0;i<n;i++){
        dp[i] = 1;
        par[i] = -1;
    }

    int max_len = 0;
    int last_ind = 0;
    for (int i=1;i<n;i++){
        for (int j=i-1;j>=0 && j+1>dp[i];j--){
            if (nums[i]%nums[j] == 0 && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                par[i] = j;
            }
        }
        if (dp[i] > max_len){
            max_len  = dp[i];
            last_ind = i;
        }
    }

    vector <int> res;
    while (last_ind!=-1)
    {
        res.push_back(nums[last_ind]);
        last_ind = par[last_ind];
    }

    return res;

}


int main(){

    vector <int> arr{2,3,3,4};
    vector <int> cur;
    vector <int> res;
    sort(arr.begin(), arr.end());
    f(0, arr, cur, res); 

    for (auto x:res)
        cout << x << " ";
    cout << endl;
    largestDivisibleDp(arr);
    return 0;

}