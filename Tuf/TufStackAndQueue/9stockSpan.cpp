#include <bits/stdc++.h>
using namespace std;

vector<int> findSpans(vector<int> &price) {
    int n = price.size();
    vector <int> res(n, 1);

    stack <int> st;
    st.push(0);

    for (int i=1;i<n;i++){
        while(!st.empty()){
            if (price[st.top()] <= price[i]){
                //res[i] = max(res[i], max(res[st.top()]+1, i-st.top()+1));
                st.pop();
            } else {
                res[i] = i-st.top();
                break;
            }
        }
        if (st.empty())
            res[i] = i+1;

        st.push(i);
    }
    return res;
}

int main(){

    return 0;
}