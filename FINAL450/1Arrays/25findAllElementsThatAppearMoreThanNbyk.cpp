#include <bits/stdc++.h>
using namespace std;


void printVector(vector <int> v){
    for (auto x:v){
        cout << x << " ";
    }
    cout<<endl;
}

struct element{
    int elem;
    int count;

};

vector <int> moreThanNbyK(vector <int> v, int k){
    vector <int> res;
    int n = v.size();
    int x = n/k;

    struct element elements[k-1];

    for (auto &e:elements){
        e.count = 0;
        e.elem = 1;
    }

    cout << "check" << endl;
    for (auto e:elements){
        cout << e.elem << endl;
    }

    for (auto a:v){
        bool flag = false;
        for (auto &e:elements){
            if (e.elem == a){
                e.count++;
                flag = true;
                break;
            }
        }
        if (!flag){
            for (auto &e:elements){
                if (e.count == 0){
                    e.elem = a;
                    cout << a << "--" << e.elem << endl;
                    e.count = 1;
                    flag = true;
                    break;
                }
            }
            if (!flag){//was not able to insert this element
                for (auto &e:elements)
                    e.count--;
            }
        }
    }

    for (auto e:elements){
        int count = 0;
        for (auto a:v){
            if (e.elem == a)
                count++;
        }

        if (count > x)
            res.push_back(e.elem);
    }

    return res;

}

int main(){
    vector <int> v{1,1,2,2,2,3,3,3,4,4,4};
    vector <int> res = moreThanNbyK(v, 4);
    printVector(res);   


    return 0;
}

