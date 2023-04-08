#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    unordered_set <string> word_set;
   
    for (auto word:wordList){
        word_set.insert(word);
      
    }   

    if (word_set.find(endWord) == word_set.end())
        return 0;

    queue <string> q;
    unordered_set <string> visited;
    visited.insert(beginWord);
    q.push(beginWord);

    int level = 1;
    while(!q.empty()){
        int cur_size = q.size();
        for (int i=0;i<cur_size;i++){
            string front = q.front(); q.pop();
            if (front == endWord){

                return level;
            }

            for (int j=0;j<front.size();j++){
                string temp = front;

                for (int k=0;k<26;k++){
                    char ch = 'a' + k;
                    
                    if (ch != front[j]){
                        
                        temp[j] = ch;
                        if (word_set.find(temp) != word_set.end() && visited.find(temp) == visited.end()){
                           
                            visited.insert(temp);
                            q.push(temp);
                        }
                    }
                }
            }
        }

        level++;
    }
    

    return 0; //not found
}

int main(){

    return 0;
}