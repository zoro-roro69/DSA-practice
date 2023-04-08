#include <bits/stdc++.h>
using namespace std;


//O(n3) solution finds a single quaruplet
vector <int> foureSome(int arr[], int n, int sum){

    sort(arr, arr + n);

    vector <int> res;

    for (int i=0;i<n;i++){

        for (int j=i+1;j<n;j++){
            int rem = sum - arr[i] - arr[j];

            int s = j+1; int e = n-1;
            while(s < e){
                int temp = arr[s] + arr[e];
                if (temp == rem){
                    //found
                    res = {arr[i], arr[j], arr[s], arr[e]};
                    return res;
                }
                else if (temp > rem){
                    e--;
                }else
                    s++;
            }
        }
    }

    return {};

}

// GFG question we need to find all unique quadruplets
// O(n3)
vector<vector<int> > fourSum(vector<int> &arr, int sum) {
    // Your code goes here
        
    sort(arr.begin(), arr.end());
    
    //find all quadruplets
    vector <vector <int>> res;
    
    int n = arr.size();
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                
                int rem = sum - arr[i] - arr[j];

                int s = j+1; int e = n-1;
                while(s < e){
                    int x = arr[s];
                    int y = arr[e];
                    int temp = x + y;
                    
                    if (temp == rem){
                        //found
                        //cout << "found" << endl;
                        
                        res.push_back({arr[i], arr[j], arr[s], arr[e]});
                        
                        while (s < e && arr[s] == x){ //to prevent duplicates
                            s++;
                        }   
                        
                        while(s < e && arr[e] == y){//to prevent duplicates
                            e--;
                        }
                        
                    }
                    else if (temp > rem){
                        e--;
                    }else
                        s++;
                }
                
                while(j+1 < n && arr[j] == arr[j+1]){ //to prevent duplicates
                    j++;
                }
            }
            
            while(i+1 < n && arr[i] == arr[i+1]){ //to prevent duplicates
                i++;
            }
        }
    return res;
}

int main(){

    return 0;
}