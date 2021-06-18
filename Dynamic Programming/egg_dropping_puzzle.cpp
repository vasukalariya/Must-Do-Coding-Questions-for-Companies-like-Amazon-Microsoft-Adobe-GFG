// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[500][500];
    
    int drop(int n, int k){
        if(n == 1 || k == 1 || k == 0) return k;
        if(dp[n][k] != -1) return dp[n][k];
        
        int mn = 999999;
        for(int i = 1;i <= k;i++){
            mn = min(mn, 1 + max(drop(n-1, i-1), drop(n,k-i)));
        }
        
        return dp[n][k] = mn;
    }
    
    
    int eggDrop(int n, int k) 
    {
        // your code here
        memset(dp,-1,sizeof(dp));
        return drop(n,k);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends