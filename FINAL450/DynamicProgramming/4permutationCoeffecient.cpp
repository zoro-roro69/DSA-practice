#include <bits/stdc++.h>
using namespace std;

int permutation(int n, int k){

    int res = 1;

    for (int i=0;i<k;i++){
        res *= (n-i);
    }

    return res;

}

int main(){

    cout << permutation(10,3) << endl;
    cout << permutation(11,5) << endl;
    cout << permutation(9, 2) << endl;
    cout << permutation(8,4) << endl;



    return 0;
}