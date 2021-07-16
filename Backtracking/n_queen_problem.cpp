// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool board[11][11];
    
    bool safe(int i, int j, int n){
        
        for(int k = 0;k < n;k++){
            if(board[k][j] || board[i][k]) return false;
            if(i+k < n && j+k < n && board[i+k][j+k]) return false;
            if(i-k >= 0 && j-k >= 0 && board[i-k][j-k]) return false;
            if(i-k >= 0 && j+k < n && board[i-k][j+k]) return false;
            if(i+k < n && j-k >= 0 && board[i+k][j-k]) return false;
        }
        
        return true;
    }

    void solve(int i, int n, vector<vector<int>> &sol){
        
        if(i == n){
            vector<int> curr;
            
            for(int m = 0;m < n;m++)
                for(int k = 0;k < n;k++)
                    if(board[m][k]) curr.push_back(k+1);
            
            sol.push_back(curr);
            
            return;
        }
        
        for(int j = 0;j < n;j++){
            if(safe(i, j, n)){
                board[i][j] = true;
                solve(i+1, n, sol);
                board[i][j] = false;
            }
        }
        
        return;
    }

    vector<vector<int>> nQueen(int n) {
        // code here
        
        memset(board, false,sizeof(board));
        vector<vector<int>> sol;
        solve(0, n, sol);
        
        return sol;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends