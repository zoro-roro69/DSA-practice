#include <bits/stdc++.h>
using namespace std;


// if your graph contains negative edge cycle then it is not practical to find the shortest
// distance, since with each each iteration you will get the shortest distance again and again

// for example:

// +-----+          -2          +------+
// |     |                      |      |
// |  1  +----------------------+   2  |
// +-----+                      +------+

// now in the above example node 1 and 2 are connected by the edge with negative wt "-2"
// lets say your source is 1
// now to reach "2" you cover distance "-2"
// now from "2" you can go back to 1 , and in doing so you cover the distance "-4"
// now from "1" you can go back to 2, with distane covered as "-6", which is smaller than previous shortest "-2"
// so in this way you can go on and on and on, and each time your distance will be shorter than the previous.

// this is the problem when graph contains -ve edge cycles
// djkastras algo fails in such cases, aand it will go on and on til infinity

// bellman ford algo, is another algorithm for finding shortest distances,
// advantage of bellman ford is that it can detect any -ve edge cycles if they are present in graph,
// if they are not present then it gives the shortest distance 

// bellman ford only works for directed graphs, so if your graph is undirected you need to convert it into directed
// 
// for example if you graph looks like this:

// +------+        -2            +-------+
// |      |                      |       |
// |  1   +----------------------+   2   |
// |      |                      |       |
// +------+                      +-------+

// then convert to directed graph like this

//                  -2
// +------+                      +-------+
// |      +------------------->  |       |
// |  1   |                      |   2   |
// |      |                      |       |
// +------+ <------------------+ +-------+
// 
//                  -2

vector <int> bellmanFord(int v, vector <vector <int>> adj[], int source){
    //assumning we have adj list of directed weighted graph as input
    const int MAX_DIST = 100001;

    //get edge list from adjacent list
    vector <vector <int>> edges;
    for (int i=0;i<v;i++){
        for (auto j:adj[i]){
            edges.push_back({i, j[0], j[1]}); //{u, v, wt}
        }
    }

    vector <int> dist(v, MAX_DIST);
    dist[source] = 0;

    //run for v-1 times always, (we run for v-1 times because v-1 is then length of the largest path in worst case)
    for (int i=0;i<v-1;i++){
        for (auto e:edges){
            //relaxation step
            if (dist[e[0]] + e[2] < dist[e[1]]){
                dist[e[1]] = dist[e[0]] + e[2];
            }
        }

    }
    //after running above step for v-1 steps we will have shortest distance

    //but to check for -ve cycle we again run the relaxation step for all edges,
    // and if the distance array gets updated then that means there is -ve edge cycle

    bool flag = false;
    for (auto e:edges){
        //relaxation a
        if (dist[e[0]] + e[2] < dist[e[1]]){
            dist[e[1]] = dist[e[0]] + e[2];
            flag = true;
            break;
        }
    }

    if (flag){
        //cycle is present
    }

    return dist;

}


int main(){


    return 0;
}