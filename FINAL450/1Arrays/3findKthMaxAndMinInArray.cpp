#include <bits/stdc++.h>
using namespace std;


//create a min heap of size k,
//add elements until heap is full, then for the next element
//compare it to the top of the heap
// if (top < element) remove top and add element to list
// else continue
// do this for all remaining elements, in the end return the top
//elemnt of heap, it will kth largest element 

int findKthMaxElementInArray(vector <int> arr, int k){

    priority_queue <int, vector<int>, greater<int>> min_heap;  

    for (auto x:arr){
        if (min_heap.size()<k)
            min_heap.push(x);
        else{
            if (min_heap.top() < x){
                min_heap.pop();
                min_heap.push(x);
            }
        }

    }
    return min_heap.top();
}


int findKthMinElementInArray(vector <int> arr, int k){
    priority_queue <int> max_heap;

    for (auto x:arr){
        if (max_heap.size()< k)
            max_heap.push(x);
        else{
            if (max_heap.top() > x){
                max_heap.pop();
                max_heap.push(x);
            }
        }
    }

    return max_heap.top();

}

int main(){

    vector <int> arr;
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(9);
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(1);
    arr.push_back(3);
    //1,2,3,3,5,7,9
    cout << findKthMaxElementInArray(arr, 3) << endl;
    cout << findKthMinElementInArray(arr, 5) << endl;

    return 0;
}