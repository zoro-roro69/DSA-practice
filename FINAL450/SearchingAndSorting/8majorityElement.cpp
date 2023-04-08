#include <bits/stdc++.h>
using namespace std;

int majorityElement(int arr[], int size){
    if (size == 0)
        return -1;
    
    int candidate = arr[0];
    int count = 1;
    for (int i= 1; i < size ; i++){
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        }
        else{
            if (arr[i] == candidate){
                count++;
            }else
                count--;
        }
    }
    
    // cout << count << endl;
    if (!count) //if count  == 0, no majority elment
        return -1;
    //else we  have a candidate for majority elment, but we need to check if its count > n/2
    // for it to be majority
    count = 0;
    for (int i=0; i < size; i++){
        if (candidate == arr[i]){
            count++;
        }
    }

    if (count > size/2)
        return candidate;
    
    return -1;
    
    
}

int main(){


    return 0;
}