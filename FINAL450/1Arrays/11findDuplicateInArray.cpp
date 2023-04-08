#include <bits/stdc++.h>
using namespace std;

//since there is dupplicate number it indicates that there is a cycle
//here we modify the given array and mark the visited node to be -1
int findDuplicate(vector<int>& nums) {
    int i = 0;
    int num = nums[i];
    while(nums[i] != -1){
        num = nums[i];
        nums[i] = -1;
        i = num;
    }
    return num;
}

//using fast and slow pinters(torotise and hare)

int findDuplicate2(vector <int> &nums){

    int f = nums[0];
    int s = nums[0];

    //first loop finds the collision point inside the cycle
    while(1){
        s = nums[s];
        f = nums[nums[f]];

        if (s == f) break;
    }

    //now we initialise one of the pointers to start, and leave other as it is
    //now we increment both by one step, there point of collision is the entry point
    //of loop and also our duplicate node

    s = nums[0];
    while(s!=f){
        s = nums[s];
        f = nums[f];
    } 

    return s;
}