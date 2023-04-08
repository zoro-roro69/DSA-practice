#include <bits/stdc++.h>
using namespace std;

//complexity O(m+n)
//using merge algorithm
int kthElement(int arr1[], int arr2[], int n, int m, int k){
    int pos = 0;
    int i = 0, j = 0;

    int res; 

    while(i<n && j<m){
        
        if (arr1[i] <= arr2[j]){
            res = arr1[i];
            i++;
        }else{
            res = arr2[j];
            j++;
        }

        pos++;
        if (pos == k)
            return res;
    }

    while(i < n){
        res = arr1[i];
        i++; pos++;
        if (pos == k)
            return res;
    }

    while(j < m){
        res = arr2[j];
        j++; pos++;
        if (pos == k)
            return res;
    }

    return 0; //dummy return
}

int main(){

    return 0;
}