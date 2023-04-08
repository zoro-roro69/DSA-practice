#include <bits/stdc++.h>
using namespace std;

int countSetBits(int x){
    int count = 0;

    while(x){
        count += (x & 1);
        x = x>>1;
    }
    return count;
}
struct mycomp{

    bool operator()(int a, int b) const{
        return countSetBits(a) > countSetBits(b);
    }
};

void sortBySetBitCount(int arr[], int n){
    //stable sort maintains the original order, if two elements are equal
    stable_sort(arr, arr + n, mycomp());
}

int main(){

    return 0;
}