#include <bits/stdc++.h>
using namespace std;

class minStack{
	// Write your code here.
    stack <int> st;
    int min_;
	public:
		// Constructor
		minStack() { 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num){
			// Write your code here.
            if (st.empty()){
                st.push(num);
                min_ = num;
            }else{
                if (min_ <= num){
                    st.push(num);
                }else{
                    //new min
                    int temp = 2*num - min_;
                    min_ = num;
                    st.push(temp);
                }
            }
		}

		// Function to remove the top element of the stack.
		int pop(){
			// Write your code here.
            if (st.empty())
                return -1;
            int top = st.top(); st.pop();
            if (top >= min_)
                return top;
            
            int temp = min_; 
            int prev_min = 2*min_ - top;
            min_ = prev_min;

            return temp;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top(){
			// Write your code here.
            if (st.empty())
                return -1;

            int top = st.top();
            if (top >= min_) //current min element is still the min
                return top;
            
            return min_;

		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin(){
			// Write your code here.
            if (st.empty())
                return -1;
            return min_;
		}
};

int main(){

    return 0;
}