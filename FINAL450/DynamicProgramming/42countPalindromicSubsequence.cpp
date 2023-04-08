#include <bits/stdc++.h>
using namespace std;



// if (s[i] == s[j]){
//     return 1 + f(i+1,j,s) + f(i, j-1,s);
// }
// in this case we do not subtract f(i+1, j-1) although it is counted twice
// consider this example "aba"
//  for this we call = "1 + f(ab), f(ba)"
// we add 1 for the subsequence 'aa' 
// now in further two recursions f(b) is counted twice, and thats okay
// first it is counted as individual subsequecne 'b'
// we count it second time because we also need it as part of the subsequence 'aba'

int f(int i, int j, string &s){
    if (i>j)
        return 0;
    if (i == j)
        return 1;

    if (s[i] == s[j]){
        return 1 + f(i+1,j,s) + f(i, j-1,s);
    }
    //if not equal
    return f(i+1, j,s) + f(i, j-1,s) - f(i+1, j-1,s);

}

int dpSol(string s){
    int n = s.size();
    int dp[n+1][n+1];

    //base case i>j return 0;
    for (int i=0;i<=n;i++){
        for (int j=0;j<i;j++){
            dp[i][j] = 0;
        }
    }

    // base case i == j return 1;
    for (int i=0;i<n;i++){
        dp[i][i] = 1;
    }

    for (int i=n-1;i>=0;i--){
        for (int j = i+1;j<n;j++){
            if (s[i] == s[j]){
                dp[i][j] = 1 + dp[i+1][j] + dp[i][j-1];
            }else{
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
            }
        }
    }
    


    return dp[0][n-1];

}

//with modulo
class Solution{
    public:
    /*You are required to complete below method */
    long long  MOD = 1000000007;
    
    long long int dpSol(string s){
    int n = s.size();
    long long int dp[n+1][n+1];

    //base case i>j return 0;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            dp[i][j] = 0;
        }
    }

    // base case i == j return 1;
    for (int i=0;i<n;i++){
        dp[i][i] = 1;
    }

    for (int i=n-1;i>=0;i--){
        for (int j = i+1;j<n;j++){
            if (s[i] == s[j]){
                dp[i][j] = ((long long)1%MOD + dp[i+1][j]%MOD + dp[i][j-1]%MOD)%MOD;
                // dp[i][j] = ((long long)1 + dp[i+1][j])%MOD;
                // dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
            }else{
                dp[i][j] = (dp[i+1][j]%MOD + dp[i][j-1]%MOD - dp[i+1][j-1]%MOD)%MOD;
                if (dp[i][j] < 0) 
                    dp[i][j] += MOD;
                // dp[i][j] = (dp[i+1][j] + dp[i][j-1])%MOD;
                // dp[i][j] = (dp[i][j] - dp[i+1][j-1])%MOD;
                
            }
        }
    }
    


    return (dp[0][n-1]%MOD);

}
    long long int  countPS(string str)
    {
       //Your code here
       return dpSol(str);
    }
     
};
int main(){

    string s = "aba";
    cout << f(0, s.size()-1, s) << endl;

    return 0;
}