#include <bits/stdc++.h>
using namespace std;

// For a sorted (in increasing order) and rotated array, the pivot
// element is the only element for which the next element to it is smaller than it.

int findPivot(int arr[], int n){

    int low = 0;
    int end = n-1;

    int pivot = low;
    while(low <= end){
        int mid = low + (end-low)/2;
        if (mid + 1 < n && arr[mid] > arr[mid+1]){
            pivot  = mid;
            break;
        }
        else if(mid -1 >=0 && arr[mid-1] > arr[mid]){
            pivot = mid-1;
            break;
        }else if (arr[low] >= arr[mid]){
            end = mid-1;
        }else{
            low = mid+1;
        }

    }

}
int main(){

    return 0;
}