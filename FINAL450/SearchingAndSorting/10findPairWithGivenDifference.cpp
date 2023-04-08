#include <bits/stdc++.h>
using namespace std;


//Note - dont confuse it with other question - find a pair that sum to a given value;

//method 1
//using sorting + binary search
// TC - nlogn
// SC  - O(1)

bool binarySearch(int arr[], int i, int e, int key){

    while(i<=e){
        int mid = i + (e-i)/2;
        if (arr[mid] == key)
            return true;
        else if (arr[mid] > key){
            e = mid-1;
        }else
            i = mid+1;
    }

    return false;

}


bool findPair1(int arr[], int size, int n){

    sort(arr, arr + size);

    for (int i=0;i<size;i++){
        //y - x = n, so y = n + x;
        int y = n + arr[i];
        //now we check if y exists in the arr or not
        if (binarySearch(arr, i+1, size, y))
            return true;
    }

    return false;

}


//Method 2 using hashing
int findPair2(int arr[], int size, int n){

    unordered_map <int, int> mp;
    for (int i=0;i<size;i++)
        mp[arr[i]] = i;
    
    for (int i=0;i<size;i++){
        int y = n + arr[i];
        if (mp.find(y) != mp.end() && mp[y] != i){
            return true;
        }
    }

    return false;

}

int main(){


    return 0;
}