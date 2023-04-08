#include <bits/stdc++.h>
using namespace std;

void printVector(vector <int> v){
    for (auto x:v){
        cout << x << " ";
    }
    cout<<endl;
}

//using bs to find the index next largest element of 'cur' 
int binarySearch(vector <int> &v, int cur, int s, int e){
    //here v[s to e] is sorted in decreasing order
    //i.e we can apply binary search to find next greater element

    int ans = s;//ans will store index of next greater element
    while(s<=e){
        int m = (s+e)/2;

        if (cur < v[m]){//candidate ans
            ans = m;
            s = m+1;
        }else{
            e = m-1;
        }
    }
    return ans;
}

void reverseVector(vector <int> &v, int s, int e){
    for (;s<e;s++,e--){
        swap(v[e], v[s]);
    }
}

void nextPermutation(vector <int> &v){
    //[5,4,1,3,2]
    if (v.size()<=1)
        return;

    int i;
    for (i = v.size()-2;i>=0;i--){
        if (v[i] < v[i+1])
            break;
    }

    if (i>=0){
        int ind = binarySearch(v, v[i], i+1, v.size()-1);
        swap(v[i], v[ind]); //swaping it with next largest element
    }
    i++;

    //reversing the array from i to end, to get sorted array from i to end(to get lexicorgraphical
    // order)
    reverseVector(v,i,v.size()-1);
}

int main(){

    vector <int> arr{5,5,3,7,4,2};
    printVector(arr);
    nextPermutation(arr);
    printVector(arr);

    return 0;
}