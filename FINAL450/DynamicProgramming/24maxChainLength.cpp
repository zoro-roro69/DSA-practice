#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;

    val(){

    }
};

struct comparator{
    bool operator()(const val &a, const val &b){
        if (a.second < b.second)
            return true;
        else if (a.second > b.second)
            return false;
        else
            return a.first <= b.first;
    }
};

/*You are required to complete this method*/
int maxChainLen(struct val p[], int n){

    sort(p, p + n, comparator());

    // for (int i=0;i<n;i++){
    //     cout << p[i].first << " " << p[i].second << endl;
    // }

    int dp[n];
    for (int i=0;i<n;i++){
        dp[i] = 1;
    }

    int res = 1;
    for (int i=1;i<n;i++){
        for (int j=0;j<i;j++){
            if (p[i].first > p[j].second){
                if (dp[j] + 1 > dp[i])
                    dp[i] = 1 + dp[j];

            }
        }
        res = max(res, dp[i]);
    }

    return res;
}


int main(){

    val p[5];

    p[0].first = 5;
    p[0].second = 24;

    p[1].first = 39;
    p[1].second = 60;

    p[2].first = 15;
    p[2].second = 28;
    
    p[3].first = 27;
    p[3].second = 40;
    
    p[4].first = 50;
    p[4].second = 90;
    
    cout << maxChainLen(p, 5) << endl;

    return 0;
}