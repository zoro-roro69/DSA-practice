#include <bits/stdc++.h>
using namespace std;



void printVector(vector <int> v){
    for (auto x:v){
        cout << x << " ";
    }
    cout<<endl;
}

//assuming we dont want any duplicates in our solution
void findIntersection(vector <int> a, vector <int> b){

    int i = 0, j = 0;
    vector <int> intersection;

    while( i < a.size() && j < b.size()){
        if(a[i] == b[j]){
            intersection.push_back(a[i]);
            //increment i
            i++;
            //this is necessary if we want to remove duplicates
            while(i < a.size() && a[i] == a[i-1]){
                i++;
            }

            //increment j
            j++;
            while(j < b.size() && b[j] == b[j-1]){
                j++;
            }
        }else{

            if (a[i] < b[j]){
                //increment i
                i++;
                while(i < a.size() && a[i] == a[i-1]){
                    i++;
                }
            }else{
                //increment j
                while(j < b.size() && b[j] == b[j-1]){
                    j++;
                }
            }

        }
    }

    printVector(intersection);

}


void findUnion(vector <int> a, vector <int> b){

    int i =0, j = 0;
    vector <int> myunion;

    while(i < a.size() && j < b.size()){

        if (a[i] == b[j]){
            myunion.push_back(a[i]);
            //increment i
            i++;
            while(i < a.size() && a[i] == a[i-1])
                i++;

            //increment j
            j++;
            while(j < b.size() && b[j] == b[j-1])
                j++;
        }else{
            //add the smaller and increment the index of one which is smaller
            //consider the test case {1,2,3,4,5} {5,6,7,8,9} 
            //if we dont add smaller one first we will end with two 5's in the result

            if (a[i] < b[j]){
                myunion.push_back(a[i]);
                //increment i
                i++;
                while(i < a.size() && a[i] == a[i-1])
                    i++;
            }else{
                myunion.push_back(b[j]);
                //increment j
                j++;
                while(j < b.size() && b[j] == b[j-1])
                    j++;
            }
        }
    }

    //if one of the arrays are not completely traversed yet
    while(i < a.size()){
        myunion.push_back(a[i]);
        //increment i
        i++;
        while(i < a.size() && a[i] == a[i-1])
            i++;
    }

    while(j < b.size()){
        myunion.push_back(b[j]);
        //incremnt j
        j++;
        while(j < b.size() && b[j] == b[j-1])
            j++;
    }

    printVector(myunion);

}

int main(){
    
    vector <int> a{1,2,2,3,4};
    vector <int> b{2,2,4,6,7,8};

    cout << "intersection " ;
    findIntersection(a, b);

    vector <int> c{1,2,3,4,5,6};
    vector <int> d{5,6,7,8,9,10};

    cout << "union " ;
    findUnion(c,d);

    return 0;
}
