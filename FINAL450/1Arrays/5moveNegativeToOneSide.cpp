#include <bits/stdc++.h>
using namespace std;



// order not maintained in this
void moveAllNegativeToOneSide(vector <int> &arr){

    int s = 0;
    for (int i=0;i<arr.size();i++){
        if (arr[i] < 0){
            swap(arr[s++], arr[i]);
        }
    }
}

//if we want to maintain the order of negative and positive 
//we can use modifed insertion sort 

void printVector(vector <int> v){
    for (auto x:v)
        cout<<x<<" ";
    cout<<endl;
}

int main(){

    vector <int> v;

    v.push_back(1);
    v.push_back(1);
    v.push_back(3);
    v.push_back(-9);
    v.push_back(-5);
    v.push_back(-6);
    v.push_back(5);
    v.push_back(2);

    printVector(v);
    moveAllNegativeToOneSide(v);
    printVector(v);
    return 0;

}