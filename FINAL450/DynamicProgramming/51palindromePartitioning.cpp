#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(int i, int j, string &s){
    for (;i<j;i++,j--){
        if (s[i]!=s[j])
            return false;
    }

    return true;
}

int f(int i, string &s){
    //base case pending
    if (i >= s.size())
        return 0;

    if (isPalindrome(i,s.size()-1, s))
        return 0;

    int res = INT_MAX;
    for (int k=i;k<s.size();k++){
        if (isPalindrome(i,k,s)){
            res = min(res, 1 + f(k+1,s));
        }
    }

    return res;
}


// If we find all palindromic substring 1st and then we calculate minimum cut, 
// time complexity will reduce to O(n2). 

int fpalindrome(int i, int j, string &s){ //returns true if s[i..j] is palindrome
    if (i >= j)
        return true;

    return s[i] == s[j] && fpalindrome(i+1, j-1, s);
}

int dpSol(string s){

    int n = s.size();
    bool p[n][n];  //returns true if p[i][j] is palindrome

    //base case i>=j
    for (int i=0;i<n;i++){
        for (int j=i;j>=0;j--){
            p[i][j] = 1;
        }
    }

    for (int i=n-1;i>=0;i--){
        for (int j=i+1;j<n;j++){
            p[i][j] = (s[i] == s[j] && p[i+1][j-1]);
        }
    }


    int cost[n+1]; //cost[i] returns min cuts needes to partiton string[i to end]
    cost[n] = 0;
    for (int i=n-1;i>=0;i--){
        cost[i] = INT_MAX;
        if (p[i][n-1]){
            cost[i] = 0;
            continue;
        }
        for (int k=i;k<n;k++){
            if (p[i][k]){
                cost[i] = min(cost[i], 1 + cost[k+1]); 
            }
        } 
    }

    return cost[0];

}




int main(){

    string s = "ababbbabbababa";

    cout << f(0, s) << endl;
    cout << fpalindrome(0, s.size()-1, s) << endl;
    cout << dpSol(s) << endl;
    return 0;
}