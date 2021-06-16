// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum number of cuts.
    
    int dp[101010];
    
    int cuts(int n, int x, int y, int z){
        if(n == 0) return 0;
        if(n < 0) return -999999;
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = 1 + max({cuts(n-x,x,y,z), cuts(n-y,x,y,z), cuts(n-z,x,y,z)});
    }
    
    
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(dp,-1,sizeof(dp));
        int num =  cuts(n,x,y,z);
        if(num < 0) return 0;
        else return num;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends