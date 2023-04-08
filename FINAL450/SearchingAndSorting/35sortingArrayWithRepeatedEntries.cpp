#include <bits/stdc++.h>
using namespace std;

//Traditional qick sort implementation
int partition(vector <int> &arr, int start, int end){
    int pivot = end;
    int lt = start;
    for (int i=start;i<end;i++){
        if (arr[i] < arr[pivot]){
            swap(arr[lt], arr[i]);
            lt++;
        }
    }

    swap(arr[pivot], arr[lt]);
    return lt;
}



//Traditional quick sort implementation doesnt work well when we have array with
//large number of repeated entries
//exampple lets say we have - {4,4,4,4,4,4}
//in this case partition algo return the pivot index as 0
//so the subproblem is reduced by jutst size 1
//there the complexity in this case becomes O(n2)

// if we can handle these equal entries we can reduce the time complexity

// we can achieve this by modifying the partitoning algorithm
// in the original partitioning algo we partition the array in two
// [--elements less than pivot--pivot--elements >= pivot]

// instead of normal partitioning if we partiton the arrray in three parts
// [----- elements <= pivot ---- elmentts == pivot ---- elements >= pivot ---]
// one such solution is by Dijkastra solution for Dutch National Flag problem(DNF)

//wrong implementation :)

struct result {
    int left;
    int right;
};



//when most of the keys are equal the complexity of this algo becomes linear
result partitionDNF(vector <int> &arr, int start, int end){

    int lt = start; //less than end
    int gt = end; //greater than end

    int pivot = arr[end];

    int i = start;
    while ( i <= gt ){
        if (arr[i] > pivot){
            swap(arr[i], arr[gt]);
            gt--;
        }else if (arr[i] < pivot){
            swap(arr[i], arr[lt]);
            i++;
            lt++;
        }else{
            //equal
            i++;
        }
    }

    result res;
    res.left = lt;
    res.right = gt;

    return res;
}



void quickSort(vector <int> &arr, int start, int end){
    if (start >= end) //size 1 or less
        return;
    
    // int pivot = partition(arr, start, end);
    result pivot = partitionDNF(arr, start, end);
    cout << pivot.left << "--" << pivot.right << endl;
    quickSort(arr, start, pivot.left-1); //pivot is already at its correct position
    quickSort(arr, pivot.right+1, end);
    
}

int main(){

    vector <int> arr{1,2,3,4};
    quickSort(arr, 0, arr.size()-1);

    for (int x:arr)
        cout << x << " ";
    cout << endl;
    return 0;
}