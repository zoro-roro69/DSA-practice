#include <bits/stdc++.h>
using namespace std;
//doesnt work
int findPages(int books[], int n, int m) {

    int low = 0;
    int high = 0;

    for (int i=0;i<n;i++){
        high += books[i];
    }
    int ans = -1;

    while(low <= high){

        int mid = low + (high - low)/2;
        //check if this can be minimum of the maximum
        int num_students = 0;
        int cur_sum = 0; //sum of pages being allocated to current student
        bool flag = false;
        for (int i=0;i<n;i++){
            cur_sum += books[i];
            if (cur_sum > mid){
                //cannot give current book to this student as sum exceeds the maximum
                cur_sum -= mid;
                if (cur_sum == 0){
                    //allocation not possible since after removing current book, no pages left (so from this point we know that sorted order of books is required)
                    flag = true;
                    break;
                }else{ //cur_sum > 0
                    //we are left with some pages, so we can allocate
                    num_students++;
                    cur_sum = 0;
                    i--; //will start allocating books for new student again from ith position
                }
            }else if (cur_sum == mid){
                num_students++;
                cur_sum = 0;
            }else{ //cur_sum < mid
                //do nothing
            }
        }

        if (num_students <= m && !flag){
            if (num_students == m)
                ans = mid;
            high = mid-1;

        }else if (num_students > m || flag){
            low = mid+1;
        }



    }

    return ans;


}

//doesnt work
 //////////   //Function to find minimum number of pages.
// int findPages(int books[], int n, int m) {

//     int low = 0;
//     int high = 0;

//     for (int i=0;i<n;i++){
//         high += books[i];
//         low = max(low, books[i]);
//     }
//     int ans = -1;
//     //cout <<  << endl;
//     while(low <= high){

//         int mid = low + (high - low)/2;
//         //check if this can be minimum of the maximum
//         int num_students = 0;
//         int cur_sum = 0; //sum of pages being allocated to current student
        
//         for (int i=0;i<n;i++){
            
//             cur_sum += books[i];
            
//             if (cur_sum > mid){
//                 cur_sum = books[i];
//                 num_students++;
//             }
//         }
        
//         // if (num_students == m){
//         //     ans = mid;
//         //     high = mid-1;
//         // }
//         if (num_students < m){
//             high = mid-1;
            //   ans = mid;
//         }else{
//             low = mid+1;
//         }

//     }

//     return ans;


//working solution

// int findPages(int A[], int N, int M) 
// {
//     if(M>N)
//         return -1;
//     if(M==N)
//         return *max_element(A,A+N);
//     if(M==1)
//         return accumulate(A,A+N,0);
        
//     int low=*max_element(A,A+N),high=accumulate(A,A+N,0);
//     int mid,res=-1;
//     //  cout << low << endl;
//     while(low<=high)
//     {
//         int sum=0,m=0;
//         mid=low+(high-low)/2;
//         for(int i=0;i<N;i++)
//         {
//             sum+=A[i];
//             if(sum>mid)
//             {
//                 sum=A[i];
//                 m++;
//             }
//         }
//         if(m<M)
//             high=mid-1,res=mid;
//         else
//             low=mid+1;
//     }
//     return res;
// }



// }




int main(){


    return 0;
}