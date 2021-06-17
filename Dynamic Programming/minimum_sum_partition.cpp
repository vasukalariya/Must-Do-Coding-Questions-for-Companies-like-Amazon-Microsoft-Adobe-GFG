// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    
    int minsum(int i, int sum, int arr[], int n, int total, vector<vector<int>> &dp, vector<vector<bool>> &done){
        
        if(i == n) return abs(total - 2*sum);
        if(done[i][sum] != false) return dp[i][sum];
        
        int include = minsum(i+1,sum+arr[i],arr,n,total,dp,done);
        int exclude = minsum(i+1,sum,arr,n,total,dp,done);
        
        done[i][sum] = true;
        return dp[i][sum] = min(include, exclude);
    }
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    int total = 0;
	    for(int i = 0;i < n;i++) total += arr[i];
	    
        vector<vector<int>> dp(n, vector<int>(total,-1));
        vector<vector<bool>> done(n, vector<bool>(total,false));
	    
	    return minsum(0,0,arr,n,total,dp,done);
	   
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends