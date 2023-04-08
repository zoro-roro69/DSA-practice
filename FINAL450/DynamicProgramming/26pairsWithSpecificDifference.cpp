#include <bits/stdc++.h>
using namespace std;


// Not DP :)
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K){
    sort(arr, arr+ N);

    int i = N-1;
    int sum = 0;
    while(i>=1){

        if (arr[i] - arr[i-1] < K){
            //include
            sum += arr[i] + arr[i-1];
            i -=2;
        }else
            i --;
    }

    return sum;
}

int main(){


    return 0;

}