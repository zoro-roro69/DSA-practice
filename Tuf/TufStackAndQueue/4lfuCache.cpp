#include <bits/stdc++.h>
using namespace std;


//NOTE --- in heap the parent for ith is -- (i-1)/2;

struct Node{
    int val;
    int heap_ind;
    int freq;
    int call_num;

    Node(){
        val = 0;
        freq = 0;
        heap_ind = 0;
        call_num = 0;
    }
};

unordered_map <int, Node> mp; //mp[i] = {val, heap_ind} 

bool mycomparator(int x, int y){
    if (mp[x].freq < mp[y].freq)
        return true;
    else if (mp[x].freq > mp[y].freq)
        return false;
    else
        return mp[x].call_num < mp[y].call_num;
}

class Heap{
public:
    int arr[1001];
    int size = 0;

    Heap(){
        size = 0;
    }

    void init(){
        size = 0;
    }

    void insert(int x){
        arr[size] = x;
        mp[x].heap_ind = size;
        shiftUp(size++);
    }


    int removeTop(){
        if (size == 0)
            return -1;
        int res = arr[0];
        arr[0] = arr[--size];
        shiftDown(0);
        return res;
    }

    void shiftUp(int i){
        while(i && mycomparator(arr[i], arr[(i-1)/2])){
            swap(i, (i-1)/2);
            i = (i-1)/2;
        }
    }

    void shiftDown(int i){

        int left = 2*i+1;
        int right = 2*i+2;

        while(left < size){
            int next = left;

            if (right < size)
                next = mycomparator(arr[left], arr[right]) ? left : right;

            next = mycomparator(arr[i], arr[next]) ? i : next;

            if (next == i)
                break;

            swap(i, next);

            i = next;          
            left = 2*i+1;
            right = 2*i+2;
        }
    }

    void swap(int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        mp[arr[i]].heap_ind = i;
        mp[arr[j]].heap_ind = j;
    }
};


class LFUCache{
    int capacity;
    int call_num;
    Heap heap;
public:
    LFUCache(int cap){
        // Write your code here.
        capacity = cap;
        call_num = 0;
        heap.init();
        mp.clear();
    }

    int get(int key){
        // Write your code here.
        if (mp.find(key) == mp.end()) //key not present
            return -1;
        else{
            mp[key].freq++;
            mp[key].call_num = ++call_num;
            heap.shiftDown(mp[key].heap_ind);

            return mp[key].val;
        }
    }

    void put(int key, int value){
        // Write your code here.
        if (mp.find(key) == mp.end()){ //key not present
            //insert
            if (capacity){
                --capacity;
            }else{
                //strcuture is full
                int top = heap.removeTop();
                mp.erase(top);
                //now insert
            }


            mp[key].val = value;
            mp[key].freq = 1;
            mp[key].call_num = ++call_num;
            heap.insert(key);
        }else{
            //key present
            mp[key].val = value;
            mp[key].freq++;
            mp[key].call_num = ++call_num;
            heap.shiftDown(mp[key].heap_ind);
        }

    }
};

int main(){

    return 0;
}