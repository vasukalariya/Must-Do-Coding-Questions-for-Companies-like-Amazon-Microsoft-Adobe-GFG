// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++
#define ll long long

class Solution{
public:
    ll dp[80];

    ll print(ll n){
        if(n < 7) return n;
        if(dp[n] != -1) return dp[n];
        else{
            ll mx = -999999;
            for(ll i = n-3,j=2;i > 0;i--,j++){
                mx = max(mx, j*print(i));
            }
            return dp[n] = mx;
        }
    }
    unsigned long long int optimalKeys(int N){
        // code here
        memset(dp,-1,sizeof(dp));
        if(N > 75) return -1;
        else return print(N);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends