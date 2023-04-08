#include <bits/stdc++.h>
using namespace std;

// Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to 
// remove/delete and insert the minimum number of characters from/in str1 to transform 
// it into str2. It could be possible that the same character needs to be removed/deleted 
// from one point of str1 and inserted to some another point.


int f(int i, int j, string &s1, string &s2){
    if (i < 0 && j<0)
        return 0;
    else if (i < 0)
        return j+1;
    else if (j < 0)
        return i+1;
    else{
        int including = INT_MAX;        
        if (s1[i] == s2[j]){
            including = f(i-1, j-1, s1, s2);
        }

        int excluding = 1 + min(f(i-1, j, s1, s2), //removing
                                f(i, j-1, s1, s2) //deleting
                        );

        return min(including, excluding);
    }
}

// dp solution
int minInsertionsDeletionDp(string s1, string s2){
    int n = s1.size();
    int m = s2.size();

    int dp[n+1][m+1]; //1 based indexing

    //init
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            dp[i][j] = 0;
        }
    }

    for (int i=1;i<=n;i++){
        dp[i][0] = i;
    }

    for (int j=1;j<=m;j++){
        dp[0][j] = j;
    }
    
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            dp[i][j] = INT_MAX;
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            dp[i][j] = min({dp[i][j], dp[i-1][j], dp[i][j-1]});
        }
    }

    return dp[n][m];
}

// we can also think of this problem similar to finding longest common subsequence
// to do the min ops to make two strings equal we need to retain the longest common subsequence
// so we need to find the length of longest common subsequence = l
// then our result would be = (n-l) + (m-l)
// n = lenght of string 1
// m = length of string 2

int main(){

    string s1 = "geeksforgeeks";
    string s2 = "geeks";

    cout << f(s1.size()-1, s2.size()-1, s1, s2) << endl;

    return 0;
}