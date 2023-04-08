#include <bits/stdc++.h>
using namespace std;


//kadanes algo is used to find a contigious sub array
//that has maximum sum

int maxSubArraySum(vector <int> &v){
    if (v.size() == 0)
        return 0;

    int max_sum = v[0];
    int sum_till_now = max(v[0], 0); //if first elment is negative

    for (int i=1;i<v.size();i++){
        sum_till_now += v[i];
        max_sum = max(max_sum, sum_till_now);
        sum_till_now = max(0, sum_till_now);
    }
    return max_sum;
}

int main(){

    vector <int> v{-47, 43, 94, -94, -93, -59, 31, -86};
    cout << maxSubArraySum(v) <<endl;
    return 0;
}