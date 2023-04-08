#include <bits/stdc++.h>
using namespace std;

void printVector(vector <int> v){
    for (auto x:v){
        cout << x << " ";
    }
    cout<<endl;
}

//one solution would be to use partition algo of quick sort two times,
//first time we will keep low val as pivot 
//second time keep high val as pivot
//complexity is O(n) but it requires multiple iterations


//it can be done in single iteration like this

void threeWayPartition3(vector <int> &v, int lowVal, int highVal){

    int start = 0, end = v.size()-1;

    for (int i=0;i<=end;){
        if (v[i] < lowVal){
            swap(v[i++], v[start++]);
        }
        else if(v[i] > highVal){
            swap(v[i], v[end--]);
        }else
            i++;
    }

    return ;
}




int main(){

    vector <int> v{1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    threeWayPartition3(v, 14, 20);
    printVector(v);   

    return 0;
}