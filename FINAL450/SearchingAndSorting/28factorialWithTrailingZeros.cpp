#include <bits/stdc++.h>
using namespace std;

// The brute force approach will not work for larger values of N. So, we need to find a better approach.
// If we observe, a trailing zero is produced by the multiplication of prime factors 2 and 5. Hence, we need at least one occurrence of 2 and 5 in the prime factorization of factorial to get a trailing zero.
// We can use this observation to find the pattern. 

// Let’s see a few examples:

// 0! (= 1) has no trailing zeros. Also, all the numbers from 0 to 4 have no trailing zeros, due to the absence of prime factors 2 and 5.
// 5! (= 120) has one trailing zero. All the numbers from 5 to 9 have 1 trailing zero, due to the presence of prime factors 2 and 5, where 5 occurs only once.
// Similarly, the factorial of numbers 10 to 14 have 2 trailing zeros.
// Factorial of numbers 20 to 24 have 4 trailing zeros.
// Factorial of numbers 25 to 29 have 6 trailing zeros (one extra because 25 has two fives in its prime factorization), and so on.
// From this, we can observe that the minimum value containing at least N trailing zeros is always less than or equal to 5*N.
// So we can apply a binary search in the range 0 to 5*N to find the smallest number.
// For every iteration in binary search, we need to check if the current number has at least N trailing zeros in 
// its factorial. This can be found using the formula:
// Trailing 0s in X! = Number of 5s in the prime factorization of X!
// i.e Trailing 0s in X! = floor(X / 5) + floor(X / 25) + floor(X / 125) + .......
// The above formula is derived using the observation that in the prime factorization of a factorial, 
// the number of 5s is always less than the number of 2s. Hence, the number of trailing zeros only 
// depends on the number of 5s. (For more information you can refer to a previously solved problem here).


// int get_count(int x)

// {

//     int ans=0;

//     while( x/5 > 0 ){

//         ans += x/5;

//         x/=5;

//     }

//     return ans;

// }

int countZeros(int num){
    int count = 0;
    int five = 5;
    while(1){
        int temp = floor(num/five);
        count += temp;
        five = five*5;

        if (temp == 0)
            break;
    }
    return count;
}

int findNumber(int n){

    int low = 1;
    int high = 5*n;

    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        int count = countZeros(mid);
        if (count >= n){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    return ans;

}


int main(){

    cout << findNumber(7) << endl;
    return 0;
}