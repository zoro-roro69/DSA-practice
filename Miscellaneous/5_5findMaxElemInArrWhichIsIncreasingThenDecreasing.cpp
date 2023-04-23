#include <bits/stdc++.h>
using namespace std;

int findMaximum(int arr[], int n) {
    // code here

    int start = 0;
    int end = n-1;

    int res = INT_MIN;

    while(start <= end){
        int mid = start + (end - start)/2;
        
        if (mid > 0){
            if (arr[mid] > arr[mid-1]){ //part of first half
                start = mid+1;
            }else{ //part of second half
                end = mid-1;
            }
        }

        res = max(res, arr[mid]);
    }

    return res;
}

// int findMaximum(int arr[], int n) {
// 	    // code here
// 	    int low=0,high=n-1;
//         while(low<high){
//             int mid=low+(high-low)/2;
       
//             if(arr[mid]<arr[mid+1]){
//                 low=mid+1;
//             }
//             else{
//                 high=mid;
//             }
//         }
//         return arr[low];
//     }


int main(){

    return 0;
}