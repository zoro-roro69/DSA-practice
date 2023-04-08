#include <bits/stdc++.h>
using namespace std;

void printVector(vector <int> v){
    for (auto x:v){
        cout << x << " ";
    }
    cout<<endl;
}
//order of subsequence doesnt matter here
//method1 - using sorting
int longestSubsequence(vector <int> v){
    sort(v.begin(), v.end());
    printVector(v);
    int res = 1;

    for (int i = 0;i<v.size()-2;){
        int count = 1;
        while(i+1 < v.size() &&  v[i+1]-v[i] <=1){ //<= for duplicate elements as well
            if (v[i+1] - v[i] == 1)
                count++;
            i++;
        }
        i++;
        res = max(res, count);
    }
    return res;

}


//method 2 - using hashing
int longestSubsequence2(vector <int> v){
    unordered_set <int> mp;

    for (auto x:v)
        mp.insert(x);

    int res = 1;

    for (int i =0 ;i<v.size();i++){
        int count = 1;

        int temp = v[i]-1;
        //if cur element is starting element of the sequence
        if (mp.find(temp) == mp.end()){
            temp = v[i];           
            while(mp.find(temp)!=mp.end()){
                temp++;
                count++;
            }
        }
        res  = max(res, count);
    }
}

int main(){
    vector <int> v{6,6, 2, 3, 1, 4, 1, 5, 6, 2, 8, 7, 4, 2, 1, 3, 4, 5, 9, 6};
    cout << longestSubsequence(v) << endl;

    return 0;
}