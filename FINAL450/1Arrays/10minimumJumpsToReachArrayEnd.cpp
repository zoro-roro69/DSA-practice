#include <bits/stdc++.h>
using namespace std;


void printVector(vector <int> v){
    for (auto x:v){
        cout << x << " ";
    }
    cout<<endl;
}
int minimumJumpsToend(vector <int> v){

    if (v.size() == 0 || v.size() == 1)
        return 0;

    vector <int> temp(v.size(), 0);

    for (int i=v.size()-2;i>=0;i--){
        if (v[i] + i >= v.size()-1){
            temp[i] = 1;
        }else{
            if (v[i] == 0) {//not reachable
                temp[i] = 0;
                continue;    
            }else{
                int min_ = INT_MAX;
                for (int j=1;j<=v[i];j++){
                    if (temp[i+j] != 0){
                        min_ = min(min_, temp[i+j]);
                    }
                }
                if (min_ == INT_MAX){//not reachable
                    temp[i] = 0;
                }else{
                    temp[i] = min_ + 1;
                }
            }
        }
    }

    printVector(temp);

    return temp[0];
}

// Returns minimum number of jumps
// to reach arr[n-1] from arr[0]
int minJumps(int arr[], int n)
{
 
    // The number of jumps needed to
    // reach the starting index is 0
    if (n <= 1)
        return 0;
 
    // Return -1 if not possible to jump
    if (arr[0] == 0)
        return -1;
 
    // initialization
    // stores all time the maximal
    // reachable index in the array.
    int maxReach = arr[0];
 
    // stores the number of steps
    // we can still take
    int step = arr[0];
 
    // stores the number of jumps
    // necessary to reach that maximal
    // reachable position.
    int jump = 1;
 
    // Start traversing array
    int i = 1;
    for (i = 1; i < n; i++) {
        // Check if we have reached the end of the array
        if (i == n - 1)
            return jump;
 
        // updating maxReach
        maxReach = max(maxReach, i + arr[i]);
 
        // we use a step to get to the current index
        step--;
 
        // If no further steps left
        if (step == 0) {
            // we must have used a jump
            jump++;
 
            // Check if the current index/position or lesser index
            // is the maximum reach point from the previous indexes
            if (i >= maxReach) //(i == maxReach also works fine)
                return -1;
 
            // re-initialize the steps to the amount
            // of steps to reach maxReach from position i.
            step = maxReach - i;
        }
    }
 
    return -1;
}

int main(){

    vector <int> v{1,1,1,1,1,1,1,1,1,1,1};

    cout << minimumJumpsToend(v) << endl;

    return 0;
}