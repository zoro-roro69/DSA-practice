#include <bits/stdc++.h>
using namespace std;

// Given an unsorted array Arr of size N of positive integers. One number 
// 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers

//method 1 form two equations
//let the missing number = x, and repeating number be y
// {1,2,3,4,x,x};
// sum of 1 to n = Sn = (sum_of_given_array(Sa)) - x + y
// Sn - Sa = y - x;
// y = Sn - Sa + x

// Product of 1 to n = Pn = (product_of_arra(pa))*y/x;
// Pn = Pa*y/x
// Pn*x = Pa*y
// Pn*x = Pa(Sn - Sa + x)
// Pn*x = Pa*Sn - Pa*Sa + Pa*x
// x = (Pa*Sn - Pa*Sa)/(Pn - Pa);


//Note-- this approach works only for small 'n'
// for large values of n, the Product Pn will become very large as we basically are calculating the n factorial (n!)
int res[2];
int *findTwoElement(int *arr, int n) {
    // code here

    int Sn = n*(n+1)/2;
    int Sa = arr[0];
    int Pa = arr[0];
    int Pn = 1;

    int x,y;

    for (int i=1;i<n;i++){
        Sa += arr[i];
        Pa *= arr[i];
        Pn *= (i+1);
    }

    x = (Pa*Sn - Pa*Sa)/(Pn - Pa);
    y = Sn - Sa + x;

    res[0] = x;
    res[1] = y;

    return res; 
}


int *findTwoElement(int *arr, int n) {
    // code here

    for (int i=0;i<n;i++){
        if (arr[i] != i+1){
            if (arr[arr[i] - 1] != arr[i]){
                swap(arr[i], arr[arr[i] - 1]);
                i--;
            }
        }
    }

    // after this at each index we will have arr[i] == i+1 except at the index 
    // that has repeating element
    int x, y;
    for (int i=0;i<n;i++){
        if (arr[i] != i+1){
            x = arr[i];
            y = i+1;
        }
    }
    res[0] = x;
    res[1] = y;

    return res;
    

}

int main(){

    int arr[] = {1,2,3,3};
    findTwoElement(arr, 4);
    return 0;
}