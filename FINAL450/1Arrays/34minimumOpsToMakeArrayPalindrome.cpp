#include <bits/stdc++.h>
using namespace std;

int helper(vector <int> &v, int &s, int &e){
    int left = v[s++];
    int right = v[e--];
    int ops = 0;

    if (left == right)
        return ops;

    while(s<=e){

        if (left < right){
            left+= v[s++];
            ops++;
        }else{
            right += v[e--];
            ops++;
        }

        if (left == right){
            return ops;
        }
    }

    ops++;
    return ops;
}

int minimumOps(vector <int> v){
    int i =0, j= v.size()-1;
    // int i = 0, j = 5;
    int ops = 0;
    while(i<j){
        if (v[i] == v[j]){
            i++;
            j--;
        }else{
            ops += helper(v, i, j);
        }
    }
    return ops;
}

//betterway to write 
int findMinOps(int arr[], int n)
{
    int ans = 0; // Initialize result
 
    // Start from two corners
    for (int i=0,j=n-1; i<=j;)
    {
        // If corner elements are same,
        // problem reduces arr[i+1..j-1]
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
 
        // If left element is greater, then
        // we merge right two elements
        else if (arr[i] > arr[j])
        {
            // need to merge from tail.
            j--;
            arr[j] += arr[j+1] ;
            ans++;
        }
 
        // Else we merge left two elements
        else
        {
            i++;
            arr[i] += arr[i-1];
            ans++;
        }
    }
 
    return ans;
}

int main(){
    vector <int> v {11, 14, 15, 99};
    int res = minimumOps(v);
    cout << "ops:" << res << endl;

    return 0;
}