#include <bits/stdc++.h>
using namespace std;

void printVector(vector <int> v){
    for (auto x:v){
        cout << x << " ";
    }
    cout<<endl;
}


//when extra space is allowed, simple merge of mergeSort
void merge2SortedArrays(vector <int> v1, vector <int> v2){

    vector <int> res;
    
    int i = 0, j = 0;

    while(i<v1.size() && j < v2.size()){
        if (v1[i] <= v2[j]){
            res.push_back(v1[i++]);
        }else{
            res.push_back(v2[j++]);
        }
    }

    while(i<v1.size())
        res.push_back(v1[i++]);

    while(j<v2.size())
        res.push_back(v2[j++]);

    cout << "res:"; printVector(res);
    
}

//when no extra space is allowed
//insertion sort like algorithm, we start from last element of second array
//and try to insert it in first array
//complexity - O(n*m) , n = size of arr1, m = size of arr2

void merge2(vector <int> v1, vector <int> v2){

    for (int j=v2.size()-1;j>=0;j--){
        int i = v1.size()-1;
        int last = v1[i];

        while(v2[j]<v1[i]){
            v1[i] = v1[i-1];
            i--;
        }

        i++;
        
        if (i < v1.size()){
            v1[i] = v2[j];
            v2[j] = last; 
        }
    }
    //now v1 and v2 will be in sorted order

    printVector(v1);
    printVector(v2);
}

//return ceil of gap/2
int nextGap(int gap){
    if (gap <=1)
        return 0;
    return gap/2 + gap%2;

}


//complexity - O((n+m)*log(n+m))
void merge3(vector <int> v1, vector <int> v2){

    int n = v1.size();
    int m = v2.size();

    int gap = n+m;

    int i =0, j = 0;
    for (gap = nextGap(gap); gap>0;gap = nextGap(gap)){

        for (i=0;i+gap<n;i++){
            if (v1[i] > v1[i+gap]){
                //swap
                swap(v1[i], v1[i+gap]);
            }
        }

        j = (gap>n) ? (gap-n):0; 

        for (;i<n && j < m;i++,j++){
            if (v1[i] > v2[j]){
                //swap
                swap(v1[i], v2[j]);
            }
        }

        if (j<m){
            for(;j+gap<m;j++){
                if (v1[j] > v1[j+gap]){
                    //swap
                    swap(v1[j], v2[j+gap]);
                }
            }
        }
    }

    printVector(v1);
    printVector(v2);

}



int main(){

    vector <int> v1{1,1,2,3,4,5};

    vector <int> v2{1,2,3};

    cout << "vector 1:"; printVector(v1);
    cout << "vector 2:"; printVector(v2);

    merge2SortedArrays(v1, v2);

    cout << "merge 2:" << endl; 
    merge2(v1, v2);

    cout << "merge 3:" << endl; 
    merge2(v1, v2);

    return 0;
}