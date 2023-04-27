#include <bits/stdc++.h>
using namespace std;


struct Node{
    string data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

bool compute(Node* root){

    string s = "";

    while(root){
        s += root->data;
        root = root->next;
    }

    for (int i=0, j = s.size()-1; i<j; i++, j--){
        if (s[i] != s[j])
            return false;
    }
    return true;

}

int main(){

    return 0;
}