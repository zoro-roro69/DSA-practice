#include <bits/stdc++.h>
using namespace std;


string toKey(pair <int, int> &p){
    return to_string(p.first) + "-" + to_string(p.second);
}

void waterJugBFS(int n, int m, int d){

    unordered_map <string, pair <int,int>> visited; //will be used for marking visited, as well as stroing parent
    visited["0-0"] = {-1,-1};

    queue <pair <int,int>> q;
    q.push({0,0});

    pair <int, int> res = {-1,-1};
    while(!q.empty()){
        pair <int, int> front = q.front(); q.pop();
        if ((front.first == d && front.second == 0) || (front.first == 0 && front.second == d)){
            res = front; //found final state
            break;
        }

        //generate neighbors
        pair <int, int> nbor;
        string key;

        //making first empty
        nbor = {0,front.second}; 
        key = toKey(nbor);
        if (visited.find(key) == visited.end()){
            visited[key] = front;
            q.push(nbor);
        }

        //making second empty
        nbor = {front.first, 0};
        key = toKey(nbor);
        if (visited.find(key) == visited.end()){
            visited[key] = front;
            q.push(nbor);
        }

        //make first full
        nbor = {n,front.second}; 
        key = toKey(nbor);
        if (visited.find(key) == visited.end()){
            visited[key] = front;
            q.push(nbor);
        }

        //making second full
        nbor = {front.first, m}; 
        key = toKey(nbor);
        if (visited.find(key) == visited.end()){
            visited[key] = front;
            q.push(nbor);
        }


        //if first is partially filled, try to fill it
        if (front.first < n){
            int empty_amt = n-front.first;
            int transfer_amt = min (empty_amt, front.second);
            nbor = {front.first + transfer_amt, front.second - transfer_amt};
            key = toKey(nbor);
            if (visited.find(key) == visited.end()){
                visited[key] = front;
                q.push(nbor);
            }
        }

        //if second is partially empty, try to fill it
        if (front.second < m){
            int empty_amt = m-front.second;
            int transfer_amt = min(empty_amt, front.first);
            nbor = {front.first - transfer_amt, front.second + transfer_amt};
            key = toKey(nbor);
            if (visited.find(key) == visited.end()){
                visited[key] = front;
                q.push(nbor);
            }
        }

    }
    vector <pair <int, int>> v; 
    if (res.first!=-1){
        string key = toKey(res);
        while(visited[key].first!=-1){
            v.push_back(res);
            res = visited[key];
            key = toKey(res);
        }
        v.push_back(res);
    }

    reverse(v.begin(), v.end());

    for (auto x: v){
        cout << "( " << x.first << ", " << x.second << ") ";
    }
    cout << endl;

    return;

}

int main(){
    waterJugBFS(3,5,4);
    return 0;
}