#include <bits/stdc++.h>
using namespace std;


//this code works in coding ninjas, but doesnt work on geeks for geeks :/
//if you want to pass in gfg then if max_area is equal of two matrix than out of them
// we need to select the one with bigger width
vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
    //Code Here
        
      int n = a.size();
      int m = a[0].size();
  
      vector <int> sum_matrix(m, 0);
  
      int max_area = 0;
      int tx, ty;
      int bx, by;
      for (int i=0;i<n;i++){
          for (int j=i;j<n;j++){
              for (int k=0;k<m;k++){
                  sum_matrix[k] += a[j][k];
              }
  
              unordered_map<int, int> mp;
              mp[0] = -1;
              int sum_ = 0;
              for (int k=0;k<m;k++){
                  
                  sum_ += sum_matrix[k];
                  
                  if (mp.find(sum_) != mp.end()){
                      //0 sum found
                      int width = k - mp[sum_];
                      int ht = j-i+1;
                      if (width*ht > max_area){
                          max_area = width*ht;

                          cout << max_area << endl;

                          tx = i; ty = mp[sum_] + 1;
                          bx = j; by = k;
                      }
                  }else{
                      mp[sum_] = k;
                  }
              }
  
          }
  
          for (int k=0;k<m;k++){
              sum_matrix[k] = 0;
          }
      }
  
      vector <vector <int>> res;
      
      cout << tx << " " << ty << " " << bx << " " << by << endl;
  
      vector <int> temp;
      for (int i=tx;i<=bx;i++){
          temp.clear();
          for (int j=ty;j<=by;j++){
              temp.push_back(a[i][j]);
          }
          res.push_back(temp);
      }

      for (int i=0;i<res.size();i++){
          for (int j=0;j<res[0].size();j++){
              cout << res[i][j] << " ";
          }
          cout << endl;
      }

      return res;
}

int main(){
// 17 -7 -18 43 7 -23 -10 -5 -22
// -24 24 26 38 -49 2 38 -22 25
// 40 5 48 -38 49 50 -28 27 49
// 22 -24 16 -32 -1 39 47 -33 42
// -40 -50 48 -45 43 -5 6 36 -5
// -14 -3 18 9 -28 -43 45 9 11
// -26 47 22 -11 -16 10 -9 12 -22
// 44 28 -14 -38 17 -28 26 -49 41
    vector <vector <int>> arr{
{17, -7, -18, 43, 7 ,-23, -10, -5, -22},
{-24, 24, 26, 38, -49, 2 ,38, -22, 25,},
{40 ,5 ,48, -38, 49, 50, -28, 27, 49},
{22 ,-24, 16 ,-32 ,-1 ,39, 47 ,-33, 42},
{-40, -50, 48 ,-45, 43 ,-5, 6, 36 ,-5},
{-14, -3 ,18 ,9, -28, -43, 45, 9,11},
{-26, 47 ,22 ,-11 ,-16 ,10, -9 ,12, -22},
{44, 28, -14 ,-38, 17 ,-28, 26, -49, 41}
};

    vector <vector <int>> res = sumZeroMatrix(arr);

    return 0;
}