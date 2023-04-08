#include <bits/stdc++.h>
using namespace std;

int countSquares(int n) {
    // code here    
    int low = 1;
    int high = n;

    int res = 0;
    while(low <= high){
        long long int mid = low + (high - low)/2;
        long long sqr = mid*mid;
        if (sqr < n){
            res = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }

    return res;
}

int main(){


    return 0;
}