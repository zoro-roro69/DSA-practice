#include <bits/stdc++.h>
using namespace std;


// Given three integers  'A' denoting the first term of an arithmetic sequence , 
// 'C' denoting the common difference of an arithmetic sequence and an integer 'B'.
//  you need to tell whether 'B' exists in the arithmetic sequence or not. 
// Return 1 if B is present in the sequence. Otherwise, returns 0.

int inSequence(int A, int B, int C){
    // code here
    if (C == 0){
        return A==B;
    }
    if (C>0 && B<A)
        return 0;
    if (C<0 && B>A)
        return 0;
    
    if ((B-A)%C != 0)
        return false;
    
    return true;
}

int main(){

    return 0;
}
