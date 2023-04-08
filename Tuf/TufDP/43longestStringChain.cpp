#include <bits/stdc++.h>
using namespace std;

struct less_than_key
{
    inline bool operator() (const string& s1, const string& s2)
    {
        return (s1.size() < s2.size());
    }
};

bool mycomparaator(const string &s1, const string &s2){
    return s1.size() <= s2.size();
}

bool helper(string word1, string word2){
    //return true if word2 is predecessor of word1
    int n = word1.size();
    int m = word2.size();

    if (n!=m+1)
        return false;

    int i = 0 , j = 0;
    int diff_count = 0;
    while(i<n && j < m){
        if (word1[i] != word2[j]){ //if dont match
            if (diff_count) return false;
            diff_count++;
            i++;
        }else{ //if match
            i++;
            j++;
        }
    }

    return true;


}

int longestStringChain(vector <string> words){
    int n = words.size();
    if (n<=1)
        return n;

    sort(words.begin(), words.end(), less_than_key());

    int dp[n];

    for (int i=0;i<n;i++)
        dp[i] = 1;

    int res = 1;
    for (int i=1;i<n;i++){
        for (int j=i-1;j>=0 && j+1>=dp[i];j--){
            if (dp[j]+1 > dp[i] && helper(words[i], words[j])){
                dp[i] = dp[j] +1;
            }
        }

        res = max(res, dp[i]);
    }

    return res;

}

int main(){
    
    vector <string> arr{"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"};
    // sort (arr.begin(), arr.end(), mycomparaator);

    for (auto x:arr)
        cout << x << " ";
    cout << endl;

    cout << longestStringChain(arr) << endl;

    return 0;
}