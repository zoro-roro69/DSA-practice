#include <bits/stdc++.h>
using namespace std;


void printVector(vector <int> v){
    for (auto x:v){
        cout << x << " ";
    }
    cout<<endl;
}

int minimizeMaximumDifference(vector <int> v, int k){

    sort(v.begin(), v.end());
    printVector(v);

    int temp_min = v[0];
    int temp_max = v.back();


    int diff = temp_max - temp_min; //if k=0 then this will be the answer

    for (int i=0; i<v.size()-1; i++){
        temp_min = min(v[0]+k, v[i+1]-k);
        temp_max = max(v[i]+k, v.back()-k);


        diff = min(diff, temp_max - temp_min);
    }

    return diff;
}

int main(){

    vector <int> v{8,1,5,4,7,5,7,9,4,6};
    cout << minimizeMaximumDifference(v, 5) << endl;
    return 0;
}
