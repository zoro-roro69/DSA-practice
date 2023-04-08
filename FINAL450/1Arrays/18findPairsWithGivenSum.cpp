#include <bits/stdc++.h>
using namespace std;

int getPairsCount(vector <int> v, int sum){

    int res = 0;
    unordered_map <int, int> mp;
    mp[v[0]] = 1;

    for (int i=1;i<v.size();i++){
        if (mp.find(sum-v[i])!=mp.end()){
            res += mp[sum-v[i]];
        }
        mp[v[i]]++;
    }

    return res;
}
int main(){

    vector <int> v{1,1,1,1};

    cout << "res: " << getPairsCount(v, 2) << endl;

    return 0;
}