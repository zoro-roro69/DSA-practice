#include <bits/stdc++.h>
using namespace std;

//you can add memoization to further improve the code
string writeAsYouSpeak(int n){
    //print after nth iteration
    string s = "1";
    if (n == 1)
        return s;
    vector <pair<int,char>> count_arr;

    int i =1;
    while(i<n){
        int count = 1;
        int j= 1;
        while(j<s.size()){
            if (s[j] == s[j-1]){
                count++;
            }else{
                count_arr.push_back({count , s[j-1]}); //conver int to string
                count = 1;
            }
            j++;
        }

        count_arr.push_back({count , s[j-1]});
        //get string
        s = "";
        for (auto p:count_arr){
            s += to_string(p.first);
            s += p.second;
        }

        count_arr.clear();
        i++;
    }

    return s;
}

int main(){
    cout << writeAsYouSpeak(7) << endl;
    return 0;
}