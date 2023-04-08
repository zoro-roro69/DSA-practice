#include <bits/stdc++.h>
using namespace std;


string infixToPrefix(string infix){

    string res = "";
    stack <char> st; 

    map<char, int> mp;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;

    reverse(infix.begin(), infix.end());
    for (int i=0;i<infix.size();i++){
        if (infix[i] == ')')
            infix[i] = '(';
        else if (infix[i] == '(')
            infix[i] = ')';
    }

    // cout << infix << endl;

    for (auto ch: infix){
        if (ch == '('){
            st.push(ch);
        }
        else if(ch == ')'){
            while(st.top() != '('){
                res += st.top(); st.pop();
            }
            st.pop(); //removing opening parenthesis
        }
        else if(mp.find(ch) != mp.end()){ //operator
            while(!st.empty() && st.top()!='('){
                if (mp[st.top()] > mp[ch]){
                    res += st.top(); st.pop();
                }else{
                    break;
                }
            }

            st.push(ch);
        }else{ //operand
            res += ch;
        }
    }

    while(!st.empty()){
        res += st.top(); st.pop();
    }
    cout << res << endl;

    reverse(res.begin(), res.end());

    return res;
}

int main(){
    cout << 4*-5 << endl;
    string infix = "(a+b)*(c-d)";
    cout << infixToPrefix(infix) << endl;

    //(a+d)*

    return 0;
}