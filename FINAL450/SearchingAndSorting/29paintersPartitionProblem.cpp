#include <bits/stdc++.h>
using namespace std;

//TIP while doing binary search carefully select what will be the low and high range :)

// We have to paint n boards of length {A1, A2…An}.
//  There are k painters available and each takes 1 unit of time to paint 1 unit of the board. 

// The problem is to find the minimum time to get 
// this job was done under the constraints that any painter will only paint continuous sections of boards,


int paintersParitionProblem(vector <int> &arr, int k){
    // arr = array of boards
    // k = num of painters
    // return min time to  reqd to paint the boards

    int low = 0;
    int high = 0;
    //max time will be sum of all boards when we only have one painter
    for (int x:arr){
        high += x;
        low = max(x, low);
    }

    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int num_painters = 0;
        int cur_sum = 0;
        for (int x:arr){
            cur_sum += x;
            if (cur_sum > mid){
                num_painters++;
                cur_sum = x;
            }
        }
        if (cur_sum <=mid){
            if (num_painters < k){
                high = mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }else{
            //need to increase the max time
            low = mid+1;
        }
    }

    return ans;

}

int main(){

    vector <int> arr{6, 2, 1, 3, 4, 7, 4, 6, 1, 1};
    cout  << paintersParitionProblem(arr, 7) << endl;

    return 0;
}