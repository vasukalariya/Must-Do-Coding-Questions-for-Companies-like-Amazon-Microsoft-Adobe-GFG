// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution
{
    public:
    
    // bool vis[1010];
    
    // bool dfs(int idx, vector<int> avail[], vector<string> A, int N, bool incall[], int cycle){
        
    //     vis[idx] = true;
    //     incall[idx] = true;
    //     int ch = A[idx][A[idx].length()-1] - 'a';
        
    //     for(int i = 0;i < avail[ch].size();i++){
    //         if(incall[avail[ch][i]] && avail[ch][i] != idx && cycle == N) return true;
    //         if(!vis[avail[ch][i]] && dfs(avail[ch][i], avail, A, N, incall,cycle+1)) return true;
    //     }
        
    //     incall[idx] = false;
    //     return false;
    // }
    

    int isCircle(int N, vector<string> A)
    {
        // code here
        // Alternate Graph Approach is commented
        // vector<int> avail[26];
        // memset(vis,false,sizeof(vis));
        // bool incall[N] = {false};
        
        // if(N == 1 && A[0][0] == A[0][A[0].length()-1]) return 1;
        
        // for(int i = 0;i < N;i++){
        //     avail[A[i][0]-'a'].push_back(i);
        // }
        
        // if(dfs(0,avail,A,N,incall,1)) return 1;
        
        // return 0;
        
        int start[26] = {0};
        int end[26] = {0};
        
        for(int i = 0;i < N;i++){
            int s = A[i][0] - 'a';
            int e = A[i][A[i].length()-1] - 'a';
            start[s]++;
            end[e]++;
        }
        
        for(int i = 0;i < 26;i++){
            if(start[i] != end[i]) return 0;
        }
        return 1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends