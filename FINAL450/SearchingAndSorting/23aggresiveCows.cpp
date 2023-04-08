#include <bits/stdc++.h>
using namespace std;

// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are 
// located along a straight line at positions x1 ... xN (0 <= xi <= 1,000,000,000).

// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other 
// once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?


int aggresiveCows(int n, int c, vector <int> &stalls){
    //n = num of stalls
    //c = num of cows

    sort(stalls.begin(), stalls.end());
    for(int x:stalls){
        cout << x << endl;
    }

    int low = 1; //min distance can be of 1 between any two stalls
    int high = 1000000000; //max distance possible, given in question

    int ans = 1; //as c <=n therefore ans = 1 in worst case
    while (low <= high){
        int mid = low + (high-low)/2;
        //will check if mid as minimum distance is possible or not
        
        int prev = stalls[0]; //placing the first cow at 0th stall
        int rem_cows = c-1;

        for(int i=1;i<n && rem_cows>0;i++){
            if (stalls[i] - prev >= mid){
                prev = stalls[i]; //placing current cow here
                rem_cows--;
            }
        } 

        if (rem_cows == 0){ //all cows placed
            ans = mid; //found the answer
            low = mid+1; //now we try for larger distance
        }else{
            //current mid is not possible for minimum disntace
            // so we try lower value

            high = mid-1;
        }

    }

    return ans;

}

int main(){
    // freopen("0input.txt", "r", stdin);

    int t;
    cin >> t;

    while(t--){
        int n, c;
        cin >> n >> c;

        vector <int> stalls(n,0);
        for (int i=0;i<n;i++){
            cin>>stalls[i];
        }

        cout << aggresiveCows(n, c, stalls) << endl;

    }

    return 0;
}