// Binary Search
// Problem 1) [0,0,0,0,0,1,1,1,1,1,1]
// find index of 1st one.
// 1st approach: Linear Search O(n)
// 2nd approach: Binary Search:

#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    Problem Statement:
    You are given an array having bunch of 0's and 1's 
    where all 0's are placed before 1's. You have to find 
    the index of first '1' in the array
    
    Example1: 
    nums[] = [0,0,0,1,1,1,1,1,1];
    ans = 3 
    nums2[] =[0,0,0,0,1,1,1,1,1,1];
    ans=4 
    */
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    
    int lo=0,hi=n-1;
    int first1_index = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2; // lo+(hi-lo)/2
        if(nums[mid]==1){
            first1_index=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    
    cout<<"index of first 1: "<<first1_index<<'\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums={0,0,0,0,0,1,1,1,1,1,1};
    int target=1;
    int low=0;
    int high=nums.size()-1;
    while (low<=high){
        int mid=low+(high-low)/2;
        if (nums[mid]==target && nums[mid-1]!=target){
            cout<<mid;
            break;
        }
        else if (nums[mid]<target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return 0;
}



// Problem 2: CSES-> https://cses.fi/problemset/task/1620
// #include <bits/stdc++.h>
// using namespace std;

int main()
{
    /*
    Problem Statement:
    You are given n machines where each machines can produce
    a product in ki times you have to find the minimum time
    in which we can make t products, given you can operate all
    machines simultanously
    
    Example1:
        3 7
        3 2 5
        x=15
        f(int x,int t)-> this function will return the number of 
        products you can produce in x unit of time
        
    
    */
    
    int n,t; cin>>n>>t;
    
    vector<int> time_taken(n);
    for(int i=0;i<n;i++) cin>>time_taken[i];
    
    long long lo=1,hi=(long long)1e12;
    
    int ans = hi;
    auto check = [&](long long m)->bool{
        long long product_made_so_far =0;
        for(int i=0;i<n;i++){
            product_made_so_far+=m/time_taken[i];
            if(product_made_so_far>=t){
                return true;
            }
        }
        return false;
    };
    while(lo<=hi){
        int m = (lo+hi)/2;
        if(check(m)){
            ans=m;
            hi=m-1;
        }else{
            lo=m+1;
        }
    }
    
    cout<<"minimum time to produce: "<<t<<" products is: "<<ans<<'\n';
    return 0;
}
