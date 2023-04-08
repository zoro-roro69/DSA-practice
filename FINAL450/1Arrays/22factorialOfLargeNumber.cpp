#include <bits/stdc++.h>
using namespace std;

void printVector(vector <int> v){
    for (auto x:v){
        cout << x << " ";
    }
    cout<<endl;
}
void reverseVector(vector <int> &v){
    for (int i=0, j = v.size()-1;i<j;i++,j--){
        swap(v[i], v[j]);
    }
}


vector <int> multiplyByDigit(vector <int> num, int digit){

    vector <int> res;
    int carry = 0;
    int rem = 0;
    for (auto x:num){
        int prod = x*digit + carry;
        carry = prod/10;
        int rem = prod%10;
        res.push_back(rem);
    }
    //if (carry)
    //    res.push_back(carry);
	
	while(carry){
		res.push_back(carry%10);
		carry /= 10;
	}

    return res;
}

vector <int> addVectors(vector <int> a, vector <int> b){

    vector <int> res;

    int i = 0, j = 0;
    int carry =0, rem = 0;

    for (;i<a.size() || j<b.size();i++,j++){
        int sum = (i<a.size() ? a[i]:0) + (j<b.size() ? b[j]: 0) + carry;
        carry = sum/10;
        rem = sum%10;
        res.push_back(rem);
    }

    if (carry)
        res.push_back(carry);

    return res;
}

vector <int> getDigits(int n){
    vector <int> res;
    while(n>0){
        res.push_back(n%10);
        n /= 10;
    }
    return res;
}


vector <int> findFactorial(int n){

    vector <int> res{1};

    for (int i=2;i<=n;i++){
        vector <int> digits = getDigits(i);
        vector <int> prev{0};
        vector <int> mul;
        for (int j=0;j<digits.size();j++){
            mul = res;
            vector <int> temp = multiplyByDigit(mul, digits[j]);
            vector <int> add_{0};
            if (j){
                add_.insert(add_.end(), temp.begin(), temp.end());
            }else{
                add_ = temp;
            }
            prev = addVectors(add_, prev);
        }
        res = prev;

    }
    return res;
}

vector <int> findFactorial2(int n){

	vector <int> res{1};

	for (int i = 2;i<=n;i++){
		res = multiplyByDigit(res, i);
	}
	reverseVector(res);
	return res;
}

int main(){

    //vector <int> res;
    //res = findFactorial(20);
    //reverseVector(res);
    //printVector(res);
//2432902008176640000
	vector <int> res;
	res = findFactorial2(20);
	printVector(res);
    return 0;
}
