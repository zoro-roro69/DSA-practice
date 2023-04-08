#include <bits/stdc++.h>
using namespace std;



//NSE = next Smaller element (first element which is greater than the current element)
vector<int> nextSmallerElement(vector<int> &arr, int n){
    if (n == 0)
        return {};

    vector <int> res(n, -1);
    stack <int> st;

    //at any point the elements in the stack will be in sorted order
    for (int i=0;i<n;i++){
        //checking if ith element is NSE for elements in the stack
        while(!st.empty()){
            int top = st.top();
            if (arr[top] > arr[i]){ //ith is the NSE for top
                res[top] = arr[i];
                st.pop();
            }else{
                //ith element is greater than all the stack elements
                break;
            }
        }
        st.push(i);
    }

    return res;

}

int main(){
    vector <int> arr{3,2,1,4,5,6};
    vector <int> res = nextSmallerElement(arr, arr.size());

    for (int x: res)
        cout << x << " ";
    cout << endl;

    return 0;
}