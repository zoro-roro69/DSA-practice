#include <bits/stdc++.h>
using namespace std;


void printVector(vector <int> v){
    for (auto x:v){
        cout << x << " ";
    }
    cout<<endl;
}

void rotateArrayByOne(vector <int> &arr){

    if (arr.empty())
        return;

    int last = arr.back();
    
    for (int i= arr.size()-1;i>0;i--){
        arr[i] = arr[i-1];
    }

    arr[0] = last;
    printVector(arr);
}

void rotateArrayByOne2(vector <int> &arr){

    if (arr.empty())
        return;

    int i =0, j = arr.size()-1;

    //here the last position will act as temporary storage for elements before putting
    //them into their correct position
    //example {1,2,3,4,5} in first iteration we swap 1,5 
    //now 5 is at ind 0, 1 is at ind 4 now in next itr i == 1
    // we swap 2,1, now 1 is at its correct position and 2 in temprary storage in next itr 
    //2 will be at its correct position
    for (;i<j;i++){
        swap(arr[i], arr[j]);
    }
}

int main(){

    vector <int> arr{1,2,3,4,5};

    printVector(arr);
    rotateArrayByOne(arr);

    return 0;
}
