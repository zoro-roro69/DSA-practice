#include <bits/stdc++.h>
using namespace std;

//inspired by kadanes algo
//this assumes that answer is always +ve or zero
int maxProductSubArray(vector <int> v){
	
	int max_prod = 0;
	int max_ending_here = 1; //positive product
	int min_ending_here = 1; //negative product

	int flag = 0;


	for (int i=0;i<v.size()<i++){
		if (v[i] > 0 ){ //positive number
			max_ending_here = max_ending_here*v[i];
			min_ending_here = min(min_ending_here*v[i], 1);
			flag = 1;
		}else if (v[i] == 0){
			max_ending_here = 1;
			min_ending_here = 1;
		}else{ //negative number
			//-ve * -ve = +ve
			int temp = max_ending_here;
			max_ending_here = min_ending_here*v[i];
			min_ending_here = temp*arr[i];
		}

		if (max_prod < max_ending_here)
			max_prod = max_ending_here;
	}
	if (flag == 0 && max_prod == 1)
		return 0;

	return max_prod;
}


int maxProdSubArray2(vector <int> v){
	int max_prod = v[0];
	int max_ending_here = v[0];
	int min_ending_here = v[0];

	for (int i=1;i<v.size();i++){
		int temp = maxOf3(v[i], max_ending_here*v[i], min_ending_here*v[i]);
		min_ending_here = minOf3(v[i], max_ending_here*v[i], min_ending_here*v[i]);
		max_ending_here = temp;
		max_prod = maxOf2(max_ending_here, max_prod);
	}

	return max_prod;
}



int main(){
	vector <int> res{0,0,0,0};
	cout << maxProductSubArray(res) << endl;

	return 0;
}
