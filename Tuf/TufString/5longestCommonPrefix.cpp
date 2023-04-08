#include <bits/stdc++.h>
using namespace std;

//trie
struct TNode{
    int count = 0;
    TNode *arr[26];

    TNode(){
        count = 0;
        for (int i=0;i<26;i++)
            arr[i] = 0;
    }
};

void insertInTrie(TNode *root, string &s, int ind){
    if (ind >=s.size()) 
        return;

    int i = s[ind] - 'a';
    if (root->arr[i] == NULL)
        root->arr[i] = new TNode();
    
    root->arr[i]->count++;
    insertInTrie(root->arr[i], s, ind+1);
}

void insertInTrieIterative(TNode *root, string &s){

    for (int ind = 0;ind < s.size(); ind++){
        int i = s[ind] - 'a';
        if (root->arr[i] == NULL)
            root->arr[i] = new TNode();

        root->arr[i]->count++;
        root = root->arr[i];
    }

}
//optimised version for this problem
//in this we only insert the first string completely in the trie
//for all other strings only the prefix part is stored
void insertInTrieIterativeOptimised(TNode *root, string &s, bool first){

    for (int ind = 0;ind < s.size(); ind++){
        int i = s[ind] - 'a';
        if (root->arr[i] == NULL) {
            if (first == true)
                root->arr[i] = new TNode();
            else
                break; //not first string
        }

        root->arr[i]->count++;
        root = root->arr[i];
    }

}

void longestPrefixHelper(TNode *root, int n, string &prefix){
    
    for (int i=0;i<26;i++){
        if (root->arr[i] != NULL && root->arr[i]->count == n){
            prefix += char('a' + i);
            longestPrefixHelper(root->arr[i], n, prefix);
            break;
        } 
    }
    return;
}

void longestPrefixHelperIterative(TNode *root, int n, string &prefix){

    while(root){
        int i;
        for (i=0;i<26;i++){
            if (root->arr[i] != NULL && root->arr[i]->count == n){
                prefix += char('a' + i);
                root = root->arr[i];
                break;
            }
        }
        if (i == 26)
            break;
    }

}

string longestCommonPrefix(vector<string> &arr, int n){
    // n = num of strings in arr
    TNode *root = new TNode();

    for (string s:arr)
        // insertInTrie(root, s, 0);
        insertInTrieIterative(root, s);

    string prefix = "";

    // longestPrefixHelper(root, n, prefix);
    longestPrefixHelperIterative(root, n, prefix);

    return prefix;



}


//solutiong without trie

string longestCommonPrefix2(vector <string> &s, int n){

    string prefix = "";

    bool flag = true;
    for (int i=0;i<s[0].size();i++){ //traverse thrught chars of first string
        char ch = s[0][i];

        for (int j=1;j<n;j++){
            if (ch == s[j][i]){
                flag = true;
            }else{
                flag = false;
                break;
            }
        }

        if (flag == true)
            prefix += ch;
        else
            break;
    }

    return prefix;

}

int main(){

    // vector <string> arr {"flower","flow","flight"};
    vector <string> arr {"dog","racecar","car"};
    cout << longestCommonPrefix(arr, 3) << endl;
    return 0;
}