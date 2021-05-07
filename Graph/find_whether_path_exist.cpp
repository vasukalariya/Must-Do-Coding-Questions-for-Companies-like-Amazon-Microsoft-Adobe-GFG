// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    
    bool vis[600][600];
    
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    bool dfs(int i, int j, vector<vector<int>> &grid, int n, int ex, int ey){
        
        vis[i][j] = true;
        if(i == ex && j == ey) return true;

                
        for(int k = 0;k < 4;k++){
            int x = i + dx[k];
            int y = j + dy[k];
            
            if(x >= 0 && y >= 0 && x < n && y < n && (grid[x][y] == 3 || grid[x][y] == 2) && !vis[x][y]){
                if(dfs(x,y,grid,n,ex,ey)) return true;
            }
        }
        return false;
    }
    
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        
        memset(vis,false,sizeof(vis));
        int sx,sy,ex,ey;
        int n = grid.size();
        
        
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){
                    sx = i;
                    sy = j;
                }
                if(grid[i][j] == 2){
                    ex = i;
                    ey = j;
                }
            }
        }
        
        return dfs(sx,sy,grid,n,ex,ey);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends