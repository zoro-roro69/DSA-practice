#include <bits/stdc++.h>
using namespace std;


int f(int i, vector <bool> &visited){
    if (i<0)
        return 1;
    if (visited[i])
        return f(i-1, visited);
    
    int single = f(i+1, visited);
    int couple = 0;

    for (int j = 0;j<i;j++){
        if (visited[j])
            continue;
        visited[j] = true;
        couple += f(i-1, visited);
        visited[j] = false;
    }

    return single + couple;
}



int f2(int n){
    if (n<=2)
        return n;
    //
    // when we keep it as single so we have 1*f(n-1) elements
    // when we try to pair it with remaining n-1 elements we have (n-1)*f(n-2)
    // n-2 because for pairing you consume 2 items
    return f2(n-1) + (n-1)*f2(n-2);

}


int dpSolution(int n){
    vector <int> dp(n+1,0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i=3;i<=n;i++){
        dp[i] = dp[i-1] + (i-1)*dp[i-2];
    }
    return dp[n];
}

//answer with modulo
const int MOD = 1000000007;
int countFriendsPairings(int n) { 
    vector <long long int> dp(n+1,0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i=3;i<=n;i++)
        dp[i] = ((dp[i-1])%MOD + ((i-1)*dp[i-2])%MOD)%MOD;

    return dp[n]%MOD;
}

int main(){

    return 0;
}