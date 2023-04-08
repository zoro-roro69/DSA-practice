#include <bits/stdc++.h>
using namespace std;


void printVector(vector <int> v){
    for (auto x:v){
        cout << x << " ";
    }
    cout<<endl;
}

vector <int> findCommonIn3Sorted(vector <int> a, vector <int> b, vector <int> c){
    vector <int> res;

    int i=0,j=0,k=0;

    for(;i<a.size()&&j<b.size()&&k<c.size();){
        //all are equal
        if (a[i] == b[j] && b[j] == c[k]){
            res.push_back(a[i]);

            //uncomment the while loops, if you dont want any duplicates
            //increment i
            i++;
            while(i<a.size() && a[i]==a[i-1])
                i++;
            //increment j
            j++;
            while(j<b.size() && b[j]==b[j-1])
                j++;
            //increment k
            k++;
            while(k<c.size() && c[k]==c[k-1])
                k++;
        }else{
            //all are not equal
            int max_ = max(a[i], max(b[j], c[k]));
            
            while(i<a.size() && a[i]<max_)
                i++;

            while(j<b.size() && b[j]<max_)
                j++;
            

            while(k<c.size() && c[k]<max_)
                k++;
        }
    }

    return res;
}

int main(){

    vector <int> res;

//ar1[] = {1, 5, 5} 
//ar2[] = {3, 4, 5, 5, 10} 
//ar3[] = {5, 5, 10, 20} 

    vector <int> a{1,5,5};
    vector <int> b{3,4,5,5,10};
    vector <int> c{5,5,10,20};

    res = findCommonIn3Sorted(a, b, c);

    cout << "common: "; printVector(res);
    return 0;
}