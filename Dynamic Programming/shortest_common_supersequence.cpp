// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    
    int dp[101][101];
    
    int lcs(int i, int j, string s1, string s2, int m, int n){
        
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i-1] == s2[j-1]) return dp[i][j] = 1 + lcs(i-1,j-1,s1,s2,m,n);
        else return dp[i][j] = max(lcs(i-1,j,s1,s2,m,n), lcs(i,j-1,s1,s2,m,n));
    }
    

    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        memset(dp,-1,sizeof(dp));
        int len = m + n - lcs(m,n,X,Y,m,n);
        
        return len;
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends