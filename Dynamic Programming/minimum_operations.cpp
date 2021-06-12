// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
  
    int dp[100010];
  
    int minop(int num){
        if(dp[num] != -1) return dp[num];
        if(num == 0) return 0;
        else if(num < 0) return 9999999;
        else{
            if(num%2 == 0) return dp[num] = 1 + min(minop(num-1), minop(num/2));
            else return dp[num] = 1 + minop(num-1);
        }
    }
  
    int minOperation(int n)
    {
        //code here.
        memset(dp,-1,sizeof(dp));
        return minop(n);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends