#include <bits/stdc++.h>
using namespace std;



void printVector(vector <int> v){
    for (auto x:v){
        cout << x << " ";
    }
    cout<<endl;
}

int merge(vector <int> &v, int s, int mid, int e){
    int inversion_count = 0;

    vector <int> temp;
    int i=s, j= mid+1;
    for(; i<=mid && j<=e;){

        if (v[i]<=v[j]){//no inversion
            temp.push_back(v[i++]);
        }else{
            //inversion
            temp.push_back(v[j++]);
            inversion_count += mid-i+1;
        }
    }

    while(i<=mid)
        temp.push_back(v[i++]);

    while(j<=e)
        temp.push_back(v[j++]);

    i = s;
    for (auto x:temp)
        v[i++]=x;

    return inversion_count;

}

int mergeSort(vector <int> &v, int s, int e){
    if (s >= e) 
        return 0;
    else{
        int mid = (s+e)/2;

        int inv = 0; 
        inv += mergeSort(v, s, mid);
        inv += mergeSort(v, mid+1, e);

        return inv + merge(v, s, mid, e);
    }
}

int main(){

    vector <int> v{5,4,1,3,2};

    printVector(v);
    cout << "inversion :" << mergeSort(v, 0, v.size()-1) << endl;
    printVector(v);

    return 0;
}
