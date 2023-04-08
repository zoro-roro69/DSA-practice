#include <bits/stdc++.h>
using namespace std;

// A Derangement is a permutation of n elements, such that no element appears in its original position.
//  For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.
// Given a number n, find the total number of Derangements of a set of n elements.

// Input: n = 2
// Output: 1
// For two elements say {0, 1}, there is only one 
// possible derangement {1, 0}

// Input: n = 3
// Output: 2
// For three elements say {0, 1, 2}, there are two 
// possible derangements {2, 0, 1} and {1, 2, 0}

// Input: n = 4
// Output: 9
// For four elements say {0, 1, 2, 3}, there are 9
// possible derangements {1, 0, 3, 2} {1, 2, 3, 0}
// {1, 3, 0, 2}, {2, 3, 0, 1}, {2, 0, 3, 1}, {2, 3,
// 1, 0}, {3, 0, 1, 2}, {3, 2, 0, 1} and {3, 2, 1, 0}

// solution
// lets say that we have n elemetns = {0, 1, ,2, .... n-1}
// now 0 can be placed at all other indexes except '0' i.e it can be placed in n-1 places
// so the answer is (n-1)*[solution of subproblems]
// now for the 'solution of subproblems part'
// when we place 0 at any of the n-1 indexes lets say ith index, we have two case:
//      1.  we swap the them, and fix there positions,
                // i.e now ith element is at 0 index and 0 element is at ith index
                // since we have fixed two elements now we need to place n-2 elments
                // f(n-2)

//      2.  we place 0th element at ith index , but we dont place or fix the ith element at 0
            //since we only fixed place for 0, we still have n-1 elements remaining
            //so  = f(n-1)

// therefore f(n) = (n-1)*[f(n-2) + f(n-1)];

int f(int n){
    //base case pending
    if (n<=1)
        return 0;
    if (n == 2)
        return 1;

    return (n-1)*(f(n-2) + f(n-1));

}

int dpSol(int n){

    int dp[n+1];
    dp[0] = dp[1] = 0;

    dp[2] = 1;

    for (int i=3;i<=n;i++){
        dp[i] = (i-1)*(dp[i-2] + dp[i-1]);
    }

    return dp[n];

}

//can be further space optimised
int dpSol2(int n){

    int res;
    int a, b; //a = n-2 state, b = n-1 state
    a = 0; //for i = 1
    b = 1;// for i = 2
    for (int i = 3;i<=n;i++){
        res = (i-1)*(a + b);
        a = b;
        b = res;
    }
    
    return res;

}


int main(){

    cout << f(4) << endl;
    cout << dpSol(4) << endl;
    cout << dpSol2(4) << endl;

    return 0;
}