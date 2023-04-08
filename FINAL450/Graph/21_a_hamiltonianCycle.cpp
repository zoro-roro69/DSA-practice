#include <bits/stdc++.h>
using namespace std;

// Hamiltonian path in a graph is a path through which we can visit all
// the vertices of graph exactly once
// example 1
// +----+          +----+
// | 1  |          | 2  +---------+
// +-+--+          +----+         |
//   |                          +-+--+
//   |                          | 5  |
//   |                          +--+-+
// +-+--+          +---+           |
// | 3  | +------+ | 4 +-----------+
// +----+          +---+

// so in this graph we can see that if we follow the path 1--3--4--5--2,
// we can visit all the vertices exactly once therefore this is a hamiltonian path

// similarly we have the path 2--5--4--3--1 (reverse of the above)


// Hamiltonian cycle 
// hamiltonian cycle is the hamiltonian path in which last vertext has an edge to source vertex
// forming a cycle
// example 2

// +----+          +----+
// | 1  | -------- | 2  +---------+
// +-+--+          +-+--+         |
//   |             | |          +-+--+
//   |  +----------+ |          | 5  |
//   |  |            |          +--+-+
// +-+--+          +-+-+           |
// | 3  | +------+ | 4 +-----------+
// +----+          +---+

// So in the above example we have hamiltonian cycle: 1 -- 3 -- 4 -- 5 -- 2 -- 1
// another cycle : 1 -- 2 -- 5 -- 4 -- 3 -- 1
// we also have hmailtonian path which is not cycle: 1 -- 3 -- 2 -- 4 -- 5

// Note-
// in a graph if there exists a hamiltonian cycle, then we can take any vertex as source 
// and do dfs/backtracking, and we will be able to find the hamiltonian cycle
// you can checkk for yourself in example number 2 

// BUT
// in case when thr graph doesnt have a cycle and we need to find the hamiltonian path
// then from which vertex we start matters. in example 1 if we start from any other vertex
// other than 1 or 2 we will not be able to find the path with dfs/backtracking

void dfs(int i, int source, vector <bool> &visited, vector <int> adj[], vector <int> &res){

    visited[i] = true;
    res.push_back(i);

    bool cycle = false;


    for (int j:adj[i]){
        if (!visited[j]){
            dfs(j, source, visited, adj, res);
            visited[j] = false;            
            res.pop_back();

        }else{ //if visited
            if (j == source){
                cycle = true;
            }
        }
    }
    // for checking if all of them are visited we can maintain an visited count
    // rather than looping :)
    for (int j=0;j<visited.size();j++){ 
        if (!visited[j]){
            return;
        }
    }

    if (cycle){
        for (int x:res)
            cout << x << " ";
        cout << endl;
    }

}

void printAllHamiltonianCycle(int n, vector <int> adj[]){

    vector <int> res = {};

    vector <bool> visited(n, false);

    int source = 0;

    dfs(0, 0, visited, adj, res);

    // for (int i=0;i<n;i++){
    //     if (!visited[i])
    //         return;
    // }


}

int main(){

// (0)--(1)--(2)
//  |   / \   |
//  |  /   \  | 
//  | /     \ |
// (3)-------(4)

    // vector <int> adj[5];
    // adj[0].push_back(1);
    // adj[0].push_back(3);

    // adj[1].push_back(0);
    // adj[1].push_back(2);


    // adj[2].push_back(1);
    // adj[2].push_back(4);


    // adj[4].push_back(2);
    // // adj[4].push_back(3);


    // adj[3].push_back(0);
    // // adj[3].push_back(4);


    // vector <int> adj[6];

    // adj[0].push_back(1);
    // adj[0].push_back(2);
    // adj[0].push_back(5);


    // adj[1].push_back(0);
    // adj[1].push_back(2);
    // adj[1].push_back(4);
    // adj[1].push_back(5);

    // adj[2].push_back(1);
    // adj[2].push_back(3);
    // adj[2].push_back(0);


    // adj[3].push_back(2);
    // adj[3].push_back(4);

    // adj[4].push_back(3);
    // adj[4].push_back(1);
    // adj[4].push_back(5);


    // adj[5].push_back(0);
    // adj[5].push_back(1);
    // adj[5].push_back(4);

    // printAllHamiltonianCycle(6, adj);
    freopen("input.txt", "r", stdin);

    int n,m;
    cin >> n >> m;

	vector <int> adj[n];

	for (int i=0;i<m;i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	printAllHamiltonianCycle(n, adj);


    return 0;
}