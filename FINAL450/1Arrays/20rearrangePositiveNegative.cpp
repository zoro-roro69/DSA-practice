#include <bits/stdc++.h>
using namespace std;

void printVector(vector <int> v){
    for (auto x:v){
        cout << x << " ";
    }
    cout<<endl;
}

//order is not maintained 
void rearrangePositiveNegative(vector <int> v){
    //check size
    if (v.size()<=0)
        return;

    int next_pos = 0;
    int next_neg = 1;

    for (int i=0;i<v.size();){
        if (i%2){ //odd place - for -ve
            if (v[i]<0){
                if (next_neg < i){
                    swap(v[i], v[next_neg]);
                    next_neg+=2;
                }
                i++;
            }
            else{
                if (next_pos < v.size()){
                    swap(v[i], v[next_pos]);
                    next_pos +=2;
                }else
                    i++;
            }
        }else{ //even plce - for +ve
            if (v[i]>=0){
                if (next_pos < i){
                    swap(v[i], v[next_pos]);
                    next_pos+=2;
                }
                i++;
            }
            else{
                if (next_neg <v.size()){
                    swap(v[i], v[next_neg]);
                    next_neg += 2;
                }else
                    i++;
            }
        }
    }
    cout <<"order not maintained:" ;printVector(v);
}


//modified insertion sort, to maintain the order
//O(n2)
void rearrange2(vector <int> v){

    //even index -- positive
    //odd index -- negative
    int n = v.size();

    for (int i=0;i<n;i++){
        if (i%2 == 0){//even
            if (v[i] >= 0)
                continue;
            else{
                //find next positive
                int j = i+1;
                while(j<n && v[j]<0)
                    j++;

                if (j == n)  //no positives left
                   break;
                //move the positive to i, and shift the array
                int temp = v[j];
                for (int k=j;k>i;k--)
                    v[k] = v[k-1];
                v[i] = temp;
            }
        }else{//odd
            if (v[i] < 0)
                continue;
            else{
                //find next negative
                int j = i+1;
                while(j<n && v[j]>=0)
                    j++;

                if (j == n) //no more negatives left
                    break;
                
                //move negative to i, and shift the array
                int temp = v[j];
                for (int k=j;k>i;k--)
                    v[k] = v[k-1];

                v[i] = temp;
            }

        }
    }

    cout << "order maintained:" ; printVector(v);

}

int main(){
    vector <int> v{1,2,3,-1,-2,-3};

    cout << "original:"; printVector(v);
    rearrangePositiveNegative(v);
    rearrange2(v);

    return 0;
}