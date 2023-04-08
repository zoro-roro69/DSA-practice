#include <bits/stdc++.h>
using namespace std;

// worst case
// aaaaaaaab - string
// aaab - pattern

// basic idea od KMP is
// it ttries to check whether is there any prefix which is also suffix in the pattern

// we create a lps table (longest prefix suffix)

// lps[i] = length of longest prefix-suffix for string starting from and ending at i

// a a a b 

// 0 1 2 0


// after the lp table is done lets match it with the string

// first 
// 0 1 2  3  4 5 6 7 8 9

// a a a |a| a a a a a b

// a a a |b|

// //first mismatch occurrs at i=3 and j = 3
// // that means that pattern from 0 to j-1 must have matched
// //now KMP thinks that this must have been suffix which we were trying to match and we //were unsuccesfull, so lets give another chance by assuming that what we need is
// //prefix instead so we move to j to end of this prefix which we get from kps table
// // j = lps[j-1] 

// // so in this we move j to 2 and i remains at 3
// // then we start algo. again

// // in the naive algorithm we would have moved j to 0 i.e starting
// // so this is the optimisation that we achieve by KMP string pattern matching


// But how to calculate the LPS table for our pattern?
// we apply kind of same approach, but instead here we search in same string i.e pattern

// 0 1 2 3
// a a a b

// we take a variable len =0, //it will store length of largest prefix-suffix

// for i = 0, we set lps[0] = 0
// then we start from i =1, and len = 0

// we check if pat[i] == pat[len]
// 	if yes then we do len++
// 		we assign lps[i] = len
// 		then do i++ aswell
// 	but if pat[i] != pat[len] //mismatch and i and len
// 		then we check if len > 0
// 			if yes then we apply the same approach
// 				i,e pattern 0 to len-1 must have matched , we were trying as suffix, now lets try as prefix
// 				so we move j to where prefix ended i.e lps[len-1]
// 				so we set len = lps[len-1]
// 		if len == 0 //if len is already at first index so we cannot move more backwar and try as prefix
// 			so we set lps[i] = 0
// 			and then do i++

vector <int> kmpPatternMatching(string s, string pattern){

    int n = s.size();
    int m = pattern.size();

    vector <int> lsp(m, 0);

    //[[preprocessing step, filling the lsp table
    int len = 0;
    lsp[0] = 0;
    int i = 1;

    while(i<m){
        if (pattern[i] == pattern[len]){
            len++;
            lsp[i++] = len;
        }else{
            if (len != 0){
                len = lsp[len-1]; //move at end of prefix
            }else{
                lsp[i++] = 0;
            }
        }
    }
    //]]
    cout << "done preprocessing" << endl;

    //now we do the pattern matching, and store all occurences in res array
    vector <int> res;

    i=0; int j = 0;

    while(i<n){
        if (s[i] == pattern[j]){
            i++;
            j++;
        }else{
            if (j!=0)
                j = lsp[j-1];
            else{
                i++;
            }
        }

        if (j == m){ //pattern matched completely
            //storing starting index of the match
            res.push_back(i-j);
            j = lsp[j-1];
        }
    }

    return res;


}			

int findLastOccurence(string A,string B){
    //Code Here
    vector <int> res;
    res = kmpPatternMatching(A, B);
    if (!res.empty())
        return res.back();
    return -1;
}

int main(){

    vector <int> res;

    string a = "AABAACAADAABAABA";
    string b = "AABA";
    res = kmpPatternMatching(a, b);

    for (int x:res)
        cout << x << " ";
    cout << endl;

    cout << findLastOccurence(a, b) << endl;

    return 0;
}
