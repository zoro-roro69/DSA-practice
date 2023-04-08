#include <bits/stdc++.h>
using namespace std;


int minLength(vector <int> v, int sum){
    int n = v.size();
    int s = 0, e = 0;

    int cur_sum = 0;
    int res = n;
    while (e<n) {
        cur_sum += v[e++];

        cur_sum -= v[s++];
        while (s<e && cur_sum > sum){
            cur_sum -= v[s]; 
            s++;
        }
        cur_sum += v[--s];

        if (cur_sum > sum){
            res = min(e-s, res);
        }
    }

    if (cur_sum < sum)
        return -1;
    return res;
}


//better way of writing the loop
int smallestSubWithSum(int arr[], int n, int x)
{
    // Initialize current sum and minimum length
    int curr_sum = 0, min_len = n + 1;
 
    // Initialize starting and ending indexes
    int start = 0, end = 0;
    while (end < n) {
        // Keep adding array elements while current sum
        // is smaller than or equal to x
        while (curr_sum <= x && end < n)
            curr_sum += arr[end++];
 
        // If current sum becomes greater than x.
        while (curr_sum > x && start < n) {
            // Update minimum length if needed
            if (end - start < min_len)
                min_len = end - start;
 
            // remove starting elements
            curr_sum -= arr[start++];
        }
    }
    return min_len;
}


//when array contains negative values too
int smallestSubWithSumNeg(vector<int> arr, int n, int x)
{
    // Initialize current sum and minimum length
    int curr_sum = 0, min_len = n + 1;
 
    // Initialize starting and ending indexes
    int start = 0, end = 0;
    while (end < n) {
        // Keep adding array elements while current sum
        // is smaller than or equal to x
        while (curr_sum <= x && end < n){
            curr_sum += arr[end++];
            if (curr_sum < 0){
                curr_sum = 0;
                start = end;
            }
        }
 
        // If current sum becomes greater than x.
        while (curr_sum > x && start < n) {
            // Update minimum length if needed
            if (end - start < min_len)
                min_len = end - start;
 
            // remove starting elements
            curr_sum -= arr[start++];
        }
    }
    return min_len;
}
 

int minLengthNeg(vector <int> v, int sum){
    int n = v.size();
    int s = 0, e = 0;

    int cur_sum = 0;
    int res = n;
    while (e<n) {
        cur_sum += v[e++];
        if (cur_sum < 0 ){
            cur_sum = 0;
            s = e;
        }
        else{
            cur_sum -= v[s++];
            while (s<e && cur_sum > sum){
                cur_sum -= v[s]; 
                s++;
            }
            cur_sum += v[--s];

            if (cur_sum > sum){
                res = min(e-s, res);
            }
        }
    }

    return res;
}

int main(){
    vector <int> v{-8, 1, 4, 2, -6};

    cout << " res: " << smallestSubWithSumNeg(v, v.size(), 4) << endl;

    return 0;
}