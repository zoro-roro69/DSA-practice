#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

// Given a fence with n posts and k colors, find out the number of ways of painting the fence so 
// that not more than two consecutive fences have the same colors. Since the answer can be large 
// return it modulo 10^9 + 7.

//so in this basically we construct the solution from the previous
//exame for n = 1 and k = 3, lets say k = r ,g, b
// we can paint the fence in k ways
//now n = 2 and k = 3
// no. of ways in which we have same on 2 consecutive is = k = 3
// rr
// gg
// bb
// no. of ways in which we have different is = k*(k-1) = simple permutation and combination:
// rg
// rb
// gr
// gb
// br
// bg
// now n = 3 , k =3 we can add one fence to n =2 to construct our answer
// so the number of ways in which this third fence can have "same" color as its previous, (we use diff of previous)
// rg g
// rb b
// gr r
// gb b
// br r
// bg g
// here we can se we that it is same as diff of two we just repeated the last color
// now the number of ways in which, third fence is of different color than its previous
// for calculating this we use both "same" and diff of previous n = 2
// for example from same
// rr x (x can be any of k-1 color except the r)
// gg x (x can be any of k-1 color excep the g)
// ...
// ... and so on
// similarly from diff
// rg x (x can be any of the color except g)
// rb x (x can be any of the color except b) ... and so on
// so the final answer
// total ways = same + diff;
// same = different of previous
// diff = (same of prev + diff of prev)*(k-1);


int paintingTheFence(int n, int k){
    if (n == 0)
        return 0;
    if (n == 1){
        return k;
    }
    //for n == 2
    int same = k;
    int diff = k*(k-1);

    for (int i=3;i<=n;i++){
        //same for this can constructed from diff of previous
        int temp = same;
        same = diff;
        //diff can be consructed from both same and diff of prev
        diff = ((diff + temp)%MOD)*(k-1)%MOD;
    }
    return diff + same;
}

int main(){

    return 0;
}