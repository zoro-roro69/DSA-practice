#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector <pair <int, int>> adj[n];

    for (auto v:flights){
        adj[v[0]].push_back({v[1], v[2]});   
    }

    vector <int> dist(n, INT_MAX);
    dist[src] = 0;

    queue <pair <int,int>> q;
    q.push({src,0});
    int level = 0;
    while (!q.empty() && level<=k){
        int size = q.size();
        while(size && level <=k){
            auto front = q.front(); q.pop();size--;
            for (auto p: adj[front.first]){
                if (dist[p.first] > front.second + p.second){
                    dist[p.first] = front.second + p.second;
                    q.push({p.first, dist[p.first]});
                }
            }
            
        }
        level++;
    }

    if (dist[dst] == INT_MAX)
        return -1;

    return dist[dst];
    


}
//Using bellman ford algo
// /*  In bellman-ford algo calculates the shortest distance from the source
//     point to all of the vertices.
//     Time complexity of Bellman-Ford is O(VE),
// */
// int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
//     /* distance from source to all other nodes */
//     vector<int> dist( n, INT_MAX );
//     dist[src] = 0;
    
//     // Run only K+1 times since we want shortest distance in K hops
//     for( int i=0; i <= K; i++ ) {
//         vector<int> tmp( dist );
//         for( auto flight : flights ) {
//             if( dist[ flight[0] ] != INT_MAX ) {
//                 tmp[ flight[1] ] = min( tmp[flight[1]], dist[ flight[0] ] + flight[2] );
//             }
//         }
//         dist = tmp;
//     }
//     return dist[dst] == INT_MAX ? -1 : dist[dst];
// }

int main(){


    return 0;
}