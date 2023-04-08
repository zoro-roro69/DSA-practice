#include <bits/stdc++.h>
using namespace std;


unordered_set <int> row;
unordered_set <int> col;
unordered_set <int> diag1;
unordered_set <int> diag2;

bool noConflict(int r, int c){
    if (row.find(r) != row.end())
        return false;
    if (col.find(c) != col.end())
        return false;
    if (diag1.find(c-r) != diag1.end())
        return false;
    if (diag2.find(c+r) != diag2.end())
        return false;

    return true;
}

void helper(int i, int n, vector <int> &config, vector <vector <int>> &res){
    if (i >= n){
        // cout << "config :: " << config.size() << endl;
        res.push_back(config);
        return;
    }

    for (int j=0;j<n;j++){
        if (noConflict(i, j)){

            config.push_back(j);

            row.insert(i);
            col.insert(j);
            diag1.insert(j-i);
            diag2.insert(j+i);

            helper(i+1, n, config, res);

            //backtrack
            config.pop_back();
            row.erase(i);
            col.erase(j);
            diag1.erase(j-i);
            diag2.erase(j+i);
        }
    }



}

vector<vector<int>> solveNQueens(int n) {

    vector <int> config;
    vector <vector <int>> res;

    row.clear();
    col.clear();
    diag1.clear();
    diag2.clear();

    helper(0, n, config, res);

    return res;

}


int main(){
    vector <vector <int>> res;
    res = solveNQueens(4);
    cout << res.size() << endl;

    for (int i=0;i<res.size();i++){
        for (int j=0;j<res[0].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}