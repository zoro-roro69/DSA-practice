#include <bits/stdc++.h>
using namespace std;

int median(int arr[], int s, int e){
    return (arr[(s+e)/2] + arr[(s+e+1)/2])/2; 
}

int findMedianOf2Sorted(int a[], int b[], int sa, int ea,int sb, int eb){

    if (ea - sa <= 1){ 
        //[1,3] [2,4] --- [1,2,3,4]
        return (max(a[sa], b[sa]) + min(a[ea], b[eb]))/2;
    }
    else{
        int m1 = median(a, sa, ea);
        int m2 = median(b, sb, eb);

        if (m1 == m2)
            return m1;
        else if (m1 < m2){

            return findMedianOf2Sorted(a, b, (sa + ea + 1)/2, ea, sb, (sb + eb + 1)/2);
        }
        else
            return findMedianOf2Sorted(a, b, sa, (sa + ea +1)/2, (sb + eb +1)/2 , eb);

    }

}

int main(){

    return 0;
}
