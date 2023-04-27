#include <bits/stdc++.h>
using namespace std;



inline bool validStr(string s){
      
       if (s[0] == '0')
           return false;
       if (s[0] == '1')
           return true;
       if (s[0] == '2')
           return s[1] >= '0' && s[1] <= '6';
       
       return false;
       
}

int f(string &s, int i){
    if (i == s.size())
        return 1;
    int res = 0;
    if (s[i] != '0')
        res = f(s, i+1);
    if (i+1 < s.size() && validStr(s.substr(i,2))){
        res += f(s, i+2);
    }

    return res;

}

int CountWaysDp(string s){
    // Code here
    // return f(str, 0);
    int n = s.size();
    vector <int> dp(n+1, 0);

    //base case
    dp[n] = 1;

    for (int i=n-1;i>=0;i--){
        dp[i] = 0;
        if (s[i] != '0')
            dp[i] = dp[i+1];
        if (i+1 < s.size() && validStr(s.substr(i, 2)))
            dp[i] = (dp[i] + dp[i+2])%1000000007;
    }

    return dp[0];
}


int main(){

    return 0;
}