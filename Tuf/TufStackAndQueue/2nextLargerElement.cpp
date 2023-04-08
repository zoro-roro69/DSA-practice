#include <bits/stdc++.h>
using namespace std;

//NGE == next greater element
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    if (n == 0)
        return {};
    
    stack <int> st;
    vector <int> res(n, -1);

    //at any point elements in the stack will be in reverse sorted order(decreasing order)
    for (int i=0;i<n;i++){

        while(!st.empty()){
            int top = st.top();

            if (arr[top] < arr[i]){ //ith is nge for top element
                res[top] = arr[i];
                st.pop();
            }else{
                // ith is smaller than all elements on the stack
                break;
            }
        }
        st.push(i);
    }

    return res;
}


int main(){

    return 0;
}