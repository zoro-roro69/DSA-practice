#include <bits/stdc++.h>
using namespace std;


string getsubstr(int start, int end, string &s){
    string res = "";
    for (int i=start;i<=end;i++){
        res += s[i];
    }
    return res;
}

int f(int i, int j, string &s, unordered_set<string> &dict){
    string sub = getsubstr(i,j,s);
    if (dict.find(sub)!= dict.end())
        return true;


    for (int k=i; k<j;k++){
        if (f(i,k, s, dict) && f(k+1, j, s, dict))
            return true;
    }

    return false;
}

//n^3 solution
int dpSol(string s, unordered_set<string> &dict){
    int n = s.size();
    int dp[n][n];

    for (int i=n-1;i>=0;i--){
        for (int j=i;j<n;j++){
            dp[i][j] = false;
            string sub = getsubstr(i,j,s);
            if (dict.find(sub)!=dict.end())
                dp[i][j] = true;
            
            for (int k=i;k<j;k++){
                if (dp[i][k] && dp[k+1][j])
                    dp[i][j] = true;
            }
        }
    }

    return dp[0][n-1];

}


int f2(int start, string &s, unordered_set <string> &dict){
    if (start >= s.size())
        return true;

    for (int i=start; i<s.size();i++){
        string sub = getsubstr(start, i, s);
        if (dict.find(sub)!=dict.end() && f2(i+1, s, dict)){
            return true;
        }
    }

    return false;

}

int f2_iter(string s, unordered_set <string> &dict){

    int n = s.size();
    int dp[n+1];
    //base case start >= n return 1
    dp[n] = 1;

    for (int start = n-1 ; start>=0 ; start--){
        dp[start] = false;
        for (int j=start;j<n;j++){
            string sub = getsubstr(start, j, s);
            if (dict.find(sub) != dict.end() && dp[start+1])
                dp[start] = true;
                
        }
    }

    return dp[0];
}

//rather than passing start index, pass the substring 
int dpSol2(string s, unordered_set<string> &dict, unordered_map<string, int> &dp){
    if (s == ""){
        return 1;
    }
    if (dp[s]!=0)
        return dp[s];

    for (int i=0; i<s.size();i++){
        string sub = getsubstr(0, i, s);
        if (dict.find(sub)!=dict.end() && dpSol2(getsubstr(i+1, s.size()-1, s), dict, dp)){
            dp[s] = 1;
            return 1;
        }
    }
    dp[s] = -1;
    return false;

}


int main(){

    return 0;
}