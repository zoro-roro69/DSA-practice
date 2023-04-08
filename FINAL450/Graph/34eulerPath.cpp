#include <bits/stdc++.h>
using namespace std;

// Euler path is a path that uses every edge exactly once 
// Euler circuit is a euler path that starts and ends ar same vertex/node

//              +----+          +----+
//   +----------+ 2  | +--------+ 3  |
//   |          +----+          +--+-+
//   |                          |  |
// +-+-+                        |  |
// | 1 |          +-------------+  |
// +---+          |                |
//                |                |
//              +-+---+         +--+-+
//              |  5  |         |    |
//              |     +---------+ 4  |
//              +-----+         +----+

//so in the above graph we have a euler path as 1--2--3--4--5--3
//this path covers all the edges in graph

// euler circuit -- euler path which starts and ends at same vertex

//    +---------------------------------------+
//    |                                       |
//    |                                       |
// +--+--+                   +------+         |
// |  1  |                   |      |         |
// |     +-------------------+   2  |         |
// +--+--+                   +--+---+         |
//    |  |                      |             |
//    |  |                      |             |
//    |  +-----------------+    |             |
//    |                    |    |             |
//    |                    |    |             |
//    |                    +--+-+--+          |
// +--+--+                    |    |          |
// |     +--------------------+ 3  +----------+
// |  4  |                    +----+
// +-----+

// in the above graph the euler circuit is:
// 1--2--3--1--3--4--1

// Rules for determining whether the graph has euler path/circuit

// 1. A connected multigraph (and simple graph) with at least two vertices has a Euler
// circuit if and only if each of its vertices has an even degree

// Proof of the above statement is that every time a circuit passes through a vertex,
//  it adds twice to its degree. Since it is a circuit, it starts and ends at the same 
// vertex, which makes it contribute one degree when the circuit starts and one when it 
// ends. In this way, every vertex has an even degree.

//                         +----+
//    +--------------------+    |
//    |                    | 2  |
// +--+-+                  +-+--+
// |    |                    |
// | 1  |                    |
// +-+--+                    |
//   |                       |
//   |                       |
//   |                   +---+--+
//   |                   |      |
//   +-------------------+   3  |
//                       +------+

// in the above connected graph we can see see that all nodes have even degree i.e (2),
// therefore it has euler circuit : 1 -- 2 -- 3 -- 1


// 2. A connected multigraph (and simple graph) has an Euler path but not an Euler 
// circuit if and only if it has exactly two vertices of odd degree.

// The proof is an extension of the proof given above. Since a path may start and end at 
// different vertices, the vertices where the path starts and ends are allowed to have odd degrees. 

// +----+              +-----+           +------+
// | 1  |              |  2  |           |  3   |
// |    +--------------+     +-----------+      |
// +----+              +-----+           +------+
// we have exactly two vertices with odd degree (1 and 3)
// so the above connected graph has euler path but not euler cycle
//  the euler path is : 1 -- 2 -- 3


// int dfsCount(int i, vector <bool> &visited, vector <vector <int>> &graph){
//     visited[i] = true;
//     int count = 1;

//     int n = graph.size();
//     for (int j=0;j<n;j++){
//         if ((graph[i][j]) && !visited[j]){
//             count += dfsCount(j, visited, graph);
//         }
//     }

//     return count;

// }

// //returns true if edge i -- j is valid next edge to be included in euler path
// bool isValidEdge(int i, int j, vector <vector <int>> &graph){

//     int count = 0;
//     int n = graph.size();
//     for (int k=0;k<n;k++){
//         if (graph[i][k])
//             count++; 
//     }

//     if (count == 1){ // if j is the only adjacent vertex if i
//         return true;
//     }
//     // else

//     vector <bool> visited(n, false);
//     int count1 = dfsCount(i, visited, graph); //get number of nodes reachable from i
    

//     //get numbder of nodes reaachable from i, after removing edge i -- j
//     graph[i][j] = graph[j][i] = 0;

//     for (int k=0;k<n;k++)
//         visited[k] = false;

//     int count2 = dfsCount(i, visited, graph);
//     graph[i][j] = graph[j][i] = 1; //adding edge back 

//     //if number of nodes reach able from i decreases after removing the edge i -- j, then it is not valid edge(bridge)

//     return count1 > count2 ?  false:true;


// }

// void dfs(int i, vector <vector <int>> &graph, vector <int> &res){

//     res.push_back(i);

//     int n = graph.size();
//     for (int j=0;j<n;j++){
//         if (graph[i][j] && isValidEdge(i, j, graph)){
//             cout << j << endl;
//             graph[i][j] = 0;
//             graph[j][i] = 0;
//             dfs(j, graph, res);
//         }
//     }

// }

// vector <int> getEulerPath(int n, vector <vector <int>> graph){
//     //graph = adjency matrix


//     vector <int> degree(n);
//     for (int i=0;i<n;i++){
//         for (int j=0;j<n;j++){
//             if (graph[i][j]){
//                 degree[i]++;
//             }
//         }
//     }

//     int odd_count = 0;
//     int odd_ = 0;

//     for (int i=0;i<n;i++){
//         if (degree[i]%2){
//             odd_count++;
//             odd_ = i;
//         }
//     }

//     if (odd_count == 1 || odd_count > 2){
//         return {}; //euler path doesnt exist
//     }

//     vector <int> res;
//     //while doing dfs we delete the edge after using it
//     dfs(odd_, graph, res);

//     return res;
// }


//better solution
void dfsHelper(int i, vector <vector <int>> &graph, vector <int> &res){

    int n =graph[i].size();
    for (int j=0;j<n;j++){
        if (graph[i][j]){
            graph[i][j] = graph[j][i] = 0; //deleting this edge
            dfsHelper(j, graph, res);
        }
    }

    res.push_back(i);
}



//in directed graph we check if any vertex has abs(outdegree - indegree) > 1
//then that graph doesnt have a eulerian path
//also  if for anyvertext outdegree - indegree == 1,
// then that means it is our start node
// if for any vertex indegree - outdegree  == 1
// then it is our end node
//if we have more than one start and end nodes then that graph doesnt have eulerian cycle

vector <int> getEulerPath(int n, vector <vector <int>> graph){

    vector <int> degree(n, 0);

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (graph[i][j])
                degree[i]++;
        }
    }

    int odd_count = 0;
    int odd = 0;;
    for (int i=0;i<n;i++){
        if (degree[i] % 2){
            odd_count++;
            odd = i;
        }
    }


    if (odd_count > 2) //euler path doesnt exist
        return {};

    vector <int> res;
    //if odd count == 0 then we can start from any vertex
    //if odd_count == 2 then we can start from any of the two vertexes with odd degree
    //in directed graph we start from the vertex which has an extra out degree
    dfsHelper(odd, graph, res);
    reverse(res.begin(), res.end());

    return res;

}

int main (){

    int n = 5;

    vector <vector <int>> graph(n, vector <int>(n,0));

    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][4] = graph[4][3] = 1;
    graph[4][2] = graph[2][4] = 1;

    vector <int> res = getEulerPath(n, graph);

    for (int x:res)
        cout << x << " ";

    cout << endl;

    return 0;
}