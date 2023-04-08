#include <bits/stdc++.h>
using namespace std;



bool row[10][10];
bool col[10][10];
bool box[10][10];


int getBoxNum(int i, int j){
    return i/3*3 + j/3; //or i + j/3
}

bool isPossible(int r, int c, int val){
    if (row[r][val])
        return false;
    if (col[c][val])
        return false;
    int box_num = getBoxNum(r,c);
    if (box[box_num][val])
        return false;

    return true;
}


bool solve(int num, int matrix[][9]){

    if (num>=81)
        return true;

    int r = num/9;
    int c = num%9;

    if (matrix[r][c] != 0)
        return solve(num+1, matrix);
    
    for (int val = 1; val <= 9 ; val++){
        if (isPossible(r,c, val)){

            matrix[r][c] = val;
            row[r][val] = true;
            col[c][val] = true;
            box[getBoxNum(r, c)][val] = true;

            if (solve(num+1, matrix))
                return true;
            
            //backtrack
            row[r][val] = false;
            col[c][val] = false;
            box[getBoxNum(r, c)][val] = false;
        }
    }

    return false;

}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.

    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            row[i][j] = false;
            col[i][j] = false;
            box[i][j] = false;
        }
    }

    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            if (matrix[i][j] != 0){
                int val = matrix[i][j];
                row[i][val] = true;
                col[j][val] = true;
                int box_num = getBoxNum(i, j);
                box[box_num][val] = true;
            }
        }
    }

    return solve(0, matrix);

}

int main(){

    int matrix[9][9] = {{1,5,9,0,0,6,0,3,2},
                        {2,7,4,0,0,0,0,0,0},
                        {3,8,6,2,0,0,0,0,5},
                        {4,9,2,5,0,1,0,8,0},
                        {6,3,7,0,4,0,0,0,0},
                        {5,1,0,8,2,0,0,0,0},
                        {8,2,1,0,0,0,0,0,0},
                        {7,6,0,1,0,0,4,2,0},
                        {9,4,3,0,7,0,0,6,1}};

    cout << isItSudoku(matrix) << endl;
    return 0;;
};

