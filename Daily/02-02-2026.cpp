/*
Recursion
Problem 1: YOu are given a sequence of size n, you have to generate all subset of this particular sequence
[1,2,3];
[1],[2],[3],[1,2],[2,3],[1,3],[1,2,3]
*/

#include <bits/stdc++.h>
using namespace std;

void generate_subset(int i,vector<int> &nums,vector<int> &cur_subset){
    /*
    we have decided numbers till (i-1)th index, now try to 
    generate subset with whatever you have decided earlier
    
    */
    if(i==nums.size()){
        for(int x:cur_subset) cout<<x<<" "; cout<<'\n';
        return ;
    }
    //choice 1: don't include
    generate_subset(i+1,nums,cur_subset);
    //choice 2: include this ith element
    cur_subset.push_back(nums[i]);
    generate_subset(i+1,nums,cur_subset);
    cur_subset.pop_back();
    
    
}
int main()
{
    /*
    Problem Statement:
    You are given a sequence of size n, you have to generate 
    all subset of this particular sequence
    n=3
    nums[]=[1,2,3],->[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]
    generate_subset(0,nums,cur_subset)
    
    */
     int n; cin>>n;
     vector<int> nums(n); for(int i=0;i<n;i++) cin>>nums[i];
     vector<int> cur_subset;
     generate_subset(0,nums,cur_subset);
    

    return 0;
}


/*


Backtracking
Problem 2: N-Queen Problem

Problem 3: https://leetcode.com/problems/target-sum/description

Problem 4: https://leetcode.com/problems/fair-distribution-of-cookies
Problem 5: https://leetcode.com/discuss/post/4172036/oa-dp-question-by-anonymous_user-km7a/

 */