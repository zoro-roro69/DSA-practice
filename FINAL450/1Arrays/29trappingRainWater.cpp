#include <bits/stdc++.h>
using namespace std;

//using extra space 
int trappingWater(vector <int> v){

    int n = v.size();
    vector <int> temp(n, 0);

    temp[0] = v[0];

    for (int i=1;i<v.size();i++){
        temp[i] = max(temp[i-1], v[i]);
    }

    int res = 0;
    int max_right = v[n-1];

    for (int i=n-2;i>0;i--){
        int min_ht = min(max_right, temp[i-1]);
        if (min_ht > v[i]){
            res += min_ht - v[i];
        }
        max_right = max(max_right, v[i]);
    }

    return res;
}


int trappingWater2(vector <int> v){
    int n = v.size();
    int max_left = 0;
    int max_right = 0;

    int res = 0;

    for (int l = 0, r = n-1; l<r;){
        if (v[l] < v[r]){

            if (v[l] > max_left){
                max_left = v[l];
            }else{
                res += max_left - v[l];
            }
            l++;
        }else{

            if (v[r] > max_right){
                max_right = v[r];
            }else{
                res += max_right - v[r];
            }
            r--;
        }
    }
    return res;
}

int main(){

    return 0;
}