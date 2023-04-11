#include <bits/stdc++.h>
using namespace std;


int longestSubstrDistinctChars (string s){

    vector <bool> mp(26, false);
    int len = 0;
    int start = 0;
    int res = 0;
    for (int i=0;i<s.size();i++){
        if (mp[s[i] - 'a'] == false){
            //new char
            //add to mp
            mp[s[i] - 'a'] = true;
            len++;
            res = max(res, len);
        }else{
            //repeating char
            int j = start;
            while (s[j] != s[i]){
                mp[s[j]-'a'] = false;
                j++;
            }
            //j is current at point where the char s[i] previously occured
            start = j+1;
            len = i - start + 1;

        }
    }

    return res;
}

int main(){

    return 0;
}