#include <bits/stdc++.h>
using namespace std;

// Given a wooden stick of length n units. The stick is labelled from 0 to n. For example,
//  a stick of length 6 is labelled as follows:
// 0 1 2 3 4 5 6
// Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
// You should perform the cuts in order, you can change the order of the cuts as you wish.
// The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.
// Return the minimum total cost of the cuts.
int f(int i, int j, vector <int> &cuts){
    //base case is pending
    if (i == j) //also if i+1 == j
        return 0;

    int res = INT_MAX;
    for (int k=0;k<cuts.size();k++){
        if (cuts[k]>i && cuts[k] < j){ //check if cut is possible
            int cost = (j-i) + f(i, cuts[k], cuts) + f(cuts[k], j, cuts);
            res = min(res, cost);
        }
    }
    if (res == INT_MAX) //no cuts made
        return 0;
    return res;


}


//this solution times out because n == 10^6 :)
int mimimumCostToCutDp(int n, vector <int> &cuts){

    if (n<=1)
        return 0;

    // int dp[n+1][n+1];
    vector <vector <int>> dp(n+1, vector <int>(n+1,0));

    //base case i == j: return 0;
    // for (int i=0;i<=n;i++){
    //     dp[i][i] = 0;
    // }
    // cout << "done init" << endl;

    // cout << "here" << endl;
    for (int i=n-1;i>=0;i--){
        for (int j=i+1;j<=n;j++){
            int cost = INT_MAX;
            for (int k=0;k<cuts.size();k++){
                if (cuts[k]>i && cuts[k]<j){
                    cost = min(cost, (j-i) + dp[i][cuts[k]] + dp[cuts[k]][j]);
                }
            }
            if (cost == INT_MAX) //no cuts made
                dp[i][j] = 0;
            else
                dp[i][j] = cost;
        }
    }

    return dp[0][n];

}

int f2(int i, int j, vector <int> &cuts){
    //base case pending
    if (i>j)
        return 0;

    int res = INT_MAX;
    for (int k=i;k<=j;k++){
        res = min(res, f2(i, k-1, cuts) + f2(k+1, j, cuts));
    }

    res += (cuts[j+1]-cuts[i-1]);
    return res;


}

int minCostToCutStick(int n, vector <int> &cuts){

    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    // return f2(1, cuts.size()-2, cuts);

    int m = cuts.size();
    vector <vector <int>> dp(m, vector<int> (m, 0));

    //base case i>j return 0;
    // for (int i=0;i<m;i++){
    //     for (int j=i-1;j>=0;j--){
    //         dp[i][j] = 0;
    //     }
    // }

    for (int i=m-2;i>0;i--){
        for (int j=i+1;j<m-1;j++){
            dp[i][j] = INT_MAX;

            for (int k=i;k<=j;k++){
                dp[i][j] = min(dp[i][j], cuts[j+1]-cuts[i-1] +dp[i][k-1] + dp[k+1][j]);
            }
        }
    }

    for (int i=0;i<m;i++){
        for (int j=0;j<m;j++){
            cout << dp[i][j] << " ";
        }cout << endl;
    }

    return dp[1][m-2];

}


int main(){

    int n =9;
    vector <int> arr{5,6,1,4,2};

    cout << minCostToCutStick(n, arr) << endl;

    return 0;
}