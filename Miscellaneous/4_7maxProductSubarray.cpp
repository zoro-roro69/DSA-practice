#include <bits/stdc++.h>
using namespace std;

//this algo fails for the case [-1, -1]
int maxProduct(vector<int>& nums) {
    if (nums.size() == 1)
        return nums[0];

    bool flag = false;
    int max_prod = 0;
    int max_till_now = 1;
    int min_till_now = 1;

    for (int x:nums){
        if (x == 0){
            max_till_now = 1;
            min_till_now = 1;
        }
        else if (x < 0){
            int temp = max_till_now * x;
            max_till_now = min_till_now * x;
            min_till_now = temp;

            max_till_now = max(1, max_till_now);
            max_prod = max(max_prod, max_till_now);

            // cout << max_till_now << " -- " << min_till_now << endl;

        }
        else if (x > 0){
            flag = true;
            max_till_now = max_till_now * x;
            min_till_now = min_till_now * x;

            min_till_now = min(1, min_till_now);

            max_prod = max(max_prod, max_till_now);

        }
        
    }

    if (max_prod == 1 && !flag){
        return 0;
    }

    return max_prod;   
}


//this version is like the kadanes algo the only difference is that we need to traverse
//from left to right and then from right to left.
// lets say when array contains even number of -ves, then simply the product of all elements gives max prod
// but when we have odd number of -ves, now we simple cannot take product of all elements since final prod will be -ve
// so we need to leave either the first -ve or the last -ve (as seen from left)
//so when we traverse from left to right, we are automatically including first and excluding last.
//when we do reverse traversal (right to left) we automatically exclude first

//lets say inbetween we get 0, just like in kadanes algo we make the prod till now to be 1
int maxProd2(vector <int> &nums){
    
    int max_prod = nums[0];
    int prod = 1;

    //left to right
    for (int i=0;i<nums.size();i++){
        prod = prod * nums[i];
        max_prod = max(max_prod, prod);

        if (prod == 0)
            prod = 1;
    }

    //right to left
    prod = 1;
    for (int i = nums.size()-1; i>=0; i--){
        prod = prod*nums[i];
        max_prod = max(max_prod, prod);

        if (prod == 0)
            prod = 1;
    }

    return max_prod;
}

// Here we use 3 variables called max_so_far, max_ending_here & min_ending_here
// For every index, the maximum number ending at that index will be the 
// maximum(arr[i], max_ending_here * arr[i], min_ending_here[i]*arr[i])
// Similarly, the minimum number ending here will be the minimum of these 3
// Thus we get the final value for the maximum product subarray

int maxProd3(vector <int> &nums){

    int max_prod = nums[0];
    int max_ending_here = nums[0];
    int min_ending_here = nums[0];

    for (int i=1;i<nums.size();i++){
        int temp = max(max(nums[i], max_ending_here*nums[i]), min_ending_here*nums[i]);
        min_ending_here = min(min(nums[i], max_ending_here*nums[i]), min_ending_here*nums[i]);

        max_ending_here = temp;

        max_prod = max(max_ending_here, max_prod);        
    }

    return max_prod;
}


int main(){
    return 0;
}