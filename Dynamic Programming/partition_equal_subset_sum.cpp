// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int dp[1010][1010];
    
    int partition(int i, int sum, int arr[], int N){
        if(sum == 0) return 1;
        if(i == N || sum < 0) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        
        return dp[i][sum] = partition(i+1,sum-arr[i],arr,N) | partition(i+1,sum,arr,N);
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i < N;i++) sum += arr[i];
        
        if(sum%2) return 0;
        
        return partition(0,sum/2,arr,N);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends