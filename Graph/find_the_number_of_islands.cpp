// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the number of islands.
    
    int dx[8] = {1,1,0,-1,-1,-1,0,1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};
    
    bool valid(int i, int j, vector<vector<char>> &grid){
        if(i >= grid.size() || i < 0 || j < 0 || j >= grid[i].size() || grid[i][j] == '0') return false;
        return true;
    }
    
    
    void dfs(int i, int j, vector<vector<char>> &grid){
        grid[i][j] = '0';
        for(int k = 0;k < 8;k++){
            if(valid(i+dx[k],j+dy[k],grid)) dfs(i+dx[k],j+dy[k],grid);
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        int cnt = 0;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[i].size();j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends