#include <bits/stdc++.h>
using namespace std;

double medianSortedUnequalSize(vector <int> arr1, vector <int> arr2){

    int n1 = arr1.size();
    int n2 = arr2.size();

    if (n2 < n1) return medianSortedUnequalSize(arr2, arr1);

    int n = (arr1.size() + arr2.size()+1)/2;
    int low = 0, high = n1-1;

    while (low <= high){
        int cut1 = (low + high)/2;

        int cut2 = n - (cut1+1) - 1;

        int left1 = cut1 < 0 ? INT_MIN : arr1[cut1];
        int left2 = cut2 < 0 ? INT_MIN : arr2[cut2];

        int right1 = cut1 + 1 > n1 ? INT_MAX : arr1[cut1+1];
        int right2 = cut2 + 1 > n2 ? INT_MAX : arr2[cut2+1];

        //cross check
        if (left1 <= right2 && left2 <= right1){
            if ((n1 + n2)%2 == 0){
                return (max(left1, left2) + min(right1, right2))/2.0;
            }
            return max(left1, left2);
        }else if (left1 > right2){
            high = cut1-1;
        }else{
            low = cut1+1;
        }

    }
    return 0.0;
}

int main(){

    vector <int> v1{1,4,7};
    vector <int> v2{2,3,4};

    cout << medianSortedUnequalSize(v1, v2) << endl;

    return 0;
}