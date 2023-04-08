#include <bits/stdc++.h>
using namespace std;

// Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him 
// since he has a nifty new woodcutting machine that can take down forests like wildfire.
//  However, Mirko is only allowed to cut a single row of trees.

// Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and
//  the machine raises a giant sawblade to that height and cuts off all tree parts higher
//   than H (of course, trees not higher than H meters remain intact). Mirko then takes the 
//   parts that were cut off. For example, if the tree row contains trees with heights 
//   of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres, the 
// remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, 
// while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

// Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. 
// That‟s why he wants to set his sawblade as high as possible. Help Mirko find the maximum 
// integer height of the sawblade that still allows him to cut off at least M metres of wood.


int ekoSpoj(int arr[], int n, int m){
    //n = size of array
    //m = min size of wood reqd

    //range of ht of saw blade
    long long int low = 1;
    long long int high = 2000000000;
    int ans;
    while(low <= high){
        long long int mid = low + (high - low)/2;

        long long int wood_len = 0;
        for (int i=0;i<n;i++){
            if (mid < arr[i]){
                wood_len += arr[i] - mid;
            }
        }

        if (wood_len >= m){
            low = mid+1;
            ans = mid;
        }else{
            high = mid-1;
        }

    }

    return ans;

}

int main(){

    return 0;
}