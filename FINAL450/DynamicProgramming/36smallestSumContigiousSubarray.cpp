#include <bits/stdc++.h>
using namespace std;

int smallestSum(int arr[], int n){

    int sum_till_now = arr[0];
    int min_sum = arr[0];

    for (int i=1;i<n;i++){
        sum_till_now += arr[i];
        min_sum = min (min_sum, sum_till_now);
        sum_till_now = min(0,sum_till_now);
    }

    return min_sum;

}

int main(){

    return 0;
}