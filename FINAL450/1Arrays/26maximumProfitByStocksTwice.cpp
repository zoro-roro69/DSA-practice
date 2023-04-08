#include <bits/stdc++.h>
using namespace std;

void printVector(vector <int> v){
    for (auto x:v){
        cout << x << " ";
    }
    cout<<endl;
}


//using DP, time & space - O(n)
int maxProfit(vector <int> price){
    int n = price.size();
    vector <int> profit(n);

    profit[n-1] = 0;
    int max_price = price[n-1];

    //from right to left    
    for (int i=n-2;i>=0;i--){
        max_price = max(max_price, price[i]);
        profit[i] = max(profit[i+1], max_price - price[i]);
    }

    int min_price = price[0];
    for (int i = 1;i<n;i++){
        min_price = min(min_price, price[i]);
        if (i+1<n)
            profit[i] = max(profit[i-1], profit[i+1] + (price[i]-min_price));
        else
            profit[i] = max(profit[i-1], price[i]-min_price);
    }

    return profit[n-1];
}

//valley peak approach, this wont work in this case since here only two transactions are allowed
//this will work when we have unlimited transactions
int maxProfit2(vector <int> price){
    int n  = price.size();

    // valley-peak approach
    /*
                       80
                       /
        30            /
       /  \          25
      /    15       /
     /      \      /
    2        10   /
               \ /
                8
    */

    //this basically adds all of the uphill difference i.e 2 - 30,  8 - 80
    int profit = 0;
    for (int i=1;i<n;i++){
        if (price[i]>price[i-1]){
            profit += price[i]-price[i-1];
        }
    }
    return profit;
}

//THis is the most optimal soln, time O(n), space O(1)
//difficult to understand
int maxtwobuysell(int arr[],int size) {
    int first_buy = INT_MIN;
      int first_sell = 0;
      int second_buy = INT_MIN;
      int second_sell = 0;
       
      for(int i=0;i<size;i++) {
         
          first_buy = max(first_buy,-arr[i]);//we set prices to negative, so the calculation of profit will be convenient
          first_sell = max(first_sell,first_buy+arr[i]);
          second_buy = max(second_buy,first_sell-arr[i]);//we can buy the second only after first is sold
          second_sell = max(second_sell,second_buy+arr[i]);
       
    }
     return second_sell;
}


// max profit when k transactions are allowed 

//this is my wrong soution , inspired by valley-hill approach
int maxProfitKTransactions(vector <int> v, int k){

    //top k transactions
    int i = 0, n = v.size();

    //min_heap of size k
    priority_queue <int, vector<int>, greater<int>> min_heap;

    while(i<n){
        int low = v[i];
        i++;
        while(i<n && v[i] > v[i-1]){
            i++;
        }
        i--;
        //i is at the high
        int high = v[i];
        if (min_heap.size() < k){
            min_heap.push(high-low);
        }else{
            if (min_heap.top() < (high-low)){
                min_heap.pop();
                min_heap.push(high-low);
            }
        }

        //now go to bottom
        i++;
        while(i<n && v[i] < v[i-1]){
            i++;           
        }
        if (i == n) break;
        i--;
    }
    int res = 0;

    while(min_heap.empty() == false){
        res += min_heap.top();
        min_heap.pop();
    }

    return res;
}

//maximum k transactions , using DP
//complexity O(k*n*n)
/*
     * Time complexity is O(k * number of days ^ 2)
     * T[i][j] = max(T[i][j-1], max(prices[j] - prices[m] + T[i-1][m])) where m is 0...j-1
     */
int dpSolution1(vector <int> prices, int k){
    int n = prices.size();
    vector <vector <int>> dp(k+1, vector <int> (n, 0));

    for (int i=1;i<=k;i++) { //i = transactions
        for (int j=1; j<n;j++){ //j = days
            int res = dp[i][j-1]; //not making transaction on day j
            for (int m=0;m<j;m++){ //m = days before j
                res = max(res, prices[j]-prices[m] + dp[i-1][m]);
            }
            dp[i][j] = res;
        }
    }
    return dp[k][n-1];
}

//optimized dp solution 
//complexity O(k*n)
/*
     * Formula is
     * T[i][j] = max(T[i][j-1], prices[j] + maxDiff)
     * maxDiff = max(maxDiff, T[i-1][j] - prices[j])
     */
int dpSolution2(vector <int> prices, int k){
    int n = prices.size();
    vector <vector <int>> dp(k+1, vector <int> (n, 0));

    for (int i=1;i<=k;i++){
        int max_diff = -prices[0];
        for (int j=1;j<n;j++){
            dp[i][j] = max(dp[i][j-1], prices[j]+max_diff);
            max_diff = max(max_diff, dp[i-1][j] - prices[j]);
        }
        // max_diff = max(max_diff, prices[j] - dp[i][]);
    }

    return dp[k][n-1];
}

int main(){

    //{10, 22, 5, 75, 65, 80}
    vector <int> price{2,30,15,10,8,25,80};
    cout << maxProfit2(price) << endl;
    cout << maxProfitKTransactions(price, 2) << endl;

    return 0;
}