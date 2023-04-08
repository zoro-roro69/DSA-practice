#include <bits/stdc++.h>
using namespace std;

// The idea is to use three nested loops to consider every triplet (i, j, k) and check
// for the above condition (there is an edge from i to j, j to k and k to i) 
// However in an undirected graph, the triplet (i, j, k) can be permuted to give six combination

// Hence we divide the total count by 6 to get the actual number of triangles. 
// In case of directed graph, the number of permutation would be 3

// Hence in this case the total number of triangles will be obtained by dividing total count by 3. 
// For example consider the directed graph given below 

int countTriangles(int n, vector <vector <int>> &adj, bool is_directed){
    // n = number of vertices
    // adj = adjaceny matrix
    int count = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n && j!=i;j++){
            for (int k=0;k<n && k!=j && k!=i;k++){
                if (adj[i][j] && adj[j][k] && adj[k][i]) {
                    count++;
                }
            }
        }
    }

    if (is_directed)
        return count/3;
    else
        return count/6;

}

int main(){


    return 0;
}