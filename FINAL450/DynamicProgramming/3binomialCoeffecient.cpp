#include <bits/stdc++.h>
using namespace std;


//these two are also correct solutions, but im having some problem in MOD operation  
//because it involves division operation 
// int nCr(int n, int r){
//     if (n == r || r == 0)
//         return 1;
//     if (r == 1)
//         return n;

//     int res = n/r * nCr(n-1, r-1);

//     return res;
// }

int nCr(int n, int r){
    if (n < r)
        return 0;
    if (n == r || r == 0)
        return 1;

    int res = 1;
    for (int i=0;i<r;i++){
        res = res*((n-i)/(r-i));
    }
}




// to understand this solution,
//  first write down for n=0 0C0,
// then in next line for n=1 {1C0, 1C1},
// then write down for n=2 {2C0, 2C1, 2C2}
// similarly for n = 3, {3C0, 3C1, 3C2, 3C3} 
// the point  of wriiting this down is to see a pattern.
// here is the example:
// n=0  1
// n=1  1 1
// n=2  1 2 1
// n=3  1 3 3 1 
// this type of triangle is called pascals triangle 
// unique property of pascals triangle is that each row can be derived from previous row
// starting with n=0    1 0 //0C0 is always 1, added 0 at end for simplicity
// then for n=1 first element is 1 as 1C0 is 1, then to get the next element lets say it is at column j
// elem j = sum of elements at previous row at columns j and j-1
// if i is current row, then element if i,j = triangle[i-1][j] + triangle[i-1][j-1]
//so using this property we form our solution

int nCrUsingDP(int n, int r){
    if (n < r)
        return 0;
    if (n == r || r == 0)
        return 1;

    r = min(r, n-r); //as nCr == nC(n-r), so we take whatever is smaller

    int dp[r+1] = {0};
    dp[0] = 1;

    for (int i=1;i<=n;i++){
        for (int j=min(i,r);j>=1;j--){ //start filling from right
            dp[j] = dp[j] + dp[j-1];
        }
    }

    return dp[r];
}

int main(){
    return 0;
}