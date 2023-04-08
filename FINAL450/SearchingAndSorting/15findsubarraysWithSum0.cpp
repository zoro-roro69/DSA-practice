#include <bits/stdc++.h>
using namespace std;


int subArrayWithZeroSum(vector <int> &v){

    unordered_map <int, int> mp;
    // {1,2,-2,-1}
    //sum_tll_now - x = 0;
    //sum_till_now = x;
    mp[0] = -1;
    int pre_sum = 0;

    for (int i=0;i<v.size();i++){
        pre_sum += v[i];
        if (mp[pre_sum]){
            int start = mp[pre_sum] + 1;
            while(start <= i){
                cout << mp[start++] << " ";
            }
            cout << endl;
        }
        mp[pre_sum] = i;
    }

    return 0;

}

#define ll long long

//return count of all subarrays with 0 sum
ll findSubarray(vector<ll> v, int n ) {
    //code here
    unordered_map <ll, ll> mp;
    // {1,2,-2,-1}
    //sum_tll_now - x = 0;
    //sum_till_now = x;
    mp[0] = 1;
    ll pre_sum = 0;

    ll res = 0;
    for (int i=0;i<v.size();i++){
        pre_sum += v[i];
        if (mp[pre_sum]!= 0){
            res += mp[pre_sum];
        }
        mp[pre_sum]++;
    }

    return res;
}

//more elegant way of writing
ll findSubarray2(vector<ll> v, int n ) {
    //code here
    
    unordered_map <ll, ll> mp;
    // {1,2,-2,-1}
    //sum_tll_now - x = 0;
    //sum_till_now = x;
    mp[0] = 1;
    ll pre_sum = 0;

    ll res = 0;
    for (int i=0;i<v.size();i++){
        pre_sum += v[i];
        //taking advantage of the fact that default value when a keys doesnt exist in the map is 0
        res += mp[pre_sum]; 
        mp[pre_sum]++;
    }

    return res;
}

int main(){


    return 0;
}