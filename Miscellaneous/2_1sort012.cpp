#include <bits/stdc++.h>
using namespace std;

void sort012(int arr[], int n){
    int start = 0;
    int end = n-1;

    for (int i=0;i <= end;i++){
        if (arr[i] == 0){
            // cout << "here:" << i << endl;
            swap(arr[i], arr[start]);
            start++;
        }
        else if (arr[i] == 2){
            // cout << "here:" << i << endl;
            swap(arr[i], arr[end]);
            end--;
            i--;
        }
    }
    return ;   
}
    

int main(){

    return 0;
}