#include <bits/stdc++.h>
using namespace std;


int largestSubMatrixWithEqual01(vector <vector <int>> &v){

    int n = v.size();
    int m = v[0].size();

    vector <int> sum_matrix(m, 0);

    int max_area = 0;
    for (int i=0;i<n;i++){

        for (int j=i;j<n;j++){
            for (int k=0;k<m;k++){
                if (v[j][k])
                    sum_matrix[k] += 1; // if 1, +1
                else    
                    sum_matrix[k] += -1; // if 0, -1
            }

            unordered_map <int ,int> mp;
            mp[0] = -1;
            int sum_ = 0;
            for (int k=0;k<m;k++){

                sum_ += sum_matrix[k];

                if (mp.find(sum_) != mp.end()){
                    int width = k - mp[sum_];
                    int ht = j-i+1;
                    if (width*ht > max_area){
                        max_area = width*ht;
                    }
                }else{
                    mp[sum_] = k;
                }
            }
        }

        for (int k=0;k<m;k++)
            sum_matrix[k] = 0;
    }

    return max_area;

}

int main (){
    // vector <vector <int>> v{ {0, 0, 1, 1},
    //                 {0, 1, 1, 0},
    //                 {1, 1, 1, 0},
    //                 {1, 0, 0, 1} };

    vector <vector <int>> v{{0, 0, 1, 1},
                            {0, 1, 1, 1}} ;

    cout << largestSubMatrixWithEqual01(v) << endl;
    return 0;
}