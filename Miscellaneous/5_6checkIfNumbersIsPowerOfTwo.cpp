#include <bits/stdc++.h>
using namespace std;

//method1 keep on dividing the number of two until it becomes 1
// if in between the number%2 == 1 means the number is not the power of two

bool isPowerOfTwo_1(int num){

    while(num > 1){
        if (num%2 == 1)
            return false;
        num /= 2;
    }

    return true;
}

//method 2 by counting set bits
// all the numbers which are power of 2 only have 1 set bit

int isPowerOfTwo_2(int num){
    if (num == 0)
        return false;
    int count = 0;

    while(num > 0){
        if (num & 1)
            count ++;
        num >> 1;
    }

    return count > 1 ? false: true;
}


//method 3: since we know that a number which is power of 2 has only 1 bit set
// subtracting 1 from it will make this set bit 0 and all unset lower bits will be set
//example 8 (1000), 8-1 = 7 (0111)
// now if we do n&(n-1) we get 0 
// so the number is power of 2 if n&n-1 = 0

bool isPowerOfTwo_3(int num){
    if (num == 0)
        return false;

    return num&(num-1) == 0;
}

//method 4: using not operator
// example n = 8  = (001000)
// n-1  = 7 (000111)
// ~(n-1) = (111000)
// n&~(n-1) = 001000 & 111000 = n = 001000
bool isPowerOfTwo_4(int num){
    if (num == 0)
        return false;
    
    return num & ~(num-1) == num;

}

int main(){

    cout << isPowerOfTwo_2(0) << endl;
    return 0;
}