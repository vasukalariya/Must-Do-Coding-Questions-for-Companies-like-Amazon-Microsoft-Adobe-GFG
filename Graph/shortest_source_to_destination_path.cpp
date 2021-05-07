// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool vis[500][500];
  
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        memset(vis,false,sizeof(vis));
        queue<pair<int,pair<int,int>>> q;
        
        q.push({0,{0,0}});
        
        if(A[0][0] == 0 || A[X][Y] == 0) return -1;
        if(X == 0 && Y == 0) return 0;
        
        vis[0][0] = true;
        
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int dist = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;
            
            for(int k = 0;k < 4;k++){
                int new_x = x + dx[k];
                int new_y = y + dy[k];
                int new_dist = dist + 1;
                
                if(new_x >= 0 && new_y >= 0 && new_x < N && new_y < M && A[new_x][new_y] == 1 && !vis[new_x][new_y]){
                    vis[new_x][new_y] = true;
                    if(new_x == X && new_y == Y) return new_dist;
                    q.push({new_dist,{new_x,new_y}});
                }
            }
        }
        
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends