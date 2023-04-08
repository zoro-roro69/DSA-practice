#include <bits/stdc++.h>
using namespace std;

// Some points to remember:
// cost of multiplying single matrice i.e A is = 0
// cost(no. of operations) of multiplying two matrices say A(3x4) , B(4x2) is = 3x4x2 = 8
// also for matrix multiplication to be possible we need this: column of first matrix == rows of second matrix
// dimension of the resultant matrix = rows of first matrix x cols. of second matrix. in above example it would be = 4x2

//matrix chain multiplaication problem
//in this we are given the the dimension of n matrices, and we need to return the 
//minimum number of ops. required to multiply those n matrices
// lets say we have matrices ABC
// now depending which matrices we choose to multiply first the no. of multiplcation ops. will vary
// there are two ways to multiply matrices
// A(BC) or AB(C)
// in general n matrices we can form n-1 such pairs
// example for n =4 ABCD
// we have 3 ways 
// (A)(BCD)
// (AB)(CD)
// (ABC)(D)
// out of these 3 we need to find the minimum.


//recursive c[i,j] = min(for k=i to j-1 c[i,k] + c[k+1,j] + p[i-1]*p[k]*p[j]))
int minOps(int p[], int s, int e){
    if (s>=e)
        return 0;

    int res = INT_MAX;
    for (int k=s;k<e;k++){
        int left = minOps(p, s, k); //cost of multiplying for i to k
        int right = minOps(p, k+1, e); //cost of multiplying from k+1 to e
        //total cost = left + right + (cost of multiplying resultant of i to k with resultant of k+1 to e)

        int total_ops = left + right + p[s-1]*p[k]*p[e];
        res = min(res, total_ops);

    }

    return res;
    
}

// using dp bottom up
// we start from finding cost of single matrices then cost of 2 matrices , then 3 and up till multiplying n matrices
// cost of multiplying single matrices i.e dp[1][1] = dp[2][2] = 0 = ... = dp[n][n] = 0
int minOpsDP(int p[], int n){

    int dp[n+1][n+1];

    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++)
            dp[i][j] = 0;
    }


    for (int x=1;x<n;x++){
        for (int i=1;i<=n-x;i++){
            int j = i+x;
            dp[i][j] = INT_MAX;
            for (int k=i;k<j;k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j]);
            }
        }
    }

    return dp[1][n];

}


int main(){

    int p[] = { 1, 2, 3, 4, 3 };
    cout << minOps(p, 1, 4) << endl;
    cout << minOpsDP(p, 4) << endl;


    return 0;
}