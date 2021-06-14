// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    int dp[1010][1010];
    
    int _lcs(int i, int j, string &s1, string &s2){
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int mx = max(_lcs(i-1,j,s1,s2), _lcs(i,j-1,s1,s2));
        if(s1[i-1] == s2[j-1]) mx = 1 + _lcs(i-1,j-1,s1,s2);
        
        return dp[i][j] = mx;
    }
    
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        memset(dp,-1,sizeof(dp));
        return _lcs(x,y,s1,s2);
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends