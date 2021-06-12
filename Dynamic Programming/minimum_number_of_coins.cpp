// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    
    int coins[10] = {1,2,5,10,20,50,100,200,500,2000};
    
    int mincoins(int num, vector<int> &dp, vector<int> &val){
        if(num < 0) return 9999999;
        if(num == 0) return 0;
        if(dp[num] != -1) return dp[num];
        
        int mn = 9999999;
        int coin = 0;
        
        for(int i = 0;i < 10;i++){
            int op = 1 + mincoins(num-coins[i],dp,val);
            if(mn > op){
                mn = op;
                coin = coins[i];
            }
        }
        val[num] = coin;
        return dp[num] = mn;
    }


    vector<int> minPartition(int N)
    {
        // code here
        
        vector<int> dp(N+1);
        vector<int> val(N+1);
        
        for(int i = 0;i < dp.size();i++) dp[i] = -1;
        
        vector<int> seq;
        mincoins(N,dp,val);
        int sum = N;
        
        while(sum){
            seq.push_back(val[sum]);
            sum -= val[sum];
        }
        reverse(seq.begin(),seq.end());
        return seq;
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
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends