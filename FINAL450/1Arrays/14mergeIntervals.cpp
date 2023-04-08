#include <bits/stdc++.h>
using namespace std;

void print2dVector(vector <vector <int>> vec){

    for (auto v:vec){
        for (auto x:v)
            cout << x << " ";
        cout << endl;
    }
}

struct MyComparator{
    bool operator()(const vector <int> &v1, vector <int> &v2){
        if (v1[0] == v2[0])
            return v1[1]<=v2[1];
        return v1[0] < v2[0];
    }
};

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
    sort (intervals.begin(), intervals.end(), MyComparator()); //even without comparator it will sort in similar manner

    vector <vector <int>> res;
    res.push_back(intervals[0]);

    for (int i=1;i<intervals.size();i++){
        vector <int> a = res.back();
        //check if current vector can be merged with last added in res
        if (a[1]>=intervals[i][0]){
            res.pop_back();
            res.push_back({a[0], max(a[1], intervals[i][1])});
        }else{
            res.push_back(intervals[i]);
        }
    }

    cout << "after" << endl;
    print2dVector(res);
    return res;
}

int main(){

    vector <vector <int>> vec;
    //vec.push_back({[1,3],[2,6],[8,10],[15,18]]})
    vec.push_back({1,3});
    vec.push_back({2,6});
    vec.push_back({8,10});
    vec.push_back({15,18});

    cout << "before" <<endl;
    print2dVector(vec);
    merge(vec);


    return 0;
}