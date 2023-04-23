#include <bits/stdc++.h>
using namespace std;

void unionOfTwoStrings(string &s1, string &s2){

    bool mp[26];
    for (int i=0;i<26;i++)
        mp[i] = false;
    
    for (char ch:s1)
        mp[ch - 'a'] = true;

    for (char ch:s2)
        mp[ch - 'a'] = true;

    //print union
    for (int i=0;i<26;i++){
        if (mp[i])
            cout << char( 'a'+i ) << " ";
    }

    cout << endl;

    return;

}

void intersectionOfTwoStrings(string &s1, string &s2){
    bool mp[26];

    for (int i=0;i<26;i++)
        mp[i] = false;

    for (char ch:s1)
        mp[ch-'a'] = true;

    for (char ch:s2){
        if (mp[ch-'a'])
            cout << ch << " ";
    }
    cout << endl;

}

int main(){

    string s1 = "abaaacd";

    string s2 = "xxxxpornayz";

    unionOfTwoStrings(s1, s2);
    intersectionOfTwoStrings(s1, s2);

    return 0;
}