#include <bits/stdc++.h>
using namespace std;



int largestRectangleArea(vector<int>& arr) {
        // Write your code here.
    int n = arr.size();
    // we create an empty stack here.
    stack<int> s;
    // we push -1 to the stack because for some elements
    // there will be no previous smaller element in the
    // array and we can store -1 as the index for previous
    // smaller.
    s.push(-1);
    int area = arr[0];
    int i = 0;
    // We declare left_smaller and right_smaller array of
    // size n and initialize them with -1 and n as their
    // default value. left_smaller[i] will store the index
    // of previous smaller element for ith element of the
    // array. right_smaller[i] will store the index of next
    // smaller element for ith element of the array.
    vector<int> left_smaller(n, -1), right_smaller(n, n);
    while (i < n) {
        while (!s.empty() && s.top() != -1
                && arr[s.top()] > arr[i]) {
            // if the current element is smaller than
            // element with index stored on the top of stack
            // then, we pop the top element and store the
            // current element index as the right_smaller
            // for the popped element.
            right_smaller[s.top()] = i;
            s.pop();
        }
        if (i > 0 && arr[i] == arr[i - 1]) {
            // we use this condition to avoid the
            // unnecessary loop to find the left_smaller.
            // since the previous element is same as current
            // element, the left_smaller will always be the
            // same for both.
            left_smaller[i] = left_smaller[i - 1];
        }
        else {
            // Element with the index stored on the top of
            // the stack is always smaller than the current
            // element. Therefore the left_smaller[i] will
            // always be s.top().
            left_smaller[i] = s.top();
        }
        s.push(i);
        i++;
    }
    for (int j = 0; j < n; j++) {
        // here we find area with every element as the
        // smallest element in their range and compare it
        // with the previous area.
        // in this way we get our max Area form this.
        area = max(area, arr[j]
                                * (right_smaller[j]
                                - left_smaller[j] - 1));
    }
    return area;
}


// int largestRectangleArea(vector<int>& heights) {
//         // Write your code here.
//         int n = heights.size();
//         vector <int> left_smaller(n, -1);
//         vector <int> right_smaller(n, n);

//         stack <int> st;

//         for (int i=0;i<n;i++){
//             if (i > 0 && heights[i] == heights[i-1]){
//                 left_smaller[i] = left_smaller[i-1];
//                 st.push(i);
//                 continue;
//             }
//             while(!st.empty()){
//                 int top = st.top();
//                 if (heights[top] > heights[i]){
//                     right_smaller[top] = i;
//                     st.pop();
//                 }else{
//                     break;
//                 }
//             }
//             if (!st.empty() && heights[st.top()] < heights[i])
//                 left_smaller[i] = st.top();
//             st.push(i);
//         }

//         int res = 0;
//         for (int i=0;i<n;i++){
//             // if (right_smaller[i] == -1)
//             //     right_smaller[i] = n;
//             // if (left_smaller[i] == -1)
//                 // left_smaller[i] = -1;
//             int width = right_smaller[i] - left_smaller[i] - 1;
//             res = max(res, width*heights[i]);
//         }

//         return res;
// }

int main(){

    vector <int> arr{1,2,1,0,1,1,0,0,2,2};
    
    // cout << largestRectangle(arr) << endl;

    return 0;

}