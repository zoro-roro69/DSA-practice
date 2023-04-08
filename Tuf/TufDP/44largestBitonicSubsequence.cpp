#include <bits/stdc++.h>
using namespace std;

// Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
// A subsequence of array is called Bitonic if it is first increasing, then decreasing.

// Input: nums = [1, 2, 5, 3, 2]
// Output: 5
// Explanation: The sequence {1, 2, 5} is
// increasing and the sequence {3, 2} is 
// decreasing so merging both we will get 
// length 5.


int largestBitonic(vector <int> &arr){
    // code here
    int n = arr.size();
    if (n<=1) return n;

    int increasing[n];
    int decreasing[n];

    for (int i=0;i<n;i++){
        increasing[i] = 1;
        decreasing[i] = 1;
    }

    int res = 1;

    for (int i=1;i<n;i++){
        for (int j=i-1; j>=0;j--){
            if (arr[j] < arr[i]){ //increasing 
                if (increasing[j] + 1 > increasing[i])
                    increasing[i] = 1 + increasing[j];
            }else if(arr[j] > arr[i]){ //decreasing
                int temp = max(increasing[j], decreasing[j]);
                if (temp + 1 > decreasing[i])
                    decreasing[i] = 1 + temp;
            }
        }

        res = max({res, increasing[i], decreasing[i]});
    }

    return res;
}



int main(){

    return 0;
}