#include <bits/stdc++.h>
using namespace std;

int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
    // code here

    int max_  = INT_MIN;

    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            max_ = max(max_, M[i][j]);
        }
    }
    if (max_ < 0)
        return max_;

    vector <int> sum_matrix(C, 0);

    int res = INT_MIN;

    for (int i=0;i<R;i++){
        for (int j = i; j<R ; j++){
            for (int k = 0 ; k< C ; k++){
                sum_matrix[k] += M[j][k];
            }

            //find max sum largest sub array
            int max_till_now = INT_MIN;
            int cur_sum = 0;
            for (int k=0;k<C;k++){
                cur_sum += sum_matrix[k];
                max_till_now = max(cur_sum, max_till_now);
                cur_sum = max(0, cur_sum);
            }

            res = max(res, max_till_now);
        }

        for (int j=0;j<C;j++){
            sum_matrix[j] = 0;
        }
    }


    return res;
}

int main(){

    return 0;
}