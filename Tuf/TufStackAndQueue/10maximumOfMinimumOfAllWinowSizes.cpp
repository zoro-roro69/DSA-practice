#include <bits/stdc++.h>
using namespace std;

// The idea is to find the next smaller and previous smaller of each element
//then with right[i] - left[i] - 1; you get size of window in which the current element(ith elment)
// is the mnimum
vector<int> maxMinWindow(vector<int> a, int n) {
    vector <int> left_smaller(n, -1);
    vector <int> right_smaller(n, n);

    stack <int> st;
    for (int i=0;i<n;i++){
        while(!st.empty()){
            if (a[st.top()] > a[i]){
                right_smaller[st.top()] = i;
                st.pop();
            }else{
                break;
            }
        }

        if (i > 0 && a[i] == a[i - 1]) {
            // we use this condition to avoid the
            // unnecessary loop to find the left_smaller.
            // since the previous element is same as current
            // element, the left_smaller will always be the
            // same for both.
            left_smaller[i] = left_smaller[i - 1];
        }else{
            if (!st.empty()){
                left_smaller[i] = st.top();
            }
        }
        st.push(i);
    }

    vector <int> res(n, INT_MIN);

    for (int i=0;i<n;i++){
        int len = right_smaller[i] - left_smaller[i] - 1;
        res[len-1] = max(a[i], res[len-1]);
    }
    //in case some were missed
    for (int i = n - 2; i >= 0; i--) {
        res[i] = max(res[i], res[i+1]);
    }

    // for (int x:res)
    //     cout << x << " ";
    // cout << endl;

    return res;
}


int main(){
    vector <int> arr{1,2,3,4};
    vector <int> res = maxMinWindow(arr, arr.size());

    return 0;
}