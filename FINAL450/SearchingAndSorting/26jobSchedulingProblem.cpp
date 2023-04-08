#include <bits/stdc++.h>
using namespace std;

struct Job { 
    int start;	 // Job Id 
    int end; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool noOverlap(int i, int j, Job arr[]){
    if (i == -1)
        return true;
    if (arr[i].end > arr[j].start)
        return false;
    return true;
}

int f(int i, int j, int n, Job arr[], int cur_profit){
    // i = previous 
    // j = current 
    if (j == n)
        return cur_profit;

    int profit_without_cur;
    int profit_including_cur;

    if (noOverlap(i, j, arr)){

        profit_including_cur = f(j, j+1, n, arr, cur_profit + arr[j].profit);
        profit_without_cur = f(i, j+1, n, arr, cur_profit);

        return max(profit_including_cur, profit_without_cur);
    }else{
        profit_without_cur = f(i, j+1, n, arr, cur_profit);

        return profit_without_cur;
    }



}

struct mycompare{
    bool operator()(const Job &a, const Job &b){
        if (a.start < b.start)
            return true;
        else if (a.start > b.start)
            return false;
        else {
            return a.end <= b.end;
        }
    }
};

vector<int> JobScheduling(Job arr[], int n) { 
    // your code here
    sort (arr, arr+n, mycompare());


    // for (int i=0;i<4;i++){
    //     cout << arr[i].start << endl;
    //     cout << arr[i].end << endl;
    //     cout << arr[i].profit << endl;
    //     cout << "--" << endl;
    // }
    // cout <<  "score:" <<f(-1, 0, n, arr, 0);
    return {};

}
// -1, 0, 1, 2 (n = 3)
// 0 , 1, 2, 3 (n = 3+1)

int jobSchedulingIter(Job arr[], int n){

    vector <vector <int>> dp(n+2, vector <int> (n+2, 0));
    sort(arr, arr+n, mycompare());

    // for (int i=0;i<4;i++){
    //     cout << arr[i].start << endl;
    //     cout << arr[i].end << endl;
    //     cout << arr[i].profit << endl;
    //     cout << "--" << endl;
    // }

    for (int i=n;i>=0;i--){

        for (int j = n; j>i;j--){

            int profit_without_cur;
            int profit_including_cur;

            if (noOverlap(i-1, j-1, arr)){
                profit_including_cur = dp[j][j+1] + arr[j-1].profit;
                profit_without_cur = dp[i][j+1];

                dp[i][j] = max(profit_including_cur, profit_without_cur);
            }else{
                profit_without_cur = dp[i][j+1];
                dp[i][j] = profit_without_cur;
            }
        }
    }

    return dp[0][1];

}

int findNextJob(Job arr[], int n, int cur_job){
    for (int i=cur_job +1;i<n;i++){
        if ( noOverlap(cur_job, i, arr))
            return i;
    }
    return -1;
}

//jobscheudlgin in O(n) space

int f2(Job arr[], int n, int i){
    if (i == n-1)
        return arr[i].profit;
    
    int including = arr[i].profit;
    int next_non_conflicting = findNextJob(arr, n, i);

    if (next_non_conflicting != -1)
        including += f2(arr, n, next_non_conflicting);
    
    int exlcuding = f2(arr, n, i+1);

    return max(including, exlcuding);

}

int f2Iter(Job arr[], int n){
    vector <int> dp(n, 0);
    //base case
    dp[n-1] = arr[n-1].profit;

    for (int i=n-2;i>=0;i--){
        int including = arr[i].profit;

        int next_non_conflicting = findNextJob(arr, n, i);
        if (next_non_conflicting != -1)
            including += dp[next_non_conflicting];

        int excluding = dp[i+1];

        dp[i] = max(excluding, including);
    }

    return dp[0];

}

void JobScheulding2(Job arr[], int n){

    sort(arr, arr+n, mycompare()); //going to sort by start time

    cout << f2(arr, n, 0) << endl;
    cout << f2Iter(arr, n) << endl;
}


//above solutiong are using dp, and the time complexity in those cases is O(n2)
//but we can optimise it even further by usning binary search
//in the method findNextJob(), instead of using linear search we can apply binary
//search to find the non conflicting job

int findNextJobBinarySearch(Job arr[], int n, int i){

    int low = i+1;
    int high = n-1;

    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if (arr[mid].start >= arr[i].end){ //no overlap
            ans = mid;
            high = mid-1; //try for even lower
        }else if (arr[mid].start < arr[i].end){
            low = mid+1;
        }
    }
    return ans;

}

int jobSchedulingBinarySearch(Job arr[], int n){

    vector <int> dp(n, 0);
    dp[n-1] = arr[n-1].profit;

    for (int i =n-2;i>=0;i--){
        int including = arr[i].profit;

        int next_non_conflicting = findNextJobBinarySearch(arr, n, i);

        if (next_non_conflicting != -1){
            including += dp[next_non_conflicting];
        }

        int excluding = dp[i+1];

        dp[i] = max(including, excluding);
    }

    return dp[0];

}


int main(){

    Job arr[] = {{5,6,50}, 
                 {6, 8, 50},
                {6, 10, 40}};
    // for (int i=0;i<4;i++){
    //     cout << arr[i].start << endl;
    //     cout << arr[i].end << endl;
    //     cout << arr[i].profit << endl;
    //     cout << "--" << endl;
    // }
    JobScheduling(arr, 3);

    cout << jobSchedulingIter(arr, 3) << endl;
    JobScheulding2(arr, 3);
    cout << jobSchedulingBinarySearch(arr, 3) << endl;
    return 0;
}