#include <bits/stdc++.h>
using namespace std;

bool mycompare(const vector<int> &a, const vector<int> &b){

    if (a[0] < b[0])
        return true;
    else if (a[0] > b[0])
        return false;
    else{
        return a[1] < b[1];
    }

}

int maxLengthPairChain(vector<vector<int>>& pairs){

    sort(pairs.begin(), pairs.end(), mycompare);
    int n = pairs.size();
    int dp[n];

    for (int i=0;i<n;i++)
        dp[0] = 1;

    int res = 1;
    for (int i=1;i<n;i++){
        for (int j=0;j<i;j++){
            if (pairs[j][1] < pairs[i][0] && dp[j]+1 > dp[i]){
                dp[i] = dp[j]+1;
            }
        }
        res = max(res, dp[i]);
    }

    return res;

}


int main(){


    return 0;
}