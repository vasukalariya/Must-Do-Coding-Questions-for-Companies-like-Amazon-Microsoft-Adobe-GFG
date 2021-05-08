// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        
        int g[31] = {0};
        
        for(int i = 0;i < N;i++){
            g[arr[2*i]] = arr[2*i+1];
        }
        
        queue<pair<int,int>> q;
        
        q.push({1,0});
        
        bool vis[31] = {false};
        vis[0] = true;
        
        while(!q.empty()){
            
            int cur = q.front().first;
            int moves = q.front().second;
            if(cur == 30) return moves;
            vis[cur] = true;
            q.pop();
            
            for(int i = 1;i < 7;i++){
                int next = cur + i;
                if(next < 31 && !vis[next]){
                    if(g[next] > 0) q.push({g[next],moves+1});
                    else q.push({next,moves+1});
                }
            }
        }
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends