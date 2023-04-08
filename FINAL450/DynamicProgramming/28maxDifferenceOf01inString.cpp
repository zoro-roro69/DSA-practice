#include <bits/stdc++.h>
using namespace std;

// Given a binary string S consisting of 0s and 1s. The task is to find the maximum 
// difference of the number of 0s and the number of 1s (number of 0s – number of 1s)
//  in the substrings of a string.

//  S = "11000010001" 

// we can convert this problem to finding maximum contiguos subarray sum and apply kaadanes algo :)))
// as we can see the result is (number of 0s - numbers of 1s)
// here we can see more the number of 0s in the string better the answer (and if all 0s then the best)
//lets say if we replace 0s by 1 and 1 by -1
//   "1, 1, 0, 0 ,0 ,0, 1, 0"
//to "-1, -1, 1, 1, 1, 1, -1, 1" 
// to this we can apply kadanes algo and get the answer

int maxdiff01(string s){


    int sum_till_now = 0;
    int max_till_now = 0;

    for (auto ch:s){
        sum_till_now += (ch == '1' ? -1 : 1);
        max_till_now = max(max_till_now, sum_till_now);
        sum_till_now = max(sum_till_now, 0);
    }

    if (max_till_now == 0) //there are no '0's in string
        max_till_now = -1;

    return max_till_now;

}

int main(){


    return 0;
}