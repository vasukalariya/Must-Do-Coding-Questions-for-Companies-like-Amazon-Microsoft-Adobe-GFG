// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    
    long long dp[100010];
    
    long long ways(int n){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = (ways(n-1) + ways(n-2) + ways(n-3))%1000000007;
    }
    
    
    
    long long countWays(int n)
    {
        // your code here
        memset(dp,-1,sizeof(dp));
        return ways(n);
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends