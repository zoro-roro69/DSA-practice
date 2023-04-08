#include <bits/stdc++.h>
using namespace std;


void helper(string &s, int i, vector <string> &res){
    if (i >= s.size()){
        res.push_back(s);
        return;
    }

    for (int j=i;j<s.size();j++){
        swap(s[i], s[j]);
        helper(s, i+1, res);
        swap(s[i], s[j]);
    }


}

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector <string> res;

    helper(s, 0, res);
    return res;
}

int main(){

    return 0;
}