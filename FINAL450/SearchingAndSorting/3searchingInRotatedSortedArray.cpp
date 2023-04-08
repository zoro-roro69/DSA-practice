#include <bits/stdc++.h>
using namespace std;

//Mthod 1 
//find the pivot
//then apply bs to both halves to fing the ans
int binarySearch(vector <int> &arr, int low, int end, int key){

    int mid;
    while(low <= end){
        mid = low + (end - low)/2;

        if (arr[mid] == key)
            return true;
        else if (arr[mid] > key){
            end = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return false;

}

int searchInRotated(vector <int> &arr, int key){

    int low = 0;
    int end = arr.size()-1;

    int pivot = low;
    while (low <= end ){
        int mid = low + (end-low)/2;

        if (mid+1 < arr.size() && arr[mid] > arr[mid+1]){
            pivot = mid;
            break;
        }
        else if ( mid-1>=0 && arr[mid] < arr[mid-1] ){
            pivot = mid - 1;
            break;
        }else if (arr[mid] >= arr[low]){
            end  = mid-1;
        }else{
            low = mid+1;
        }
    }

    if (key >= arr[low] && key <= arr[pivot]){
        return binarySearch(arr, low, pivot, key);
    }
    else if (key >= arr[pivot+1] && key <= arr[end])
        return binarySearch(arr, end, pivot, key);

    return false;

}

//Method 2: without finding the pivot first
// in this we check mid lies in which half, after identifying the half
// we check if key lies in that half or not
// if it liest in this half then we apply B.S otherwise we apply B.S to other half

int searchInRotated2(vector <int> &arr, int key){

    int low  =0;
    int end = arr.size()-1;

    while(low <= end){
        int mid = low + (end-low)/2;

        if (arr[mid] == key)
            return mid;
        
        if (arr[low] <= arr[mid]){
            //low to mid is sorted
            if (key >= arr[low] && key <= arr[mid]){ //check if key lies within this range
                end = mid-1;
            }else{
                low = mid+1;
            }
        }else if(arr[end] >= arr[mid]) {
            //mid to end is sorted
            if (key >= arr[mid] && key <= arr[end])
                low = mid+1;
            else{
                end = mid-1;
            }
        }
 
    }

    return -1;

}

int main(){


    return 0;
}