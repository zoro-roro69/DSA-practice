#include <bits/stdc++.h>
using namespace std;

void printVector(vector <int> v){
    for (auto x:v){
        cout << x << " ";
    }
    cout<<endl;
}


//kadanes algo
int largestSumContigiousSubArray(vector <int> v){

    int max_sum = INT_MIN;
    int sum_till_now = 0;

    for (auto x:v){
        sum_till_now += x;
        max_sum = max(max_sum, sum_till_now);
        sum_till_now = max(0, sum_till_now);
    }

    return max_sum;
}

//storing the indices of sub array as well
void largestSumContigiousSubArray2(vector <int> v){

    if (v.empty())
        return;

    int max_sum = v[0];
    int sum_till_now = v[0];
    int i =0, j =0;

    if (sum_till_now < 0 ){
        sum_till_now = 0; 
        i++;
    }

    for (int k=1;k<v.size();k++){
        sum_till_now += v[k];

        if (sum_till_now > max_sum){
            max_sum = sum_till_now;
            j = k;
        }

        if (sum_till_now < 0){
            sum_till_now = 0;
            i++;
        }
    }

    if (i > j) i = j;
    cout << i << " to " << j << " sum: " << max_sum <<endl;
}

int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0,
       start =0, end = 0, s=0;
 
    for (int i=0; i< size; i++ )
    {
        max_ending_here += a[i];
 
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
 
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << "Maximum contiguous sum is "
        << max_so_far << endl;
    cout << "Starting index "<< start
        << endl << "Ending index "<< end << endl;
}
 

int main(){

    vector <int> v{-2, -3, -1, -2,-3};;
    printVector(v);

    // cout << largestSumContigiousSubArray(v) <<endl;

    largestSumContigiousSubArray2(v);

    return 0;
}