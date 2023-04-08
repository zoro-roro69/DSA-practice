#include <bits/stdc++.h>
using namespace std;

pair <int, int> f(int i, int j, string &s){
    if (i == j){
        if (s[i] == 'T')
            return {1, 0};
        else if (s[i] == 'F')
            return {0, 1};
    }

    int num_true = 0;
    int num_false = 0;

    for (int k=i;k<=j;k++){
        if (s[k] == '|'){
            pair <int,int> res_left = f(i, k-1, s); 
            pair <int,int> res_right = f(k+1, j, s); 
            num_true += res_left.first * res_right.first; //T T
            num_true += res_left.first * res_right.second; // T F
            num_true += res_left.second * res_right.first; // F T

            num_false += res_left.second * res_right.second; // F F
        }
        else if (s[k] == '&'){
            pair <int, int > res_left = f(i, k-1, s);
            pair <int, int > res_right = f(k+1, j, s);

            num_true += res_left.first * res_right.first;// T T

            num_false += res_left.first * res_right.second;// T F
            num_false += res_left.second * res_right.first;// F T
            num_false += res_left.second * res_right.second;// F F
        }
        else if (s[k] == '^'){
            pair <int, int > res_left = f(i, k-1, s);
            pair <int, int > res_right = f(k+1, j, s);

            num_true += res_left.first * res_right.second; //T F
            num_true += res_left.second * res_right.first; //F T
            
            num_false += res_left.first * res_right.first; //F F
            num_false += res_left.second * res_right.second; //T T
        }
    }

    return {num_true, num_false};
}

int dpSol(int n, string s){

    pair<int,int> dp[n][n];

    for (int i=0;i<n;i++){
        if (s[i] == 'T'){
            dp[i][i] = {1, 0};
        }
        else if (s[i] == 'F')
            dp[i][i] = {0, 1};
    }

    for (int i = n-1;i>=0;i--){
        for (int j=i+1;j<n;j++){
 
            int num_false = 0;
            int num_true = 0;

            for (int k=i+1;k<=j-1;k++){
                if (s[k] == '|'){
                    pair <int,int> res_left = dp[i][k-1]; 
                    pair <int,int> res_right = dp[k+1][j]; 
                    num_true += res_left.first * res_right.first; //T T
                    num_true += res_left.first * res_right.second; // T F
                    num_true += res_left.second * res_right.first; // F T
                    num_false += res_left.second * res_right.second; // F F
                }
                else if (s[k] == '&'){

                    pair <int,int> res_left = dp[i][k-1]; 
                    pair <int,int> res_right = dp[k+1][j]; 

                    num_true += res_left.first * res_right.first;// T T

                    num_false += res_left.first * res_right.second;// T F
                    num_false += res_left.second * res_right.first;// F T
                    num_false += res_left.second * res_right.second;// F F

                }
                else if (s[k] == '^'){
                    pair <int,int> res_left = dp[i][k-1]; 
                    pair <int,int> res_right = dp[k+1][j]; 

                    num_true += res_left.first * res_right.second; //T F
                    num_true += res_left.second * res_right.first; //F T
                    
                    num_false += res_left.first * res_right.first; //F F
                    num_false += res_left.second * res_right.second; //T T

                }
            }

            dp[i][j] = {num_true, num_false};
        }
    }

    return dp[0][n-1].first;
}


//MOD the result :)

const int MOD = 1003;

int dpSol(int n, string s){

    pair<int,int> dp[n][n];

    for (int i=0;i<n;i++){
        if (s[i] == 'T'){
            dp[i][i] = {1, 0};
        }
        else if (s[i] == 'F')
            dp[i][i] = {0, 1};
    }

    for (int i = n-1;i>=0;i--){
        for (int j=i+1;j<n;j++){
 
            int num_false = 0;
            int num_true = 0;
            
            

            for (int k=i+1;k<=j-1;k++){
                if (s[k] == '|'){
                    pair <int,int> res_left = dp[i][k-1]; 
                    pair <int,int> res_right = dp[k+1][j]; 
                    num_true += (res_left.first * res_right.first)%MOD; //T T
                    num_true %=MOD;
                    num_true += (res_left.first * res_right.second)%MOD; // T F
                    num_true %=MOD;
                    num_true += (res_left.second * res_right.first)%MOD; // F T
                    num_true %=MOD;
                    
                    num_false += (res_left.second * res_right.second)%MOD; // F F
                }
                else if (s[k] == '&'){

                    pair <int,int> res_left = dp[i][k-1]; 
                    pair <int,int> res_right = dp[k+1][j]; 

                    num_true += (res_left.first * res_right.first)%MOD;// T T
                    num_true %=MOD;

                    num_false += (res_left.first * res_right.second)%MOD;// T F
                    
                    num_false += (res_left.second * res_right.first)%MOD;// F T
                    num_false += (res_left.second * res_right.second)%MOD;// F F

                }
                else if (s[k] == '^'){
                    pair <int,int> res_left = dp[i][k-1]; 
                    pair <int,int> res_right = dp[k+1][j]; 

                    num_true += (res_left.first * res_right.second)%MOD; //T F
                    num_true %=MOD;
                    num_true += (res_left.second * res_right.first)%MOD; //F T
                    num_true %=MOD;
                    
                    num_false += (res_left.first * res_right.first)%MOD; //F F
                    num_false %= MOD;
                    num_false += (res_left.second * res_right.second)%MOD; //T T
                    num_false %= MOD;

                }
            }

            dp[i][j] = {num_true, num_false};
        }
    }

    return dp[0][n-1].first % 1003;
}


int main(){

    string s = "T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F";
    pair <int, int> res = f(0, s.size()-1, s);
    cout << res.first << endl;

    cout << dpSol(s.size(), s) << endl;
    
    return 0;
}