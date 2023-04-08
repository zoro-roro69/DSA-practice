#include <bits/stdc++.h>
using namespace std;

//NOTE -- this is different from counting inversions

// create a duplicate array;
// sort the duplicate
// create a map which stores the element and its index in sorted array
// then loop through the original array 
// if current element its already at its correct pos then move on
// else we swap it with element which is currently placed at this elements correct position
//      increment num of swaps
// repeat until sorted 

int minSwaps(vector<int>&nums){
    // Code here
    vector <int> temp = nums;
    sort(temp.begin(), temp.end());

    unordered_map <int, int> mp;
    for (int i=0;i<temp.size();i++)
        mp[temp[i]] = i;

    int res = 0;
    for (int i=0;i<nums.size();){
        if (nums[i] != temp[i]){
            swap(nums[i], nums[mp[nums[i]]]);
            res++;
        }else
            i++;
    }

    return res;
}

int main(){

    return 0;
}