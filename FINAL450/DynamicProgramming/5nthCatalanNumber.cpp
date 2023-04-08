#include <bits/stdc++.h>
using namespace std;

// In combinatorial mathematics, the Catalan numbers are a sequence of natural 
// numbers that occur in various counting problems, often involving recursively 
// defined objects. 
// The nth Catalan number can be expressed directly in terms of binomial coefficients by
// cn = (2n)!/(2n+1)!

//formulae for finding nth catalan number
// c0 = 1;
// c1 = 1;
// c2 = c0.c1 + c1.c0 = 2
// c3 = c0.c2 + c1.c1 + c2.c0 = 2 + 1 + 2 = 5
// similarly
// c4 = c0.c3 + c1.c2 + c2.c1 + c3.c0 = 5 + 2 + 2 + 5 = 14 


int nthCatalanNumber(int n){

    if (n <= 1)
        return 1;
    int catalan[n+1];

    catalan[0] = catalan[1] = 1; 

    for (int i=2;i<=n;i++){
        catalan[i] = 0;
        for (int j = 0; j<i;j++){
            catalan[i] += catalan[j]*catalan[i-j-1];
        }
    }

    return catalan[n];
}

int main(){

    cout << nthCatalanNumber(4) << endl;
    cout << nthCatalanNumber(8) << endl;
    cout << nthCatalanNumber(6) << endl;
    cout << nthCatalanNumber(5) << endl;

    return 0;
}


// 10 examples where catalan numbers are used in questions


//////// Example 1, 
// given n nodes find total no. of Binary search trees that can be formed. (BST = root>=left && root<=right)
// for example for n=0, answer is 1
// for n=1, answer is 1
// for n=2 (keys = 1,2)
//  now hrere there are two ways first when 1 is root and second when 2 is the root
// 1                2
//  \              /
//   2            1
// so the answer is 2
// for n = 3 (keys = 1,2,3)
// at root we have 3 possibilities i.e to have 1 ,2 or 3 as root
// when we have 1 as root on left side we have 0 elmements(c0)
// and on right we have 2 elements (c2)
// res1 = so total no. of bsts when we have 1 as root = c0*c2 = 2
// now when we have 2 as root
// on left and right we have 1 each (c1)
// res2 = total no. of bsts when we have 2 as root = c1*c1 = 1;
// when we have 3 as root
// on left we have 2 elements (c2)
// on right we have 1 element (c1)
// res3 total no. of bsts when we have 3 as root = c2*c1 = 1;
// so final aswer i.e total no. of bsts when we have 3 nodes = res1 + res2 + res3
// which is basically 3rd catalan number c3 = c0.c2 + c1.c1 + c2.c0


int noOfBsts(int n){
    //assuming keys are distinct
    if (n<=1)
        return 1;

    int catalan[n+1];
    catalan[0] = catalan[1] = 1;

    for (int i=2;i<=n;i++){
        catalan[i] = 0;
        for (int j=0;j<i;j++){
            catalan[i] += catalan[j]*catalan[i-j-1];
        }
    }

    return catalan[n];
}


// Example 2 - count no. of unlabbeled trees when you have n nodes (all n nodes are similar)
// problem is exaclty same as above res = nth catalan number

// Example 3- count no. of binary trees when you have n labelelled nodes
// for n=3 you have {1,2,3} nodes unlike bsts you dont have to maintain order you can arrange
// as you like
// so formula for this is  = cn*n!;


// Exmaple 4- no. of ways to arrange n pair parenthesis which are correctly matched
// for n = 0 answer 1
// for n = 1 answer  = 1 = ()
// for n = 2
// after we put the first parenthest = ()
// now we have two options either to put the second one outside the first = ()() = nc0*nc1 = (0 inside) * (1 outside)
// or put the second inside the first = (()) = nc1*nc0 = (1 inside)* (0 outside)
// which is basically cn = c2 = c0.c1 + c1.c0
// so the answer is nth catalan number


//Example 5 - Dyck words , in this you are given two alphabets/or characters each with count = n.
// lets say the two chars. are x and y, and n = 3
// now we have to find in how many ways we can arrange them such that at any point no. of x is always >= to number of
// of y's
// example one arrangement for n = 3 is xyxyxy which is valid
// other arrangement is yyxyxx which is invalid, as you can see till index 0 we have x count = 0, y count = 1
// y count >= x count therefore invalid
// this question can also be solved using catalan number.
// it is similar to parenthesis question, lets consider the x as opening bracket and y as closing bracket
// now for n = 0, ans = 1
// now for n = 1, ans = 1
// now for n = 2, 
// lets put the first xy (parenthesis) = xy
// now for second xy we have two options either to put outside the first = xyxy = nc0*nc1 = (0 inside) * (1 outside)
// or put second inside the first = xxyy = nc1*nc0 = (1 inside)* (0 outside) 
// which is basically cn = c2 = c0.c1 + c1.c0
// so the answer is nth catalan number

//Example 5 - mountain ranges , in this we are give n upstrokes and n downstrokes
// 1 upstroke = means to go up by 1
// 1 downstroke = means to go down by 1
// using these n upstrokes and n downstrokes we have to form a mountain range such that at any time
// we should not go down below the 0 level or horizontal level or sea level
// example for n = 3
// one valid arrangement
//  /\
// /  \/\
// ----------
// invalid arrangement as we go below the horizontal level
// /\   /\
// ------------
//    \/

// same as above example this can also be treated as parenthesis problem consider '/' as opening bracket
// and '\' as closing bracket
// so the answer is given by nth catalan number


//Example 6 - path on grid.
// you are given a grid of size n*n, you have to start from bottom left corner and to top right corner
// you can move only two directions i.e up and right
// at any poiint you have to stay either on or below the  diagonal. (problem can be changed to stay above the diagonal)
// this problem is similar to dyck words lets represent up as U and right as R
// now to reach top right without crossing the diagonal you have to arrange U's and R's in such a way that at point
// no. of R's >= U's
// RRU is valid , UUR invalid (as we will cross the diagonal)

// other examples are circels and chords, no. of ways triangulation

