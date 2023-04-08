#include <bits/stdc++.h>
using namespace std;


void bishuAndSoldiers(vector <int> &arr, vector <int> &pre_sum, int power){

    int n = arr.size();

    int l = 0;
    int r = n;

    int ind = -1;
    while(l <=r ){
        int mid = l+(r-l)/2;
        if (arr[mid] <=power){
            ind = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    if (ind >= n)
        ind--;

    if (ind != -1){
        cout << (ind+1) << " " << pre_sum[ind] << endl;
    }else
        cout << 0 << " " << 0 << endl;
}

int main(){

    freopen("0input.txt", "r", stdin);

    int n, q;
    cin >> n;

    vector <int> arr(n);
    vector <int> pre_sum(n, 0);
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }


    cin>>q;
    sort(arr.begin(), arr.end());
    int sum_ = 0;
    for (int i=0;i<n;i++){
        pre_sum[i] = sum_ + arr[i];
        sum_ += arr[i];
    }

    while(q){
        int power;
        cin>>power;
        bishuAndSoldiers(arr, pre_sum, power);
        --q;
    }

    return 0;
}