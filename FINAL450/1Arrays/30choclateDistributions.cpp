#include <bits/stdc++.h>
using namespace std;


int chocholateDistribution(vector <int> v, int m){
    int n = v.size();
    sort(v.begin(), v.end());

    int res = v[m-1] - v[0];
    for (int i=1 ; i<=n-m ; i++){
        if (v[i+m-1] - v[i] < res){
            res = v[i+m-1] - v[i];
        }
    }
    return res;
}

int main(){

    vector <int> v{12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    cout << "res: " << chocholateDistribution(v, 7) << endl;

    return 0;

}