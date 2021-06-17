// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int dp[101][101];
    
    int maxsum(int i, int j, vector<vector<int>> &mat){
        
        if(j < 0 || j >= mat[0].size()) return -999999;
        if(i == mat.size()-1) return mat[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = mat[i][j] + max({maxsum(i+1,j,mat), maxsum(i+1,j-1,mat), maxsum(i+1,j+1,mat)});
        
    }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        int mx = 0;
        for(int i = 0;i < Matrix[0].size();i++) mx = max(mx, maxsum(0,i,Matrix));
        
        return mx;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends