#include <bits/stdc++.h>
using namespace std;

// Consider a game where a player can score 3 or 5 or 10 points in a move. 
// Given a total score n, find number of distinct combinations to reach the given score.


//when order matters
// i.e if n = 8
// then there are two ways {3, 5} and  {5, 3}
int reachScoreOrderMatters(int n){

    int dp[n+1];
    //base cases
    dp[0] = 1;
    dp[1] = dp[2]  = 0 ; //no way to make these since lowest possible score is 3

    for (int i=3;i<=n;i++){
        int score = dp[i-3];
        if (i >= 5)
            score += dp[i-5];
        if (i >= 10)
            score += dp[i-10];

        dp[i] = score;
   }

    return dp[n];

}

// order doesnt matter
// n = 8;
// since order doesnt matter so {3,5} {5,3} are same
// so total ways = 1;
int reachScoreOrderDoesntMatter(int n){

    int dp[n+1];
    //base case
    dp[0] = 1;
    dp[1] = dp[2] = 0;

    //since order doesnt matter
    //we will consider only one order in which we take 3 first then 5 and then 10

    for (int i=3;i<=n;i++){
        dp[i] = dp[i-3];
    }

    for (int i=5;i<=n;i++){
        dp[i] += dp[i-5];
    }

    for (int i=10;i<=n;i++)
        dp[i] += dp[i-10];


    return dp[n];

}


int main(){

    return 0;
}