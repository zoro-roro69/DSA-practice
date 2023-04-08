#include <bits/stdc++.h>
using namespace std;


bool possible(vector <int> &arr, int limit, int p){
    //return true if can cook >= p paranthas within the limit
    //else return false

    int num_paranthas = 0;
    for (int x:arr){ //remember size of arr is 50 (we only have at max 50 cooks)
        int time = 0;
        int count = 1;
        while(time + x*(count) <= limit){
            time += x*count;
            count++;
            num_paranthas++;
        }
    }

    return num_paranthas >= p;
}

int rotiParantha(vector <int> &arr, int p){
    // arr = times taken by cooks
    // p = num of paranthas to get
    // return min time to get p paranthas
    int low = 1;
    int high = 0;
    for (int x:arr){
        // low = max(x, low);
        high = max(high, x*p*(p+1)/2);
    }

    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if (possible(arr, mid, p)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    return ans;
}

int main(){

    freopen("0input.txt", "r", stdin);

    int t;
    cin >> t;
    
    while(t--){
        int p; cin>>p;
        int n; cin>>n;
        vector <int> arr(n, 0);
        for (int i=0;i<n;i++)
            cin >> arr[i];

        cout << rotiParantha(arr, p) << endl;
    }

    return 0;
}