#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n){
    
    // Your code here
    int sum_till_now = arr[0];
    int max_sum = arr[0];
    
    for (int i=1;i<n;i++){
        sum_till_now += arr[i];
        max_sum = max(max_sum, sum_till_now);
        sum_till_now = max(sum_till_now,0);
    }
    
    
    return max_sum;
    
}

int main(){


    return 0;
}