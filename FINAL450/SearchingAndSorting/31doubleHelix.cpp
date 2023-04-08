#include <bits/stdc++.h>
using namespace std;


int doubleHelix(vector <int> &arr1, vector <int> &arr2){
	
    unordered_map <int, int> hash;

    for (int i = 0;i<arr1.size();i++){
        hash.insert({arr1[i], i});
    }
    vector <pair <int, int>> intersections;
    for (int i=0;i<arr2.size();i++){
        if (hash.find(arr2[i])!=hash.end()){
            //intersection
            intersections.push_back({hash[arr2[i]], i}); //index of 1st seq and 2nd seq
        }
    }
    


    vector <int> pre_sum1(arr1.size(), 0);
    vector <int> pre_sum2(arr2.size(), 0);

    int sum = 0;
    for (int i=0;i<arr1.size();i++){
        sum += arr1[i];
        pre_sum1[i] = sum;
    }

    sum = 0;
    for (int i=0;i<arr2.size();i++){
        sum += arr2[i];
        pre_sum2[i] = sum;
    }
    
    if (intersections.size() == 0){
    	//no intersections
    	return max(pre_sum1[arr1.size()-1], pre_sum2[arr2.size()-1]);
    }

    sum = 0;
    pair <int, int> prev = {-1,-1};
    for (auto p: intersections){

        int psum1 = pre_sum1[p.first];
        if (prev.first != -1){
            psum1 -= pre_sum1[prev.first];
        }

        int psum2 = pre_sum2[p.second];
        if (prev.second != -1){
            psum2 -= pre_sum2[prev.second];
        }

        if (psum1 > psum2)
            sum += psum1;
        else
            sum += psum2;
        
        prev = p;
    }
    int sum_till_last1 = 0;
    int sum_till_last2 = 0;

    if (arr1.size()-1 != intersections.back().first){
        sum_till_last1 += pre_sum1.back() - pre_sum1[prev.first];
    }

    if (arr2.size()-1 != intersections.back().second){
        sum_till_last2 += pre_sum2.back() - pre_sum2[prev.second];
    }

    sum += max(sum_till_last1, sum_till_last2);

    return sum;

}

int main(){

    //freopen("0input.txt", "r", stdin);

    while(1){
        int n; cin >> n;
        if (n == 0)
            break;
        vector <int> arr1(n, 0);
        for (int i=0;i<n;i++)
            cin >> arr1[i];

        int m; cin >> m;
        vector <int> arr2(m, 0);
        for (int i=0;i<m;i++)
            cin >> arr2[i];

        cout << doubleHelix(arr1, arr2) << endl;
    }

    return 0;
}