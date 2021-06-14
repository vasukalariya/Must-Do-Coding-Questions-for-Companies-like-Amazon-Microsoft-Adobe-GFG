// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    int dp[101][101];
    
    int dist(int i, int j, string &s, string &t){
        
        if(i == s.length()) return t.length() - j;
        if(j == t.length()) return s.length() - i;
        if(dp[i][j] != -1) return dp[i][j];
        
        int mn = 1 + min({dist(i,j+1,s,t), dist(i+1,j,s,t), dist(i+1,j+1,s,t)});
        if(s[i] == t[j]) mn = min(mn, dist(i+1,j+1,s,t));
        
        return dp[i][j] = mn;
    }
    
      
    int editDistance(string s, string t) {
        // Code here
        memset(dp,-1,sizeof(dp));
        return dist(0,0,s,t);
    }
    
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends