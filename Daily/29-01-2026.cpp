/*
#Problem 1: https://leetcode.com/problems/maximum-tastiness-of-candy-basket/
#Problem 2: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/
*/

/*
#Two Pointer
Problem 4: https://leetcode.com/problems/max-consecutive-ones-iii/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*
    Problem Statement:
    You are given an array of size n having 0's and 1's.
    Given you can flip atmost k zero's. What is maximum length
    subarray that you can have after applying this flip in optimal
    way.
    
    Example1:             t    h    
            nums[] = [0,1,0,0,1,0,0] k=2 ans=4
    */
    int n,k; cin>>n>>k;
    int nums[n];
    for(int i=0;i<n;i++) cin>>nums[i];
    
    int tail=0,head=-1;
    int zero_count=0,max_len=0;
    
    while(tail<n){
        while(head+1<n && zero_count+(nums[head+1]==0?1:0)<=k){
            if(nums[head+1]==0){
                zero_count++;
            }
            head++;
        }
        max_len = max(max_len,head-tail+1);
        if(nums[tail]==0) {
            zero_count--;
        }
        tail++;
        // if(tail>head){
        //     tail++;
        //     head=tail-1;
        // }else{
        //     if(nums[tail]==0) zero_count--;
        //     tail++;
        // }
    }
    cout<<max_len<<'\n';
    return 0;
}

/*
Problem 5: https://leetcode.com/problems/subarray-product-less-than-k/description/
Problem 6: https://leetcode.com/problems/count-the-number-of-good-subarrays/description/ 

*/