#include <bits/stdc++.h>
using namespace std;

// Chinese Postman Problem is a variation of Eulerian circuit problem for undirected graphs. An Euler Circuit is
//  a closed walk that covers every edge once starting and ending position is same.

// Chinese Postman problem is defined for connected and undirected graph. The problem is to find shortest path 
// or circuity that visits every edge of the graph "at least" once

// If input graph contains Euler Circuit, then a solution of the problem is Euler Circuit 

// . In weighted graph the minimum possible weight of Postman tour is sum of all edge weights which we
//  get through Eulerian Circuit. We can’t get a shorter route as we must visit all edges at-least once. 

//   If input graph does NOT contain Euler Circuit 

// In this case, the task reduces to following. 

// 1) In unweighted graph, minimum number of edges to duplicate so that the given graph converts to a graph with Eulerian Cycle

// 2) In weighted graph, minimum total weight of edges to duplicate so that given graph converts to a graph with Eulerian Cycle.

// Algorithm to find shortest closed path or optimal 
// Chinese postman route in a weighted graph that may
// not be Eulerian.

// step 1 : If graph is Eulerian, return sum of all 
//          edge weights.Else do following steps.
// step 2 : We find all the vertices with odd degree 
// step 3 : List all possible pairings of odd vertices  
//          For n odd vertices total number of pairings 
//          possible are, (n-1) * (n-3) * (n -5)... * 1
// step 4 : For each set of pairings, find the shortest 
//          path connecting them.
// step 5 : Find the pairing with minimum shortest path 
//          connecting pairs.
// step 6 : Modify the graph by adding all the edges that  
//          have been found in step 5.
// step 7 : Weight of Chinese Postman Tour is sum of all 
//          edges in the modified graph.
// step 8 : Print Euler Circuit of the modified graph. 
//          This Euler Circuit is Chinese Postman Tour.


vector <vector <pair <int, int>>> res;
vector <int> odd_vertices;

void generatePairs(vector <pair<int,int>> &cur_path, vector <bool> &selected, int prev){
	
	int u = -1;
	int v = -1;
	for (int i=prev+1;i<odd_vertices.size();i++){
		if (!selected[i]){

			u = odd_vertices[i];
			selected[i] = true;

			for (int j = i+1; j<odd_vertices.size();j++){
				if (!selected[j]){
					v = odd_vertices[j];

					selected[j] = true;
					cur_path.push_back({u, v});
					generatePairs(cur_path, selected, i);

					selected[j] = false;
					cur_path.pop_back();
				}
			}
			selected[i] = false;
            break;
		}
	}
	if (u == -1){
		res.push_back(cur_path);
	}
}

int djkastra(int s, int e, int n, vector <pair <int, int>> adj[]){

    vector <int> distance(n, INT_MAX);
    distance[s] = 0;
    queue <int> q;
    q.push(s);

    while(!q.empty()){
        int front = q.front(); q.pop();

        for (auto p:adj[front]){
            if (distance[p.first] > distance[front] + p.second){
                distance[p.first] = distance[front] + p.second;
                q.push(p.first);
            }
        }
    }

    return distance[e];

}

int chinesePostman(int n, vector <pair <int, int>> adj[]){
    odd_vertices.clear();
    for (int i=0;i<n;i++){
        if (adj[i].size() % 2){
            odd_vertices.push_back(i);
        }
    }

    int sum_edges = 0;
    for (int i=0;i<n;i++){
        for (auto p:adj[i]){
            if (p.first > i){
                sum_edges += p.second;
            }
        }
    }
    if (odd_vertices.empty()){
        //if no odd vertices then, euler circuit exists and and the answer is simply
        //sum of all edges
        return sum_edges; 
    }else{
        //no euler path
        res.clear();
        vector <pair <int, int>> cur_path;
        vector <bool> selected(odd_vertices.size(), false);
        generatePairs(cur_path, selected, -1);

        int min_cost = INT_MAX;
        for (int i=0;i<res.size();i++){
            int cur_cost  = 0;
            for (auto p:res[i]){
                cur_cost += djkastra(p.first, p.second, n, adj);
            }
            min_cost = min(min_cost, cur_cost);
        }
        cout << sum_edges << endl;

        return min_cost + sum_edges;
    }


}


int main(){
    // odd_vertices.push_back(1);
    // odd_vertices.push_back(2);
    // odd_vertices.push_back(3);
    // odd_vertices.push_back(4);
    // odd_vertices.push_back(5);
    // odd_vertices.push_back(6);
    // vector <pair <int, int>> cur_path;
    // vector <bool> selected(7, false);
    // generatePairs(cur_path, selected, -1);

    // for (auto v:res){
    //     for (auto p:v){
    //         cout << "( " << p.first << ", " << p.second << ")" << " ";
    //     }
    //     cout << endl;
    // }

// 1         +----+      3        +-----+        1
//   +-------+ 0  ++              |  1  +--------+
//   |       +--+-----------------+--+--+        |
//   |          |                    |           |
// +-+-+        |                    |        +--+-+
// | 2 |        | 5                  |6       |  5 |
// +-+-+        |                  +-+--+     +--+-+
//   |        +-+--+               |    |        |
//   +--------+ 3  +---------------+  4 +--------+
//   2        +----+        4      +----+       1



    vector <pair <int, int>> adj[6];


    adj[0].push_back({1, 3});
    adj[0].push_back({2, 1});
    adj[0].push_back({3, 5});

    adj[1].push_back({0, 3});
    adj[1].push_back({5, 1});
    adj[1].push_back({4, 6});

    adj[2].push_back({0, 1});
    adj[2].push_back({3, 2});

    adj[3].push_back({2, 2});
    adj[3].push_back({4, 4});
    adj[3].push_back({0, 5});

    adj[4].push_back({3, 4});
    adj[4].push_back({1, 6});
    adj[4].push_back({5, 1});

    adj[5].push_back({1, 1});
    adj[5].push_back({4, 1});

    cout << chinesePostman(6, adj) << endl;


    return 0;
}