#include <bits/stdc++.h>
using namespace std;

string decodedString(string s){
    // code here
    stack <int> count;
    vector <string> st;

    string num_s = "";
    // for (char ch:s){
    for (int i=0;i<s.size();i++){
        char ch = s[i];
        if (ch >= '0' && ch <= '9'){
            num_s += ch;
        }
        else if(ch == '['){
            int num = stoi(num_s);
            num_s = "";
            count.push(num);
            st.push_back("[");
        }
        else if (ch == ']'){
            string str = "";
            while(!st.empty() && st.back()!="["){
                str += st.back(); st.pop_back();
            }
            if (!st.empty())
                st.pop_back();//remove '['

            // reverse(str.begin(), str.end());
            int cnt = count.top(); count.pop();
            string res = "";
            while(cnt){
                res += str; cnt--;
            }
            // cout << res << endl;
            st.push_back(res);
        }else{ //a - z
            // cout <<"char:" << ch<< endl;;
            string temp="";
            temp+= ch;
            // cout << "temmpp : "<<temp << endl;
            st.push_back(temp);
        }
    }
    // string res = st.back();
    string res = "";
    for (string s: st){
        reverse(s.begin(), s.end());
        res += s;
    }
    // reverse(res.begin(), res.end());
    return res;

}

int main(){
    string s = "";
    cout << decodedString(s) << endl;


    return 0;
}