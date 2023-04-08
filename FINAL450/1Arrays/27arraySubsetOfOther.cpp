#include <bits/stdc++.h>
using namespace std;

bool isSubset(vector <int> a, vector <int> b){
    //check if b is subset of a
    unordered_set <int> mp;
    for (auto x:a)
        mp.insert(x);
    
    for (auto x:b){
        if (mp.find(x) == mp.end())
            return false;
    }
    return true;
}

int main(){


}