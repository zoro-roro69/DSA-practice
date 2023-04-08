#include <bits/stdc++.h>
using namespace std;

//using dp O(n^2) solution
int AlternatingaMaxLength(vector<int>&arr){
    int n = arr.size();
    int dp1[n]; //when ith is take as i > i-1
    int dp2[n];// when ith is taken as i < i-1

    for (int i=0;i<n;i++){
        dp1[i] = dp2[i] = 1;
    }

    int res = 1;
    for (int i = 1;i<n;i++){
        for (int j = i-1;j>=0;j--){
            if (arr[i] > arr[j]){
                int temp = 1 + dp2[j];
                dp1[i] = max(dp1[i], temp);
            }else if (arr[i] < arr[j]){
                int temp = 1 + dp1[j];
                dp2[i] = max(dp2[i], temp);
            }
        }
        res = max(dp1[i], dp2[i]);
    }

    return res;
}
//O(n) solution
int sol2(vector <int> &arr){
    int n = arr.size();

    int i_greater = 1; //when arr[i] > arr[i-1]
    int i_smaller = 1; //when arr[i] < arr[i-1]

    for (int i=1;i<n;i++){
        if (arr[i] > arr[i-1]){
            i_greater = i_smaller + 1;
        }else if (arr[i] < arr[i-1]){
            i_smaller = i_greater + 1;
        }
    }

    return max(i_smaller, i_greater);

}

int main(){

    return 0;
}