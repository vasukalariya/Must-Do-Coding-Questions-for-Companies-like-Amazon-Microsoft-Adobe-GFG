// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int dp[1010][1010];
    
    int ks(int i, int cap, int wt[], int val[]){
        if(i == 0 || cap == 0) return 0;
        if(dp[i][cap] != -1) return dp[i][cap];
        
        int mx = ks(i-1,cap,wt,val);
        if(cap >= wt[i-1]) mx = max(mx, val[i-1] + ks(i-1,cap-wt[i-1],wt,val));
        
        return dp[i][cap] = mx;
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(dp,-1,sizeof(dp));
       return ks(n,W,wt,val);
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends