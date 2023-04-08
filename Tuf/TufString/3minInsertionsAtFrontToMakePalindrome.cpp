#include <bits/stdc++.h>
using namespace std;

//this question is little different from the previous one,
//in the previous one we were allowed to insert everywhere
//but in this we can only insert at front

int minInsertionsAtFront(string s){
    vector <int> lps(s.size(), 0);
    string temp = s;
    reverse(temp.begin(), temp.end());

    temp = s + "$" + temp;

    lps[0] = 0;
    int i = 1; int len = 0;

    while(i < temp.size()){
        if (temp[i] == temp[len]){
            len++;
            lps[i++] = len;
        }else{
            if (len != 0){
                len = lps[len-1];
            }else{
                lps[i++] = 0;
            }
        }
    }

    return s.size() - lps.back();

}

int main(){

    string s = "axxb";

    cout << minInsertionsAtFront(s) << endl;

    return 0;
}

