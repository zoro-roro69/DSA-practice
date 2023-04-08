#include <bits/stdc++.h>
using namespace std;


// this approach gives TLE :)

// void dfs(int i, int par, vector <int> &dist, vector <int> adj[]){

//     for (int j:adj[i]){
//         if (par!=j){
//             dist[j] = dist[i]+1;
//             dfs(j, i, dist, adj);
//         }
//     }
// }


// bool searchDfs(int y, int x, int par,vector <int> &dist, vector <int> adj[], int &type){

//     if (y == x)
//         return true;
    
//     for (int j:adj[y]){
//         if (par != j){
//             if (type){ //away from king
//                 if (dist[j] > dist[y] && searchDfs(j, x, y, dist, adj, type))
//                     return true;
//             }else{ //towards the king
//                 if (dist[j] < dist[y] && searchDfs(j, x, y, dist, adj, type))
//                     return true;
//             }
//         }
//     }

//     return false;
// }

//this question can be solved using the "Euler Tour" algo

void eulerTourDfs(int i, int par, int &time, vector <int> adj[], vector <int> &in_time, vector <int> &out_time){
    in_time[i] = ++time;

    for (int j:adj[i]){
        if (par != j){
            eulerTourDfs(j, i, time, adj, in_time, out_time);
        }
    }

    out_time[i] = ++time;
}



int main(){

    freopen("input.txt", "r", stdin);

    // int n;
    // cin>>n;

    // vector <int> adj[n+1];

    // vector <int> dist(n, -1);
    // dist[1] = 0;

    // for (int i=0;i<n-1;i++){
    //     int u, v; cin >> u >> v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);

    // }

    // dfs(1, 0,dist, adj);

    // int q; cin>>q;

    // while(q--){
    //     int type; int x; int y; //from y find x;
    //     cin >> type >> x >> y;
    //     if (searchDfs(y, x, 0, dist, adj, type)){
    //         cout << "YES" << endl;
    //     }else
    //         cout << "NO" << endl;
    // }

    // added the two lines below for faster io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    // It is recommended to use cout << “\n”; instead of cout << endl;. endl is slower because 
    // it forces a flushing stream, which is usually unnecessary

    int n;
    cin >> n;

    vector <int> in_time(n+1, 0);
    vector <int> out_time(n+1, 0);

    vector <int> adj[n+1];

    for (int i=0;i<n-1;i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);


    }
    int time = 0;
    eulerTourDfs(1, 0, time, adj, in_time, out_time);

    int q; cin>>q;

    while(q--){
        int type, x,  y;
        cin >> type >> x >> y;
        if (type){ //away from king
            //check if x comes in subtree of y
            if (in_time[y] < in_time[x] && out_time[y] > out_time[x]){
                cout << "YES" << endl;
            }else
                cout << "NO" << endl;
        }else{ //towards king
            //check if y comes in subtree of x
            if (in_time[y] > in_time[x] && out_time[y] < out_time[x]){
                cout << "YES" << endl;
            }else
                cout << "NO" << endl;
        }
    }


    return 0;
}