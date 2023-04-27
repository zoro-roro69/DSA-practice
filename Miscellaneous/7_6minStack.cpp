#include <bits/stdc++.h>
using namespace std;


// basic startegy here is that whenever i get a new min
// i dont want to loose the previous min
// i need a way to recover the old min from the new min

// when i get new num s.t num < min

// so on the stack instead of stroing the current num,
// we storea new num which is combination of previous min 
// adn this num (new min)
// and i.e
	
// 	2*num - min 

// Note - min here is storing the previous
// so after inserting this we update our min to a new number
// i.e 
// 	min = num

// why do we choose " 2*num - min " ?

// 	since num is less than prev min
// 	i.e 
// 		num < min

// 	this number " 2*num - min " is also less than num
	
// 	so lets say when on top of the stack we have , top = " 2*num - prev_min "
// 	the min will containing num.
// 	i.e:
// 		min == num

// 	now lets ssay we get pop operation, so now we have to remove the min and update
// 	the min in this case
// 	so from this equation 

// 		top = 2*num - prev_min

// 		prev_min = 2*num - top

// 	Note here num == min, which is being removed

// 	so
// 		prev_min = 2*min - top

// 	then we just simply update our min

// 		min = prev_min

// Ok but how do we know that on top of stack we have " 2*num - prev_min " ?
	
// 	like we discussed above that this number is always going to be less than the
// 	cuurent min
	
// 	so we simply check this condition
// 	if (top < min){
// 		//hence remove min and update it 
// 	}
		 


int main(){

    return 0;
}