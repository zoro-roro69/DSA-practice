#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

    queue <pair <int,int>>  q;

    int n = image.size();
    int m = image[0].size();

    q.push({sr,sc});
    int init_color = image[sr][sc];
    image[sr][sc] = color;

    vector <vector <int>> neighbors{{1,0},{-1,0}, {0,1},{0,-1}};

    while(!q.empty()){
        pair <int, int> front = q.front(); q.pop();

        for (auto nbr:neighbors){
            int x = nbr[0] + front.first;
            int y = nbr[1] + front.second;

            if (x>=0 && x< n && y>=0 && y<m && image[x][y] == init_color){
                q.push({x,y});
                image[x][y] = color;
            }


        }

    }
    return image;

}

int main(){

    return 0;
}