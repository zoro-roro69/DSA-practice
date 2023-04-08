#include <bits/stdc++.h>
using namespace std;


bool helper(int i, string &s, unordered_set <string> &map, vector <string> &res){
    if (i >=s.size())
        return true;

    string cur_str = "";
    for (int j=i;j<s.size();j++){
        cur_str = s.substr(i, j-i+1);
        if (map.find(cur_str) != map.end()){
            res.push_back(cur_str);
            if (helper(j+1, s, map, res)){
                return true;
            }
            res.pop_back(); //backtrack
        }
    }
    return false;

}

vector<string> wordBreak(string &s, vector<string> &dictionary){
    // Write your code here

    unordered_set <string> map;
    for (string s:dictionary)
        map.insert(s);

    vector <string> res;


    helper(0, s, map, res);

    return res;
    

}

int main(){
    vector <string> dict{"god","is","now","no","where","here"};
    string s = "godisnowherenowhere";

    vector <string> res = wordBreak(s, dict);
    for (auto x:res)
        cout << x << " ";
    cout << endl;
    return 0;
}