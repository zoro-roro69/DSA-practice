#include <bits/stdc++.h>
using namespace std;


//the celebrity problem

/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

// dummy function
bool knows(int i, int j){
    return true;
}


//total comparisons in this = 3*(N-1)
//first loop N-1 comparisons
//second loop 2(N-1) comparisons
int findCelebrity(int n) {
 	// Write your code here.

    int start = 0;
    int end = n-1;
    int res;
    while(start < end){
        if (knows(start, end)){
            //start knows end so, start cannot be celebrity
            res = end; //end maybe celebrity
            start++;
        }else{
            //start doesnt know end, so end cannot be celebrity
            res = start; //start maybe celebrity
            end--;
        }
    }

    //now check if res is actually the celebrity
    for (int i=0;i<n;i++){
        if (i!=res) {
            if ( !(knows(i, res) && !knows(res, i)) ){
                return -1; //no celebrity
            }
        }
    }
    //res is the celebrity 
    return res;


}

int main(){

    return 0;
}