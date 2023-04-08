#include <bits/stdc++.h>
using namespace std;


void sort012Array(vector <int> &v){
    
    int count_0 = 0;
    int count_1 = 0;

    for (auto x:v){
        if (x == 0) count_0++;
        if (x == 1) count_1++;
    }
    int i = 0;
    while(count_0){
        v[i] = 0;
        count_0--;
        i++;
    }

    while(count_1){
        v[i] = 1;
        count_1--;
        i++;
    }

    while(i<v.size()){
        v[i++] = 2;
    }
}

void printVector(vector <int> v) {
    for (auto x:v)
        cout<< x << " " ; 

    cout << endl;
}

//better solution, does in 1 iteration
// Function to sort the input array,
// the array is assumed
// to have values in {0, 1, 2}
void sort012(int a[], int arr_size)
{
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;
 
    // Iterate till all the elements
    // are sorted
    while (mid <= hi) {
        switch (a[mid]) {
 
        // If the element is 0
        case 0:
            swap(a[lo++], a[mid++]);
            break;
 
        // If the element is 1 .
        case 1:
            mid++;
            break;
 
        // If the element is 2
        case 2:
            swap(a[mid], a[hi--]);
            break;
        }
    }
}

int main(){

    vector <int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);

    printVector(v);
    sort012Array(v);
    printVector(v);


    
    return 0;
}