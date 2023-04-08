#include <bits/stdc++.h>
using namespace std;

// floyd - warsahll algorithm
// for finding shortest path between each pair of vertices
// in this algo what we do is we try to take each vertex as an "intermediate" vertex
// between every other pair of vertices
// lets say we have vertex i and j. we try to reach j from i via intermediate vertex k if we have better path
// than the current path
// [i][j]  = min([i][j], [i][k] + [k][j])
// with each iteration we update our adjacency/distance matrix

//example

// +---------+   4     +---------+  2   +-----------+
// |   1     |         |    2    |      |    3      |
// |         +-------> |         +----> |           |
// +---------+         +---------+      +-----------+

// so in the above example we first try to take 1 as intermediate node 
// since we can see that 1 doesnt come in between any other node
// so adjaceny matrix remains same

// next we try to take 2 as intermediadte node
// we can see that currently to reach from 1 to 3 is not possible
// but if we take 2 as intermediate node we can reach 3 [1 to 2] then [2 to 3]
// now we update our adjaceny matrix,
// updation to adjaceny matrix is like updating previous edge with minimum wt
// or adding a new edge if the path didnt exist before
// in this case we add a new edge from 1 to 3 with wt 6(4 + 2)

// +---------+   4     +---------+  2   +-----------+
// |   1     |         |    2    |      |    3      |
// |         +-------> |         +----> |           |
// +---------+         +---------+      +-----+-----+
//      X                                     ^
//      X                                     |
//      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX+
//                       6

//next we try to take 3 as intermediate node
// since 3 doesnt come in between any nodes so distance matrix remains same
// and we have our answer in the distance matrix
//distance matrix[i][j] contains shortest distance between i and j




void shortest_distance(vector<vector<int>>&matrix){

    int n = matrix.size();
    for (int k=0;k<n;k++){
        //trying k as intermediate node between i and j
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (i != k && k != j && i != j){
                    int dist1 = matrix[i][k];
                    int dist2 = matrix[k][j];

                    if (dist1!= -1 && dist2!=-1){
                        if (matrix[i][j] == -1 || dist1 + dist2 < matrix[i][j]){
                            matrix[i][j] = dist1 + dist2;
                        }
                    }
                }
            }
        }
    }

}

int main(){

    return 0;
}