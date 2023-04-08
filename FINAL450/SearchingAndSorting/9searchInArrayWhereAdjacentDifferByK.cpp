#include <bits/stdc++.h>
using namespace std;

// A step array is an array of integers where each element has a difference of at most k with
// its neighbor. Given a key x, we need to find the index value of x if multiple-element exist
// to return the first occurrence of the key.

int search(int arr[], int n, int x, int k){

    int i = 0;

    while(i < n){
        if (arr[i] == x){
            return i;
        }else{

        // We use max here to make sure that i
        // moves at-least one step ahead.
            int steps = max (1, abs(arr[i]-x)/k);
            i = i + steps;
        }
    }

    return -1; //element doesnt exist
}

int main(){

    return 0;
}