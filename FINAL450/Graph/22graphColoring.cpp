#include <bits/stdc++.h>
using namespace std;

//this workds but get TLE :(
// bool dfs(int i, int n, int colors, vector <int> &visited, bool graph[][101]){

//     //try to color with all candidates one by one
//     int cur_color = 0;

//     bool flag = false;
//     for (int j=1;j<=colors && flag == false;j++){
//         cur_color = j; //try jth color
//         for (int k=0;k<n;k++){
//             if (graph[i][k] && visited[k] == j){ //a negihbor is painted with this color 
//                 cur_color = 0; //we cannot color this with k
//                 break;
//             }
//         }
//         if (cur_color == 0) //we cannot color it with jth color so try next
//             continue;
//         else{
//             visited[i] = cur_color;
//             flag = true;

//             for (int k=0;k<n;k++){
//                 if (graph[i][k] && visited[k] == 0){
//                     if (dfs(k, n, colors, visited, graph)){
//                         flag = true;
//                     }else{
//                         flag = false;
//                         break; //try with different color
//                     }
//                 }
//             }
//         }
        
//     }

//     visited[i] = 0;

//     return flag;

// }

bool dfs(int i, int n, int colors, vector <int> &visited, bool graph[][101]){
    if (i == n)
        return true;

    int cur_color = 0;
    for (int cr = 1; cr<=colors; cr++){
        cur_color = cr;
        for (int j=0;j<n;j++){
            if (graph[i][j] && visited[j] == cr){ //neighbor already colored with cr
                cur_color = 0;
                break;
            }
        }
        if (cur_color == 0) //not able to color with cr so try next color
            continue;
        else{
            visited[i] = cur_color;

            if (dfs(i+1, n, colors, visited, graph)){
                return true;
            }

            visited[i] = 0;

        }
    }

    return false;

}

bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here

    vector <int> visited(n, 0); //0 - not visited, any other number means colored with that color

    return dfs(0, n, m, visited, graph);
    // for (int i=0;i<n;i++){
    //     if (visited[i] == 0){
    //         if (dfs(i, n, m, visited, graph) == false){
    //             return false;
    //         }
    //     }
    // }
    // return true;


}


int main(){

    return 0;
}