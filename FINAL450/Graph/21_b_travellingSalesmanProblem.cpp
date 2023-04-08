#include <bits/stdc++.h>
using namespace std;

//Travelling salesman problem
// This is NP Hard Problem :)
// i.e no polynomial time solution exists for this problem


// time Complexity -- N! (N factorial)
void dfs(int i, int source, vector <bool> &visited, vector <vector <int>> &adj, 
         int &vis_count, vector <int> &cur_path, int &cur_cost, vector <int> &res_path, int &min_cost)
{
    visited[i] = true; 
    vis_count++;
    cur_path.push_back(i);

    bool cycle = false;
    for (int j=0;j<adj.size();j++){
        if (!visited[j] && adj[i][j]!=-1){
            cur_cost += adj[i][j];

            dfs(j, source, visited, adj, vis_count, cur_path,cur_cost,res_path,min_cost);

            visited[j] = false;
            cur_path.pop_back();
            cur_cost -= adj[i][j];
            vis_count--;

        }else{
            if (adj[i][j]!=-1 && j == source){
                cycle = true;
            }
        }
    }

    if (vis_count != adj.size()){ //all are visited
        return;
    }

    if (cycle == true){
        cur_cost += adj[i][source];
        if (cur_cost < min_cost){
            min_cost = cur_cost;
            res_path = cur_path;

            cur_cost -= adj[i][source];
        }
    }


}

vector <int> travellingSalesmanProblem(int n, vector <vector <int>> &adj){

    vector <int> res_path;
    vector <int> cur_path;
    int cur_cost = 0;
    int min_cost = INT_MAX;

    vector <bool> visited(n, false);
    int vis_count = 0;
    dfs(0, 0, visited, adj, vis_count, cur_path, cur_cost, res_path, min_cost);

    cout << min_cost << endl;
    return res_path;

}

int main(){
    vector <vector <int>> adj{ { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };

    vector <int> res = travellingSalesmanProblem(4, adj);

    for (int x:res)
        cout << x << " ";
    cout << endl;

    return 0;
}