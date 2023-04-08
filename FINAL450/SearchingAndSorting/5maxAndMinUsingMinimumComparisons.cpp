#include <bits/stdc++.h>
using namespace std;

//Question type 1
//middle of three

// Given three distinct numbers A, B and C. 
// Find the number with value in middle (Try to do it with minimum comparisons).

int middle(int A, int B, int C){
    //code here//Position this line where user code will be pasted.
    //in worst case we need maximum 3 comparison
    if (A > B){
        if (A > C){
            if (B > C)
                return B;
            else
                return C;
        }else{
            return A;
        }
    }else{
        if (B > C){
            if (A > C)
                return A;
            else
                return C;
        }else{
            return B;
        }
    }
}

//Question type 2
//find min and max from an array in minimum comaprisons


int main(){


    return 0;
}