#include <bits/stdc++.h>
using namespace std;

// Given an array nums[] of size n, construct a Product Array P (of same size n) such that 
// P[i] is equal to the product of all the elements of nums except nums[i].

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {

    vector <long long> res(n, 0);
    int num_zeros = 0;
    int product_without_zero = 1;
    for (auto x: nums){
        if (x == 0)
            num_zeros++;
        else
            product_without_zero *= x;
    }
    if (num_zeros > 1)
        return res;
    
    if (num_zeros == 1){
        for (int i=0;i<n;i++){
            if (nums[i] == 0)
                res[i] = product_without_zero;
            else
                res[i] = 0;
        }
    }

    //num_zeros == 0
    for (int i=0;i<n;i++){
        res[i] = product_without_zero/nums[i];
    }

    return res;
}

vector <long long int> productExceptSelf(vector <long long> &nums, int n){

    vector <long long int> pre_product(n, 0);

    long long prod = 1;
    for (int i=0;i<n;i++){
        pre_product[i] = prod;
        prod *= nums[i];
    }

    //pre_product[i] = product of elements till i-1;
    int temp = 1; //temp will contain product of elements from i+1 to end

    for (int i=n-1;i>=0;i--){
        //pre_product[i] == prod till i-1, temp = prod from i+1,
        //  so multiplying them gives product of all elements except i
        pre_product[i] = pre_product[i] * temp; 
        temp *= nums[i];
    }

    return pre_product;

} 


int main(){

    return 0;
}