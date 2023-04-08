#include <bits/stdc++.h>
using namespace std;

int minSwapsToBringLessThanKTogether(vector <int> v, int k){

    int n = v.size();
    int count = 0;
    for (auto x:v){
        if (x <= k)
            count++;
    }

    int min_swaps = INT_MAX;

    for (int i = 0;i<n;i++){
        int cur_swaps = 0, j;
        for ( j = i;j<i+count;j++){
            if (v[j] > k){
                cur_swaps++;
            }
        }
        min_swaps = min(min_swaps, cur_swaps);
        i = j;
    }

    return min_swaps;    
}

int main(){

    vector <int> v{2, 7, 9, 5, 8, 7, 4};
    cout << "res:" << minSwapsToBringLessThanKTogether(v, 5) << endl;

    return 0;
}