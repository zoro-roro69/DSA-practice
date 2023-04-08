#include <bits/stdc++.h>
using namespace std;


int f(int i, int k, vector <int> &arr){
    //base case pending
    if (i>=arr.size())
        return 0;

    int len = 0;
    int res = INT_MAX;
    for (int j=i;j<arr.size();j++){
        len += arr[j] + (j!=i);
        if (len <= k){
            int c = k - len;
            if (j == arr.size()-1)
                c = 0;
            res = min(res, c*c + f(j+1, k, arr));
        }else{
            break;
        }
    }

    return res;
}


int dpSol(vector <int> &arr, int k){

    int n = arr.size();

    int cost[n+1];
    cost[n] = 0;

    for (int i=n-1;i>=0;i--){
        int len = 0;
        cost[i] = INT_MAX;
        for (int j=i;j<n;j++){
            len += arr[j] + (j!=i);
            if (len <= k){
                int c = k-len;
                if (j == n-1)
                    c = 0;
                cost[i]=  min(cost[i], c*c + cost[j+1]);
            }else
                break;
        }
    }

    return cost[0]; 

}

int main(){
    vector <int> arr{3,2,2};
    cout << f(0, 4, arr) << endl;
    cout << dpSol(arr, 4) << endl;
    return 0;
}