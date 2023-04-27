#include <bits/stdc++.h>
using namespace std;
//Function to return a list of integers denoting spiral traversal of matrix.
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
    // code here 
    int left = 0;
    int top = 0;
    int right = c-1;
    int bottom = r-1;
    // cout << r << c << endl;

    vector <int> res;

    while(left <= right && top <= bottom){
        for (int i=left;i<=right;i++){
            // cout << matrix[top][i] << " ";
            res.push_back(matrix[top][i]);
        }
        top++;

        for (int i=top;i<=bottom;i++){
            // cout << matrix[i][right] << " ";
            res.push_back(matrix[i][right]);
        }
        right--;

        if (bottom >= top){
            for (int i = right;i>=left;i--){
                // cout << matrix[bottom][i] << " ";
                res.push_back(matrix[bottom][i]);
            }
        }

        bottom--;
        if (right >= left){
            for (int i = bottom; i>=top;i--){
                // cout << matrix[i][left] << " ";
                res.push_back(matrix[i][left]);
            }
        }
        left++;
    }

    return res;
    }
int main(){
vector <vector <int>> matrix{
                            {1,2,3}, 
                            {4,5,6}};

    int r = matrix.size();
    int c = matrix[0].size();
    spirallyTraverse(matrix, r, c);
    return 0;
}