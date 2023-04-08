#include <bits/stdc++.h>
using namespace std;


bool findSubArraySumk(vector <int> v, int k){
    unordered_set <int> mp;

    int sum = 0;
    for (auto x:v){
        sum += x;
        if (sum == k)
            return true;
        if (mp.find(sum-k)!=mp.end())
            return true;

        mp.insert(sum);
    }
    return false;
}

int main(){

    vector <int> v{4,2,-3,6};
    cout << findSubArraySumk(v, 0) <<endl;

    return 0;
}