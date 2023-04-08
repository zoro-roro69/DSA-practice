#include <bits/stdc++.h>
using namespace std;


// Given the mobile numeric keypad. You can only press buttons that are up, left, right, or down to
//  the current button or the current button itself (like 00,11, etc.). You are not allowed to press 
// the bottom row corner buttons (i.e. * and # ). Given a number N, the task is to find out the number
//  of possible numbers of the given length.

long long dpSol(int n){

    vector <vector<int>> neighbors(0, vector <int>());
    neighbors.push_back({0,8}); //0
    neighbors.push_back({1,2,4}); //1
    neighbors.push_back({2,1,3,5}); //2
    neighbors.push_back({3,6,2}); //3
    neighbors.push_back({4,1,5,7}); //4
    neighbors.push_back({5,2,4,6,8}); //5
    neighbors.push_back({6,3,5,9}); //6
    neighbors.push_back({7,4,8}); //7
    neighbors.push_back({8,5,7,9,0}); //8
    neighbors.push_back({9,6,8}); //9

    
    long long int dp[10]; 
    long long int temp[10];
    
    for (int i=0;i<10;i++)
        dp[i] = 1;

    for (int i=2;i<=n;i++){
        
        for (int j=0;j<10;j++){
            temp[j] = 0;
            for (auto x:neighbors[j]){
                temp[j] += dp[x];
            }

        }
        for (int j=0;j<10;j++){
            dp[j] = temp[j];
        }
    }

    long long res = 0;

    for (int j=0;j<10;j++)
        res += dp[j];

    return res;
}   

int main(){

    return 0;
}