// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxBalls(int N, int M, int a[], int b[]){
        // code here
        
        int ans = 0, s1 = 0, s2 = 0, i = 0, j = 0;
        
        while(i < N && j < M){
            if(a[i] < b[j]) s1 += a[i++];
            else if(a[i] > b[j]) s2 += b[j++];
            else{
                int common = a[i];
                
                while(i < N && a[i] == common) s1 += a[i++];
                while(j < M && b[j] == common) s2 += b[j++];
                
                ans += max(s1,s2);
                s1 = 0;
                s2 = 0;
            }
        }
        while(i < N) s1 += a[i++];
        while(j < M) s2 += b[j++];
        ans += max(s1,s2);
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        int a[N], b[M];
        for(int i = 0;i < N;i++)
            cin>>a[i];
        for(int i = 0;i < M;i++)
            cin>>b[i];
        
        Solution ob;
        cout<<ob.maxBalls(N, M, a, b)<<"\n";
    }
    return 0;
}  // } Driver Code Ends