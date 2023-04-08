#include <bits/stdc++.h>
using namespace std;

bool areAnagram(string &str1, string &str2){
    // Write your code here.
    int map[26];
    for (int i=0;i<26;i++)
        map[i] = 0;

    for (char ch:str1)
        map[ch-'a']++;
    
    for (char ch:str2)
        map[ch-'a']--;
    
    for (int i=0;i<26;i++){
        if (map[i] != 0)
            return false;
    }

    return true;
}


int main(){

    return 0;
}