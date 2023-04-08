#include <bits/stdc++.h>
using namespace std;

struct Job{
    int start;
    int end;
    int profit;
};

int f(int i, int j, vector <Job> jobs, int n){
    ///base case
    if (i == n)
        return 0; 
    int included = 0;
    int excluded = 0;
    if (j == -1 || jobs[i].start >= jobs[j].end){
        included = f(i+1, i, jobs, n) + jobs[i].profit;
    }
    excluded = f(i+1, j, jobs, n);
    return max(included, excluded);
}


bool mycompare(Job i, Job j){
    if (i.start < j.start)
        return true;
    else
        return i.end <= j.end;

}

int dpSol(vector <Job> jobs, int n){

    int dp[n+1][n+2];
    sort(jobs.begin(), jobs.end(), mycompare);
    for(auto x:jobs){
        cout << x.start << " " << x.end <<  " " << x.profit << endl;
    }
    //base case
    for (int i = 0;i<=n;i++)
        dp[n][i] = 0;
    
    for (int i=n-1;i>=0;i--){
        for (int j=i-1;j>=-1;j--){
            int included = 0;
            int excluded = 0;
            if (j == -1 || jobs[i].start >= jobs[j].end){
                included = dp[i+1][i+1] + jobs[i].profit;
            }
            excluded = dp[i+1][j+1];
            dp[i][j+1] = max(included, excluded);
        }
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n+1;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[0][0];


}

int main(){

    vector <Job> myjobs;

    myjobs.push_back({1,2,50});
    myjobs.push_back({3,5,20});
    myjobs.push_back({6,19,100});
    myjobs.push_back({2,100,200});

    cout << f(0,-1, myjobs, myjobs.size()) <<endl;
    

    cout << dpSol(myjobs, myjobs.size()) << endl;

    return 0;
}