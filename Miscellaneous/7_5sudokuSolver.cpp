#include <bits/stdc++.h>
using namespace std;

const int N = 9;


    
bool solve(int i, int grid[N][N], vector <vector<bool>> &row,
        vector <vector<bool>> &col, vector <vector <bool>> &box){
    if (i>=81)
        return true;
    int row_num = i/9;
    int col_num = i%9;

    int box_num = 3*(row_num/3) + col_num/3; 

    for (int x = 1;x<=9;x++){
        if (grid[row_num][col_num]) //cell already has a number
            return solve(i+1, grid, row, col, box);
        
        //place x in (row_num, col_num)
        if (!row[row_num][x] && !col[col_num][x] && !box[box_num][x]){
            grid[row_num][col_num] = x;
            row[row_num][x] = true;
            col[col_num][x] = true;
            box[box_num][x] = true;

            if (solve(i+1, grid, row, col, box))
                return true;

            //backtrack
            grid[row_num][col_num] = 0;
            row[row_num][x] = false;
            col[col_num][x] = false;
            box[box_num][x] = false;
        }

    }

    return false;


}

//Function to find a solved Sudoku. 
bool SolveSudoku(int grid[N][N])  {
    // Your code here

    vector <vector<bool>> row_map(10, vector <bool> (10, false));
    vector <vector <bool>> col_map(10, vector <bool> (10, false));
    vector <vector<bool>> box_map(10, vector <bool> (10, false));

    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            if (grid[i][j]){
                row_map[i][grid[i][j]] = true;
                col_map[j][grid[i][j]] = true;

                int box_num = (i/3)*3 + j/3;

                box_map[box_num][grid[i][j]] = true;
            }
        }
    }

    return solve(0, grid, row_map, col_map, box_map);

}

//Function to print grids of the Sudoku.
void printGrid (int grid[N][N]) {
    // Your code here 

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

int main(){

    return 0;
}