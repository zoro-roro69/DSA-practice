#include <bits/stdc++.h>
using namespace std;

int maxIndex(vector <int> &v){
    int max_ind = 0;
    int val = v[0];
    for (int i=1;i<v.size();i++){

        if (v[i] > val){
            val = v[i];
            max_ind = i;
        }
    }

    return max_ind;
}

int minIndex(vector <int> &v){

    int min_ind = 0;
    int val = v[0];
    for (int i=1;i<v.size();i++){

        if (v[i] < val){
            val = v[i];
            min_ind = i;
        }
    }

    return min_ind;
}


vector <vector <int>> minimizeCashFlow(int n, vector <vector <int>> &adj){

    vector <vector <int>> res(n, vector <int> (n, 0));
    vector <int> net_amount(n, 0); //net_mount[i] = received - given

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            net_amount[i] += adj[j][i] - adj[i][j];
        }
    }

    while(1){
        int max_creditor = maxIndex(net_amount);
        int max_debitor = minIndex(net_amount);

        if (net_amount[max_creditor] == 0 && net_amount[max_debitor] == 0){
            break;
        }

        int min_ = min(-net_amount[max_debitor], net_amount[max_creditor]);

        net_amount[max_creditor] -= min_;
        net_amount[max_debitor] += min_;

        res[max_debitor][max_creditor] = min_; //adding new edge

    }

    return res;

}


int main(){

    return 0;
}