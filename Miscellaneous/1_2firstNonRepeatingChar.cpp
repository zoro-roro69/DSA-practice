#include <bits/stdc++.h>
using namespace std;


//using hashing
// Time Complexity: O(26 * n)
// Auxiliary Space: O(n)

string FirstNonRepeating(string A){
    string res = "";
    unordered_set <char> mp; //to store the chars encountered till now
    vector <char> v; //at any point it will store the chars that are currently unique (not repeated)
    //if v is empty means no unique chars till now

    for (char ch: A){
        if (mp.find(ch) == mp.end()){
            //first occurence of char
            v.push_back(ch);
            mp.insert(ch);
        }else{

            auto it = find(v.begin(), v.end(), ch);
            if (it == v.end()){
                //this char is already removed from vector
                //do nothing
            }else{
                //it is in vector , so we remove it now
                v.erase(it);
            }

        }

        //if v is empty then add '#' else add char at front
        res += (v.empty() ? '#' : v.front());
    }

    return res;
}

int main(){

    return 0;
}