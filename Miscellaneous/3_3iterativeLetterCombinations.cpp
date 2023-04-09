#include <bits/stdc++.h>
using namespace std;


//iterative solution
vector <string> letterCombinationsBFS(vector <int> &numbers){
    //using BFS
    vector <string> mp { 
                        "0", //0
                        "1", //1
                        "abc", //2
                        "def", //3
                        "ghi", //4
                        "jkl", //5
                        "mno", //6
                        "pqrs", //7
                        "tuv", //8
                        "wxyz" //9
                        };

    vector <string> res;
    queue <string> q;
    q.push("");

    

    while(!q.empty()){
        string front = q.front(); q.pop();
        int ind = front.size();
        if (ind == numbers.size()){

            res.push_back(front);
            continue;
        }

        for (char ch: mp[numbers[ind]]){
            string temp = front + ch;
            q.push(temp);
        }
    }

    return res;

}

void dfs(int i, string &cur_str, vector <int> &nums, vector <string> &mp, vector <string> &res){
    if (i == nums.size()){
        res.push_back(cur_str);
        return;    
    }
    
    for (char ch: mp[nums[i]]){
        cur_str += ch;
        dfs(i+1, cur_str, nums, mp, res);
        cur_str.pop_back();
    }
}

vector <string> letterCombinationsDFS(vector <int> &nums){
    vector <string> mp { 
                        "0", //0
                        "1", //1
                        "abc", //2
                        "def", //3
                        "ghi", //4
                        "jkl", //5
                        "mno", //6
                        "pqrs", //7
                        "tuv", //8
                        "wxyz" //9
                        };

    vector <string> res;
    string cur_str = "";
    dfs(0, cur_str,nums, mp, res);

    return res;

}

int main(){

    vector <int> nums{1,3};
    vector <string> res = letterCombinationsBFS(nums);

    for (auto s:res)
        cout << s << endl;

}