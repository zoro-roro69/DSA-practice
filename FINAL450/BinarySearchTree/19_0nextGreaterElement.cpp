#include <bits/stdc++.h>
using namespace std;


//Function to find the next greater element for each element of the array.
// Time Complexity: O(N) 
// Auxiliary Space: O(N)

vector<long long> nextLargerElement(vector<long long> arr, int n){
    if (n == 0)
        return {};
    stack <long long> st;
    vector <long long> res(n, 0);

    st.push(0); //stack will contain indexes

    for (int i=1;i<n;i++){
        while(!st.empty() && arr[i] > arr[st.top()]){
            int top = st.top(); st.pop();
            res[top] = arr[i];
        }

        st.push(i);
    }

    while(!st.empty()){ //no greater element for these
        int top = st.top(); st.pop();
        res[top] = -1;
    }

    return res;
}


int main(){

    return 0;
}