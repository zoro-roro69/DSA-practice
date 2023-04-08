#include <bits/stdc++.h>
using namespace std;

struct mycomparator{
    bool operator()(pair <long long int, long long int> &p1, pair <long long int,  long long int> &p2)const{
        if (p1.first != p2.first)
            return p1.first < p2.first;
        else{
            return p1.second < p2.second;
        }
    }
};

int main(){

    //freopen("0input.txt", "r", stdin);
    int t;
    cin >>t;

    while(t--){
        int n, q;
        cin >> n >> q;
        vector <pair <long long int, long long int>> ranges;
        vector <long long int> temp;
        while(n--){
            long long int l, r;
            cin >> l >> r;
            ranges.push_back({l, r});
            // num_ += r - l + 1;
            // temp.push_back(num_);
        }

        sort(ranges.begin(), ranges.end(), mycomparator());
        //merge overlapping ranges
        vector <pair <long long int, long long int>> ranges_;
        ranges_.push_back(ranges.front());

        for (int i=1;i<ranges.size();i++){
            //check if ranges[i] overlaps with last of ranges_
            pair<long long int, long long int> p1 = ranges_.back();
            pair <long long int, long long int> p2 = ranges[i];
            if (p1.second >=  p2.first){ //overlap
                //merge
                ranges_.pop_back(); //removing previous
                ranges_.push_back({p1.first, p2.second > p1.second ? p2.second: p1.second}); //adding after merging
            }else{
                ranges_.push_back(p2);
            }
        }

        long long int num_ = 0;
        for (int i=0;i<ranges_.size();i++){
            num_ += ranges_[i].second - ranges_[i].first + 1;
            temp.push_back(num_);
        }

        while(q--){
            long long int k;
            cin >> k;
            //binary search
            long long int ans = -1;
            int low = 0;
            int high = temp.size()-1;
            while(low <= high){
                int mid = low + (high-low)/2;
                if (temp[mid] >= k){
                    ans = mid;
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            if (ans == -1)
                cout << -1 << endl;
            else{
                long long int sub = temp[ans] - k;
                long long int res = ranges_[ans].second - sub;
                cout << res << endl;
            }
        }

    }

    return 0;
}