#include <bits/stdc++.h>
using namespace std;


// NOTE - this is different from finding SUBSET/SUBSEQUENCE that sums to given the value
// SUBSET/SUBSEQUENCE sum is done using DP


//subset sum with non - negative numebrs
//whene we know that all numbers in the array are >=0 then we can use sliding window approach
//in this we maintain the sum off current_window
// if cur_sum  == reqd.
// return true;
// else if cur_sum < reqd:
// increase window size by 1 and add the next element
// else if cur_sum > reqd:
// remove the first element of the window from sum
vector<int> subarraySum(vector <int> &arr,int n, int s){
        // Your code here
        
        // int n = arr.size();
        int i = 0;
        int j = 1;
        long long int cur_sum = arr[0];
        while(j<=n){
            if (cur_sum  == s){
                // return true;
                if (i < j)
                    return {i+1, j}; //1 based indexing, returning start and end index, [start, end]
                else{
                    if (i<n)
                    cur_sum = arr[i];
                    j++;
                }
                    
            }
            else if (cur_sum < s) {
                
                if (j < n){
                    cur_sum += arr[j];
                }
                j++;
            }else{
                cur_sum -= arr[i];
                i++;
                
            }
        }
        // return false;
        return {-1};
}


//subset sum but array can contain negative numbers as well
//the above approach is only possible when the numbers are non -ve
//since the numbers are all >=0 , adding a new number to the window will always increase the sum
// and removing a number from the window will decrease the sum
// but when we have -ve numbers as well in the array the above statements doesnt hold true
// since if the new number is -ve and we add it to exisitng sum our sum will decrease instead of increasing
// also if number we remove from the window is -ve then our sum will increase.

// so to handle -ve numbers we use different approach
// in this we use a map,
bool subarraySum(vector <int> &arr, int s){
    //find subarray with sum equal to s

    unordered_map <int, int> mp; //mp[s] = ind; 


    int sum_till_now = 0;

    mp[0] = -1;

    for (int i=0;i<arr.size();i++){
        sum_till_now += arr[i];
        if (mp.find(sum_till_now - s) != mp.end()){ //found
            cout << "start_index:" << mp[sum_till_now - s] << "end_index: " << i << endl; 
            return true;
        }
        mp[sum_till_now] = i;
    }

    return false;
}

//need to return count of subarrays with the given sum
int subarraySumCount(vector<int>& arr, int s) {
    unordered_map <int, int> mp; //mp[s] = count; 


    int sum_till_now = 0;

    mp[0] = 1;

    int res = 0;

    for (int i=0;i<arr.size();i++){
        sum_till_now += arr[i];
        if (mp.find(sum_till_now - s) != mp.end()){ //found
            // cout << "start_index:" << mp[sum_till_now - s] << "end_index: " << i << endl; 
            // return true;
            res += mp[sum_till_now - s];
        }
        mp[sum_till_now]++; //increasing the count
    }

    return res;
}

//given an array find a subarray that sums closes to given value.
//array can contain -ve numbers as well
// Input : arr[] = {-1, 3, 2, -5, 4}
// Output : 1, 3
// Subarray from index 1 to 3 has sum closest to 0 i.e.
// 3 + 2 + -5 = 0

// Input : {2, -5, 4, -6, 3} 
// Output : 0, 2
// 2 + -5 + 4 = 1 closest to 0
int subarraySumClosestToGivenSum(vector <int> &arr,int s){

    // map <int, int> mp;
    set <int> mp;

    mp.insert(0);
    int sum_till_now = 0;

    int res = INT_MAX;

    for (int i=0;i<arr.size();i++){
        sum_till_now += arr[i];
        int diff = sum_till_now - s;
        auto it = mp.find(diff);

        if (*it == diff){ //found exact sum
            return s;
        }
        else{
            int cur_sum;
            if (it != mp.end()){
                cur_sum = abs(sum_till_now - *it);
                if ( abs(s-res) > abs(s - cur_sum) ){
                    res = cur_sum;
                }
            }

            if (it != mp.begin()){
                //checking for previous element
                it--;
                cur_sum = abs(sum_till_now - *it);
                if ( abs(s-res) > abs(s - cur_sum) ){
                    res = cur_sum;
                }
            }
        }

        mp.insert(sum_till_now);
    }
    return res;
}


//another method to solve this

// An Efficient method is to perform following steps:-

// Maintain a Prefix sum array . Also maintain indexes in the prefix sum array.
// Sort the prefix sum array on the basis of sum.
// Find the two elements in a prefix sum array with minimum difference

// i.e.  Find min(pre_sum[i] - pre_sum[i-1]) 


// struct prefix {
//     int sum;
//     int index;
// };
 
// // Sort on the basis of sum
// bool comparison(prefix a, prefix b)
// {
//     return a.sum < b.sum;
// }
 
// // Returns subarray with sum closest to 0.
// pair<int, int> findSubArray(int arr[], int n)
// {
//     int start, end, min_diff = INT_MAX;
 
//     prefix pre_sum[n + 1];
 
//     // To consider the case of subarray starting
//     // from beginning of the array
//     pre_sum[0].sum = 0;
//     pre_sum[0].index = -1;
 
//     // Store prefix sum with index
//     for (int i = 1; i <= n; i++) {
//         pre_sum[i].sum = pre_sum[i-1].sum + arr[i-1];
//         pre_sum[i].index = i - 1;
//     }
 
//     // Sort on the basis of sum
//     sort(pre_sum, pre_sum + (n + 1), comparison);
 
//     // Find two consecutive elements with minimum difference
//     for (int i = 1; i <= n; i++) {
//         int diff = pre_sum[i].sum - pre_sum[i-1].sum;
 
//         // Update minimum difference
//         // and starting and ending indexes
//         if (min_diff > diff) {
//             min_diff = diff;
//             start = pre_sum[i-1].index;
//             end = pre_sum[i].index;
//         }
//     }
 
//     // Return starting and ending indexes
//     pair<int, int> p = make_pair(start + 1, end);
//     return p;
// }

int main(){

    vector <int> arr{2, -5, 4, -6, 3} ;

    cout << subarraySumClosestToGivenSum(arr, 0) << endl;
    return 0;
}