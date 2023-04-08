#include <bits/stdc++.h>
using namespace std;


struct node{
    int x;
}node_pool[10];

struct comp{
    bool operator()(int a, int b) const{
        return node_pool[a].x < node_pool[b].x;
    }
};

int main(){

    node_pool[0].x = 1;
    node_pool[1].x = 2;
    node_pool[2].x = 0;
    node_pool[3].x = 3;

    set <int, comp> s;

    s.insert(0); 
    s.insert(1); 
    s.insert(2); 
    s.insert(3); 

    for (auto x:s)
        cout << x << ", " << node_pool[x].x << endl;
    cout << endl;

    node_pool[2].x = 10;


    for (auto x:s)
        cout << x << ", " << node_pool[x].x << endl;

    s.erase(2);



    cout << endl;

    for (auto x:s)
        cout << x << ", " << node_pool[x].x << endl;

    return 0;
}