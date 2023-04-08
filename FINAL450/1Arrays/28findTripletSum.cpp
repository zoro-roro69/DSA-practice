#include <bits/stdc++.h>
using namespace std;


//complexity nlogn + O(n^2)
bool findTripletSum1(vector <int> v, int sum){

    int n = v.size();
    sort(v.begin(), v.end());

    for (int i=0;i<n;i++){
        int rem = sum - v[i];

        for (int s = i+1, e = n-1; s<e;){
            int temp = v[s] + v[e];
            if (temp == rem)
                return true;
            else if (temp > rem)
                e--;
            else
                s++;
        }
    }
    return false;
}


//using hashing
bool findTripletSum2(vector <int> v, int sum){

    int n = v.size();

    for (int i=0;i<n;i++){
        int curr_sum = sum - v[i];
        unordered_set<int> mp;

        for (int j = i+1;j<n;j++){
            if (mp.find(curr_sum-v[j])!= mp.end()){
                return true;
            }
            mp.insert(v[j]);
        }
    }
    return false;
}

int main(){


    return 0;
}