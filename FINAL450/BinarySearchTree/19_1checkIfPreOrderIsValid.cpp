#include <bits/stdc++.h>
using namespace std;


// check if given preorder of BST is valid or not
// lets say if this is the given bst
//                   +----+
//                   | 5  |
//           +-------+----+-------+
//           |                    |
//           |                    |
//        +--+-+                +-+--+
//        | 3  |                |  7 +-------+
//   +----+----+                +-+--+       |
//   |         |                  |          |
//   |         |                  |          |
// +-+-+      ++---+          +---++      +--+--+
// | 2 |      | 4  |          |  6 |      |  8  |
// +---+      +----+          +----+      +-----+

// then its preorder will be : 5 3 2 4 7 6 8

// in this you can see that for any element all elements after the first greater elment, 
// are also greater than that element
// lets say for 5 the first greater element is 7 and all elements after that (6, 8) are also > than 5
// so we will us this property to check if given preorder is valid or not

// An Efficient Solution can solve this problem in O(n) time. The idea is to use a stack. 
// This problem is similar to Next (or closest) Greater Element problem. Here we find the next greater 
// element and after finding next greater, if we find a smaller element, then return false.

// 1) Create an empty stack.
// 2) Initialize root as INT_MIN.
// 3) Do following for every element pre[i]
//      a) If pre[i] is smaller than current root, return false.
//      b) Keep removing elements from stack while pre[i] is greater
//         then stack top. Make the last removed item as new root (to
//         be compared next).
//         At this point, pre[i] is greater than the removed root
//         (That is why if we see a smaller element in step a), we 
//         return false)
//      c) push pre[i] to stack (All elements in stack are in decreasing
//         order)



int canRepresentBST(int arr[], int N) {
    // code here
    if (N == 0)
        return true;
    stack <int> st;
    st.push(arr[0]);
    int root = INT_MIN;

    for (int i=1;i<N;i++){
        if (arr[i] < root)
            return false;
        while(!st.empty() && arr[i] > st.top()){
            root = st.top();
            st.pop();
        }
        st.push(arr[i]);
    }

    return true; //if empty then true else false
    
}



int main(){
    int arr[] = {2,3,4};

    cout << canRepresentBST(arr, 3) << endl;

    return 0;
}